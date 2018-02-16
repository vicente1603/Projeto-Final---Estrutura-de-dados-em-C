#include <string.h>
#include <stdio.h>
#include <locale.h>
#define MAX 5


typedef struct Dados{

    char cpf[12];
    char nome[40];
        char idade[3];
}cdado;

typedef struct fila{
    int inicio, final, quantidade;
    cdado Cadastro[MAX];
}Fila;

void iniciar(Fila *f){
    f->inicio=0;
    f->final=-1;
    f->quantidade=0;
}

int estacheia(Fila *f){
    if(f->quantidade==MAX){
        return 1;
    }else{
        return 0;
    }
}

int estavazia(Fila *f){
    if(f->quantidade==0){
        return 1;
    }else{
        return 0;
    }
}

int inserir(Fila *f, cdado e){
    if(estacheia(f)){
        return 0;
    }else{
        f->final++;
        f->Cadastro[f->final]= e;
        f->quantidade++;
        return 1;
    }
}

int remover(Fila *f, cdado *e){
    if(estavazia(f)){
        return 0;
    }else{
        *e=f->Cadastro[f->inicio];
        f->inicio ++;
        f->quantidade--;
        return 1;
    }
}

int  buscacpf(Fila f, char cpf []){
    while(f.final>=f.inicio){
        if(strcmp(cpf, f.Cadastro[f.inicio].cpf)==0){
            printf("CPF Encontrado:  %s \n", f.Cadastro[f.inicio].cpf);
            printf("Nome:  %s \n", f.Cadastro[f.inicio].nome);
            printf("Posicao: %d \n", f.inicio+1);
            break;
            return 1;
        }
        f.inicio++;
    }
}

cdado inicial(Fila f){
    if(f.final>-1){
        return f.Cadastro[f.inicio];
    }
}

int menu(){
    int opcao;
    printf("\t\tCadastro de Pacientes\n");
    printf("1- Adicionar paciente\n");
    printf("2- Atender o paciente\n");
    printf("3- Verificar próximo\n");
    printf("4- Verificar posição do paciente por CPF \n");
    printf("0- Sair\n");
    printf("Opcão: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    setlocale(LC_ALL, "Portuguese");



    Fila minhaClinica;
    Fila preferencial;
    cdado consulta;
    int op;
    iniciar(&minhaClinica);
    iniciar(&preferencial);
    int tipo,x,pref = 2;

do{
        printf("\n_______________________________________________________________________________\n");
       printf("|\tClinica de Urgencia WVA!\t\t\t      |\n");
       printf("|\tDesenvolvedores:\n");
       printf("|\tALEF LANIEL DOS SANTOS OLIVEIRA             |\n");
       printf("|\tVICENTE JOSE SANTIAGO COSTA OLIVEIR\n");
       printf("|\tWANDER AQUINO DA COSTA  |\n");
       printf("|\tCurso: SISTEMAS DE INFORMAÇÃO - São Cristóvão  \t\t      |\n");
       printf("|\tESTRUTURA DE DADOS I   |\n");
    op=menu();
        switch(op){
        case 1:

            printf("\t\t----------Dados dos Pacientes----------\n");
            printf("Entre com o Nome, CPF e a Idade: \n");
            fflush(stdin);
            printf("Nome: ");
            gets(consulta.nome);
            printf("CPF: ");
            gets(consulta.cpf);
            printf("Idade: ");
            gets(consulta.idade);
            x = atoi(consulta.idade);
            if ( x >= 60  )
			{
            	tipo = 1;
			}
            else
            {
            	tipo = 2;
			}
            if(tipo == 1)
            {
             if(inserir(&preferencial, consulta)){
                printf("Paciente preferencial cadastrado: %s \n", consulta.nome);
            }else{
                printf("Fila esta cheia! \n");
            }
			}
			else
			{
            if(inserir(&minhaClinica, consulta)){
                printf("Paciente  cadastrado: %s \n", consulta.nome);
            }else{
                printf("Fila esta cheia! \n");
            }
            }
            break;

        case 2:

			if(estavazia(&minhaClinica))
			{
			pref= 2;
			}

            if((remover(&preferencial, &consulta))&&(pref >= 1)){
                printf("Paciente preferencial  Atendido: %s \n", consulta.nome);
                printf("Com CPF: %s \n", consulta.cpf);
                pref-=1;
            }
			else if(remover(&minhaClinica, &consulta))
			  {
                printf("Paciente Atendido: %s \n", consulta.nome);
                printf("Com CPF: %s \n", consulta.cpf);
                pref = 2;
              }
              else
              {

           		printf("fila vazia");

			  }



            break;

        case 3:

            printf("-------------Proximo Paciente a ser Atendido-------------\n");

            if(!(estavazia(&preferencial)) && (pref >= 1))

			{

            	consulta=inicial(preferencial);
                printf("Proximo Paciente : %s \nFila preferencial\n", consulta.nome);
                printf("CPF: %s \n", consulta.cpf);

            }
			else if(!(estavazia(&minhaClinica)))
			  {

			  	consulta=inicial(minhaClinica);
                printf("Proximo  Paciente:  %s \nFila comum\n", consulta.nome);
                printf("CPF: %s \n", consulta.cpf);
                pref = 2;
              }
              else
              {

           		printf("fila vazia");
           	  }



            break;

        case 4:

            printf("----------Digite o CPF----------\n");
            char cpf[12];
            fflush(stdin);
            gets(cpf);

            if (buscacpf(preferencial, cpf) && (pref >=1) && (preferencial.inicio>-1))
            {
            	printf ("Fila Preferencial  \n");

			}
			else
			{
			  if (buscacpf(minhaClinica, cpf) && (minhaClinica.inicio>-1))
			{
				printf ("Fila comum  \n");

			}
			else
			{
				printf("nao localizado");
			}
		    }
            break;

        case 0:
            printf("Saindo.... Para sair presione uma tecla");
            break;

        default: printf("comando invalido! \n");
        }
    getch();
system("cls");
}while(op!=0);


}
