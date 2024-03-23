#include <math.h>
#include <stdio.h>
#include <cs50.h>

int get_valid(void);

int main(void)
{
    int tr = get_valid();
    int n = 0;
    while (tr > 0)
    {
        if (tr - 25 >= 0)
        {
            tr = tr - 25;
            n++;
            continue;
        }
        if (tr - 10 >= 0)
        {
            tr = tr - 10;
            n++;
            continue;
        }
        if (tr - 5 >= 0)
        {
            tr = tr - 5;
            n++;
            continue;
        }
        if (tr - 1 >= 0)
        {
            tr = tr - 1;
            n++;
            continue;
        }
    }
    printf("%i\n", n);
}

int get_valid(void)
{
    float dol;
    int cents;
    do
    {
        dol = get_float("Troco devido: ");
        cents = round(dol * 100);
    }
    while (dol < 0);
    return cents;
}
