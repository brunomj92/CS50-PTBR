#include <stdio.h>
#include <cs50.h>

int get_valid(int a, char b);

int main(void)
{
    int ni = get_valid(9, 'i'); //Solicite o valor inicial ao usuário
    int no = get_valid(ni, 'o'); //Solicite o valor final ao usuário
    int d = no - ni; //Calcule o número de anos até o limite
    int yrs = 0;
    while (d > 0)
    {
        ni = ni + ni/3 - ni/4;
        d = no - ni;
        yrs++;
    }
    printf("Years: %i\n", yrs); //Imprima o número de anos
}

int get_valid(int a, char b)
{
    int n;
    do
    {
        if (b == 'i')
        {
            n = get_int("Start size: ");
        }
        else if (b == 'o')
        {
            n = get_int("End size: ");
        }
    }
    while (n < a);
    return n;
}
