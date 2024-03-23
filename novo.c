#include <stdio.h>

int main(void) {
	// your code goes here
    int N; // Número de premiados
    scanf("%d", &N);

    // Tamanhos solicitados pelos premiados
    char input[2*N]; // String para armazenar os números separados por espaço
    printf("Digite os números separados por espaço: ");
    fgets(input, sizeof(input), stdin); // Lê a string de entrada

    int countP = 0, countM = 0; // Variáveis para contar os números 1 e 2

    // Loop para percorrer a string e contar os números 1 e 2
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '1') {
            countP++;
        } else if (input[i] == '2') {
            countM++;
        }
    }

    int P, M; // Número de camisetas de tamanho pequeno e médio produzidas
    scanf("%d", &P);
    scanf("%d", &M);

    // Verifica se há camisetas suficientes para cada tamanho solicitado pelos premiados
    if (countP <= P && countM <= M) {
        printf("S"); // Todos serão atendidos
    } else {
        printf("N"); // Nem todos serão atendidos
    }
	return 0;
}
