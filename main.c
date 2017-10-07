//Programa de cadastro de Disciplinas: Cadastro de disciplinas (Nome, Código, Professor, Sala), Busca por Nome, Sala e Professor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplina{
    char nome[50];
    int codigo;
    int sala;
    char professor[20];

}Disciplina;

void adDisciplina(Disciplina *, char *, int, int, char *);
void listDisciplina(Disciplina *, int);
void copiastring(char *, char *, int);
void procNome(Disciplina *, char *);
void procProfessor(Disciplina *, char *);
void procSala(Disciplina *, int * );
int comparar(char *, char * );


int main(){

    Disciplina vetDisc[100];
    int qtd,i, codigo, a, sala;
    char  nome[50], professor[20];

    do{
        printf("\nCADASTRO DE DISCIPLINA\n\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("1 - Adcionar Disciplina\n");
        printf("2 - Listar Disciplina\n");
        printf("3 - Procurar por Disciplina\n");
        printf("4 - Procurar por Sala\n");
        printf("5 - Procurar por professor\n");
        printf("6 - Sair\n");
        scanf("%d",&a);

        switch(a){
        case(1):
            printf("VOCE ESCOLHEU ADCIONAR DISCIPLINA\n\n");
            printf("Diga quantas discipinas voce quer criar: ");
            scanf("%d", &qtd);

            for(i=0;i<qtd;i++){

                printf("Digite o nome da disciplina:\n ");
                scanf(" %[^\n]", nome);
                printf("Digite o codigo: \n");
                scanf("%d", &codigo);
                printf("Digite a sala: \n");
                scanf("%d", &sala);
                printf("Digite o nome do professor:\n ");
                scanf("%s", professor);

                adDisciplina(vetDisc + i, nome, codigo, sala, professor);

            }

            break;

        case(2):
            listDisciplina(vetDisc, qtd);
            break;

        case(3):
            printf("Digite a disciplina a ser procurada:\n");
            scanf("%s", nome);

            procNome(vetDisc, nome);
            break;

        case(4):
            printf("Digite a sala a ser procurada:\n");
            scanf("%d", &sala);

            procSala(vetDisc, sala);
            break;

        case(5):
            printf("Digite o nome do professor a ser procurado:\n");
            scanf("%s", professor);

            procProfessor(vetDisc, professor);
            break;

        case(6):
            break;
           default: printf("\nTENTE NOVAMENTE\n");
        }

    }while(a!=6);

}


void adDisciplina(Disciplina * x, char *nome, int codigo, int sala, char *professor){
    copiastring(x->nome, nome, 50);
    x->codigo = codigo;
    x->sala = sala;
    copiastring(x->professor, professor, 20);
}

void listDisciplina(Disciplina *vet, int qtd){
    int i;
    for(i=0;i<qtd;i++){

        printf("Nome: %s\n",(vet+i)->nome);
        printf("Codigo: %d\n", (vet+i)->codigo);
        printf("Sala: %d\n", (vet+i)->sala);
        printf("Professor: %s\n", (vet+i)->professor);
        printf("\n******************************\n\n");
    }
}

void copiastring(char *str1, char *str2, int num){
    int i;
    for(i=0;i<num;i++){
        str1[i] = str2[i];
    }
}

int comparar(char * str1, char * str2){
    int cont = 0;
    int i = 0;
    if(strlen(str1) == strlen(str2)){  // compara os tamanhos da string
        while ((str1[i] != '\0') && (str2[i] != '\0')){  // enquanto a posição da string for diferente de \0
            if(str1[i] != str2[i]){  //ferifica se a letra da string é diferente da outra na mesma posiçao
                return 0;
            } else {
                cont++;
            }
            i++;
        }
        if (cont == strlen(str1)) { //confere se o cont é igual o tamanho da string
            return 1;
        }
    }
    return 0;
}


void procProfessor(Disciplina *vet, char *professor){
    int i;
    for(i=0; i < (sizeof(vet)); i++){
        if(comparar((vet + i)->professor, professor) == 1){
            printf("Nome: %s\n",(vet+i)->nome);
            printf("Codigo: %d\n", (vet+i)->codigo);
            printf("Sala: %d\n", (vet+i)->sala);
            printf("Professor: %s\n", (vet+i)->professor);
            printf("\n******************************\n");
        }
    }

}

void procSala(Disciplina *vet, int *sala){
    int i;
    for(i=0; i< (sizeof(vet)); i++){
        if(vet[i].sala == sala){
            printf("Nome: %s\n",(vet+i)->nome);
            printf("Codigo: %d\n", (vet+i)->codigo);
            printf("Sala: %d\n", (vet+i)->sala);
            printf("Professor: %s\n", (vet+i)->professor);
            printf("\n******************************\n");
        }
    }

}

void procNome(Disciplina *vet, char *nome){
    int i;
    for(i=0; i < (sizeof(vet)); i++){
        if(comparar((vet + i)-> nome, nome) == 1) {
            printf("Nome: %s\n",(vet+i)->nome);
            printf("Codigo: %d\n", (vet+i)->codigo);
            printf("Sala: %d\n", (vet+i)->sala);
            printf("Professor: %s\n", (vet+i)->professor);
            printf("\n******************************\n");
        }
    }

}
