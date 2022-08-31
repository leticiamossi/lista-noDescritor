#include <stdio.h>
#include <stdlib.h>
#include "ponte.h"

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct descritor {
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
};

Lista* cria_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
        li->qtd = 0;
    }else{
        erro_memoria();
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int verifica_lista(Lista* li){
    if(li == NULL){
        inexistente();
        return 1;
    }
    if(li->inicio == NULL){
        vazio();
        return 1;
    }
    return 0;

}

int seleciona(int *opcao){
    printf("\nEscolha a opcao desejada: ");
    scanf("%d", opcao);
    return opcao;
}

int matricular(struct aluno *dados_aluno){
    printf("\nDigite a matricula: ");
    scanf("%d", &dados_aluno->matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", &dados_aluno->nome);
    printf("Digite a primeira nota: ");
    scanf("%f", &dados_aluno->n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &dados_aluno->n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &dados_aluno->n3);
    return dados_aluno;
}

void pergunta_mat(int *mat){
    printf("\nInforme a matricula: ");
    scanf("%d", mat);
}

void pergunta_pos(int *pos){
    printf("\nInforme a posicao: ");
    scanf("%d", pos);
}

int insere_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        inexistente();
        return 0;
    }
    matricular(&al);
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        erro_memoria();
        return 0;
    }
    no->dados = al;
    no->prox = li->inicio;
    if(li->inicio  == NULL){
        li->fim = no;
    }
    li->inicio = no;
    li->qtd++;
    sucesso();
    return 1;
}

int insere_final(Lista* li, struct aluno al){
    if(li == NULL){
        inexistente();
        return 0;
    }
    matricular(&al);
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        erro_memoria();
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if(li->inicio == NULL){
        li->inicio = no;
    }else{
        li->fim->prox = no;
    }
    li->fim = no;
    li->qtd++;
    sucesso();
    return 1;
}

int insere_ordenado(Lista* li, struct aluno al){
    if(li == NULL){
        inexistente();
        return 0;
    }
    matricular(&al);
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        erro_memoria();
        return 0;
    }
    no->dados = al;
    if(li->inicio == NULL){
        no->prox = NULL;
        li->inicio = no;
        li->fim = no;
        li->qtd++;
        sucesso();
        return 1;
    }else{
        Elem *ant, *atual = li->inicio;
        while(atual != NULL && atual->dados.matricula>al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == li->inicio){
            no->prox = li->inicio;
            li->inicio = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        sucesso();
        return 1;
    }
}

int remove_inicio(Lista* li){
    if(verifica_lista(li)){
        return 0;
    }
    Elem* no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(li->inicio == NULL){
        li->fim = NULL;
    }
    li->qtd--;
    removido();
    return 1;
}

int remove_final(Lista* li){
    if(verifica_lista(li)){
        return 0;
    }
    Elem *ant, *no = li->inicio;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio){ //remove do inicio
        li->inicio = NULL;
        li->fim = NULL;
    }else{
        ant->prox = no->prox;
        li->fim = ant;
    }
    free(no);
    li->qtd--;
    removido();
    return 1;
}

int remove_mat(Lista* li, int mat){
    if(verifica_lista(li)){
        return 0;
    }
    pergunta_mat(&mat);
    Elem *ant, *no = li->inicio;
    while(no->prox != NULL && no->dados.matricula != mat){
        ant = no;
        no =  no->prox;
    }
    if(no == NULL){
        nao_encontrado();
        return 0;
    }
    if(no == li->inicio){
        li->inicio = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    removido();
    return 1;
}

void imprime_consulta(struct aluno *al){
    printf("-----------------------------------\n");
    printf("Matricula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("Notas: %.1f %.1f %.1f\n", al->n1,
                                      al->n2,
                                      al->n3);
    printf("-----------------------------------\n\n");
    system("pause");
}

int consulta_pos(Lista* li, int pos, struct aluno *al){
    if(verifica_lista(li)){
        return 0;
    }
    pergunta_pos(&pos);
    if(pos<=0){
        invalido();
        pergunta_pos(&pos);
    }
    Elem* no = li->inicio;
    int i=1;
    while(no != NULL && i<pos){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        nao_encontrado();
        return 0;
    }else{
        *al = no->dados;
        imprime_consulta(al);
        return 1;
    }
}

int consulta_mat(Lista* li, int mat, struct aluno *al){
    if(verifica_lista(li)){
        return 0;
    }
    pergunta_mat(&mat);
    if(mat<=0){
        invalido();
        pergunta_mat(&mat);
    }
    Elem* no = li->inicio;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        nao_encontrado();
        return 0;
    }else{
        *al = no->dados;
        imprime_consulta(al);
        return 1;
    }
}

int imprime_lista(Lista* li){
    if(verifica_lista(li)){
        return 0;
    }
    Elem* no = li->inicio;
    while(no != NULL){
        printf("\nMatricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.1f %.1f %.1f\n", no->dados.n1,
                                        no->dados.n2,
                                        no->dados.n3);
        printf("-----------------------------------\n");

        no = no->prox;
    }
    system("pause");
}

int tamanho_lista(Lista* li){
    verifica_lista(li);
    printf("\nTamanho da lista: %d\n\n\n", li->qtd);
    system("pause");
}
