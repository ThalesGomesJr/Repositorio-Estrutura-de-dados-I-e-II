/*****************************************************************************
- Aluno:Thales Junior de Souza Gomes RA:201611117                            *
- Aluno:Gieldson Alves de Oliveira - RA:201611923                            *
- Estrutura de dados II					                                     *
- IREVIR - Ir e vir  														 *
- Busca em Grafos	                          				          		 *
- DACC/UNIR, Profa. Carolina Watanabe										 *
- Compilador: DEV - C++/ versão: 5.11/ Sistema Operacional:Windows 10        *
*****************************************************************************/    

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 2000

bool G[MAX][MAX];//Matriz de adjacência 
bool Vi[MAX];//armazena os vertices visitados
int N, M;
 
void profundidade(int vertices){// Busca por profundidade 
	 int i;   
	 if(Vi[vertices] == true){
 		return;
 		}
	
	else{
 		Vi[vertices] = true; // armazena os vertices visitados
 		for(i=1;i<=N;i++)
 			if(G[vertices][i]&&!Vi[i]) 
			 	profundidade(i);
 		}
	}   
	             
main(){                
	setlocale(LC_ALL,"Portuguese_Brazil.1252");    
	bool resposta;
	int i;
	int j;
	int v, w, p;
	FILE *arq;
    arq = fopen("IREVIR.txt","r");
    if(arq == NULL){
   	    printf("|-> Erro, não foi possivel abrir o arquivo\n");
		printf("|-------------------------------------------|\n");
    }
    
    else{
    	printf("|-----------------------------------------------------------------|\n");
    	printf("|----------------------> IREVIR - Ir e vir <----------------------|\n");
    	printf("|-----------------------> BUSCA EM GRAFOS <-----------------------|\n");
    	while(!feof(arq)){                              
    		fscanf(arq,"%d",&N);
			fscanf(arq,"%d",&M);
			if((N==0&&M==0)){
				resposta = false;//Quando N ou M são 0 o programa deve ignoralos
			}
			else{
 				for(i=1;i<=N;i++){
 					Vi[i] = false;
 					for(j=1;j<=N;j++){
 						G[i][j] = false;
 					}
 				}		
 				for(i=1;i<=M;i++){
 					fscanf(arq,"%d %d %d", &v, &w, &p);
					if(p==1)
		  				G[v][w] = true;
 					else{
 						G[v][w] = true;
 						G[w][v] = true;
 					}
 				}
 				profundidade(1);
 				resposta = true;///conexidade aceita
 				for(i=1;i<=N;i++){
 					if(!Vi[i]){
 						resposta = false;//caso de conexidade não aceita
 					}
 				}
 				if(resposta==true){
 				//matriz de adjacência 
 					for(i=1;i<=N;i++){
 						Vi[i] = false;
 						for(j=i+1;j<=N;j++){
 							if(G[i][j]&&G[j][i]) 
								continue;
 							else if(G[i][j]){
 								G[j][i] = true; 
								G[i][j] = false;
 							}
 							else if(G[j][i]){
 								G[i][j] = true; 
					   			G[j][i] = false;
 							}
 						}
 					}
 					profundidade(1);
 				}
 				for(i=1;i<=N;i++){
 					if(!Vi[i]){
 						resposta = false; //caso de conexidade não aceita
 					}
 				}
				if(resposta==1)//requisito de conexidade está satisfeito                        
		 			printf("\n|-> Resultado: 1 (Requisito de conexidade está satisfeito)\n");
			
			 	else //requisito de conexidade não está satisfeito
					printf("\n|-> Resultado: 0 (Requisito de conexidade não está satisfeito)\n");
					printf("|-----------------------------------------------------------------|\n\n");
			}
		}   
		system("PAUSE");         
	}
	fclose(arq);
	return 0;
}

