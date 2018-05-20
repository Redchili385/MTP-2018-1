//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

int somarecursiva(int vetor[],int* c)
{
	vetor[0] = vetor[*c] + vetor[0];
	(*c)--;
	if (*c == 0)
	{
		return vetor[0]; 
	}
	else
	{
		somarecursiva(vetor,c);
	}
}

float dividir (int soma, int n)
{
	return ((float) soma)/((float) n);
}

int main(void)
{
	int n, numero[20];
	printf("Digite a quantidade de numeros a serem digitados: ");
	scanf("%d%*c",&n);
	printf("Digite de 5 a 20 numeros inteiros\n");
	int i=0;
	while(i<n)
	{
		numero[i] = 0;
		//printf("%d: ",i+1);
		scanf("%d%*c",&numero[i]);
		i++;
	}
	int* c;   //c = contador
	*c = n-1;
	int soma = somarecursiva(numero,c);
	float media = dividir(soma,n);
	printf("media = %g", media);
	printf("\n\n");
	main();
}
