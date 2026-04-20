#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[40], autor[30];
    int anio;
    struct Node *next;
}Nodo;

typedef struct Lista_simple
{
    Nodo *head;
}Lista;

Lista *Inicializar_lista(Lista *P) {
    P = (Lista *)malloc(sizeof(Lista));
    P->head = NULL;
    return P;
}

void Mostrar(Lista *P) {
    if (P->head == NULL)
    {
        printf("Lista vacia\n");
    } else {
        Nodo *Leyendo;
        Leyendo = P->head;
        printf("Playlist:\n");
        while (Leyendo != NULL)
        {
            printf("%s - %s [%d]\n", Leyendo->name, Leyendo->autor, Leyendo->anio);
            Leyendo = Leyendo->next;
        }
    }
}

int Insertar(Lista *L, char *n, char *au, int a) {
    Nodo *N;
    N = (Nodo *)malloc(sizeof(Nodo));

    if (N != NULL)
    {
        if (L->head == NULL)
        {
            N->next = NULL;
            L->head = N;
            strcpy(N->name, n);
            strcpy(N->autor, au);
            N->anio = a;
        } else {
            N->next = L->head;
            L->head = N;
            strcpy(N->name, n);
            strcpy(N->autor, au);
            N->anio = a;
        }
        return 1;
    }
    return 0;
}

char* Buscar(Lista *L, char *C) {
    Nodo *Leyendo;
    Leyendo = L->head;
    while (Leyendo != NULL)
    {
        if (strcmp(C, Leyendo->name) == 0)
        {
            return Leyendo->name;
        }
        Leyendo = Leyendo->next;
    }
}

char Eliminar(Lista *L, char *C) {
    Nodo *Leyendo;
    char *ctemp;
    Leyendo = L->head;

    if (strcmp(Leyendo->name, C) == 0)
    {
        strcpy(ctemp, Leyendo->name);
        L->head = Leyendo->next;
        free(Leyendo);
        return ctemp;
    } else {

    }
    
}

int main(int argc, char const *argv[])
{
    Lista *Mi_lista;
    int opcion = 1, anio;
    char buffer1[50], buffer2[50];
    Mi_lista = Inicializar_lista(NULL);
    printf("--Playlist manager 3000--\n");
    while (opcion != 0)
    {
        printf("1-Agregar cancion\n2-Eliminar cancion\n3-Mostrar playlist\n4-Buscar cancion\n0-Salir");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\nNombre: ");
            fgets(buffer1, 50, stdin);
            getchar();
            printf("Autor: ");
            fgets(buffer2, 50, stdin);
            getchar();
            printf("Año: ");
            scanf("%d", &anio);
            Insertar(Mi_lista, buffer1, buffer2, anio);
            break;
        
        case 2:
            fgets(buffer1, 50, stdin);
            Eliminar(Mi_lista, buffer1);
            break;

        case 3:
            Mostrar(Mi_lista);
            break;

        case 4:
        fgets(buffer1, 50, stdin);
            Buscar(Mi_lista, buffer1);
            break;

        default:
            if (opcion != 0)
            {
                printf("Opcion invalida");
            }
            
            break;
        }
    }
    
    return 0;
}

