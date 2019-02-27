// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames and n_index
    char *infile = argv[2];
    char *outfile = argv[3];
    int n_index = atoi(argv[1]);

    if (n_index <= 0 || n_index > 100)
    {

        fprintf(stderr, "N-index must be a positive value or no more than 100\n");
        return 1;

    };

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //fprintf(stderr, "Padding %i\n", padding);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int old_biWidth = bi.biWidth;
    int old_biHeight = bi.biHeight;

    // new Width and Height
    bi.biWidth *= n_index;
    bi.biHeight *= n_index;

    // determine padding for scanlines

    int outptr_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //fprintf(stderr, "Out Padding %i\n", outptr_padding);

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + outptr_padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);


    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(old_biHeight); i < biHeight; i++)
    {

        // for n-1 times & resize vertically
        for (int g = 0 ; g < (n_index - 1) ; g++)
        {

            //iterate over pixels in scanline
            for (int j = 0; j < old_biWidth; j++)
            {

                //temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile and resize horizontally
                for (int l = 0; l < n_index; l++)
                {

                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    //fprintf(stderr, " Green - %i\n Blue - %i\n Red - %i\n =====\n", triple.rgbtGreen, triple.rgbtBlue, triple.rgbtRed);
                };


            };


            //adding padding to outptr file
            for (int k = 0; k < outptr_padding; k++)
            {
                fputc(0x00, outptr);
            };

            //send our cursor back
            fseek(inptr, -old_biWidth * 3, SEEK_CUR);
        };





        // iterate over pixels in scanline
        for (int j = 0; j < old_biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile and resize horizontally
            for (int l = 0; l < n_index; l++)
            {

                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            };
        };


        //then add it back (to demonstrate how)
        for (int k = 0; k < outptr_padding; k++)
        {
            fputc(0x00, outptr);
        };

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    };


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}