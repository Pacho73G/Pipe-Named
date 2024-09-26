tuberia con nombre o FIFO.

Una tubería con nombre es una versión extendida de la tubería tradicional en Unix. Mientras que una tubería tradicional es temporal y no tiene nombre, una tubería con nombre persiste mientras el sistema esté en funcionamiento o hasta que se elimine. Estas tuberías aparecen como archivos especiales en el sistema de archivos y permiten que múltiples procesos se conecten para leer y escribir, facilitando la comunicación entre ellos.

Un archivo FIFO permite que varios procesos se comuniquen a través de lecturas y escrituras en el mismo archivo. Se crea con la llamada al sistema mkfifo() en C, y una vez creado, cualquier proceso puede abrir la tubería para realizar operaciones de lectura o escritura, similar a un archivo normal. No obstante, es esencial que la tubería con nombre esté abierta simultáneamente en ambos extremos (lectura y escritura) para que las operaciones de entrada o salida puedan llevarse a cabo.
