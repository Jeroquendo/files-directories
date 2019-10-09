## Realizado por: Juan Esteban Rodas & Juan Camilo Rojas ## 

# Files and Directories #

En esta tarea, nos familiarizaremos con el API descrito en el capítulo del libro. Para hacer esto, usted solo debe escribir unos cuantos programas, la mayoría basados en varias utilidades UNIX.

## Questions ##

1. **Stat**: Escriba su propia versión del comando ```stat```, la cual simplemente invoca la llamada del sistema ```stat()``` en un archivo o directorio. Imprima el tamaño del archivo, el número de bloques asignado, contador de referencias (links), etc. ¿Qué significa el contador de referencias (link count) de un directorio?, ¿cómo cambia el número de entradas en el directorio? Interfaces útiles: ```stat()```, naturalmente.

- El codigo realizado para el comando ```Stat()``` es el siguiente: [fstat.c](https://github.com/Jeroquendo/files-directories/blob/master/fstat.c)
- Al ejecutar el codigo este muestra lo siguiente:

![alt tag](https://github.com/Jeroquendo/files-directories/blob/master/Imagenes/01%20Stat.png)

- Link Count:  El link count de un archivo indica el número total de enlaces que tiene un archivo, que no es más que el número de enlaces duros que tiene un archivo. Este recuento, sin embargo, no incluye el recuento de enlaces blandos.

- Nota: El enlace suave no forma parte del recuento de enlaces, ya que el número de inodo del enlace suave es diferente del archivo original.
```
 $ ln test.c test1.c     #hard link
 $ ln -s test.c test2.c  #soft link
 $ ls -l test*.c
 -rwxr-xr-x 2 guru users 267 Jul 18 16:59 test1.c*
  lrwxrwxrwx 1 guru users   6 Jul 31 16:13 test2.c -> test.c*
  -rwxr-xr-x 2 guru users 267 Jul 18 16:59 test.c*
```
- Por defecto, un archivo tendrá un hardlink de 1.

- El archivo, test.c, ahora tiene un hard link de 2 porque hay un enlace duro creado para el archivo. También tenga en cuenta que la creación de archivos vinculados por software no tuvo ningún impacto en el recuento de enlaces.

2. **List Files**: Escriba un programa que liste los archivos en un directorio dado. Cuando sea llamado sin argumentos, el programa deberá imprimir solo los nombres del archivo. Cuando se invoque con la flag ```-l```, el programa deberá imprimir la información de cada archivo tal como, owner, group, permissions y otra información obtenida de la llamada de sistema ```stat()```. El programa deberá tomar un argumento adicional el cual es el directorio a leer, por ejemplo, ```myls -l directory```.  Si ningún directorio es dado, el programa deberá usar el directorio de trabajo actual. Interfaces útiles: ```stat()```, ```opendir()```, ```readdir()```, ```getcwd()```.

- El codigo realizado para el comando ```ls()``` es el siguiente: [fstat.c](https://github.com/Jeroquendo/files-directories/blob/master/mi_ls.c)

- Al ejecutar el codigo sin argumentos este muestra lo siguiente:

![alt tag](https://github.com/Jeroquendo/files-directories/blob/master/Imagenes/02.1%20mi_Ls.png)

- Para ejecutar el codigo con el flag -l los argumentos deben indicarse asi:
```c
./mi_ls -l
```

-Para tomar un argumento adicional el cual es el directorio se debe indicar asi:
```c
./mi_ls -l ..
// or 
./mi_ls -l ../..
```

3. **Tail**: Escriba un programa que imprima una cuantas líneas al final de un archivo. El programa deberá ser eficiente, de manera que realice un *seek* para desplazarse cerca del final del archivo, realice una lectura de un bloque de datos y luego retroceda hasta encontrar el número de líneas solicitado; hasta este punto, el programa debería imprimir esas lineas desde el principio al final del archivo. Para invocar el programa, uno deberia digitar: ```mytail -n file```, donde ```n``` es el número de lineas al final del archivo a imprimir. Interfaces Útiles: ```stat()```, ```lseek()```, ```open()```, ```read()```, ```close()```.

- El codigo realizado para el comando ```tail()``` es el siguiente: [fstat.c](https://github.com/Jeroquendo/files-directories/blob/master/mi_tail.c)


4. **Recursive Search**: Escriba un programa que imprima los nombres de cada archivo y directorio del árbol del sistema de archivos (*file system tree*), empezando en un punto dado del sistema de archivos en el árbol. Por ejemplo, cuando ejecute sin argumentos, el programa deberá empezar con el directorio de trabajo actual e imprimir su contenido, así como con los contenidos de cualquier subdirectorio en este, etc., hasta que el árbol entero, root en el CWD sea impreso. Si se da un único argumento (de un nombre de un directorio), use este como root en vez de él del sistema. Refine su busqueda recursiva con más opciones de busqueda divertidas, similar a la poderosa herramienta por línea de comandos ```find```. Interfaces Útiles: Resolverlo.


## Referencias de utilidad ##

1. [Conceptos básicos claves resumidos](https://docs.google.com/document/d/1-336S7oKYwzSSSH-vzks8lGJ0R5VJoZu3PGBsz3vP2w/edit?usp=sharing)
2. [Aspectos básicos de C](https://github.com/repos-SO-UdeA/lab3)
3. [Manejo dinámico de memoria en C](https://github.com/repos-SO-UdeA/lab5)
4. [Manejo de archivos en C](https://github.com/repos-SO-UdeA/lab6)

