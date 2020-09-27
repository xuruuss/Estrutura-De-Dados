#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


//Tipos Abstratos de Dados

typedef struct Elemento   // Definir o tipo
{
	
		int info; //
		struct Elemento *prox; //
}TElemento;

 

typedef struct Lista //
{
		TElemento *inicio; //ponteiro inicio
		TElemento *fim;		// ponteiro   fim
}TLista;

// Funcao que define a lista como vazia
void inicialza_lista(TLista *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
}

//Funcao que insere um elemento do inicio da lista

int inserir_elemento(TLista * lista)
{
	TElemento *novo;
	novo = new TElemento;
	
	printf("\n Informe o valor: ");
	scanf("%d", &novo->info);
	novo->prox = NULL;
	
	if (lista->inicio == NULL )
	{
		lista->inicio = novo;
		lista->fim = novo;
	}
	else
	{
		lista->fim->prox = novo; //encadeamento da lista
		lista->fim = novo;	 
	}
}


//Função que imprime toda lista

void  apresentar_elementos(TLista *lista)
{
	TElemento *aux;
	aux = lista->inicio;
	
	if(aux ==NULL)
	{
		printf("\n Lista vazia!");
	}
	else
	{
		while (aux != NULL)
		{
			printf("\n Valor: %d", aux->info);
			aux = aux->prox;
		}
	}
}

void exclui_elemento(TLista * Lista)
{
	
	int valor;
	TElemento * anterior, *atual; //ponteiros
	
	printf("\n Infome o elemento a ser excluido");
	scanf("%d", &valor);
	
	if (Lista->inicio == NULL)
	{
		printf("\n Lista Vazia");
	}
	else
	{
		
		anterior = Lista->inicio;
		atual= Lista->inicio;
		while (atual != NULL)
		{
			if (atual->info == valor)
		{
				if (atual == Lista->inicio)
			{
					Lista->inicio = Lista->inicio->prox;
					free(atual);
					break;
			}
			
				else
				{
					if(atual == Lista->fim)
					{
						Lista->fim = anterior;
					}
				
				//refazendo o encadeamento
				anterior->prox = atual->prox;
				free(atual);
				break;
			}
		}
			else
			{
				anterior = atual;
				atual = atual->prox;
			}
		}
	}
}



//Programa 	principal 

int main()
{
	TLista L1;
	
	inicialza_lista( &L1);
		
	int opcao;
	
	  
	do
	{
		printf("\nOpcoes: \n\n");
		printf("1 - Inserir novo Elemento\n");
		printf("2 - listar todos os elementos\n");
		printf("3 - Excluir elemento\n");
		printf("Entre com  sua opcao:");
		scanf("%d", opcao); 			//Lê a opção do usario//
		switch (opcao)
		{	
				case 1: inserir_elemento(&L1); break;
				case 2: apresentar_elementos(&L1); break;
				case 3: exclui_elemento(&L1); break;
				case 0: break;
				default: printf("\n\n Opcao Invalida"); getch(); break;
		}
	} 
	while (opcao != 0); 
}


