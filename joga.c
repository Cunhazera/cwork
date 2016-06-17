#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int numero = atoi(argv[1]);
	int sorteio = 0;
	srand( (unsigned)time(NULL) );
	sorteio = (1 + rand() % numero);
	return sorteio;
}