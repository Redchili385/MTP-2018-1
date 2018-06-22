//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

int CharParaInt(char caractere)
{
	int inteiro;
	if(caractere >= '0' && caractere <= '9')
	{
		inteiro = caractere - '0';
	}
	else
	{
		inteiro = caractere - 'A' + 10;
	}
	return inteiro;
}

char IntParaChar(int inteiro)
{
	char caractere;
	if(inteiro < 10)
	{
		caractere = inteiro + '0';
	}
	else
	{
		caractere = inteiro - 10 + 'A';
	}
	return caractere;
}

int Potencia (int base, int expoente)
{
	int numero = 1, expoenteatual = 0;
	while(expoenteatual != expoente)
	{
		numero = numero * base;
		expoenteatual++;
	}
	return numero;
}

void Transforme(char bits[],char BaseAnterior[],char BasePosterior[])
{
	//Etapa 1: Identificar a base de Entrada
	int BA;
	if(BaseAnterior == "Binario")   //Provavelmente isso apenas verifica o primeiro caractere, mas funciona por enquanto...
	{
		BA=2;
	}
	else if (BaseAnterior == "Octal")
	{
		BA=8;
	}
	else if (BaseAnterior == "Hexadecimal")
	{
		BA=16;
	}
	else
	{
		BA=10;
	}
	//Etapa 2: Transformar os bits em um inteiro de acordo com a base de entrada
	int w=0;
	while(bits[w]!='\0')
	{
		w++;
	}
	w--;
	int expoente = 0;
	int numero = 0;
	while(w>=0)
	{
		numero = numero + CharParaInt(bits[w]) * Potencia(BA,expoente);
		w--;
		expoente++;
	}
	//Etapa 3: Identificar a base de Saída
	int BP;
	if(BasePosterior == "Binario")
	{
		BP=2;
	}
	else if (BasePosterior == "Octal")
	{
		BP=8;
	}
	else if (BasePosterior == "Hexadecimal")
	{
		BP=16;
	}
	else
	{
		BP=10;
	}
	//Etapa 4: Inserir os bits de acordo com o número inteiro e a base posterior
	//Etapa 4.1: Identificar a primeira casa. O numero(char) não deve possuir 0 à esquerda.
	expoente = 0;
	while(numero/Potencia(BP,expoente) != 0)
	{
		expoente++;
	}
	expoente--;
	//Etapa 4.2: Inserir bits
	w=0;
	while(numero != 0 || expoente >= 0)
	{
		bits[w] = IntParaChar(numero/Potencia(BP,expoente));
		numero = numero % Potencia(BP,expoente);
		w++;
		expoente--;
	}
	//Etapa 4.3: Inserir o \0
	bits[w] = '\0';
	//Etapa 5: Printar os bits
	printf("O numero na base %d(%s) eh: %s",BP,BasePosterior,bits);
	getchar();
}

int main()
{
	char bits[256];
	printf("Insira um inteiro: ");
	scanf("%s%*c",bits);
	int opcao=0;
	printf
	(
		"\n1. Binario para decimal"
		"\n2. Binario para hexadecimal"
		"\n3. Hexadecimal para Decimal"
		"\n4. Hexadecimal para Binario"
		"\n5. Decimal para Binario"
		"\n6. Decimal para Hexadecimal"
		"\n7. Octal para Decimal"
		"\n8. Decimal para Octal"
		"\n\nDigite o numero da opcao: "
	);
	scanf("%d",&opcao);
	getchar();
	if(opcao>0 && opcao<9)
	{
		if(opcao==1)
		{
			Transforme(bits,"Binario","Decimal");
		}
		if(opcao==2)
		{
			Transforme(bits,"Binario","Hexadecimal");
		}
		if(opcao==3)
		{
			Transforme(bits,"Hexadecimal","Decimal");
		}
		if(opcao==4)
		{
			Transforme(bits,"Hexadecimal","Binario");
		}
		if(opcao==5)
		{
			Transforme(bits,"Decimal","Binario");
		}
		if(opcao==6)
		{
			Transforme(bits,"Decimal","Hexadecimal");
		}
		if(opcao==7)
		{
			Transforme(bits,"Octal","Decimal");
		}
		if(opcao==8)
		{
			Transforme(bits,"Decimal","Octal");
		}
	}
	printf("\n\n");
	main();
	return 0;
}
