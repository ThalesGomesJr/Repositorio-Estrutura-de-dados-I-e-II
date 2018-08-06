/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/

#include <stdio.h>

typedef struct{
	int chave;
}Tipo_elem;

typedef struct no{
	Tipo_elem info;
	struct no *prox;
}No;

typedef struct{
	int nelem;
	No *head;
}Lista;

int Busca(Lista *L,int x);
int Vazia(Lista *L);
int Inserir(Lista *L, Tipo_elem v);
void Iniciar(Lista *L);
int Tamanho(Lista *L);
void Exibir(Lista *L);
int Verifica_ordenada_crescente(Lista *L);
int Verifica_ordenada_decrescente(Lista *L);
void Copia(Lista *L, Lista *L2);
void Copia_nrep(Lista *L, Lista *L2);
No *Buscar(Lista *L, int nbusca);
void Esvaziar(Lista *L);
void Inverter(Lista *L, Lista *L2);
void Insere_Inicio(Lista *L, int a);
void Intercalar(Lista *L,Lista *L3, Lista *L4);
void QuestaoF(Lista *L, Lista *L2);
void QuestaoG(Lista *L, Lista *L2);
