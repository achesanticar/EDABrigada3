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
    if (P->Cima == 9){printf("La pila esta llena");} 
    else {
        P->Cima++;
        printf("Introduce el nombre de la pelicula: ");
        getchar();
        fgets(P->Titulo[P->Cima], 100, stdin);
    } 
}

void pop(pelicula *P) {
    if (P->Cima == -1) {printf("La pila esta vacia\n");} 
    else {      
        printf("%s", P->Titulo[P->Cima]);
        P->Cima--;
    }
}

int main(int argc, char const *argv[])
{
    int c=1;
    pelicula *P1;
    P1 = crear_pila(P1);

    while (c != 2)
    {
        printf("Elige una accion:\nPush-0\nPop-1\nSalir-2\n");
        scanf("%d", &c);
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


