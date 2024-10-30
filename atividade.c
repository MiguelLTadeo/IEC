#include <stdio.h>
#include <string.h>
#define MAXCONTACTS 10

int contacontatos = 0;

int totalcontatos = MAXCONTACTS;

typedef struct{

    char name[15];
    int number;

}Contatos;

Contatos contato[MAXCONTACTS];
void cadastrar();
void mostrarTodos();
void pesquisar();

int main(void){
    int op;
    do{
        printf("[1]cadastrar[2]mostrartodos[3]pesquisar[4]sair\n");
        scanf("%i", &op);
        switch(op){
            case 1:
            cadastrar();
            break;
            case 2:
            mostrarTodos();
            break;
            case 3:
            pesquisar();
            break;
            case 4:
            printf("Saindo...\n");
            break;
            default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }while(op!=4);
}
void cadastrar(){
    if(contacontatos == totalcontatos){
        printf("limite de contatos atingido\n");
    }
    else{
        printf("nome?\n");
        scanf("%s", contato[contacontatos].name);
        printf("numero?\n");
        scanf("%i", &contato[contacontatos].number);
        contacontatos++;
    }
}
void mostrarTodos(){
    if(contacontatos == 0){
        printf("nenhum contato existente.\n");
    }
    else{
        for(int i = 0; i < contacontatos; i++){
            printf("contato %i\n", i+1);
            printf("%s", contato[i].name);
            printf("\n");
            printf("%i", contato[i].number);
            printf("\n");
        }
    }
}
void pesquisar(){
    char pesquisa[15];
    int encontrado;
    if(contacontatos == 0){
        printf("nenhum contato existente.\n");
    }
    else{
        printf("Nome a pesquisar? ");
        scanf("%s", pesquisa); 
        
        for (int i = 0; i < contacontatos; i++) {
            if (strcmp(contato[i].name, pesquisa) == 0) {
                printf("Nome: %s\n", contato[i].name);
                printf("Número: %i\n", contato[i].number);
                encontrado = 1; 
                break; 
            }
        }

        if (!encontrado) {
            printf("Contato não encontrado.\n");
        }
    }
}
