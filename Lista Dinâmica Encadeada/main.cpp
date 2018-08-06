/*Nome:Thales Junior de Souza Gomes RA:201611117
Estrutura de dados 1 2017.2
lista 5.*/

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
	int verificacres = 0,verificadesc = 0;
	int op,pos;
	Lista L;
	Lista L2;
	Lista L3;
	Lista L4;
	Iniciar(&L);
	Iniciar(&L2);
	Iniciar(&L3);
	Iniciar(&L4);
	Tipo_elem v;

	do{
		system("cls");
		printf("\n1 - Inserir elementos na L1");
		printf("\n2 - Exibir L1");
		printf("\n3 - Verificar se L1 esta ordenada");
		printf("\n4 - Copiar L1 em L2");
		printf("\n5 - Copiar L1 em L2 sem repeticao");
		printf("\n6 - Inserir elementos L3");
		printf("\n7 - Exibir L3");
		printf("\n8 - Intercalar L1 L3 e colocar em L4");
		printf("\n9 - Inverter L1 e exibir em L2");
		printf("\n10 - L2 com Elem L1 e cont quantas repeticoes");
		printf("\n11 - Mostrar quem aparece mais e menos vezes em L1 e quantas vezes aparecem");
		printf("\n12 - Esvaziar");
		printf("\n13 - Sair ");
		printf("\nDigite a Opcao: ");
		scanf("%d",&op);

		switch(op){

			case 1: //inserir L1
				printf("Digite o valor: ");
				scanf("%d",&v.chave);
				if(Inserir(&L,v))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Nao foi possivel inserir o elemento!\n");
			break;

			case 2://exibir L1
				Exibir(&L);
			break;

      		case 3: //verificar se L1 esta ordenada
					if(Vazia(&L))
					printf("\nA lista esta vazia");
					verificacres=Verifica_ordenada_crescente(&L);
					verificadesc=Verifica_ordenada_decrescente(&L);
					if(verificacres==0)
					if(verificadesc==0)
					printf("Lista nao esta ordenada\n");
					break;


			case 4://copiar L1 em L2
			    Copia(&L,&L2);
			    printf("Copia feita com sucesso!\n");
					printf("L2 ");
					Exibir(&L2);
			break;

			case 5://exibir L2
			Copia_nrep(&L,&L2);
			//printf("Copia sem repeticao feita com sucesso\n");
				Exibir(&L2);
			break;

			case 6://Inserir L3
				printf("Digite o valor: ");
				scanf("%d", &v.chave);
				if(Inserir(&L3,v))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Nao foi possivel inserir o elemento!\n");
			break;

			case 7:
			//Exibir L3
						 Exibir(&L3);
			break;

			case 8://intercalar
			    Intercalar(&L,&L3,&L4);
			  //  printf("Funcao intercalar realizada com sucesso\n");
			break;

			case 9://Inverter
			    Inverter(&L,&L2);
			    printf("\nInversao realizada com sucesso!\n");
			break;

			case 10:
			QuestaoF(&L,&L2);
			break;

			case 11:
			QuestaoG(&L,&L2);
			break;

				case 12://esvaziar
        Esvaziar(&L);
				printf("Lista esvaziada com sucesso!\n");
			break;

    	}
    system("pause");
	}while(op!=14);
return 0;
}
