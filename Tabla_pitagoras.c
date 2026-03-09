#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int Ren, Col, **tab;

    printf("-Tabla de pitagoras dinamica-\nRenglones: ");
    scanf("%d", &Ren);
    printf("\nColumnas: ");
    scanf("%d", &Col);

    tab = (int **)malloc(Col * sizeof(int**));
    *tab= (int *)malloc(Ren * sizeof(int*));

    for (int i = 0; i <= Col ; i++)
    {
        for (int j = 0; j <= Ren; j++)
        {
            tab[j][i] = j * i;
        }
    }
    
    for (int i = 0; i <= Col ; i++)
    {
        for (int j = 0; j <= Ren; j++)
        {
            printf("%d", tab[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}
