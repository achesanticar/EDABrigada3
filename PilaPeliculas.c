#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Peliculas
{
    int Cima, Anno[10];
    char Titulo[10][100], Director[10][50];
}pelicula;

pelicula *crear_pila(pelicula *P) {
    P = (pelicula *)malloc(sizeof(pelicula));
    P->Cima = -1;
    return P;
}

void push(pelicula *P) {
    if (P->Cima == 9){printf("La pila esta llena");} 
    else {
        P->Cima++;
        printf("Nombre de la pelicula: ");
        getchar();
        fgets(P->Titulo[P->Cima], 100, stdin);
        P->Titulo[P->Cima][strcspn(P->Titulo[P->Cima], "\n\r")] = 0;
        printf("Director: ");
        fgets(P->Director[P->Cima], 50, stdin);
        P->Director[P->Cima][strcspn(P->Director[P->Cima], "\n\r")] = 0;
        printf("\nAnno de lanzamiento: ");
        scanf("%d", &P->Anno[P->Cima]);
    } 
}

void pop(pelicula *P) {
    if (P->Cima == -1) {printf("La pila esta vacia\n");} 
    else {      
        printf("%s, %s %d\n", P->Titulo[P->Cima], P->Director[P->Cima], P->Anno[P->Cima]);
        P->Cima--;
    }
}

int main(int argc, char const *argv[])
{
    int c=1;
    pelicula *P1;
    P1 = crear_pila(P1);

    while (c != 3)
    {
        printf("Elige una accion:\nPush-0\nPop-1\nVer la pila completa-2\nSalir-3\n");
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            push(P1);
            break;
        
        case 1:
            pop(P1);
            break;
        
        case 2:
            for (int i = P1->Cima; i >= 0; i--)
            {
                printf("%d-%s, %s %d\n", i+1, P1->Titulo[i], P1->Director[i], P1->Anno[i]);
            }
            break;
        default:
            break;
        }
    }
    
    free(P1);
    return 0;
}


