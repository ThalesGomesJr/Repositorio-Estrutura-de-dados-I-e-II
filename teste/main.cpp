/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/


#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

int main(){
	int op,pos;
	Lista L;
	Lista L2;
	Lista L3;
	Iniciar(&L);
	Iniciar(&L2);
	Iniciar(&L3);
	Tipo_elem v;

	do{
		system("cls");
		printf("\n1 - Inserir elementos na L1");
		printf("\n2 - Exibir L1");
		printf("\n3 - Verificar se L1 esta ordenada");
		printf("\n4 - Copiar L1 em L2");
		printf("\n5 - Exibir L2");
		printf("\n6 - Copiar L1 em L2 sem repeticao");
		printf("\n7 - Inserir na L2");
		printf("\n8 - Intercalar");
		printf("\n9 - Exibir L3");
		printf("\n10 - Inverter L1");
		printf("\n11 - Lista L2 contendo:elem,que contém um elemento de L1 e count");
		printf("\n12 - Os elementos que aparecem o maior e o menor numero de vezes em L1");
		printf("\n13 - Esvaziar");
		printf("\n14 - Sair");
		printf("\nDigite a Opcao: ");
		scanf("%d",&op);

		switch(op){
		
			case 1: //inserir L1
				printf("Digite o valor: ");
				scanf("%d",&v.chave);
				if(inserir_ord(&L,v))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Nao foi possivel inserir o elemento!\n");
			break;

			case 2://exibir L1
				Exibir(&L);
			break;

      		case 3: //verificar se L1 esta ordenada
				if(Verifica_ordenada(&L))
					printf("A lista esta ordenada!\n");
                else 
                    printf("Lista nao esta ordenada!\n");

			break;


			case 4://copiar L1 em L2
			    Copia(&L,&L2);
			    printf("Copia feita com sucesso!\n");
			break;

			case 5://exibir L2
				Exibir(&L2);
			break;

			case 6://copia sem repeticao
			    Copia_nrep(&L,&L2);
			    printf("Copia sem repeticao feita com sucesso\n");
			break;

			case 7://Inserir L2
				printf("Digite o valor: ");
				scanf("%d", &v.chave);
				if(inserir_ord(&L2,v))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Nao foi possivel inserir o elemento!\n");
			break;
			
			case 8://intercalar
			    Intercalar(&L,&L2,&L3);
			    printf("Funcao intercalar realizada com sucesso\n");
			break;
			
			case 9://Exibir L3
			       Exibir(&L3);
			break;
			

			case 10://Inverter
			    InverterL1(&L,&L2);
			    printf("Inversao realizada com sucesso!\n");
			break;

      		case 11:
        		QuestaoF(&L,&L2);
          	break;

			case 12:
				QuestaoG(&L,&L2);
			break;
			
     		case 13://esvaziar
            	Esvaziar(&L,&L2,&L3);
				printf("Listas L1, L2 e L3 esvaziadas com sucesso!\n");
			break;

    	}
    system("pause");
	}while(op!=14);
	return 0;
}
