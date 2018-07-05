//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float * vetor, int tam)
{
	int i;
	float num;
	for(i = 0; i < tam; i++)
	{
		vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
	}
}

float soma(float* inicio_vetor, float* fim_vetor)
{
	if(inicio_vetor == fim_vetor)
	{
		return 0.0f;
	}
	else
	{
		return *inicio_vetor + soma(inicio_vetor + 1 , fim_vetor);
	}
}

float produto(float* inicio_vetor, float* fim_vetor)
{
	if(inicio_vetor == fim_vetor)
	{
		return 1.0f;
	}
	else
	{
		return *inicio_vetor * produto(inicio_vetor + 1, fim_vetor);
	}
}

int main()
{
	srand(123456);  //Diferente para Linux e Windows.
	printf
	(
		"1-Somatorio \n"
		"2-Produtorio \n"
		"\n"
		"Escolha a opcao desejada: "
	);
	int opcao;
	scanf("%d%*c",&opcao);
	float vetor[100];
	gera_numeros(vetor,100);
	if(opcao == 1)
	{
		printf("%f",soma(vetor,vetor+99));
	}
	else if(opcao == 2)
	{
		printf("%f",produto(vetor,vetor+99));
	}
	else
	{
		printf("Opcao invalida!");
		getchar();
		printf("\n\n\n\n\n\n");
		main();
	}	
	return 0;
}
