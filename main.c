#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SI_NO 3//Cantidad de caracteres que tendra la variable
#define MAX_CHAR 50

int eleccionA = 0, eleccionB = 0, eleccionC = 0, eleccionD = 0,
        eleccionE = 0, eleccionF = 0, siVa = 0;           //Variables que nos diran que eleccion ha tomado el usuario

void recibo(double total){
    FILE *archivo;
    archivo = fopen("Datos.txt","a");
    printf("Usted eligio:\n");
    if (eleccionA==1) {
        printf("Reparacion de motor\n");
        fprintf(archivo,"Reparacion-de-motor ");
        siVa = 1;
    }
    if (eleccionB==1) {
        printf("Cambio de llantas\n");
        fprintf(archivo,"Cambio-de-llantas ");
        siVa = 1;
    }
    if (eleccionC==1) {
        printf("Lavado de auto\n");
        fprintf(archivo,"Lavado-de-auto ");
        siVa = 1;
    }
    if (eleccionD==1) {
        printf("Reparacion de carroceria\n");
        fprintf(archivo,"Reparacion-de-carroceria ");
        siVa = 1;
    }
    if (eleccionE==1) {
        printf("Reparacion de luces\n");
        fprintf(archivo,"Reparacion-de-luces ");
        siVa = 1;
    }
    if (eleccionF==1) {
        printf("Reparacion de auto\n");
        fprintf(archivo,"Mantenimeinto-de-auto ");
        siVa = 1;
    }
    if (siVa==0) {
        printf("No eligio ninguna opcion!, cree una nueva cuenta\n");
        fclose(archivo);
    }
    if (siVa==1) {
        printf("Total a pagar: %f",total);
        fprintf(archivo,"$%f\n",total);
        fclose(archivo);
    }
}

void mostrarMenu(){
    printf("a)Reparacion de motor $1520\n");
    printf("b)Cambio de llantas $1500\n");
    printf("c)Lavado de auto $500\n");
    printf("d)Reparacion de carroceria $2000\n");
    printf("e)Reparacion de luces $1250\n");
    printf("f)Mantenimeinto de auto $2299\n");
    printf("g)Continuar\n");
    printf("Eleccion -> ");
}

void datosUsuarioYAuto(){
    char nombre[MAX_CHAR], direccion[MAX_CHAR], marca[MAX_CHAR], modelo[MAX_CHAR], pass[MAX_CHAR];
    printf("Por favor no usar espacios, y en caso de ser necesario usar '_'/guion bajo\n");
    printf("Nombre: ");
    gets(nombre);
    printf("Direccion: ");
    gets(direccion);
    printf("-Auto-\n");
    printf("Marca: ");
    gets(marca);
    printf("Modelo/Version: ");
    gets(modelo);
    printf("Es de Pasajeros o Carga?: ");
    gets(pass);
    FILE *archivo;
    archivo = fopen("Datos.txt","a");
    fprintf(archivo,"%s %s %s %s %s ",nombre,direccion,marca,modelo,pass);
    //Falta agregarle lo que tendra dentro el archivo, datos de user etc.
    fclose(archivo);
}

void crearCuenta(){
    char x[50], y[50];
    printf("Inserte su nombre de usuario sin espacios: ");
    gets(x);
    printf("Inserte su contraseña sin espacios: ");
    gets(y);
    FILE *archivo;
    archivo = fopen("Datos.txt","w");
    fprintf(archivo,"%s %s ",x,y);//Falta agregarle lo que tendra dentro el archivo, datos de user etc.
    fclose(archivo);
}

