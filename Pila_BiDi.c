#include <stdio.h>
#include <stdlib.h>

typedef struct Pila_Bidimensional
{
    int s_top, top[10];
    float data[10][10];
}Pila;

Pila *Inicializar_Pila (Pila *P) {
    P = (Pila *)malloc(sizeof(Pila));
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

void Push (Pila *P, float info) {
    if (P->s_top == -1)
    {
        printf("No hay pilas creadas\n");
    } else if (P->top[P->s_top] == 9)
    {printf("Pila llena; Operacion no disponible\n");}
     else {
        P->top[P->s_top]++;
        P->data[P->s_top][P->top[P->s_top]] = info;
    } 
}

void Pop_Pila (Pila *P) {
    if (P->s_top == -1)
    {
        printf("Pila de pilas vacia; Operacion no disponible\n");
    } else {
        for (int i = 0; i <= P->top[P->s_top]; i++)
        {
            printf("%d-> %.2f\n", i+1, P->data[P->s_top][i]);
        }
        P->s_top--;
    }
}

void Pop (Pila *P) {
    if (P->s_top == -1)
    {
        printf("No hay pilas creadas\n");
    } else if (P->top[P->s_top] == -1)
    {printf("Pila vacia; Operacion no disponible\n");}
    else {
        printf("%.2f\n", P->data[P->s_top][P->top[P->s_top]]);
        P->top[P->s_top]--;
    }
}

int main(int argc, char const *argv[])
{
    Pila *P;
    P = Inicializar_Pila(P);
    int opcion = 1;
    float info;

    printf("--Pila bidimensional--\n");
    while (opcion != 0)
    {
        printf("\n1-Push pila\n2-Push\n3-Pop pila\n4-Pop\n0-Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            Push_Pila(P);
            break;

        case 2:
            printf("->");
            scanf("%f", &info);
            Push(P, info);
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
                printf("\nEleccion invalida");
            }
            break;
        }
    }
    
    free(P);

    return 0;
}
