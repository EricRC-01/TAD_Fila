



#ifndef F_filas_h

#define F_filas_h

#endif 




typedef struct{

    int idade;
    char nome[40];

    // 1 = verdadeiro 0 = falso
    int idosa;
    // 1 = Agravante, 0 = Não agravante
    int condicao;

}dadosPessoa;

typedef struct{

    dadosPessoa *filaP1;
    int qntPessoasP1;

    dadosPessoa *filaP2;
    int qntPessoasP2;

    dadosPessoa *filaP3;
    int qntPessoasP3;

    dadosPessoa *filaP4;
    int qntPessoasP4;


    int qntTotalPessoas;

}dadosFilas;


dadosPessoa *addFila(dadosPessoa *pessoaDestino, dadosPessoa pessoaGenerica, int *qntPessoas);

dadosPessoa *removeFila(dadosPessoa *fila, int *qntPessoas);

int encontPrioridade(dadosPessoa pessoa, int prioridade);

void printPessoa(dadosPessoa pessoa);



