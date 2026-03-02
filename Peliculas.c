#include <stdio.h>
#include <string.h>

struct Peliculas
{
    char Titulo[50], Director[50];
    int Año, Genero, pnum;
    float Puntuacion, Duracion;
};


int main(int argc, char const *argv[])
{
    int op = 1, n=1;
    char buff[200];
    FILE* base;

    base = fopen("base_datos.txt", "r");

    while (fgets(buff, 200, base) != NULL)
    {
        struct Peliculas n;
        sscanf(buff, "%d %s %s %d %d %f %f", n.pnum, n.Titulo, n.Director, n.Año, n.Genero, n.Puntuacion, n.Duracion);
        n++;
    }

    printf("--Base de datos de peliculas--\n");
    while (op != 0)
    {
        printf("Elige una opcion:\n0-Salir\n1-Agregar una entrada\n2-Ver base de datos\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            base = fopen("base_datos.txt", "a");
            if (base == NULL)
            {
                printf("Error abriendo archivo");
                return 1;
            }
            
            printf("Nombre:");
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
}
