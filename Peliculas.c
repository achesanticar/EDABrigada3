#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Peliculas
{
    char Titulo[50], Director[50], Genero[30];
    int Año, pnum;
    float Puntuacion, Duracion;
};


int main(int argc, char const *argv[])
{
    int op = 1, n=1;
    char buff[200];
    FILE* base;

    struct Peliculas *datos = NULL;

    base = fopen("base_datos.txt", "r");
    if (base == NULL)
        {
            printf("Error abriendo archivo");
            return 1;
        }

    while (fgets(buff, 200, base) != NULL)
    {
        datos = realloc(datos, (n+1) * sizeof(struct Peliculas));
        sscanf(buff, "%d %s %s %d %s %f %f", &datos[n].pnum, datos[n].Titulo, datos[n].Director, &datos[n].Año, datos[n].Genero, &datos[n].Puntuacion, &datos[n].Duracion);
        n++;
    }

    fclose(base);

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
            
            printf("Titulo:");
            gets(datos[n].Titulo);
            

            fclose (base);
            break;
        
        case 2:
            for (int i = 0; i < n; i++)
            {
                printf("%d-%s Dirigida por: %s en %d. Pelicula de %s, puntuacion de %.1f y duracion de %.1f\n", i+1, datos[n].Titulo, datos[n].Director, &datos[n].Año, datos[n].Genero, &datos[n].Puntuacion, &datos[n].Duracion);
            }
            
            break;
        
        default:
            break;
        }
    }
    
    free (datos);
    
    return 0;
}
