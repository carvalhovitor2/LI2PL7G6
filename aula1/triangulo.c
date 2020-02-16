#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	float s;
	int a, b, c;
	char triangulo[30]="isosceles";
	printf("Escreva a medida de cada um dos 3 lados do triangulo separados por virgulas: (Ex: o triangulo pitagorico seria 3, 4, 5)\n");
	scanf("%d %d %d", &a, &b, &c);
	if( !( abs(b-c) < a && a < (b+c)) ) {
		printf("Nao eh triangulo\n");
		return 0;
	}
	s = (a + b + c)/2.0f;
	if( a == b && a == c) {
		strncpy(triangulo, "equilatero", 30); 
	}
	else if( a != b && a != c && b != c) {
		strncpy(triangulo, "escaleno", 30);
	}
	printf("O triangulo inserido e: %s\nA area do triangulo inserido e: %.2f\n", triangulo, sqrt(s*(s-a)*(s-b)*(s-c)));
	return 0;
}
