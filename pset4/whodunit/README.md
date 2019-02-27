# Questions

## What's `stdint.h`?

It is a header file, which allows to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To declare needed number of memomy in bites.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE - 1 byte
DWORD - 4 bytes
LONG - 4 bytes
WORD - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize - declares size, in bytes, of the bitmap file.
biSize - declaries size, also in bytes, required by the structure of a file.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If there is no file exist.

## Why is the third argument to `fread` always `1` in our code?

Lines #40 & #44 - we are reading "BITMAPFILEHEADER" and "BITMAPINFOHEADER", which is unique for a file. There is no reason to read multiple times.
Line #75 - The same case, our code reads "RGBTRIPLE" info for each pixel.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

In this case padding will equial to "3".

## What does `fseek` do?

This function changes the offset of the file pointer if there is any padding.

## What is `SEEK_CUR`?

An argument definies an integer, that our codes starts reading a file from.

## Whodunit?

It was Professor Plum with the candlestick in the library