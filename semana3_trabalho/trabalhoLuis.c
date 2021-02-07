#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
    char nome[30];
    int matricula;
    float N1;
    float N2;
    float N3;
    float N4;
    float media;
} Aluno;

Aluno *aluno;

void imprimeMenu();
void limpaTela();
void imprimeTelaFinal();

int main(void){

    int opcao;
    int tam=0;

    setlocale(LC_ALL,"");

    aluno = (Aluno*) malloc(sizeof(Aluno));
    
    do{

        imprimeMenu();
        scanf("%d",&opcao);

        switch (opcao){
        case 1:
            limpaTela();
            fflush(stdin);
            aluno= (Aluno*) realloc(aluno, (sizeof(Aluno) * (tam+1)));
            printf("\nDigite o nome: ");
            scanf("%s",aluno[tam].nome);
            printf("\nDigite a matricula: ");
            scanf("%d",&aluno[tam].matricula);
            printf("\nDigite a primeira nota: ");
            scanf("%f",&(aluno[tam].N1));
            printf("\nDigite a segunda nota: ");
            scanf("%f",&(aluno[tam].N2));
            printf("\nDigite a terceira nota: ");
            scanf("%f",&(aluno[tam].N3));
            printf("\nDigite a quarta nota: ");
            scanf("%f",&(aluno[tam].N4));
            aluno[tam].media = (aluno[tam].N1 + aluno[tam].N2 + aluno[tam].N3 + aluno[tam].N4) / 4;
            tam++;
            break;
        case 2:
            for (int i = 0; i < (tam); i++){
                printf("\n\tnome: %s\tMatricula: %d\tN1: %.2f\tN2: %.2f\tN3: %.2f\tN4: %.2f\tmedia: %.2f",aluno->nome,aluno->matricula,aluno->N1,aluno->N2,aluno->N3,aluno->N4,aluno->media);
                *aluno++;
            }
            
            break;
        case 3:
            
            break;
        
        default:
            break;
        }

    }while(opcao != 4);

    return 0;
}

void imprimeMenu(){
    limpaTela();
    printf("\n\t1 - Novo registro\n");
    printf("\t2 - Salvar todos no arquivo.txt\n");
    printf("\t3 - Pesquisar nome de aluno\n");
    printf("\t4 - Sair\n");
    printf("Opção: \n\n");
}

void imprimeTelaFinal(){
    limpaTela();
    printf("\n\nEncerrando programa......\n\n");
}

void limpaTela(){
    system("clear || cls");
}