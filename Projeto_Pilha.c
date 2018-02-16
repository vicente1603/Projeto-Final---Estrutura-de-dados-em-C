#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct retorno {
int f, p;
};

struct retorno *func( char lt[] ) {
    int tipo;
	static struct retorno r[1];
    tipo = lt[0]-48;
	switch (tipo){

			case 1:
					//#isopor
					//#maximo empilhamento  50 kg
					//#peso por lote        10 kg
				r->f =  50;
				r->p  = 10;
				printf("Lote de isopor ");
			  	return r;
			case 2:
					//#madeira
					//#maximo empilhamento  100 kg
					//#peso por lote        20 kg
					r->f =  100;
				    r->p  = 20;
    				printf("lote de madeira");
					return r ;

			case 3:
					//#plastico
					//#maximo empilhamento  125 kg
					//#peso por lote        25 kg
					r->f =  120;
				    r->p  = 25;
				    printf("lote de plastico");
				return r ;


            case 4:
            	   //#metal
            	   //#maximo empilhamento  1000 kg
				   //#peso por lote        200 kg
				r->f =  1000;
				r->p  = 200;
				printf("lote de metal");
				return r ;




			default:return r ;
		}


}
struct Pilha {

	int topo;
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )

      return 1;

   else

      return 0;

}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capa - 1)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){

   return p->pElem [p->topo];

}

float proxpilha ( struct Pilha *p){

    return p->pElem [p->topo-1];

}
main()
{
    setlocale(LC_ALL, "Portuguese");

	char lote[80];
	int fp[80],pp[80],x,peso,frag;
	struct Pilha minhapilha;
	int capacidade, op;
    int valor,y;
    x=0;
    printf("\n***************************** Transporte de materiais **************************\n\n\n\n");

    printf("\nAlunos: Vicente José Santiago, Wander Aquino da Costa e Alef Laniel.\n");


	capacidade = 10;
	criarpilha (&minhapilha, capacidade);

	while( 1 ){

        printf("\n********************************************************************************\n");
        printf("O primeiro digito do lote inserido identifica o tipo do material.\n");
		printf("\n1- Adicionar lote a ser transportado\n");
		printf("2- Despachar lote já transportado\n");
		printf("3- Mostrar o lote atual a ser despachado \n");
		printf("4- Mostrar próximo lote a ser despachado \n");
        printf("5- Tipos e caracteristicas dos materiais\n");
		printf("6- Sair\n");
		printf("\nOpcão? ");
		scanf("%d", &op);
		printf("\n*********************************************************");

		switch (op){

			case 1:

				if( estacheia( &minhapilha ) == 1 )
				{

                    system("cls");
					printf("\nNão é possivel adicionar mais lotes - A capacidade total foi atingida.\n");
                    getch();
                }
				else {
					 system("cls");
					 printf("\nPor favor informe o lote do produto a ser inserido:");
					 scanf("%d", &valor);
					 sprintf(lote, "%i", valor);
					 y=lote[0]-48;
					 struct retorno *rr = func(lote);

					 if ((y>0)&&(y<=4))
					 {

   					 if(estavazia(&minhapilha) == 1)
					 {

						fp[x] = rr->f;
					 	pp[x] = rr->p;
					 	empilhar (&minhapilha, valor);
					 	printf(" numero %d adicionado com sucesso!\n", valor);
					 	printf("Peso do lote %d kg \nPeso que pode ser adicionado a pilha: %d kg \n", rr->p, rr->f );
					 	printf("Peso total de pilha  %d\n",pp[x]);

					 }
					 else
					 {
					       peso = rr->p ;
					       frag = rr->f;
							if (fp[x] >=  peso )
							{
							    if (fp[x] >  frag )
						     	{
						        x+=1;
								fp[x]=frag;
							    pp[x]=pp[x-1]+peso;
								empilhar (&minhapilha, valor);
								printf(" numero %d adicionado com sucesso!\n", valor);
								printf("Peso do lote %d kg \nPeso que pode ser adicionado a pilha: %d kg \n", rr->p, rr->f );
					 	        printf("Peso total de pilha  %d\n", pp[x]);
                    			}
                    			else
                    			{
                    			x+=1;
                    			fp[x]=fp[x-1]-peso;
							    pp[x]=pp[x-1]+peso;
								empilhar (&minhapilha, valor);
								printf(" numero %d adicionado com sucesso!\n", valor);
							    printf("Peso do lote %d kg \nPeso que pode ser adicionado a pilha: %d kg \n", rr->p, rr->f );
					 	        printf("Peso restante em pilha %d - Peso total de pilha  %d\n",pp[x]);
								}
                			}
                			else
                			{
                					printf("\nNão é possivel adicionar lote -\n O peso do lote solicitado poderá causar danos aos produtos inseridos.\n");
							}


						}
				   }
				   else
				   {
				   	printf("lote invalido");
				   }

				   getch();
				   system("cls");
				}
				break;

			case 2:
				if ( estavazia(&minhapilha) == 1 )

					printf( "\nNão há nenhum lote a ser despachado. \n" );

				else{

					valor = desempilhar (&minhapilha);
					printf ( "\nLote %d  despachado com sucesso!\n", valor );
					x-=1;

				}
				break;

			case 3:
				if ( estavazia (&minhapilha) == 1 )

					printf( "\nNão há nenhum lote a ser despachado.\n" );

				else {

					valor = retornatopo (&minhapilha);
					printf ( "\nLote atual a ser despachado: %d\n", valor );


				}
				break;

            case 4:
                if ( estavazia(&minhapilha) == 1 )

					printf( "\nNão há nenhum lote a ser despachado.\n" );

				else {

					valor = proxpilha(&minhapilha);
					printf ( "\nPróximo lote a ser despachado : %d\n", valor );

				}
				break;

            case 5:
                printf("\nIsopor: Lotes começados por 1\n");
                printf("Peso por lote: 10kg - Máximo por empilhamento: 50kg\n");
                printf("____________________________________________________\n");
                printf("\Madeira: Lotes começados por 2\n");
                printf("Peso por lote: 20kg - Máximo por empilhamento: 100kg\n");
                printf("____________________________________________________\n");
                printf("\Plástico: Lotes começados por 3\n");
                printf("Peso por lote: 25kg - Máximo por empilhamento: 125kg\n");
                printf("____________________________________________________\n");
                printf("\Metal: Lotes começados por 4\n");
                printf("Peso por lote: 200kg - Máximo por empilhamento: 1000kg\n");
                printf("____________________________________________________\n");

                break;

			case 6:
				exit(0);

			default: printf( "\nOpção inválida! \n" );
		}

}
}
