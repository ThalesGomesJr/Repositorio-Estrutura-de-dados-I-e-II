/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/

#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void Exibir(Lista *L){
	No *p;
	if(Vazia(L))
		printf("A Lista esta vazia!\n");
	else{
		p = L->head;
		while(p!=NULL){
			printf("%d ",p->info.chave);
			p = p->prox;
		}
	}
}

void Iniciar(Lista *L){
	L->head=NULL;
}

int Vazia(Lista *L){
	return(L->head==NULL);
}

int Inserir(Lista *L, Tipo_elem v){
	No *novo,*p,*q;
	novo=(No*)malloc(sizeof(No));
	if(novo==NULL) return 0;
	if(Vazia(L)){
		novo->info=v;
		L->head=novo;
		L->head->prox=NULL;
	}
	else{
		for(p = L->head ; p != NULL ; p = p->prox){
			q=p;
		}
		novo->info = v;
		q->prox = novo;
		novo->prox=NULL;
	}
	return 1;
}

int Tamanho(Lista *L){
	int cont = 0;
	No *p = L->head;
	if(p==NULL) return 0;
		while(p!=NULL){
		p=p->prox;
		cont++;
	}
	return cont;
}

int Verifica_ordenada_crescente(Lista *L){
	int cont = 0;
	int pos = Tamanho(L);
	if(L->head == NULL)
		printf("A Lista esta vazia\n");
	No *p = L->head;
	while(p->prox != NULL){
		if(p->info.chave < p->prox->info.chave)
			cont++;
		p = p->prox;
	}
	if(cont == pos-1){
		printf("Lista Ordenada (Crescentemente)\n");
		return 1;
	}
	else
		return 0;
}

int Verifica_ordenada_decrescente(Lista *L){
	int cont=0;
	int pos = Tamanho(L);
	if (L->head==NULL)
		printf("A Lista esta vazia\n");
	No *p = L->head;
	while(p->prox != NULL){
		if (p->info.chave > p->prox->info.chave)
		cont++;
		p=p->prox;
	}
	if(cont == pos-1){
		printf("Lista Ordenada (Decrescentemente)\n");
		return 1;
	}
	else
		return 0;
}

void Copia(Lista *L, Lista *L2){
	Esvaziar(L2);
	No *novo=(No*)malloc(sizeof(No));
	No *p,*q,*x,*y;
	L2->head=novo;
	L2->head->info.chave=L->head->info.chave;
	L2->head->prox=NULL;
	for(p= L->head->prox ; p != NULL ; p = p->prox){
		No *nov=(No*)malloc(sizeof(No));
		q=p;
		for(x = L2->head; x != NULL ; x = x->prox)
			y=x;
		nov->info.chave=q->info.chave;
		y->prox=nov;
		nov->prox=NULL;
	}
}

void Copia_nrep(Lista *L, Lista *L2){
	Esvaziar(L2);
	No *novo=(No*)malloc(sizeof(No));
	No *p,*q,*x,*y,num;
	L2->head=novo;
	L2->head->info.chave=L->head->info.chave;
	L2->head->prox=NULL;
	int nbusca;
	No *posicao;
	for(p=L->head;p!=NULL;p=p->prox){
		q=p;
		nbusca=(int)q->info.chave;
		posicao=Buscar(L2,nbusca);
		if(posicao==NULL){
			No *nov=(No*)malloc(sizeof(No));
			for(x = L2->head; x != NULL ; x = x->prox)
				y=x;
			nov->info.chave=nbusca;
			y->prox=nov;
			nov->prox=NULL;
		}
	}
}
int Busca(Lista *L2,int x){
	No *p;
	int cont=0;
	for(p=L2->head ; p!=NULL ; p=p->prox){
		if(p->info.chave==x)
		cont++;
	}
		return cont;
}

void Esvaziar(Lista *L){
	No	*p,*q;
 	p = L->head;
	while(p != NULL){
		q=p;
		p=p->prox;
	free(q);
	}
	L->head=NULL;
}

No *Buscar (Lista *L, int x){
	No *p;
	p=L->head;
	while(p != NULL && p->info.chave != x){
		p=p->prox;
		}
		return p;
}

void Insere_Inicio(Lista *L, int a){
	No *p;
	p = (No*)malloc(sizeof(No));
	p->info.chave=a;
	p->prox=L->head;
	L->head=p;
}

