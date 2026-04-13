#include <stdio.h>
#include <stdlib.h>

typedef struct Pila_Bidimensional
{
    int s_top, top[10];
    float data[10][10];
}Pila;

Pila *Inicializar_Pila (Pila *P) {
    P->s_top = -1;
    for (int i = 0; i < 10; i++)
    {
        P->top[i] = -1;
    }
    return P;
}

void Push_Pila (Pila *P) {
    if (P->s_top == 9)
    {
        printf("Pila de pilas llena; Operacion no disponible\n");
    } else {
        P->s_top++;
        P->top[P->s_top] = -1;
    }
}

void Push (Pila *P) {
    if (P->top[P->s_top] == 9)
    {
        printf("Pila llena; Operacion no disponible\n");
    } else {
        P->top[P->s_top]++;
        printf("->");
        scanf("%f", P->data[P->s_top][P->top[P->s_top]]);
    } 
}

void Pop_Pila (Pila *P) {
    if (P->s_top == -1)
    {
        printf("Pila de pilas vacia; Operacion no disponible");
    } else if (P->top[P->s_top] == -1)
    {
        printf("Pila vacia; Operacion no disponible");
    } else {
        for (int i = 0; i <= P->top[P->s_top]; i++)
        {
            printf("%d-> %.2f", i+1, P->data[P->s_top][P->top[P->s_top]]);
        }
        P->s_top--;
    }
}

void Pop (Pila *P) {
    if (P->top[P->s_top] == -1)
    {
        printf("Pila vacia; Operacion no disponible");
    } else {
        printf("%.2f", P->data[P->s_top][P->top[P->s_top]]);
        P->top[P->s_top]--;
    }
}

int main(int argc, char const *argv[])
{
    Pila *P;
    int opcion = 1;

    printf("--Pila bidimensional--\n");
    while (opcion != 0)
    {
        printf("1-Push pila\n2-Push\n3-Pop pila\n4-Pop\n0-Salir");
        switch (opcion)
        {
        case 1:
            Push_Pila(P);
            break;

        case 2:
            Push(P);
            break;

        case 3:
            Pop_Pila(P);
            break;
        
        case 4:
            Pop(P);
            break;
        
        default:
            if (opcion != 0)
            {
                printf("Eleccion invalida");
            }
            break;
        }
    }
    
    return 0;
}
