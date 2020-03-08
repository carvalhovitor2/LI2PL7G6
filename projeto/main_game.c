#include <stdio.h>
#include <stdlib.h>
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
}


int main(){
        char ch;

        move *moves = malloc(sizeof(move));
        if(!moves)
            exit(1);

        scanf("%c%d", &moves->line, &moves->collumn);
        printf("Move 1 = %c%d\n", moves->line, moves->collumn);

        moves = (move*)realloc(moves, sizeof(move)*2);
        if(!moves)
            exit(1);

       while(ch=getchar()!='\n'&&ch!=EOF);
       scanf("%c%d", &(moves+1)->line, &(moves+1)->collumn);
       printf("Move 2 = %c%d\n", (moves+1)->line, (moves+1)->collumn);
       
       
       for(int i=0; i < 2 ; i++){
	       printf("Move %d = %c%d\n", i+1, (moves+i)->line, (moves+i)->collumn);
       
       }
       
       return 0;

}
