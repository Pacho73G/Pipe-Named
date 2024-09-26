/****************************************************************************
Pontificia Universidad Javeriana
Autor: Francisco Javier Guzman Villegas
Fecha: 24/09/2024
Materia: Sistemas Operativos
Tema: Pipe Named o FIFO o Tuberia
Topico: Comunicacion uni-Direccional
      CLIENTE
****************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"
 int main() {
     int ArchivoDesc;
     int fin_proceso;
     int cadena;
     char BusMensaje[80];
     char senalFin[5];
   
     printf("\n \t\t >>>>>> INICIO Cliente <<<<<<  \n");
     printf("FIFO_CLIENT: Enviando Mensajes, infinitamente, para finalizar \"end\"\n");
     ArchivoDesc = open(FIFO_FILE, O_CREAT|O_WRONLY);
     strcpy(senalFin, "fin"); 
     while (1) {
        printf("Ingrese mensaje: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);
        cadena = strlen(BusMensaje);
        BusMensaje [cadena - 1] = '\0';
        fin_proceso = strcmp(BusMensaje, senalFin);
  
        printf("Final del proceso %d\n", fin_proceso);
        if (fin_proceso != 0) {
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Mensaje enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
        } else {
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Mensaje enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
           close(ArchivoDesc);
           break;
        }
    }
  return 0;
}