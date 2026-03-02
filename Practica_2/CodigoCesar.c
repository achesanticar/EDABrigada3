#include <stdio.h>

int main(int argc, char const *argv[])
{
    int dez, arr, Size=0, r, option;
    char txt[100], abc[26], ABC[26], ABC2[26], abc2[26];

    for (int j = 0; j < 26; j++)
        {
            abc[j]='a'+j;
            ABC[j]='A'+j;
        }

    printf("Elige una accion:\n1-Codificar un mensaje\n2-Decodificar un mensaje\n");
    scanf("%d", &option);

    printf("Introduce el desfaze: ");
    scanf("%d", &dez);
    getchar();

    printf("Introduce el texto:");
    fgets(txt, sizeof(txt), stdin);

    while (txt[Size] != '\n' && txt[Size] != '\0')
    {
        Size++;
    }
    
    switch (option)
    {
    case 1:
        for (int j = 0; j < 26; j++)
        {
            abc2[j]='a'+j+dez;
            ABC2[j]='A'+j+dez;
            if (j + dez >= 26)
            {
                arr= j + dez - 26;
                abc2[j]='a'+arr;
                ABC2[j]='A'+arr;
            } 
        }

        for (int i = 0; i < Size; i++)
        {
            r=0;
            while (r < 26 &&txt[i] != abc[r] && txt[i] != ABC[r])
            {
                r++;
            }
            if (r < 26)
            {
                txt[i]=(txt[i] == abc[r]) ? abc2[r] : ABC2[r];
            }
        }
        
    break;
    case 2:
        for (int j = 0; j < 26; j++)
        {
            abc2[j]='a'+j-dez;
            ABC2[j]='A'+j-dez;
            if (j - dez < 0)
            {
                arr= j - dez + 26;
                abc2[j]='a'+arr;
                ABC2[j]='A'+arr;
            } 
        }
        
        for (int i = 0; i < Size; i++)
        {
            r=0;
            while (r<26 && txt[i] != abc[r] && txt[i] != ABC[r])
            {
                r++;
            }
            if (r < 26)
            {
                txt[i]=(txt[i] == abc[r]) ? abc2[r] : ABC2[r];
            }
        }

    break;
    default:
        printf("opcion invalida");
        break;
    }

    for (int i = 0; i < Size; i++)
        {
            printf("%c",  txt[i]);
        }
        printf("\n");
    
    return 0;
}
