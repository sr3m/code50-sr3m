#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int getHeight = 0;
    do
    {
        getHeight = get_int("Height: ");
    }
    while (!(getHeight >= 1 && getHeight <= 8));

    if (getHeight >= 1 && getHeight <= 8)
    {
        for (int i = 1; i <= getHeight; i++)
        {
            for (int z = getHeight - i; z > 0; z--)
            {
                printf(" ");
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                printf("#");
                continue;
            }
            printf("  ");
            for (int k = 0; k < i; k++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}

