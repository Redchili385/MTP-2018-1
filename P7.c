//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

int Ackermann(int m,int n)
{
	if(m == 0)
	{
		return n+1;
	}
	else if (n == 0)
	{
		return Ackermann(m-1,1);
	}
	else
	{
		return Ackermann(m-1,Ackermann(m,n-1));
	}
}

int main(void)
{
	int a1,a2,resultado; 
	printf("Ackermann Function");
	printf("\nInsira o primeiro argumento inteiro: ");
	scanf("%d%*c",&a1);
	printf("Insira o segundo argumento: ");
	scanf("%d%*c",&a2);
	resultado = Ackermann(a1,a2);
	printf("%d",resultado);
	printf("\n\n");
	main();
}
