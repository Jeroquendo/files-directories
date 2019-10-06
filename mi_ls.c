#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc > 3){
        return 1;
    }
    

    DIR *mid;
    struct dirent *miArchivo;
    struct stat fstat;

    if(argc == 1){
        mid = opendir(".");
        while((miArchivo = readdir(mid)) != NULL)
        {
            printf("%s\t", miArchivo->d_name);
        }    
        printf("\n");
        closedir(mid);
        return 0;
    }

    if(argc == 2 && strcmp(argv[1],"-l") != 0) {
        mid = opendir(argv[1]);
        while((miArchivo = readdir(mid)) != NULL)
        {
            printf("%s\n", miArchivo->d_name);
        }    
        printf("\n");
        closedir(mid);
        return 0;
    }

    if(argc == 2 && strcmp(argv[1],"-l") == 0) {

        mid = opendir(".");
        char buf[512];

        while((miArchivo = readdir(mid)) != NULL)
        {
            sprintf(buf, "%s/%s", argv[1], miArchivo->d_name);    
            char archivo[100];
            strcpy(archivo, "./punto1.out ");
            strcat(archivo, miArchivo->d_name);
            int status = system(&archivo);
        }
        printf("\n");
        closedir(mid);
        return 0;
    }

    if(argc == 3 && strcmp(argv[1],"-l") == 0) {
        mid = opendir(argv[2]);
        char buf[512];

        while((miArchivo = readdir(mid)) != NULL)
        {
            sprintf(buf, "%s/%s", argv[1], miArchivo->d_name);
            char archivo[100];
            strcpy(archivo, "./punto1.out ");
            strcat(archivo, argv[2]);
            strcat(archivo, "/");
            strcat(archivo, miArchivo->d_name);
            int status = system(&archivo);
        }   
        closedir(mid);
        return 0;
    }
}