void Inverter(Lista *L, Lista *L2){
	Esvaziar(L2);
	No *p;
	int a;
	for(p = L->head ; p != NULL; p = p->prox){
		a=(int)p->info.chave;
		Insere_Inicio(L2,a);
	}
	Exibir(L2);
}


void Intercalar(Lista *L,Lista *L3, Lista *L4){
	Esvaziar(L4);
	No *novo=(No*)malloc(sizeof(No));
	No *p,*q,*x,*y,*a,*b;
	int taml,taml3,tamtotal;
	taml=Tamanho(L);
	taml3=Tamanho(L3);
	tamtotal=taml+taml3;
	L4->head=novo;
	L4->head->prox=NULL;
	while(tamtotal>1){
		No *nov=(No*)malloc(sizeof(No));
		for(x = L4->head; x != NULL ; x = x->prox)
			y=x;
		y->prox=nov;
		nov->prox=NULL;
		tamtotal--;
	}
	x=L->head;
	a=L3->head;
	for(p=L4->head;p!=NULL;p=p->prox->prox){
		q=p;
		while(x!=NULL){
			y=x;
			q->info.chave=y->info.chave;
			x=x->prox;
			break;
	}
		while(a!=NULL){
			b=a;
			q->prox->info.chave=b->info.chave;
			a=a->prox;
			break;
		}
	}
	Exibir(L4);
}

void QuestaoF(Lista *L, Lista *L2){
	Esvaziar(L2);
	No *novo=(No*)malloc(sizeof(No));
	No *p,*q,*x,*y,num;
	L2->head=novo;
	L2->head->info.chave=L->head->info.chave;
	L2->head->prox=NULL;
	int nbusca;
	No *posicao;
	for(p=L->head;p!=NULL;p=p->prox){
		q=p;
		nbusca=(int)q->info.chave;
		posicao=Buscar(L2,nbusca);
		if(posicao==NULL){
			No *nov=(No*)malloc(sizeof(No));
			for(x = L2->head; x != NULL ; x = x->prox)
				y=x;
			nov->info.chave=nbusca;
			y->prox=nov;
			nov->prox=NULL;
		}
	}
	int tamL2=Tamanho(L2);
	int i;
	int resulcont[tamL2];
	for(i=0;i<tamL2;i++)
		resulcont[i]=0;
	i=0;
	for(p=L2->head;p!=NULL;p=p->prox){
		q=p;
		nbusca=(int)q->info.chave;
		resulcont[i]=Busca(L,nbusca);
		if(resulcont[i]==1)
			printf("%d Aparece %d Vez\n",nbusca,resulcont[i]);
	else
		printf("%d Aparece %d Vezes\n",nbusca,resulcont[i]);
		i++;
	}
}


void QuestaoG(Lista *L, Lista *L2){
	Esvaziar(L2);
	No *novo=(No*)malloc(sizeof(No));
	No *p,*q,*x,*y,num;
	L2->head=novo;
	L2->head->info.chave=L->head->info.chave;
	L2->head->prox=NULL;
	int nbusca;
	No *posicao;
	for(p=L->head;p!=NULL;p=p->prox){
		q=p;
		nbusca=(int)q->info.chave;
		posicao=Buscar(L2,nbusca);
		if(posicao==NULL){
			No *nov=(No*)malloc(sizeof(No));
			for(x = L2->head; x != NULL ; x = x->prox)
				y=x;
			nov->info.chave=nbusca;
			y->prox=nov;
			nov->prox=NULL;
		}
	}
	int tamL2=Tamanho(L2);
	int i;
	int nbbusca[tamL2];
	int resulcont[tamL2];
	int maior=0,menor=99999;
	int pposicaomaior,pposicaomenor;
	for(i=0;i<tamL2;i++){
		resulcont[i]=0;
		nbbusca[i]=0;
	}
	i=0;
	for(p=L2->head;p!=NULL;p=p->prox){
		q=p;
		nbbusca[i]=(int)q->info.chave;
		resulcont[i]=Busca(L,nbbusca[i]);
		i++;
	}
	for(i=0;i<tamL2;i++){
		if(resulcont[i]>maior){
			maior=nbbusca[i];
			pposicaomaior=i;
		}		
		if(resulcont[i]<menor){
			menor=nbbusca[i];
			pposicaomenor=i;
		}
	}
	printf("%d Aparece o maior numero de vezes %d vezes\n",maior,resulcont[pposicaomaior]);
	printf("%d Aparece o menor numero de vezes %d vez\n",menor,resulcont[pposicaomenor]);
}	
