#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[40], autor[30];
    int anio;
    struct Node *next, *prev;
} Nodo;

typedef struct Lista_simple {
    Nodo *head;
} Lista;

Lista *Inicializar_lista(Lista *P) {
    P = (Lista *)malloc(sizeof(Lista));
    P->head = NULL;
    return P;
}

void Mostrar(Lista *P) {
    if (P->head == NULL) {
        printf("Lista vacia\n");
    } else {
        printf("%s - %s [%d]\n", P->head->name, P->head->autor, P->head->anio);
    }
}

int Insertar(Lista *L, char *n, char *au, int a) {
    Nodo *N = (Nodo *)malloc(sizeof(Nodo));

    if (N != NULL) {
        if (L->head == NULL)
        {
            N->next = L->head;
            N->prev = NULL;
            L->head = N;

            strcpy(N->name, n);
            strcpy(N->autor, au);
            N->anio = a;

        return 1;
        } else if (L->head->prev == NULL)
        {
            N->next = L->head;
            N->prev = NULL;
            L->head->prev = N;
            L->head = N;

            strcpy(N->name, n);
            strcpy(N->autor, au);
            N->anio = a;

        return 1;
        }
         else
        
        N->next = L->head;
        N->prev = L->head->prev;
        L->head->prev->next = N;
        L->head->prev = N;
        L->head = N;
        

        strcpy(N->name, n);
        strcpy(N->autor, au);
        N->anio = a;

        return 1;
    }
    return 0;
}

char* Buscar(Lista *L, char *C) {

    while (L->head->prev != NULL) {
        L->head = L->head->prev;
    }
    while (L->head != NULL) {
        if (strcmp(C, L->head->name) == 0) {
            return L->head->name;
        }
        L->head = L->head->next;
    }
    return NULL; 
}

int Eliminar(Lista *L, char *C) {

    int *temp;
    while (L->head->prev != NULL) {
        L->head = L->head->prev;
    }

    while (L->head != NULL) {
        if (strcmp(L->head->name, C) == 0) {
            if (L->head->prev == NULL) {
                L->head = L->head->next;
            } else {
                L->head->prev->next = L->head->next;
                temp = L->head->prev;
            }
            free(L->head);
            L->head = temp;
            return 1;
        }
        L->head = L->head->next;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    Lista *Mi_lista;
    int opcion = 1, anio;
    char buffer1[50], buffer2[50];

    Mi_lista = Inicializar_lista(NULL);

    printf("--Playlist manager 3000--\n");

    while (opcion != 0) {
        printf("\n1-Agregar cancion\n2-Eliminar cancion\n3-Mostrar playlist\n4-Buscar cancion\n0-Salir\n");
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch (opcion) {
        case 1:
            printf("Nombre: ");
            fgets(buffer1, 50, stdin);
            buffer1[strcspn(buffer1, "\n")] = 0;

            printf("Autor: ");
            fgets(buffer2, 50, stdin);
            buffer2[strcspn(buffer2, "\n")] = 0;

            printf("Anio: ");
            scanf("%d", &anio);
            while (getchar() != '\n'); 

            Insertar(Mi_lista, buffer1, buffer2, anio);
            break;

        case 2:
            printf("Nombre a eliminar: ");
            fgets(buffer1, 50, stdin);
            buffer1[strcspn(buffer1, "\n")] = 0;

            if (Eliminar(Mi_lista, buffer1))
                printf("Eliminado\n");
            else
                printf("No encontrado\n");
            break;

        case 3:
            Mostrar(Mi_lista);
            break;

        case 4:
            printf("Nombre a buscar: ");
            fgets(buffer1, 50, stdin);
            buffer1[strcspn(buffer1, "\n")] = 0;

            char *res = Buscar(Mi_lista, buffer1);
            if (res)
                printf("Encontrado: %s\n", res);
            else
                printf("No encontrado\n");
            break;

        default:
            if (opcion != 0) {
                printf("Opcion invalida\n");
            }
            break;
        }
    }

    return 0;
}