#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Insert the starting population size of llamas: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size

    int end_size;
    do
    {
        end_size = get_int("Insert the ending population size of llamas: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    /* start_size + born_per_year - loss_per_year = end_size
    start_size + (start_size/3 - start_size/4)^n = end_size
    start_size*(13/12) = start_size2
    start_size*(13/12)*(13/12)**  **(13/12) = end_size
    years = ln[end_size/start_size]/ln(13/12)
    int year_counter = 0; */

    int n = 0;

    float log1 = log((double) end_size / (double) start_size);
    float log2 = log(13.0 / 12.0);

    n = log1 / log2;

    // int n = 0;

    // while (start_size < end_size)
    // {
    //     start_size = start_size + (start_size / 3) - (start_size / 4);
    //     n++;
    // }


    // TODO: Print number of years
    printf("Years: %i", n);
}