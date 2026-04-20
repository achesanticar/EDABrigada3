#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[40], autor[30];
    int anio;
    struct Node *next;
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
        Nodo *Leyendo = P->head;
        printf("Playlist:\n");
        while (Leyendo != NULL) {
            printf("%s - %s [%d]\n", Leyendo->name, Leyendo->autor, Leyendo->anio);
            Leyendo = Leyendo->next;
        }
    }
}

int Insertar(Lista *L, char *n, char *au, int a) {
    Nodo *N = (Nodo *)malloc(sizeof(Nodo));

    if (N != NULL) {
        N->next = L->head;
        L->head = N;

        strcpy(N->name, n);
        strcpy(N->autor, au);
        N->anio = a;

        return 1;
    }
    return 0;
}

char* Buscar(Lista *L, char *C) {
    Nodo *Leyendo = L->head;

    while (Leyendo != NULL) {
        if (strcmp(C, Leyendo->name) == 0) {
            return Leyendo->name;
        }
        Leyendo = Leyendo->next;
    }
    return NULL; 
}

int Eliminar(Lista *L, char *C) {
    Nodo *actual = L->head;
    Nodo *anterior = NULL;

    while (actual != NULL) {
        if (strcmp(actual->name, C) == 0) {
            if (anterior == NULL) {
                L->head = actual->next;
            } else {
                anterior->next = actual->next;
            }
            free(actual);
            return 1;
        }
        anterior = actual;
        actual = actual->next;
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