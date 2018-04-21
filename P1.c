//Aluno: Vinícius Pereira Duarte
//Matricula: 11721ECP003

#include <stdio.h>

int maquina (int estado, char bit)
{
	if(estado == 0)
	{
		if(bit == '0')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (estado == 1)
	{
		if(bit == '0')
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(bit == '0')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

int main()
{
	char bits[256];
	printf("Insira o numero em binario: ");
	fflush(stdin);
	gets(bits);
	int posF=0;
	while(bits[posF]!='\0')
	{
		posF++;
	}
	posF--;
	int estadomaquina=0;
	while(posF>=0)
	{
		//printf("\nEstado anterior: %d  bit: %c ",estadomaquina,bits[posF]);
		estadomaquina = maquina(estadomaquina, bits[posF]);
		//printf("Estado atual: %d",estadomaquina);
		posF--;
	}
	if(estadomaquina == 0)
	{
		printf("\nO numero eh multiplo de 3");
	}
	else
	{
		printf("\nO numero nao eh multiplo de 3");
	}
	getchar();
	return 0;
}
