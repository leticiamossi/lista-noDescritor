struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct descritor Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int verifica_lista(Lista* li);
int seleciona(int *opcao);
int matricular(struct aluno *dados_aluno);
void pergunta_mat(int *mat);
void pergunta_pos(int *pos);
int insere_inicio(Lista* li, struct aluno al);
int insere_final(Lista* li, struct aluno al);
int insere_ordenado(Lista* li, struct aluno al);
int remove_inicio(Lista* li);
int remove_final(Lista* li);
int remove_mat(Lista* li, int mat);
void imprime_consulta(struct aluno *al);
int consulta_pos(Lista* li, int pos, struct aluno *al);
int consulta_mat(Lista* li, int mat, struct aluno *al);
int imprime_lista(Lista* li);
int tamanho_lista(Lista* li);
