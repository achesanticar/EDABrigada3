#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Peliculas
{
    int Cima;
    char Titulo[10][100];
}pelicula;

pelicula *crear_pila(pelicula *P) {
    P = (pelicula *)malloc(sizeof(pelicula));
    P->Cima = -1;
    return P;
}

void push(pelicula *P) {
    P->Cima++;
    printf("Introduce el nombre de la pelicula: ");
    fgets(P->Titulo[P->Cima], 100, stdin);
}

void pop(pelicula *P) {
    printf("%s", P->Titulo[P->Cima]);
    P->Cima--;
}

int main(int argc, char const *argv[])
{
    int c;
    pelicula *P1;
    P1 = crear_pila(P1);

    printf("Elige una acción:\nPush-0\nPop-1\nSalir-2");
    scanf("%d", &c);
    while (c != 2)
    {
        switch (c)
        {
        case 0:
            push(P1);
            break;
        
        case 1:
            pop(P1);
            break;

        default:
            break;
        }
    }
    
    return 0;
}


