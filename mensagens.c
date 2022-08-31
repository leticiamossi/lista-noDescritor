#include <stdio.h>
#include <stdlib.h>
#include "ponte.h"

void menu()
{
    printf("   -------------------------------------------\n");
    printf("   |       Aluna: Leticia Mossi Cardoso      |\n");
    printf("   |       3 fase - CC - Clayton Zambon      |\n");
    printf("   -------------------------------------------\n");
    printf("   |        Lista Dinamica Encadeada         |\n");
    printf("   -------------------------------------------\n");
    printf("   |                                         |\n");
    printf("   |   1 - Inserir Elemento no Inicio        |\n");
    printf("   |   2 - Inserir Elemento no Final         |\n");
    printf("   |   3 - Inserir Elemento Ordenado         |\n");
    printf("   |   4 - Remover Elemento Inicio           |\n");
    printf("   |   5 - Remover Elemento no Final         |\n");
    printf("   |   6 - Remover Elemento pela Matricula   |\n");
    printf("   |   7 - Consultar Elemento Pela Posicao   |\n");
    printf("   |   8 - Consultar Elemento Pela Matricula |\n");
    printf("   |   9 - Exibir Lista                      |\n");
    printf("   |   10 - Exibir Tamanho da Lista          |\n");
    printf("   |   11 - Sair                             |\n");
    printf("   |                                         |\n");
    printf("   -------------------------------------------\n");
}

void vazio(){
    printf("\nA lista esta vazia.\n\n");
    system("pause");
}

void inexistente(){
    printf("\nA lista informada nao existe.\n\n");
    system("pause");
}

void invalido(){
    printf("\nNumero Invalido. Tente outro numero.\n\n");
    system("pause");
}

void erro_memoria(){
    printf("\nMemoria insuficiente.\n\n");
    system("pause");
}

void sucesso(){
    printf("\nAluno inserido com sucesso.\n\n");
    system("pause");
}

void removido(){
    printf("\nAluno removido com sucesso.\n\n");
    system("pause");
}

void nao_encontrado(){
    printf("\nNumero nao encontrado. Tente outro numero.\n\n");
    system("pause");
}

void adeus()
{
    printf("\n            Tchau.\n");
    printf("           Ate Logo!\n");
    printf("     ()_() /\n");
    printf("     (^-^)\n");
    printf("     (___)~\n\n\n");

}