void buscarCuenta(){
    char x[50], y[50], compareX[50], compareY[50];
    printf("Inserte su nombre de usuario sin espacios: ");
    gets(x);
    printf("Inserte su contraseña sin espacios: ");
    gets(y);
    FILE *archivo;
    archivo = fopen("Datos.txt","r");
    if (archivo!=NULL) {
        fscanf(archivo, "%s %s", compareX, compareY);
        if (strcmp(compareX, x) == 0) {
            if (strcmp(compareY, y) == 0) {
                char nombre[MAX_CHAR], direccion[MAX_CHAR], marca[MAX_CHAR], modelo[MAX_CHAR], passajero[MAX_CHAR];
                char multiVar[MAX_CHAR];
                printf("Cargando datos...\n");
                fscanf(archivo,"%s",nombre);
                fscanf(archivo,"%s",direccion);
                fscanf(archivo,"%s",marca);
                fscanf(archivo,"%s",modelo);
                fscanf(archivo,"%s",passajero);
                printf("Bienvenido %s\n",nombre);
                printf("Marca de su auto: %s\n",marca);
                printf("Modelo de su auto: %s\n",modelo);
                printf("Tipo: %s\n",passajero);
                printf("Usted ha elegido las siguientes reparaciones, el costo total va al ultimo:\n");
                do{
                    fscanf(archivo,"%s",multiVar);
                    if (!feof(archivo)) {
                        printf("%s\n",multiVar);
                    }
                }while (!feof(archivo));
            } else {
                printf("Acceso Denegado!\n");
                fclose(archivo);
            }
        } else {
            printf("Acceso Denegado!\n");
            fclose(archivo);
        }
    } else if (archivo==NULL){
        printf("Usted no ha creado ninguna cuenta!\n");
    }
}

int main() {
    char acc[SI_NO], eleccion;                                  //Se declaran dos variables de tipo char
    double dinero = 0.00;                                       //para acceder a las distintas opciones que tiene el programa
    printf("Bienvenido al taller mecanico!\n");          //Se creara una variable dinero para ir guardando el monto
    printf("Ya ha accedido antes?: (si/no) ");
    gets(acc);
    if (strcmp(acc,"si")==0) {
        buscarCuenta();                                         //Se buscara la cuenta
    } else {
        crearCuenta();                                      //Se creara una cuenta
        printf("Bienvenido, por favor inserte sus datos...\n");
        datosUsuarioYAuto();                                //Se le pedira al usuario sus datos
        while (eleccion!='x') {
            printf("Total a pagar reunido: %f\n",dinero);
            printf("Que opcion desea elegir?\n");
            mostrarMenu();                                      //Se mostrara el menu al usuario
            scanf("%c", &eleccion);
            getchar();                                          //Evitara problemas del scanf
            if (eleccion == 'a') {
                printf("Opcion A elegida! Gracias por su compra!\n");
                dinero = dinero + 1520.00;
                eleccionA = 1;
            } else if (eleccion == 'b') {
                printf("Opcion B elegida! Gracias por su compra!\n");
                dinero = dinero + 1500.00;
                eleccionB = 1;
            } else if (eleccion == 'c') {
                printf("Opcion C elegida! Gracias por su compra!\n");
                dinero = dinero + 2000.00;
                eleccionC = 1;
            } else if (eleccion == 'd') {
                printf("Opcion D elegida! Gracias por su compra!\n");
                dinero = dinero + 2000.00;
                eleccionD = 1;
            } else if (eleccion == 'e') {
                printf("Opcion E elegida! Gracias por su compra!\n");
                dinero = dinero + 1250.00;
                eleccionE = 1;
            } else if (eleccion == 'f') {
                printf("Opcion F elegida! Gracias por su compra!\n");
                dinero = dinero + 2299.00;
                eleccionF = 1;
            } else if (eleccion == 'g') {
                printf("Desea realizar su compra/proceder con el trabajo?: (si/no) ");
                gets(acc);
                if (strcmp(acc,"si")==0) {
                    recibo(dinero);
                    eleccion = 'x';
                }else {
                    eleccion = 'x';
                    printf("Espero a futuro le interese algun mantenimiento!\n");
                }
            } else {
                printf("Elija una opcion correcta!\n");
            }
        }
    }
    return 0;
}
