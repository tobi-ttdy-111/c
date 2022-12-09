
# include <stdio.h>
# include <stdlib.h>
# include <stdio_ext.h>

int main(){

    // informacion general
    int cantidadHombres = 0,cantidadMujeres = 0, edadM = 0;
    int *edad = (int* )malloc(5* sizeof(int));
    char * sexo = (char* )malloc(5* sizeof(char));
    char * * nombre = (char* * )malloc(5* sizeof(char* ));

    for(int i = 0; i < 5; i++) {
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
    };

    // contador de sexo femenino / masculino
    for(int i = 0; i < 5; i++)
    {
        if(*(sexo+i) == 'f' || *(sexo+i) == 'F') cantidadMujeres++;
        else cantidadHombres++;
    }

    // contador edad mas grande
    for(int i = 0; i < 5; i++) { if(*(edad + i) > edadM) edadM = *(edad + i); }

    // inpresion de la informaccion
    printf("\n El numero de cantidadMujeres es de: %d ", cantidadMujeres);
    printf("\n EL numero de cantidadHombres es de: %d ", cantidadHombres);
    printf("\n El estudiante con mayor edad tiene: %d años", edadM);
    printf("\n Su informacion es: ");


    for(int i = 0; i < 5; i++) {
        if(*(edad + i) == edadM ) {
            printf("\n\tNombre: %s", *(nombre + i));
            printf("\n\tSexo: %c", *(sexo + i));
            printf("\n\tEdad: %d años\n",*(edad + i));
        }
    }

    // liberaciond e memoria
    for (int k = 0; k < 5; k++) { free(*(nombre+k))};
    free(edad);
    free(sexo);
    return 0;
}
