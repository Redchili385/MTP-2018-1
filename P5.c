//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

int main(void)
{
	int opcao;
	printf
	( 
		"1. Codificar"
		"\n2. Decodificar"
		"\nSelecione a opcao desejada: "
	);
	scanf("%d",&opcao);
	getchar(); //limpar o buffer
	if(opcao == 1)
	{
		char input[256];
		{
			int c=0;
			while(c<256)
			{
				input[c] = 0;
				c++;
			}
		}
		printf("Escreva o texto a ser codificado: ");
		gets(input);
		int i = 0;
		while(input[i] != '\0')
		{
			if(i == 0)
			{
				printf("%d",*((int*)(&input[i])));
			}
			else
			{
				printf(", %d",*((int*)(&input[i])));
			}
			i+=4;
		}
		printf("\n\n\n");
	}
	else if(opcao == 2)
	{
		int input[64];
		printf("Escreva o numero a ser decodificado(Com virgula e espaço entre os inteiros):\n\n");
		int i = 0;
		char virgula;
		while(1)
		{
			scanf("%d%c",&input[i],&virgula);
			//printf("%d",input[i]);
			if(virgula != ',')
			{
				break;
			}
			//printf("%c",virgula);
			//printf("%c",getchar());
			getchar();
			i++;
		}
		printf("%s\n\n\n",(char*)input);
	}
	main();
}

