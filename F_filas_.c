

/************************************************************
*            Eric Rodrigues das Chagas                      *
*    [ICMC - Bacharelado em Ciências da Computação - 2021]  *
*    NºUSP: 12623971                                        *
* ||----------------------Contatos----------------------||  *
*            Telegram [ @EricRC_123 ]                       *
*            Email  [ eric.r.c@usp.br ]                     *
*************************************************************/



#include "F_filas_.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




dadosPessoa *addFila(dadosPessoa *pessoaDestino, dadosPessoa pessoaGenerica, int *qntPessoas)
{
    int qntPessoasF = *qntPessoas;
    qntPessoasF++;

    if(qntPessoasF == 1){
        pessoaDestino=malloc( (qntPessoasF+1)*sizeof(dadosPessoa) );
    }
    else{
        pessoaDestino=realloc(pessoaDestino, (qntPessoasF+1)*sizeof(dadosPessoa));
    }


    *qntPessoas=qntPessoasF;
    
    pessoaDestino[qntPessoasF-1]=pessoaGenerica;
    return pessoaDestino;
}

int encontPrioridade(dadosPessoa pessoa, int prioridade)
{
    //Definir se é idosa
    if(pessoa.idade >= 60) pessoa.idosa=1;
    else pessoa.idosa = 0;


    //Encontrar prioridade
    if(pessoa.idosa == 1 && pessoa.condicao == 1){
        prioridade = 1;
    }

    else if(pessoa.condicao == 1){
        prioridade = 2;
    }

    else if (pessoa.idosa == 1){
        prioridade = 3;
    }

    else{
        prioridade = 4;
    }

    return prioridade;
}

void printPessoa(dadosPessoa pessoa){

    printf("%s %d %d\n",
        pessoa.nome,
        pessoa.idade, 
        pessoa.condicao);
    //printf("Prioridade: %i\n\n",prioridade);
}

dadosPessoa *removeFila(dadosPessoa *fila, int *qntPessoas){

    int qntP= *qntPessoas;
    
    for(int i=0; i < qntP; i++){

        fila[i]=fila[i+1];

    }
    qntP--;
    
    fila=realloc(fila, qntP*sizeof(dadosPessoa));

    *qntPessoas=qntP;
    return fila;
}


