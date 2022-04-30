#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int nstart, start, end, new, death, foryear, years = 0;

    // Prompt to user write the values
    do
    {
        start = get_int("Numero inicial: ");
    }
    while (start < 9);
    do
    {
        end = get_int("Numero final: ");
    }
    while (end < start);
    printf("\n");

    // Tradind the start for nstart to calcule the loop
    nstart = start;

    // Loop for count years
    while (start < end)
    {
        new = (float) start / 3;
        death = (float) start / 4;
        foryear = new - death;
        start += foryear;
        years++;
    }

    // Return for user
    printf("Populacao inicial: %i\n", nstart);
    printf("Populacao final: %i\n", end);
    printf("Anos que levarao: %i\n", years);

}