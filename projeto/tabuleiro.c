#include <stdio.h>
#include "game.h"

void print_tabuleiro(char matriz[8][8]){
	for(int linhas = 0; linhas < 8; linhas++){
		for(int colunas=0; colunas < 8; colunas++){
			printf("%c", matriz[linhas][colunas]);	
		}
		printf("\n");
	}

}


void gr(char tabuleiro[8][8]){
	FILE *file;
	file = fopen("estado_tabuleiro", "ab+");
	for(int i=0; i<8; ++i)fwrite(tabuleiro[i], sizeof(tabuleiro[i][0]), 8, file);
}

//void ler(){
//	FILE *file;
//	unsigned char algo1;
//	file = fopen("estado_tabuleiro", "ab+");
//	for(int i=0; i<8; ++i)fread(tabuleiro, sizeof
//	
//}

void preenche_inicial(char tabuleiro[8][8]){
	for(int linhas = 0; linhas < 8 ; linhas++){
		for(int colunas=0; colunas < 8 ; colunas++){
			if( linhas == 0 && colunas == 7)tabuleiro[linhas][colunas]='2';
			else if ( linhas == 7 && colunas == 0)tabuleiro[linhas][colunas]='1';
			else tabuleiro[linhas][colunas]='.';

		}
	}
<<<<<<< HEAD
}


int main(){
	struct coordenada a;
	scanf("%c", &a.linha);
	printf("linha = %c", a.linha);
	//print tabuleiro
//	char tabuleiro[8][8];
//	//preenche_inicial(tabuleiro);
//	gr(tabuleiro);
//	print_tabuleiro(tabuleiro);
=======
	//BLAH
	print_tabuleiro(tabuleiro);
>>>>>>> c52036a5140c25bf5146a688b24c17a730156a58
	return 0;
}
