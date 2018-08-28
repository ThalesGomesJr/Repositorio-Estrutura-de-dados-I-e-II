/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/
#include "Lista5.h"
#include <stdio.h>


void Iniciar(Lista *L){
     L->nelem = 0;
}

int Vazia(Lista *L){
    return(L->nelem == 0);
}

int Cheia(Lista *L){
    return(L->nelem==MAX);
}


int inserir_ord(Lista *L, Tipo_elem v){
	int pos, i;
	if(Cheia(L)) return 0;
		pos=0;
	while(pos<L->nelem&&v.chave>L->A[pos].chave)
		pos++;
	for(i=L->nelem;i>pos;i--)
		L->A[i]=L->A[i-1];
	L->A[pos]=v;
	L->nelem++;
	return 1;
}

void Exibir(Lista *L){
	int i;
	if(Vazia(L)) 
		printf("\nA lista esta vazia!\n");
	else{
		for(i=0;i<L->nelem;i++)
			printf("%d ",L->A[i].chave);
	}
}

int Tamanho(Lista *L){
	return(L->nelem);
}

void esvaziar(Lista *L){
	L->nelem=0;
}


int busca(Lista *L2, int nbusca){
	int posicao = -1;
	int i;
	for(i=0 ; i < L2->nelem ; i++ )
    	if(nbusca == L2->A[i].chave)
      		posicao = i;
    return posicao;
}

int Verifica_ordenada(Lista *L){
	int ordenado = 0;
	if(Vazia(L)) return 0;
	int i;
	for(i=0;i<L->nelem;i++){
		if(L->A[i].chave<L->A[i+1].chave) ordenado = 1;			
		if(L->A[i].chave>L->A[i+1].chave) ordenado = 1;
	}
	
	return ordenado;
}


void Copia(Lista *L, Lista *L2){
	int i;
	for(i=0 ; i< L->nelem ; i++){
		L2->A[i] = L->A[i];
		L2->nelem++;
	}
}

void Copia_nrep(Lista *L, Lista *L2){
    L2->nelem=0;
    int i;
    int j=1;
    int posicao;
    int aux;
    L2->A[0].chave=L->A[0].chave;
    L2->nelem++;
    for(i=0;i<L->nelem;i++){
        aux=L->A[i].chave;
        posicao=busca(L2,aux);
        if(posicao == -1){
     	   	L2->A[j].chave = aux;
        	L2->nelem++;
        	j++;
    	}
	}
}

void Intercalar(Lista *L,Lista *L2,Lista *L3){
  	L3->nelem=0;
  	int i;
  	int j=0,k=0;
  	int tamL = Tamanho(L);
  	int tamL2 = Tamanho(L2);
  	int tamanho_geral;
  	tamanho_geral = tamL+tamL2;
		for(i=0;i<tamanho_geral;i++){
			if(i%2==0){
			L3->A[i].chave = L->A[j].chave;
			j++;
			}
			else{
				L3->A[i].chave = L2->A[k].chave;
				k++;
			}
	    }
	L3->nelem = tamanho_geral;
}
        


void InverterL1(Lista *L, Lista *L2){
	L2->nelem=0;
	int i,tam;
	int pos;
	pos=Tamanho(L);
	tam=pos;
	for(i=0;i<L->nelem;i++){
		L2->A[i]=L->A[tam-1];
		tam--;
		L2->nelem++;
	}
}

void QuestaoF(Lista *L, Lista *L2){
    L2->nelem=0;
    int pos=Tamanho(L);
    int i;
    int j=1;
    int k;
    int posicao;
    int aux;
    int cont[pos];
    for(i=0;i<pos;i++)
    	cont[i]=0;
    L2->A[0].chave = L->A[0].chave;
    L2->nelem++;
    for(i=0;i<L->nelem;i++){
        aux=L->A[i].chave;
        posicao=busca(L2,aux);
        if(posicao == -1){
        	L2->A[j].chave = aux;
        	j++;
        }
	}
	L2->nelem=j;
	for(i=0 ;i < L2->nelem ; i++){
		for(k=0 ; k < L-> nelem ; k++)
			if(L2->A[i].chave == L->A[k].chave)
				cont[i]++;
	}

	for(i=0;i<L2->nelem;i++){
		if(cont[i]>1)
		printf("%d Aparece %d vezes\n",L2->A[i].chave,cont[i]);
	else
		printf("%d Aparece %d vez\n",L2->A[i].chave,cont[i]);
	}
}

void QuestaoG(Lista *L, Lista *L2){
	L2->nelem=0;
	int i;
	int j=1;
	int k;
	int posicao;
	int aux;
	L2->A[0].chave = L->A[0].chave;
	L2->nelem++;
	for(i=0; i < L->nelem ; i++){
		aux=L->A[i].chave;
		posicao=busca(L2,aux);
		if(posicao==-1){
			L2->A[j].chave = aux;
			j++;
		}
	}
	L2->nelem=j;
	int pos=Tamanho(L2);
	int cont[pos];
	for(i=0 ; i < pos ; i++)
	cont[i]=0;
	for(i=0 ;i < L2->nelem ; i++){
		for(k=0 ; k < L-> nelem ; k++)
			if(L2->A[i].chave == L->A[k].chave)
		cont[i]++;
	}
	int maior=0;
	int menor=100;
	int localizamaior=0;
	int localizamenor=0;
	for(i=0;i<pos;i++){
		if(cont[i]>=maior){
			maior=cont[i];
			localizamaior=i;
		}
		if(cont[i]<=menor){
			menor=cont[i];
			localizamenor=i;
		}
	}
	printf("%d Aparece %d vez(es)\n",L2->A[localizamaior].chave,maior);
	printf("%d Aparece %d vez(es)\n",L2->A[localizamenor].chave,menor);
}

void Esvaziar(Lista *L, Lista *L2, Lista *L3){
	L->nelem=0;
	L2->nelem=0;
	L3->nelem=0;
}

MUDEI AQUI
