/****************************************************************************
Pontificia Universidad Javeriana
Autor: Francisco Javier Guzman Villegas
Fecha: 24/09/2024
Materia: Sistemas Operativos
Tema: Pipe Named o FIFO o Tuberia
Topico: Comunicacion uni-Direccional
            SERVIDOR
****************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"
  int main() {
    // Creación de variables
     int ArchivoDesc;
     char BusMensaje[80];
     char final[10];
     int fin;
     int cantidadBytes;
     printf("\n \t\t >>>>>> INICIO SERVIDOR <<<<<<  \n");
     // Crear el FIFO si no existe, con permisos de lectura/escritura para el propietario
     mknod(FIFO_FILE, S_IFIFO|0640, 0);
     strcpy(final, "end");// Copia "end" en la variable final para la comparación
     while(1) {
       ArchivoDesc = open(FIFO_FILE, O_RDONLY);
       cantidadBytes = read(ArchivoDesc, BusMensaje, sizeof(BusMensaje));
       BusMensaje[cantidadBytes] = '\0';

       // Muestra el mensaje recibido y la cantidad de bytes
       printf("Cadena recibida: \"%s\" y cantidad de bytes %d\n", BusMensaje, (int)strlen(BusMensaje));
        fin = strcmp(BusMensaje, final); // Compara el mensaje recibido con "fin"
        if (fin == 0) {
           close(ArchivoDesc);
           break;
        }
     }
    return 0;
  }
