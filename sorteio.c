#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int saldoInicial = 25;
	int numeroLimite = 0;
	int numeroAposta = 0;
	int valorAposta = 0;
	int process = 0;
	char* argumentos[3];
	int status = 0;
	int numReturned = 0;

	while(saldoInicial > 0) {
		printf("Digite um número: \n");
		scanf("%d", &numeroLimite);
		if (numeroLimite <= 1) {
			printf("Numero invalido\n");
			return 0;
		}

		printf("Digite um numero para a aposta:\n");
		scanf("%d", &numeroAposta);
		if (numeroAposta > numeroLimite) {
			printf("Numero invalido\n");
			return 0;
		}

		printf("Digite o valor da aposta:\n");
		scanf("%d", &valorAposta);
		if (valorAposta > saldoInicial) {
			printf("Valor nao vale\n");
			return 0;
		}

		char vetor[10];
		sprintf(vetor, "%d", numeroLimite);
		argumentos[0] = "./joga";
		argumentos[1] = vetor;
		argumentos[3] = NULL;

		process = fork();
		if (process == 0) {
			execvp( "./joga", (char *[]){ "./joga", vetor, NULL } );
		} else {
			waitpid(process, &status, 0 );
			if (WIFEXITED(status)) {
		        numReturned = WEXITSTATUS(status);
		        printf("\n\nRetornou %d\n\n", numReturned);
			}
		}

		if (numeroAposta == numReturned) {
			saldoInicial += valorAposta * numeroLimite;
			printf("Voce ganhou %d. Seu saldo eh %d\n", (valorAposta + numeroLimite), saldoInicial);
		} else {
			printf("Voce perdeu :(\n");
			saldoInicial -= valorAposta;
		}
	}
}
