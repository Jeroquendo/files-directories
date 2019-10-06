#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        return 1;
    }
 
    struct stat fs;
     if(stat(argv[1],&fs) < 0){
        printf("error al llamar a stat.\n");
        return 1;
    }   
 
    printf("Datos del archivo %s\n",argv[1]);
    printf("---------------------------\n");
    //printf("Tipo y modo de archivo: \t%s\n",fs.st_mode);
    printf("Tamaño : \t\t%d bytes\n",fs.st_size);
    printf("Nodo-i del archivo: \t\t%d\n",fs.st_ino);
    printf("Numero de bloques: \t%d\n",fs.st_blocks);
    printf("Numero de links: \t\t%d\n",fs.st_nlink);
    printf ("Último cambio de estado:% s", ctime (& fileStat.st_ctime)); 
    printf ("Último acceso al archivo:% s", ctime (& fileStat.st_atime)); 
    printf ("Última modificación del archivo:% s", ctime (& fileStat.st_mtime));
 
    printf("Permisos del Archivo: \t\t");
    printf( (S_ISDIR(fs.st_mode)) ? "d" : "-");
    printf( (fs.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fs.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fs.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fs.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fs.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fs.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fs.st_mode & S_IROTH) ? "r" : "-");
    printf( (fs.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fs.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n"); 
 
    printf("El archivo %s un  link simbolico\n", (S_ISLNK(fileStat.st_mode)) ? "es" : "No es");
 
    return 0;
}