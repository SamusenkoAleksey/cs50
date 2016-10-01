#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int bottles = GetInt();
    
    switch (bottles)
    {
        case 1:
            printf("1 minute equeals 12 bottles\n");
            break;
        case 2:
            printf("2 minutes equeals 24 bottles\n");
            break;
        case 5:
            printf("5 minutes equeals 60 bottles\n");
            break;
        case 10:
            printf("10 minutes equeals 120 bottles\n");
            break;    
    }
    
}