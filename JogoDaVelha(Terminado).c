#include <stdio.h>
int verifica(int ijogada, int jjogada, int jogada){
	if((ijogada < 0 && ijogada > 2)){
		printf("Jogada Invalida");
		return jogada;
	}else{
		jogada = jogada+1;
		return jogada;
	}
}


int main(){
	
	//tabuleiro:
	int linha, coluna, ijogada, jjogada, jogada, matriz[3][3];
	for(linha = 0; linha<3; linha++){//printa a matriz
		for(coluna = 0; coluna<3; coluna++){
			matriz[linha][coluna] = 0;
			printf("| ");
			}
		printf("|\n");
	}
	
	//Gameplay:
	do{		
		if(jogada%2==0){ // verifica o numero da jogada para saber se é o jogador X ou O;
			printf("\nJogador X\nescreva a posicao da jogada\n");
			scanf("%d", &ijogada);
			scanf("%d", &jjogada);
			ijogada--;
			jjogada--;
			system("cls");
			
			printf("jogada : %d\n", jogada);
			if(matriz[ijogada][jjogada]!=0){
				printf("jogada invalida\n");
			}else{
				jogada = verifica(ijogada, jjogada, jogada);	// Verifica se a entrada é valida
			matriz[ijogada][jjogada] = 1; //Adiciona 1 a matriz que é usado para printar X qnado for == 1, ou O quando for == 2;	
			}
			
		}else{
			printf("\nJogador O\nEscreva a posicao da jogada\n");
			scanf("%d", &ijogada);
			scanf("%d", &jjogada);
			ijogada--;
			jjogada--;
			
			system("cls");
			
			printf("jogada : %d\n", jogada);
			if(matriz[ijogada][jjogada]!=0){
				printf("jogada invalida\n");
			}else{
				jogada = verifica(ijogada, jjogada, jogada);	// Verifica se a entrada é valida
			matriz[ijogada][jjogada] = 2; //Adiciona 1 a matriz que é usado para printar X qnado for == 1, ou O quando for == 2;	
			}

		}
		for(linha = 0; linha<3; linha++){//printa a matriz
			for(coluna = 0; coluna<3; coluna++){
					
					if(matriz[linha][coluna] == 1){ // Printa X
						printf("|x");
					}else if(matriz[linha][coluna] == 2){ // Printa O;
						printf("|o");
					}else{
						printf("| "); // Printa as paredes do Tabuleiro;
					}				
				}
			printf("|\n");
		}
		
		//verificando se alguem ganhou:
		if((matriz[0][0] == 1 && matriz[1][0] == 1 && matriz[2][0] == 1) || (matriz[1][0] == 1 && matriz[1][1] == 1 && matriz[1][2] == 1) || (matriz[0][0] == 1 && matriz[1][1] == 1 && matriz[2][2] == 1 ) || (matriz[2][0] == 1 && matriz[1][1] == 1 && matriz[0][2] == 1 ) ) {
			printf("\nJogador de X ganhou\n");
			jogada = 9;
		}
		if((matriz[0][0] == 2 && matriz[1][0] == 2 && matriz[2][0] == 2) || (matriz[1][0] == 2 && matriz[1][1] == 2 && matriz[1][2] == 2) || (matriz[0][0] == 2 && matriz[1][1] == 2 && matriz[2][2] == 2 ) || (matriz[2][0] == 2 && matriz[1][1] == 2 && matriz[0][2] == 2 ) ) {
			printf("/nJogador de O ganhou/n");
			jogada = 9;
		}	
	}while(jogada != 9); // Numero maximo de jogadas em um jogo da velha é 9;
	
	return 0;
}
