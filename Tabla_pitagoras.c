#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int Ren, Col, **tab;

    printf("-Tabla de pitagoras dinamica-\nRenglones: ");
    scanf("%d", &Ren);
    printf("\nColumnas: ");
    scanf("%d", &Col);

    tab = (int **)malloc(Ren * sizeof(int*));

    for (int i = 0; i < Ren; i++)
    {
            tab[i]= (int *)malloc(Col * sizeof(int));
    }
    
    for (int i = 0; i < Ren ; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            tab[i][j] = (j+1) * (i+1);
        }
    }
    
    for (int i = 0; i < Ren ; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            printf("%d ", tab[i][j]);
            if (tab[i][j] < 10)
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
    return 0;
}
