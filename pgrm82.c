# include <stdio.h>
# include <stdlib.h>
# include <stdio_ext.h>
int main(){
    int hombres = 0,mujeres = 0, edadM = 0;
    int *edad = (int*)malloc(5*sizeof(int));
    char *sexo = (char*)malloc(5*sizeof(char));
    char **nombre = (char**)malloc(5*sizeof(char*));
    for(int i = 0; i < 5; i++)
    {
        *(nombre + i) = (char*) malloc (20*sizeof(char));
        printf("Persona [%d]\n", i+1);
        printf("\tNombre: ");
        scanf("%[^\n]", (*(nombre + i) + 0));
        __fpurge(stdin);
        printf("\tSexo: ");
        scanf(" %c", (sexo + i));
        __fpurge(stdin);
        printf("\tEdad: ");
        scanf("%d", (edad + i));
        __fpurge(stdin);
    }

    // CONTEO DE MUJERES
    for(int i = 0; i < 5; i++)
    {
        if(*(sexo+i) == 'f' || *(sexo+i) == 'F') mujeres++;
        else hombres++;
    }

    // OBTENER LA EDAD MÁS GRANDE
    for(int i = 0; i < 5; i++)
    {
        if(*(edad + i) > edadM) edadM = *(edad + i);
    }

    printf("\n El numero de mujeres es de: %d ", mujeres);
    printf("\n EL numero de hombres es de: %d ", hombres);
    printf("\n El estudiante con mayor edad tiene: %d años", edadM);
    printf("\n Su informacion es: ");

    // OBTENER LOS DATOS DEL USUARIO CON LA MAYOR EDAD
    for(int i = 0; i < 5; i++)
    {
        if(*(edad + i) == edadM)
        {
            printf("\n\tNombre: %s", *(nombre + i));
            printf("\n\tSexo: %c", *(sexo + i));
            printf("\n\tEdad: %d años\n",*(edad + i));
        }
    }

    // Liberar Memoria
    for (int k = 0; k < 5; k++)
    {
        free(*(nombre+k));
    }
    free(edad);
    free(sexo);
    return 0;
}