#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Constante que contiene los nombres de las 7 materias
const char *nombresMaterias[7] = {
    "Ingenieria de Software",
    "Administracion",
    "Economia",
    "Relaciones Internacionales",
    "Matematicas",
    "Contabilidad",
    "Ingenieria Industrial"
};

// Declaración de funciones
int Menu(int flag, int AlumnosMatriculados[5][7][2]);
void Opcion1(int AlumnosMatriculados[5][7][2]);
void Opcion2(int AlumnosMatriculados[5][7][2]);
void Opcion3(int AlumnosMatriculados[5][7][2]);

int main(){

    // Configuración de la localidad del programa
    setlocale(LC_ALL, "");
    int flag = 1;
    int AlumnosMatriculados[5][7][2];

    // Inicialización del generador de números aleatorios
    srand(time(NULL));

    // Rellena la matriz de alumnos matriculados con números aleatorios
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                AlumnosMatriculados[i][j][k] = rand()%101;
            }
        }
    }
    
    // Muestra el menú hasta que el usuario decida salir
    while (flag) {
        flag = Menu(flag, AlumnosMatriculados);
    }
   
    return 0;
}

// Función que muestra el menú al usuario
int Menu(int flag, int AlumnosMatriculados[5][7][2]){

    int menu, resultado;

    printf("Programa:\n");
    printf("Seleccione una opcion\n 1. A\361o en el que se recibio la mayor cantidad de alumnosA\n 2. Carrera que recibio la mayor cantidad de alumnos el ultimo a\361o\n 3. A\361o que recibio la mayor cantidad de alumnos Ingenieria de Software\n 4. Salir\n");
    resultado = scanf("%d", &menu);
   
    // Si la entrada no es válida, limpia el buffer de entrada y solicita una nueva entrada
    while(resultado != 1) {
        while(getchar() != '\n'); // limpiar el buffer de entrada

        printf("\nNo ingresaste una opcion valida. Intenta de nuevo: ");
        resultado = scanf("%d", &menu);
    }
    
    // Dependiendo de la opción elegida, llama a una de las funciones o sale del programa
    switch (menu)
    {
    case 1:
        system("cls");
        Opcion1(AlumnosMatriculados);
        break;
    case 2:
        system("cls");
        Opcion2(AlumnosMatriculados);
        break;
    case 3:
        system("cls");
        Opcion3(AlumnosMatriculados);
        break;
    case 4:
        system("cls");
        flag = 0;
        break;
    default:
        printf("\nNo ingresaste una opcion valida. Intenta de nuevo\n");
        break;
    }
    return flag;
}

// Función que encuentra y muestra el año en el quese matricularon más alumnos
void Opcion1(int AlumnosMatriculados[5][7][2]){

    int max;
    int cantidadMax[5] = {0};

    // Suma todos los alumnos matriculados en cada año
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                cantidadMax[i] += AlumnosMatriculados[i][j][k];
            }
        }
    }

    // Encuentra el año con la mayor cantidad de alumnos
    max = 0;
    for(int i = 1; i < 5; i++) {
        if(cantidadMax[i] > cantidadMax[max]) {
            max = i;
        }
    }

    // Muestra el resultado
    printf("El a\361o que mas alumnos ingresaron fue el %d con %d alumnos\n\n", max+1, cantidadMax[max]);

}
    //Función que encuentra y muestra la carrera que tuvo la mayor cantidad de alumnos en el último año
    void Opcion2(int AlumnosMatriculados[5][7][2]){

    int max;
    int cantidadMax[7];

    // Suma todos los alumnos matriculados en cada materia en el último año
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           cantidadMax[i] = AlumnosMatriculados[4][i][j];
        } 
    }
    
    // Encuentra la carrera con la mayor cantidad de alumnos
    max = 0;
    for(int i = 1; i < 7; i++) {
        if(cantidadMax[i] > cantidadMax[max]) {
            max = i;
        }
    }

    // Muestra el resultado
    printf("La materia que tuvo mas alumnos es %s con %d alumnos inscritos\n\n", nombresMaterias[max], cantidadMax[max]);

}
    //Función que encuentra y muestra el año en el que se matricularon más alumnos en Ingeniería de Software
    void Opcion3(int AlumnosMatriculados[5][7][2]){

    int max;
    int cantidadMax[5];

    // Suma todos los alumnos matriculados en Ingeniería de Software en cada año
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           cantidadMax[i] = AlumnosMatriculados[i][0][j];
        } 
    }
    
    // Encuentra el año con la mayor cantidad de alumnos en Ingeniería de Software
    max = 0;
    for(int i = 1; i < 5; i++) {
        if(cantidadMax[i] > cantidadMax[max]) {
            max = i;
        }
    }

    // Muestra el resultado
    printf("El a\361o que tuvo mas estudiantes de software fue el %d con %d alumnos inscritos\n\n", max+1, cantidadMax[max]);

}
