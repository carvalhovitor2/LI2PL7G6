#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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
