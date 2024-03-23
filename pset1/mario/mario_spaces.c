#include <cs50.h>
#include <stdio.h>

int get_valid(void);

int main(void)
{
    int h = get_valid();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < (h*2 + 2); j++)
        {
            if ((i + j) < (h - 1) || j == h || j == (h + 1) || (j-i) > (h + 2))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int get_valid(void)
{
    int n;
    do
    {
        n = get_int("Tamanho: \n");
    }
    while (n < 1 || n > 8);
    return n;
}
