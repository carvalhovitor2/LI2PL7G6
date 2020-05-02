#include <stdio.h>
#include "bot.h"

void mostrar_tabuleiro_Reverse(FILE *whereToPrint, ESTADO *e){
	int boardPiece = 0;
    for(int linha = 0; linha < 8; linha++){
    	char a = '8' - linha;
	if ( whereToPrint == stdout ){
		fprintf(whereToPrint, "%c", a);
		fprintf(whereToPrint, " ");
	}
        for(int coluna = 0; coluna < 8; coluna++){
		//Translate enum to chars
                    boardPiece = e->tab[linha][coluna];
			if(linha == 7 && coluna == 0) boardPiece = 3;
			if(linha == 0 && coluna == 7) boardPiece = 4;
			switch (boardPiece){
				case 0: fprintf(whereToPrint, ".");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 1: fprintf(whereToPrint, "*");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 2: fprintf(whereToPrint, "#");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 3: fprintf(whereToPrint, "1");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 4: fprintf(whereToPrint, "2");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				default: break;	

			}
                }
		fprintf(whereToPrint, "\n");
        } 

	if ( whereToPrint == stdout ){
		fprintf(whereToPrint, "  a b c d e f g h\n");
	}
}

void lerReverse(char *fileName, ESTADO *e){
    //Removes \n from string
    COORDENADA *coord = malloc(sizeof(int)*2);
    COORDENADA *coord1 = malloc(sizeof(int)*2);
    //Opens the file
    FILE *file = fopen(fileName, "r");

    //Auxiliar char to translate chars to integers
    char *c=malloc(sizeof(char));
    //Iterates through lines
    for(int linha = 0; linha < 8; linha++){

        //Please note that scanf functions read something and moves the reading pointer to the next thing to be read.
        //That is why you can iterate it like this
        //Iterates through columns
        for(int coluna = 0; coluna < 8; coluna++){

            //Reads a piece and stores it in game state
            int try = fscanf(file, "%c ", c);
	    if(try != 1)printf("could read char\n");
            if( *c == '.') e->tab[linha][coluna] = VAZIO;
            if( *c == '#') e->tab[linha][coluna] = PRETA;
            if( *c == '*') e->tab[linha][coluna] = BRANCA;
        }
    }

    //Discarding number line of the board (1, 2, 3 ...)
    //fscanf(file, "1 2 3 4 5 6 7 8 ");
    char jogada='a', p1Linha='a', p1Coluna='a', p2Linha='a', p2Coluna='a';
    //Reads first 10 movs
    for(int buffer = 0, linha = 0;linha < 81 && (fscanf(file, "%c", c) == 1); buffer++, linha++, buffer %=9){
        switch(buffer){
            case 1: jogada = *c;
                break;
            case 4: p1Linha = *c;
                break;
            case 5: p1Coluna = *c;
                break;
            case 7: p2Linha = *c;
                break;
            case 8: p2Coluna = *c;
                break;
            default:
                break;

        }
        if (buffer == 6){
            	coord->linha = p1Linha - 'a';
		changePlayer(e);
            	coord->coluna = p1Coluna - '1';
		e->jogadas[jogada-'1'].jogador1 = *coord;
        }
	if (buffer == 8){
                coord1->linha = p2Linha - 'a';
		changePlayer(e);
                coord1->coluna = p2Coluna - '1';
                e->jogadas[jogada-'1'].jogador2 = *coord1;
		incrJogada(e);
		//Discards newline
                int try = fscanf(file, " ");
		if (try != 1 && try != 0)printf("Couldnt read char");
	}
    }
    //Reads other 20 movs
        for(int buffer = 0, linha = 0;linha < 200 && (fscanf(file, "%c", c) == 1); buffer++, linha++, buffer %=9){
	        switch(buffer){
	            case 1: jogada = *c;
	                break;
	            case 4: p1Linha = *c;
	                break;
	            case 5: p1Coluna = *c;
	                break;
	            case 7: p2Linha = *c;
	                break;
	            case 8: p2Coluna = *c;
	                break;
	            default:
	                break;
	        }
	        if (buffer == 6){
	                coord->linha = p1Linha - 'a';
	                coord->coluna = p1Coluna - '1'; 
	                e->jogadas[jogada-'1'+10].jogador1 = *coord;
			changePlayer(e);
	        }
	        if (buffer == 8){
	                coord1->linha = p2Linha - 'a';
	                coord1->coluna = p2Coluna - '1';
	                e->jogadas[jogada-'1'+10].jogador2 = *coord1;
	                incrJogada(e);
			changePlayer(e);
	                //Discards newline
	                int try = fscanf(file, " ");
			if(try != 1)printf("Couldnt read char - 3\n");
	        }
	    }
}

void grReverse(char *fileName, ESTADO *e){
    //Opens the file
    FILE *file = fopen(fileName, "w+");

    //Writes the board in the file instead of stdout
    mostrar_tabuleiro_Reverse(file, e);
    fputc('\n', file);
    movs(file,e);
}


COORDENADA reverseCOORDENADA(COORDENADA C){
	int temp = C.linha;
	C.linha = 8 - C.coluna;
	C.coluna = temp;
	return C;
}

int main(int argc, char *argv[]){
	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro_Reverse(stdout, e);
	COORDENADA c = {4,4};
	jogar(e, c);
	grReverse("teste", e);
	//if(argc == 3){
	//	ler(argv[1], e, 1);
	//	COORDENADA c;
	//	c.linha = jog2(e, 1);
	//	c.coluna = jog2(e, 0);
		//c = reverseCOORDENADA(c);
	//	jogar(e, c);
	//	gr(argv[2], e, 1);
	//}
	return 0;
}