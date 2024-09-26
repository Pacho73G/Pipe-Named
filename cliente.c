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
     // Creación de variables  
     int ArchivoDesc;
     int fin_proceso;
     int cadena;
     char BusMensaje[80];
     char senalFin[5];
   
     printf("\n \t\t >>>>>> INICIO Cliente <<<<<<  \n");
     printf("FIFO_CLIENT: Enviando Mensajes, infinitamente, para finalizar \"end\"\n");

      // Abre el archivo FIFO en modo de escritura. Si no existe, lo crea.
     ArchivoDesc = open(FIFO_FILE, O_CREAT|O_WRONLY);
     strcpy(senalFin, "fin"); // Copia la palabra "fin" en la variable senalFin
     while (1) {
        printf("Ingrese mensaje: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);
        cadena = strlen(BusMensaje);
        BusMensaje [cadena - 1] = '\0';
         // Compara el mensaje con la señal de fin para ver si debe terminar
        fin_proceso = strcmp(BusMensaje, senalFin);
  
        printf("Final del proceso %d\n", fin_proceso);
        if (fin_proceso != 0) {
           // Si no es el mensaje de fin, lo escribe en la tubería FIFO   
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Mensaje enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
        } else {
            // Si es el mensaje de fin, lo escribe, cierra la tubería y termina el ciclo   
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Mensaje enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
           close(ArchivoDesc);
           break;
        }
    }
  return 0;
}
