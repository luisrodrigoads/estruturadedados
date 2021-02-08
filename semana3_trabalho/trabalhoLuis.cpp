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
int tam=0;
FILE *file;

void imprimeMenu();
void limpaTela();
void imprimeTelaFinal();

void procuraAluno();
void leituraInicialArquivo();
void adicionaNovoValor();
void salvarDadosNoArquivo();

int main(void){

    int opcao;
    
    setlocale(LC_ALL,"");

    aluno = (Aluno*) malloc(sizeof(Aluno));
    
    leituraInicialArquivo();
    
    do{

        imprimeMenu();
        scanf("%d",&opcao);

        switch (opcao){
        case 1:
            adicionaNovoValor();
            break;
        case 2:
            salvarDadosNoArquivo();
            printf("\nPara voltar digite 1\n");
            scanf("%d",&opcao);
            if(opcao == 1)
            break;
        case 3:
        	procuraAluno();
        	printf("\nPara voltar digite 1\n");
            scanf("%d",&opcao);
            if(opcao == 1)
        	break;
        
        default:
            break;
        }

    }while(opcao != 4);

    return 0;
}

void imprimeMenu(){
    limpaTela();
    printf("\n1 - Novo registro\n");
    printf("2 - Salvar todos no arquivo.txt\n");
    printf("3 - Pesquisar nome de aluno\n");
    printf("4 - Sair\n");
    printf("Opção: \n");
}

void imprimeTelaFinal(){
    limpaTela();
    printf("\n\nEncerrando programa......\n\n");
}

void limpaTela(){
    system("clear || cls");
}

void procuraAluno(){
	char nomeAluno[30];
	int encontrou=0;
	limpaTela();
	printf("\nDigite o nome do aluno: ");
	scanf("%s",nomeAluno);
	
	for(int x = 0;x < (tam); x++){
		if((strcmp(aluno->nome,nomeAluno) == 0) && (encontrou < 1)){
			printf("\n\tnome: %s\tMatricula: %d\tN1: %.2f\tN2: %.2f\tN3: %.2f\tN4: %.2f\tmedia: %.2f",aluno->nome,aluno->matricula,aluno->N1,aluno->N2,aluno->N3,aluno->N4,aluno->media);
			encontrou++;
		}
		*(aluno)++;
	}
	
	if(encontrou == 0){
		printf("\nNão encontramos ninguém com esse nome");
	}
	
}

void leituraInicialArquivo(){
		
	if((file = fopen("arquivo.txt","r")) != NULL){
		
		while(!feof(file)){
			aluno = (Aluno*) realloc(aluno, (sizeof(Aluno) * (tam+1)));
			fscanf(file,"%s %d %f %f %f %f %f",aluno[tam].nome,&aluno[tam].matricula,&(aluno[tam].N1),&(aluno[tam].N2),&(aluno[tam].N3),&(aluno[tam].N4),&(aluno[tam].media));
			tam++;
		}
		fclose(file);
	}
	
}

void adicionaNovoValor(){
	
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
}

void salvarDadosNoArquivo(){
	
	limpaTela();
	printf("\nAbrindo arquivo....");
	
	file = fopen("arquivo.txt","w+");
	
	for(int i = 0;i < (tam); i++){
	
		fprintf(file,"%s %d %f %f %f %f %f\n",aluno->nome,aluno->matricula,aluno->N1,aluno->N2,aluno->N3,aluno->N4,aluno->media);
			
		*(aluno)++;
	}
	fclose(file);
	printf("\nDados salvos no arquivo");
}
