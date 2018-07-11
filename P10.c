//Nome: Vinícius Pereira Duarte
//Matrícula: 11721ECP003

#include <stdio.h>
#include <stdlib.h>

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

void cadastrarProduto(struct Produto* produto)
{
	printf("\nInsira as informacoes do produto\n");
	printf("Nome: ");
	fgets(produto->nome,64,stdin);
	retirarNewLineDoFinalDaString(produto->nome);
	printf("Preco(R$): ");
	scanf("%f%*c",&produto->preco);
	printf("Largura(m): ");
	scanf("%f%*c",&produto->dimensoes.largura);
	printf("Profundidade(m): ");
	scanf("%f%*c",&produto->dimensoes.profundidade);
	printf("Altura(m): ");
	scanf("%f%*c",&produto->dimensoes.altura);
}

void mostrarProduto (struct Produto produto)
{
	printf
	(
		"%s, R$ %.2f, L: %gm x P: %gm x A: %gm",
		produto.nome,		
		produto.preco,
		produto.dimensoes.largura,
		produto.dimensoes.profundidade,
		produto.dimensoes.altura
	);
}

int sizeofFile(char* nArquivo)
{
	int size;
	FILE* arquivo;
	if(arquivo = fopen(nArquivo,"rb"))
	{
		fseek(arquivo,0L,SEEK_END);
		size = (int)ftell(arquivo);
		fclose(arquivo);
		return size;
	}
	else
	{
		return -1;
	}
}

void menu(struct Produto* iniciolista, int* quantidade)
{
	printf
	(
		"Produtos em memoria: %d"
		"\n1. Consultar"
		"\n2. Cadastrar novo"
		"\n3. Carregar de arquivo para memoria (sobrescreve memoria)"
		"\n4. Salvar memoria em arquivo (sobrescreve arquivo)"
		"\n0. Encerra"
		"\n\nDigite a opcao desejada: "
	,*quantidade);
	int opcaoMenu;
	scanf("%d%*c",&opcaoMenu);
	if(opcaoMenu == 1)
	{
		if(*quantidade == 0)
		{
			printf("\nNenhum produto cadastrado!");
		}
		else
		{
			printf
			(
				"\nProdutos em memoria: %d"
				"\n0. Voltar"
			,*quantidade);
			int i;
			for(i=0;i<(*quantidade);i++)
			{
				printf("\n%d. %s",i+1,iniciolista[i].nome);
			}
			printf("\n\nDigite o numero do produto que deseja consultar: ");
			int opcaoConsulta;
			scanf("%d%*c",&opcaoConsulta);
			if(opcaoConsulta > 0 && opcaoConsulta <= (*quantidade))
			{
				printf("\n");
				mostrarProduto(iniciolista[opcaoConsulta-1]);
			}
			else if(opcaoConsulta != 0)
			{
				printf("Produto inexistente!");
			}
		}
		getchar();
		printf("\n\n");
		menu(iniciolista,quantidade);
	}
	else if(opcaoMenu == 2)
	{
		(*quantidade)++;
		iniciolista = (struct Produto*)realloc(iniciolista,(*quantidade)*sizeof(struct Produto));
		cadastrarProduto(&iniciolista[(*quantidade)-1]);
		printf("\nCadastrado com sucesso!\n\n");
		getchar();
		menu(iniciolista,quantidade);
	}
	else if(opcaoMenu == 3)
	{
		char nArquivo[64];
		FILE* arquivo;
		int sof;
		printf("\nDigite o nome do arquivo a ser carregado na memoria: ");
		fgets(nArquivo,64,stdin);
		retirarNewLineDoFinalDaString(nArquivo);
		sof = sizeofFile(nArquivo);
		if (sof > 0)
		{
			arquivo = fopen(nArquivo,"rb");
			*quantidade = sof/sizeof(struct Produto);
			printf("Arquivo contem %d produto(s). ",*quantidade);
			iniciolista = (struct Produto*)realloc(iniciolista,(*quantidade)*sizeof(struct Produto));
			if(iniciolista)
			{
				fread(iniciolista,sizeof(struct Produto),*quantidade,arquivo);
				printf("Leitura realizada com sucesso!\n\n");
			}
			else
			{
				fprintf(stderr,">>> Problema de realocacao da memoria!\n\n");
				*quantidade = 0;
			}
			fclose(arquivo);
		}
		else
		{
			fprintf(stderr, ">>> Carregamento nao efetuado!\n");
		}
		getchar();
		menu(iniciolista,quantidade);
	}
	else if(opcaoMenu == 4)
	{
		char nArquivo[64];
		FILE* arquivo;
		printf("\nInsira o nome do arquivo para salvar as informacoes: ");
		fgets(nArquivo,64,stdin);
		retirarNewLineDoFinalDaString(nArquivo);
		if(arquivo = fopen(nArquivo,"wb"))
		{
			fwrite(iniciolista,sizeof(struct Produto),*quantidade,arquivo);
			fclose(arquivo);
			printf("\nProdutos armazenados em disco com sucesso!\n\n");
		}
		else
		{
			fprintf(stderr, ">>> Salvamento nao efetuado!\n\n");
		}
		getchar();
		menu(iniciolista,quantidade);
	}
	else if(opcaoMenu != 0)
	{
		printf("\nOpcao invalida!");
		getchar();
		printf("\n\n\n\n");
		menu(iniciolista,quantidade);
	}
}

int main()
{
	struct Produto* iniciolista = NULL;     //malloc(0);
	int quantidade = 0;
	menu(iniciolista, &quantidade);
	if (iniciolista)
	{
		printf("iniciolista: %d",iniciolista);
		free(iniciolista);
	}
	printf("\n%d",iniciolista);
	return 0;
}
