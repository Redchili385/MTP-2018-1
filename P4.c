//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

int main(void)
{
	char CharNumero[256];
	printf("Insira um numero: ");
	scanf("%s",CharNumero);
	getchar();
	int i=0,numero=0;
	while(CharNumero[i]!='\0')
	{
		if(CharNumero[i] >= '0' && CharNumero[i] <= '9')
		{
			numero = numero*10 + (CharNumero[i] - '0');
		}
		i++;
	}
	printf("O numero inteiro eh: %d",numero);
	getchar();
	printf("\n\n");
	main();
}
