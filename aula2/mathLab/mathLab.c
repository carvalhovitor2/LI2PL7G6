#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* randQuote(){	
	char *quotes[] = {
		"Good one!",
		"Woah!",
		"Hell yeah!",
		"You're a genius!",
		"Are you the new Einstein?",
		"Noice!",
		"Toit!"
	};
	return quotes[rand() % 7];
}


int soma(int range){
	int attempt, answer, fstNumber, sndNumber;
	srand(time(NULL));
	printf("To quit press ctrl+C, to go back to menu type in -1\n");
	do{	
		fstNumber = rand() % range;
		sndNumber = rand() % range;
		answer = fstNumber + sndNumber;
		printf("%d+%d=?\n", fstNumber, sndNumber);
		scanf("%d", &attempt);
		while( attempt != answer ) {
			if ( attempt == (-1) ) return 0;
			printf("Try again :(\n");
			printf("%d + %d=?\n", fstNumber, sndNumber);
			scanf("%d", &attempt);
		}
		
		printf("%s\n", randQuote());
	}
	while( answer != (-1) );
	return 0;

}

int multiplicacao(int range){
	int attempt, answer, fstNumber, sndNumber;
	srand(time(NULL));
	printf("To quit press ctrl+C, to go back to menu type in -1\n");
	do{	
		fstNumber = rand() % range;
		sndNumber = rand() % range;
		answer = fstNumber * sndNumber;
		printf("%d x %d=?\n", fstNumber, sndNumber);
		scanf("%d", &attempt);
		while( attempt != answer ) {
			if ( attempt == (-1) ) return 0;
			printf("Try again :(\n");
			printf("%d * %d=?\n", fstNumber, sndNumber);
			scanf("%d", &attempt);
		}
		
		printf("%s\n", randQuote());
	}
	while( answer != (-1) );
	return 0;

}

int subtracao(int range){
	int attempt, answer, fstNumber, sndNumber;
	srand(time(NULL));
	printf("To quit press ctrl+C, to go back to menu type in -1\n");
	do{	
		fstNumber = rand() % range;
		sndNumber = rand() % range; 
		answer = fstNumber - sndNumber;
		printf("%d - %d=?\n", fstNumber, sndNumber);
		scanf("%d", &attempt);
		while( attempt != answer ) {
			if ( attempt == (-1) ) return 0;
			printf("Try again :(\n");
			printf("%d - %d=?\n", fstNumber, sndNumber);
			scanf("%d", &attempt);
		}
		
		printf("%s\n", randQuote());
	}
	while( answer != (-1) );
	return 0;

}

int divisao(int range){
        float attempt, answer, fstNumber, sndNumber;
	srand(time(NULL));
	printf("To quit press ctrl+C, to go back to menu type in -1\n");
	do{	
		fstNumber = rand() % range;
		sndNumber = rand() % (range-1) + 1;
		answer = fstNumber / sndNumber;
		answer = roundf(answer * 100)/100;
		printf("%.2f / %.2f=?\n", fstNumber, sndNumber);
		scanf("%f", &attempt);
		while( attempt != answer ) {
			if ( attempt == (-1) ) return 0;
			printf("Try again :(\n");
			printf("%.2f / %.2f=?\n", fstNumber, sndNumber);
			scanf("%f", &attempt);
		}
		
		printf("%s\n", randQuote());
	}
	while( answer != (-1) );
	return 0;

}




int main(){
	int option=0, level=0, range=0;
	printf("Welcome to mathLab! It's time to do some math! :)\n");
	printf("Type in the desired math operation\n1 - Soma\n2 - Subtração\n3 - Multiplicacao\n4 - Divisao\n0 - quit\n");
	scanf("%d", &option);
	printf("Select your level\n1 - Sandbox\n2 - Easy\n3 - Medium\n4 - Hard\n0 - quit\n");
	scanf("%d", &level);
	range = pow(10,level);
	while(option != 0){
		switch(option){
			case 1:
				soma(range);
				option=-1;
				break;
			case 2:
				subtracao(range);
				option=-1;
				break;
			case 3:
				multiplicacao(range);
				option=-1;
				break;
			case 4:
				divisao(range);
				option=-1;
				break;
			case 0:
				return 0;
			default:
				printf("Welcome to mathLab! It's time to do some math! :)\n");
				printf("Type in the desired math operation\n1 - Soma\n2 - Subtração\n3 - Multiplicacao\n4 - Divisao\n0 - quit\n");
				scanf("%d", &option);
				printf("Type in the desired level\n1 - Sandbox\n2 - Easy\n3 - Medium\n4 - Hard\n0 - quit\n");
				scanf("%d", &level);
		}
	}
	return 0;
}
