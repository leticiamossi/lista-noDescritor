#include <stdio.h>
#include <stdlib.h>
#include "ponte.h"

int main()
{
    Lista* li = cria_lista();
    struct aluno dados_alunos;
    int opcao, aux;

    while(opcao!=11){
        system("cls");
        menu();
        seleciona(&opcao);
        switch(opcao){
            case 1:
                insere_inicio(li, dados_alunos);
                break;
            case 2:
                insere_final(li, dados_alunos);
                break;
            case 3:
                insere_ordenado(li, dados_alunos);
                break;
            case 4:
                remove_inicio(li);
                break;
            case 5:
                remove_final(li);
                break;
            case 6:
                remove_mat(li, aux);
                break;
            case 7:
                consulta_pos(li, aux, &dados_alunos);
                break;
            case 8:
                consulta_mat(li, aux, &dados_alunos);
                break;
            case 9:
                imprime_lista(li);
                break;
            case 10:
                tamanho_lista(li);
                break;
            case 11:
                adeus();
                break;
            default:
                invalido();
                break;
        }
    }

    return 0;
}
