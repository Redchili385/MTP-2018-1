//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

void IntToString(int numero,char binario[])
{
	binario[32] = '\0';
	int i;
	for(i=31;i>=0;i--)
	{
		if((numero & 1) == 0)
		{
			binario[i]='0';
		}
		else
		{
			binario[i]='1';
		}
		numero = numero >> 1;
	}
}

int main(void)
{
	int opcao;
	printf
	(
		"\nOperacoes Bitwise"
		"\n"
		"\n1. NOT"   //1 argumento      ~
		"\n2. AND"   //2 argumentos     &
		"\n3. OR"    //2                |
		"\n4. XOR"   //2                ^
		"\n5. Right Shift"  //2         >>
		"\n6. Left Shift"   //2         <<
		"\n0. Sair do programa"  //0
		"\n"
		"\nEscolha uma opcao: "
	);
	scanf("%d",&opcao);
	getchar();
	if(opcao==0)
	{
		return 0;
	}
	if(opcao==1)
	{
		int argint1;
		char argchar[33];
		printf("Digite o argumento: ");
		scanf("%d",&argint1);
		IntToString(argint1,argchar);
		getchar();
		int resultado;
		char resultadochar[33];
		resultado = ~argint1;
		IntToString(resultado,resultadochar);
		printf("NOT %d (%s) : %d (%s)",argint1,argchar,resultado,resultadochar);
	}
	if(opcao > 1 && opcao < 7)
	{
		int argint1, argint2, resultado;
		char argchar1[33], argchar2[33], nome_do_operador[4], resultadochar[33];
		printf("Digite o primeiro argumento: ");
		scanf("%d",&argint1);
		getchar();
		printf("Digite o segundo argumento: ");
		scanf("%d",&argint2);
		getchar();
		IntToString(argint1,argchar1);
		IntToString(argint2,argchar2);
		if(opcao == 2)
		{
			nome_do_operador[0] = 'A';
			nome_do_operador[1] = 'N';
			nome_do_operador[2] = 'D';
			nome_do_operador[3] = '\0';
			resultado = argint1 & argint2;
		}
		if(opcao == 3)
		{
			nome_do_operador[0] = 'O';
			nome_do_operador[1] = 'R';
			nome_do_operador[2] = '\0';
			nome_do_operador[3] = '\0';
			resultado = argint1 | argint2;
		}
		if(opcao == 4)
		{
			nome_do_operador[0] = 'X';
			nome_do_operador[1] = 'O';
			nome_do_operador[2] = 'R';
			nome_do_operador[3] = '\0';
			resultado = argint1 ^ argint2;
		}
		if(opcao == 5)
		{
			nome_do_operador[0] = '>';
			nome_do_operador[1] = '>';
			nome_do_operador[2] = '\0';
			nome_do_operador[3] = '\0';
			resultado = argint1 >> argint2;
		}
		if(opcao == 6)
		{
			nome_do_operador[0] = '<';
			nome_do_operador[1] = '<';
			nome_do_operador[2] = '\0';
			nome_do_operador[3] = '\0';
			resultado = argint1 << argint2;
		}
		IntToString(resultado,resultadochar); 
		printf("%d (%s) %s %d (%s) : %d (%s)",argint1,argchar1,nome_do_operador,argint2,argchar2,resultado,resultadochar);
	}
	getchar();
	printf("\n\n");
	main();
}
