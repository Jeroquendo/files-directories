#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
	FILE * file;
  char str[10000];
	int c;
  int n = abs(atoi(argv[1]));
	int linea = -1;
	

	if (argc != 3) {
		printf("Número de parametros incompletos\n");
		exit(-1);
	}

	if ((file = fopen(argv[2], "r")) == NULL) {
		perror("fallo abriendo el archivo");
		exit(-1);
	}

	if ((fseek(file, 0, SEEK_END) == -1) || (fseek(file, -1, SEEK_CUR) == -1)) {
		printf("fallo en el seek.");
		exit(-1);
	}
    
	while(1) {
		if ((c = fgetc(file)) == '\n') {
			linea++;
		}
		if (c == EOF) {
			break;
		}

		if (n <= linea) {
			break;
		}

		if (ungetc(c, file) == EOF){
			printf("falló en ungetc.");
			exit(-1);
		}
		fseek(file, -1, SEEK_CUR);
	}

	while (fgets(str, 10000, file) != NULL) {
		printf("%s", str);
	}
	printf("\n");
}
