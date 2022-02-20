/*******************************************************************************
*                       USP - Universidade de São Paulo                        *
*            ICMC - Instituto de Ciências Matemáticas e de Computação          *
********************************************************************************
*                      Eric Rodrigues das Chagas (12623971)                    * 
*                     Bacharelado em Ciências de Computação                    *
*                                   2021                                       *
********************************************************************************
*                           Filas de prioridade                                *
*                 Algoritimos e estrutura de dados (SCC 0201)                  *					
********************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "F_filas_.h"

#define Maxfila 10000



int main(){

    //Declarações iniciais
    dadosFilas filas;
    dadosPessoa pessoa_generica;

    filas.qntPessoasP1=0;
    filas.qntPessoasP2=0;
    filas.qntPessoasP3=0;
    filas.qntPessoasP4=0;

    char act[6];
    int qnt_act=0;



    scanf("%d", &qnt_act);
    while (qnt_act != 0)
    {
        
        scanf("%s", act);


        if( strncmp("ENTRA", act, 5) == 0){
            if(filas.qntTotalPessoas == Maxfila){
                printf("FILA CHEIA\n");
            }
            //printf("Entrou em: ""ENTRA""\n");
            
            filas.qntTotalPessoas++;
            
            scanf("%s", pessoa_generica.nome);
            scanf("%d", &pessoa_generica.idade);
            scanf("%d", &pessoa_generica.condicao);

            int prioridade=0;

            prioridade=encontPrioridade(pessoa_generica, prioridade);
            //printPessoa(pessoa_generica);
            
            if(prioridade == 0){
                printf("Error na leitura dos dados ou  definição de prioridade");
                return 1;
            }

            if(prioridade == 1){
                filas.filaP1=addFila(filas.filaP1, pessoa_generica, &(filas.qntPessoasP1) );
            } 

            if(prioridade == 2){
                filas.filaP2=addFila(filas.filaP2, pessoa_generica, &(filas.qntPessoasP2) );
            } 

            if(prioridade == 3){
                filas.filaP3=addFila(filas.filaP3, pessoa_generica, &(filas.qntPessoasP3) );
            } 
            
            if(prioridade == 4){
                filas.filaP4=addFila(filas.filaP4, pessoa_generica, &(filas.qntPessoasP4) );
            } 

        }


        if(strncmp("SAI", act, 3) == 0){
            if(filas.qntTotalPessoas == 0){
                printf("FILA VAZIA\n");
            }
            //printf("Entrou em: ""SAI""\n");
            
            filas.qntTotalPessoas--;

            if(filas.qntPessoasP1 != 0){
                printPessoa(filas.filaP1[0]);

                filas.filaP1=removeFila(filas.filaP1, &filas.qntPessoasP1);
            }
            
            else if(filas.qntPessoasP2 != 0){
                printPessoa(filas.filaP2[0]);

                filas.filaP2=removeFila(filas.filaP2, &filas.qntPessoasP2);
            }
            
            else if(filas.qntPessoasP3 != 0){
                printPessoa(filas.filaP3[0]);

                filas.filaP3=removeFila(filas.filaP3, &filas.qntPessoasP3);
            }
            
            else if(filas.qntPessoasP4 != 0){
                printPessoa(filas.filaP4[0]);

                filas.filaP4=removeFila(filas.filaP4, &filas.qntPessoasP4);
            }

        }


        qnt_act--;
    }
    return 0;
}

