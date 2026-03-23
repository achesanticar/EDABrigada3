#include <stdio.h>
#include <stdlib.h>

#define Q_MAX 10

typedef struct Estructura_cola
{
    int head, tail, max, *Dato; 
} Cola ;

Cola *Crea_cola(Cola *P) {
    P = (Cola *)malloc(sizeof(Cola));
    P->head = -1;
    P->tail = -1;
    P->max = Q_MAX;
    return P;
}

void Enqueue(Cola *P, int a) {
    if (P->head == -1)
    {
        P->head = 0;
    }
    
    if (P->tail < P->max)
    {
        P->tail++;
        P->Dato[P->tail] = a;
    } else
    printf("Cola llena, operacion no disponible\n");    
}

void Dequeue(Cola *P) {
    if (P->head > (-11 + P->max))
    {
        printf("%d \n", P->Dato[P->head]);
        P->head++;
        P->max++;
    } else
    printf("Cola vacia, operacion no disponible\n");
}

int main(int argc, char const *argv[])
{
    int op = 1, dato;
    Cola *P;
    P = Crea_cola(P);
    P->Dato = malloc(Q_MAX);

    while (op != 3)
    {
        printf("--Cola--\n1-Encolar\n2-Desencolar\n3Salir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n->");
            scanf("%d", &dato);
            Enqueue(P, dato);
            break;
        
        case 2:
            Dequeue(P);
            break;

        default:
            if (op != 3)
            {             
                printf("Opcion invalida");
            }
            break;
        }
    }
    
    return 0;
}
