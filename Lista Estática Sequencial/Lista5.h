/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Definindo a estrutura TAD

typedef struct{
	int chave;
}Tipo_elem;

typedef struct{
	Tipo_elem A[MAX];
	int nelem;
}Lista;


void Iniciar(Lista *L);

int Cheia(Lista *L);

int Vazia(Lista *L);

int inserir_ord(Lista *L, Tipo_elem A);

int Tamanho(Lista *L);

int Verifica_ordenada(Lista *L);

int busca(Lista *L2, int nbusca);

void Copia(Lista *L, Lista *L2);

void Copia_nrep(Lista *L, Lista *L2);

void Intercalar(Lista *L,Lista *L2,Lista *L3);

void InverterL1(Lista *L, Lista *L2);

void QuestaoF(Lista *L, Lista *L2);

void QuestaoG(Lista *L, Lista *L2);

void Exibir(Lista *L);

void Exibirl2(Lista *L2);

void Esvaziar(Lista *L, Lista *L2, Lista *L3);


