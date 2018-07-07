//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>

struct Dimensoes //Metros
{
	float largura;
	float profundidade;
	float altura;	
};

struct Produto
{
	char nome[64];
	float preco;
	struct Dimensoes dimensoes;
};

void retirarNewLineDoFinalDaString(char* string)  //substituir /n por \0 apenas
{
	int i = 0;
	while(string[i] != '\0')
	{
		if(string[i] == '\n')
		{
			string[i] = '\0';
			break;
		}
		i++;
	}
}

void cadastrarProduto(struct Produto produto[])
{
	int opcao2;
	printf("Insira o numero do produto que deseja cadastrar: ");
	scanf("%d%*c",&opcao2);
	if(opcao2 != 1 && opcao2 != 2)
	{
		printf("Atualmente, suportamos apenas o cadastro dos produtos 1 e 2, insira um destes numeros: ");
		scanf("%d%*c",&opcao2);
		if(opcao2 != 1 && opcao2 != 2)
		{
			printf("\n\n\n");
			return;
		}
	}
	printf("Insira as informacoes do produto\n");
	printf("Nome: ");
	fgets(produto[opcao2-1].nome,64,stdin);
	retirarNewLineDoFinalDaString(produto[opcao2-1].nome);
	printf("Preco(R$): ");
	scanf("%f%*c",&produto[opcao2-1].preco);
	printf("Largura(m): ");
	scanf("%f%*c",&produto[opcao2-1].dimensoes.largura);
	printf("Profundidade(m): ");
	scanf("%f%*c",&produto[opcao2-1].dimensoes.profundidade);
	printf("Altura(m): ");
	scanf("%f%*c",&produto[opcao2-1].dimensoes.altura);
	printf("Produto %d cadastrado com sucesso",opcao2);
	getchar();
	printf("\n\n\n");
}

void consultarProduto(struct Produto produto[])
{
	int opcao2;
	printf("Insira o numero do produto que deseja consultar: ");
	scanf("%d%*c",&opcao2);
	if(opcao2 != 1 && opcao2 != 2)
	{
		printf("Atualmente, suportamos apenas a consulta dos produtos 1 e 2, insira um destes numeros: ");
		scanf("%d%*c",&opcao2);
		if(opcao2 != 1 && opcao2 != 2)
		{
			printf("\n\n\n");
			return;
		}
	}
	if(produto[opcao2-1].nome[0] == '\0')
	{
		printf("Produto nao cadastrado!");
		getchar();
		printf("\n\n\n");
	}
	else
	{
		printf
		(
			"%s, R$ %.2f, L: %gm x P: %gm x A: %gm",
			produto[opcao2-1].nome,		
			produto[opcao2-1].preco,
			produto[opcao2-1].dimensoes.largura,
			produto[opcao2-1].dimensoes.profundidade,
			produto[opcao2-1].dimensoes.altura
		);
		getchar();
		printf("\n\n\n");
	}
}

void menu(struct Produto produto[])
{
	printf
	(
		"1 - Cadastro \n"
		"2 - Consulta \n"
		"\n"
		"Digite a opcao desejada: "
	);
	int opcao1;
	scanf("%d%*c",&opcao1);
	if(opcao1 == 1)
	{
		cadastrarProduto(produto);
		menu(produto);
	}
	else if (opcao1 == 2)
	{
		consultarProduto(produto);
		menu(produto);
	}
	else
	{
		printf("Opcao Invalida!");
		getchar();
		printf("\n\n\n");
		menu(produto);
	}
}

int main()
{
	struct Produto produto[2];
	int i;
	for(i=0; i<2; i++)
	{
		produto[i].nome[0] = '\0';
	}
	menu(produto);
	return 0;
}
