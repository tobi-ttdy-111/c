# include <stdio.h>
# include <stdlib.h>
int main(){
    int fil = 0, col = 0;
    char **p, car = '*';
    char chfil;
    printf("Ingresa el numero de colmunas y filas: ");
    scanf("%d", &fil);
    col = fil;
    printf("Caracter de relleno: ");
    scanf("%s", &car);

    //Llenado
    p = (char **)malloc(fil*(sizeof(char*)));

    for (int i = 0; i < fil; i++)
    {
        chfil = i+'0';
        *(p+i) = (char *)malloc(col*(sizeof(char)));

        for (int j = 0; j < col; j++)
        {

            if (i == j) *(*(p+i)+j) = chfil;
            else *(*(p+i)+j) = car;
        }
    }

    //Mostrado
    for (int i = 0; i < fil; i++)
    {
        printf("[");
        for (int j = 0; j < col; j++)
        {
            printf(" %c ", *(*(p+i)+j));
        }
        printf("]\n");
    }

    for (int i = 0; i < fil; i++) //Liberar Memoria
    { 
        free(*(p+i));
    }
    return 0;
}
