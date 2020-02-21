#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Generates one of the random 7 quotes
char* randQuote(){	
	char *quotes[] = {
		"Good one!",
		"Woah!",
		"Hell yeah!",
		"You're a genius!",
		"Are you the new Einstein?",
		"Noice!",
		"Toit!",
		NULL
	};
	return quotes[rand() % 7];
}

//Adding operation
int operation(int range, char op){
	int attempt, answer, fstNumber, sndNumber;
	printf("To quit press ctrl+C, to go back to menu type in -1\n");
	do{	
		fstNumber = rand() % range;
		sndNumber = rand() % range;
		switch(op){
			case '+': answer = fstNumber + sndNumber;
				  break;
			case '-': answer = fstNumber - sndNumber;
				  while ( answer == -1 ) {  
					fstNumber = rand() % range;
					sndNumber = rand() % range;
					answer = fstNumber - sndNumber;
				  }
				  break;
			case '*': answer = fstNumber * sndNumber;
				  break;
			case '/': answer = fstNumber / sndNumber;
				  break;
			
		}
		printf("%d %c %d=?\n", fstNumber, op, sndNumber);
		scanf("%d", &attempt);
		while( attempt != answer ) {
			if ( attempt == (-1) ) return 0;
			printf("Try again :(\n");
			printf("%d %c %d=?\n", fstNumber, op, sndNumber);
			scanf("%d", &attempt);
		}
		
		printf("%s\n", randQuote());
	}
	while( answer != (-1) );
	return 0;

}

int main(){
	int option=0, level=0, range=0;
	srand(time(NULL));
	//Prints menu for the first time
	printf("Welcome to mathLab! It's time to do some math! :)\n");
	printf("Type in the desired math operation\n1 - Soma\n2 - Subtração\n3 - Multiplicacao\n4 - Divisao\n0 - quit\n");
	scanf("%d", &option);
	if (option == 0) return 0;
	printf("Select your level\n1 - Sandbox\n2 - Easy\n3 - Medium\n4 - Hard\n0 - quit\n");
	scanf("%d", &level);
	range = pow(10, level);
	while(option != 0 && level > 0 && level <= 4){
		//Keeps printing menu and operating until quit
		oper = "+-*/";
		operaation(range, oper[option - 1]);

		switch(option){
			case 1:
				operation(range, '+');
				option=-1;
				break;
			case 2:
				operation(range, '-');
				option=-1;
				break;
			case 3:
				operation(range, '*');
				option=-1;
				break;
			case 4:
				operation(range, '/');
				option=-1;
				break;
			case 0:
				return 0;
			default:
				printf("Welcome to mathLab! It's time to do some math! :)\n");
				printf("Type in the desired math operation\n1 - Soma\n2 - Subtração\n3 - Multiplicacao\n4 - Divisao\n0 - quit\n");
				scanf("%d", &option);
				printf("Select your level\n1 - Sandbox\n2 - Easy\n3 - Medium\n4 - Hard\n0 - quit\n");
				scanf("%d", &level);
		}
	}
	return 0;
}
