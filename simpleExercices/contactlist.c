#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
   int maxValue;
   int minValue;
   char nameMin[50];
   char nameMax[50];
} ValuesFiltred;

/*
Function initFiltredVariable is used to init with default values 
the struct of filtred values how max and min age for example.
*/
ValuesFiltred initFiltredVariable(ValuesFiltred initialFiltredValue);

/*
Function initPersonVariable is used to init with default values
the array of persons.
*/
Person * initPersonVariables(Person initialPersonValues[]);

/*
Function agePersonFiltred is used to select the person with max age and
other with age.
*/
ValuesFiltred agePersonFiltred(int ageValue,char nameValue[], ValuesFiltred basicValue);

/*
Function printMinAndMaxValues is used to show result of the filter functions.
*/
void printMinAndMaxValues(ValuesFiltred basicValue);

/*
Function printMainMenu is used to show main menu program options.
*/
void printMainMenu();

/*
Function printAllList is used to show list with all person and yours values.
*/
void printAllList(Person valuesList[]);

/*
Function printEndScreen is used to show the last screen of program.
*/
void printEndScreen();

/* 
Function cleanScreen is used,how your name say, for clear screen.
*/
void cleanScreen();

/*
Function foward, is used to user return to main page of program.
 */
bool foward();

int main(void){

    Person personList[4];
    initPersonVariables(personList);

    ValuesFiltred valuesFiltred;
    valuesFiltred = initFiltredVariable(valuesFiltred);

    int option;

    do{

        printMainMenu();
        scanf("%d",&option);

        switch (option)
        {
        case 1:          
            for(int i=0;i<4;i++){
                cleanScreen();
                printf("*****************\n");
                printf("[%d] digite o nome: \n",i+1);
                scanf(" %s",personList[i].name);
                printf("[%d] digite a idade: \n",i+1);
                scanf("%d",&personList[i].age);
                fflush(stdin);
                valuesFiltred = agePersonFiltred(personList[i].age, personList[i].name,valuesFiltred);
            }
            break;
        case 2:
            printMinAndMaxValues(valuesFiltred);
            if(foward() || !foward())
                break;      
        case 3:
            printAllList(personList);
            if(foward() || !foward())
                break;
        default:
            printEndScreen();
            break;
        }

    } while (option != 4);
    
    return 0;
}

Person * initPersonVariables(Person initialPersonValues[]){
    
    for (int a = 0; a < 4; a++)
    {   
        strcpy(initialPersonValues[a].name,"Sem valores");
        initialPersonValues[a].age = 0;
    }
    
    return initialPersonValues;
}

ValuesFiltred initFiltredVariable(ValuesFiltred initialFiltredValue){
    initialFiltredValue.maxValue = 0;
    initialFiltredValue.minValue = 0;
    strcpy(initialFiltredValue.nameMax,"Sem valores");
    strcpy(initialFiltredValue.nameMin,"Sem valores");

    return initialFiltredValue;
}

ValuesFiltred agePersonFiltred(int ageValue, char nameValue[],ValuesFiltred basicValue){

    if(ageValue > 0){
        if(ageValue > basicValue.maxValue){
            basicValue.maxValue = ageValue;
            strcpy(basicValue.nameMax,nameValue);
        }
        if(basicValue.minValue == 0){
            basicValue.minValue = ageValue;
            strcpy(basicValue.nameMin,nameValue);
        }else if(ageValue < basicValue.minValue){
            basicValue.minValue = ageValue;
            strcpy(basicValue.nameMin,nameValue);
        }
    }

  return basicValue;
}

void printMinAndMaxValues(ValuesFiltred basicValue){
    cleanScreen();
    printf("------------------------------------------");
    printf("\nMaior valor\tMenor Valor\n");
    printf("------------------------------------------");
    printf("\n%s\t\t%s",basicValue.nameMax,basicValue.nameMin);
    printf("\n%d\t\t%d\n\n",basicValue.maxValue,basicValue.minValue);

}

void printMainMenu(){

    cleanScreen();
    printf("\nSistema lista de contatos\n-----------------------------\n\n");
    printf("\t1 - Inserir dados\n");
    printf("\t2 - Mostrar maior e menor valor\n");
    printf("\t3 - Mostrar lista completa\n");
    printf("\t4 - Sair\n");
    printf("Opcao: \n\n");

}

void printAllList(Person valuesList[]){

    cleanScreen();
    for (int x = 0; x < 4; x++)
    {
        printf("\n------------------------------\n");
        printf("[%d] nome: %s \t idade : %d\n",x+1,valuesList[x].name,valuesList[x].age);
    }

}

void printEndScreen(){
    cleanScreen();
    printf("\n\nEncerrando programa......\n\n");
}

void cleanScreen(){
    system("clear || cls");
}

bool foward(){
    int optionUser;
    printf("\n\nVoltar [clique - 1]\n\n");
    scanf("%d",&optionUser);
    if(optionUser == 1)
        return true;
    else
        return false;    
}