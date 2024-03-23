#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

long long get_valid(void);

int main(void)
{
    long long n = get_valid();
    char str[32];
    sprintf(str, "%llu", n);
    int z = strlen(str);
    printf("%s\n", str);
    int dz[z];
    for (int i = z - 1; i >= 0; i--)
    {
        dz[i] = n%10;
        n = n / 10;
        printf("%d,", dz[i]);
    }
}


long long get_valid(void)
{
    long long card;
    do
    {
        card = get_long_long("Número: ");
    }
    while (card < 0);
    return card;
}
