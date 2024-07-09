// Nome:Cainã Jose de Arruda Pinto RA:210626
// Nome:Nelson Stropa Junior RA 211916


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <cmath>

typedef struct dicotomia {
	float coeficiente[10];
	float expoente[10];
	float intervalos[2];
	int termos;
	float erro;
}dicotomia; // estrutura para dicotomia

typedef struct lagrange {
	float pont_x[10];
	float pont_fx[10];
	int pont_tabela;
	float pont_inter;
	int opc;
}lagrange;  // esgtrutura para lagrange

//dicotomia
void aloca_dic(dicotomia **a,int x);
void informacoes(dicotomia *a);
void calculo(dicotomia *x);

// lagrange
void aloca_lag(lagrange **y,int u);
void info_lagrange(lagrange *y);
void calc_lag(lagrange *y);



 int main()
 {
	dicotomia *dic = NULL;
	lagrange *lag = NULL;
	
	aloca_dic(&dic,1);
	aloca_lag(&lag,1);
	
	int op,a;
 	do{ 
 		system("cls");
 		printf("\n\tMenu");
 		printf("\n\n[1] Dicotomia \n[2] Lagrange \n[3] Sair\n\n ");
 		scanf("%i",&op);
 		fflush(stdin);

 		switch(op){
 			case 1:
 			informacoes(dic);  // pegar informações sobre a tabela de dicotomia
 			calculo(dic);  // calcular a dicotomia
			break;	
							  			
 			case 2:
 			info_lagrange(lag);  // pegar informações sobre lagrange
 			calc_lag(lag);  // calcular lagrange
 			break;
					
 		}
	 }while(op!=3);
	system("cls");
	printf("\n\t\t Obrigado por utilizar a calculadora para metodos numericos!\n");
 }
 
 void calculo(dicotomia *x)  // calculo dicotomia
 {
 	int y=0,j;
 	float a,b,m,fa,fb,fm,it,aux,cj;
 	
 	a= *(x->intervalos);
 	b= *(x->intervalos+1);
 	
	it = ceil(log2((b-a) / x->erro));
	printf("\n\n ________________________________________________________________________________________________________________");
	printf("\n |i| \ta\t|\tm\t|\tb\t|\tfa\t|\tfm\t|\tfb\t|\t|b-a|\t|",a,m,b,fa,fm,fb,cj);
	printf("\n ________________________________________________________________________________________________________________");
	for(y=0;y<(it+1);y++)
	{
		m= ( a + b) / 2;
		fa=0;
		fm=0;
		fb=0;
		for(j=0;j<x->termos;j++)
		{

			aux= 0;
			aux= *(x->coeficiente+j) * pow(a,*(x->expoente+j));
			fa = fa + aux;
		
			aux= 0;
			aux= *(x->coeficiente+j) * pow(b,*(x->expoente+j));
			fb = fb + aux;
		
			aux= 0;
			aux= *(x->coeficiente+j) * pow(m,*(x->expoente+j));
			fm = fm + aux;
		}
		a = round(a * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		m = round(m * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		b = round(b * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		fa = round(fa * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		fm = round(fm * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		fb = round(fb * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		y = round(y * 1000.0) / 1000.0;  // arrendondamento para 3 casas decimais
		float cj = fmod(fabs(a - b), m);   // arrendondamento para cima para ser o numero de interações
		
		printf("\n |%i|\t%.3f\t|\t%.3f\t|\t%.3f\t|\t%.3f\t|\t%.3f\t|\t%.3f\t|\t%.3f\t|",y,a,m,b,fa,fm,fb,cj);
		
		if((fa * fm)< 0)
		{
			a = a;
		}
		else
		{
			a = m;
		}
		
		if((fb*fm)< 0)
		{
			b = b;
		}
		else
		{
			b = m;
		}
	}
	printf("\n ________________________________________________________________________________________________________________");
	printf("\n A raiz da funcao é %.3f com erro de %.3f \n",m,fm);
	printf("\n O numero de interacoes e %.3f \n\n",it);
	system("pause");
	
 }
 
 void informacoes(dicotomia *a)
 {
 	int i;
 	
 	
 	printf("\nDigite a quantidade de termos da equacao(max 10):\n");
 	scanf("%i",&a->termos);
  	fflush(stdin);

	for(i=0;i<a->termos;i++)
	{
	 	printf("\nDigite o coeficiente e o expoente:\n");
		scanf("%f %f",a->coeficiente+i,a->expoente+i);
        fflush(stdin);
    }

    printf("\nDigite os intervalos:\n");
 	scanf("%f %f",a->intervalos, a->intervalos+1);
  	fflush(stdin);
  	
  	printf("\nDigite o valor do erro(em decimais):\n");
 	scanf("%f",&a->erro);
  	fflush(stdin);
  	
  	// testes foram feitos para verificar se o valor esta realmente sendo guardado no lugar certo. Para que nao acha erro no momento do calculo!
 }
 
void aloca_dic(dicotomia **a,int x)
 {
	if((*a=(dicotomia*)realloc(*a,x*sizeof(dicotomia)))==NULL) // aqui estamos alocando um espaço na memoria para a estrutura de dicotomia.
  		exit(1);	
 }

void aloca_lag(lagrange **y,int u)
{
	if((*y=(lagrange*)realloc(*y,u*sizeof(lagrange)))==NULL) // aqui estamos alocando um espaço na memoria para a estrutura de lagrange.
		exit(1);
}

void info_lagrange(lagrange *y) // coletando informações para fazer o calculo de lagrange
{
	y->opc=0;
	int i ;
	printf("\nDigite o numero de pontos na tabela de x e f(x):\n ");
	scanf("%i", &y->pont_tabela);
//	printf("valor: %i\n", y->pont_tabela); //teste
	
	for (i = 0; i < y->pont_tabela; i++)
	{
	    printf("\nDigite o valor do ponto %d de x:\n ", i+1);
	    scanf("%f", y->pont_x+i);
//	    printf("valor: %f\n", *(y->pont_x+i)); //teste
	    getchar(); //limpa o buffer de entrada
	}
	
	for (i = 0; i < y->pont_tabela; i++)
	{
	    printf("\nDigite o valor do ponto %d de f(x):\n ", i+1);
	    scanf("%f", y->pont_fx+i);
//	    printf("valor: %f\n", *(y->pont_fx+i)); //teste
	    getchar(); //limpa o buffer de entrada
	}
	
	printf("\nDigite o valor do ponto a ser interpolado:\n ");
	scanf("%f", &y->pont_inter);
//	printf("valor: %f\n", y->pont_inter); //teste
	
	printf("\nInforme se o ponto a ser interpolado perdence a:\n [1] x\n [2] fx \n ");
	scanf("%i", &y->opc);
//	printf("valor: %i\n", y->opc); //teste

}


void calc_lag(lagrange *y)
{
	int i,j;
	float aux,cj,vt;
	vt = 0;
	
	if(y->opc == 1)  // aqui a verificação para saber se o ponto de interpolção pertende ao x
	{
		
		for(i=0;i<y->pont_tabela;i++) // aqui ja estramos no calculo
		{
			if(y->pont_inter == *(y->pont_x+i)) // um if para ver se o ponto de interpolação ja nao esta presente na tabela.
			{
				vt = *(y->pont_fx+i);
				break;
			}
			
			aux = 0;
			cj = 0;
			for(j=0;j<y->pont_tabela;j++) 
			{
				if(i!=j) // if para verficar se o i nao é igual o j. 
				{
					cj = (y->pont_inter - *(y->pont_x+j)) / (*(y->pont_x+i) - *(y->pont_x + j));
				}
				else
				{
					cj = 1;
				}
				
				if(aux == 0 ) //if para ver se caso estiver com 0 ele apenas ficar com o mesmo valor de cj
				{
					aux = cj;
				}
				else
				{
					aux = aux * cj; // else para continuar o calculo
				}
				
			}
			
				if(y->pont_inter == *(y->pont_x+i))
				{
					printf("\n__\n");  // apenas um explica para se caso parecer se for igual.
				}
				else
				{
					printf("\n Valor de l[%i] e %.3f\n",i,aux); // aqui é o print para mostrar os valores de l
					vt = vt + aux * *(y->pont_fx+i); // ultima parte do calculo.
			    }
		}
		
		printf("\n Valor de e %.3f\n\n",vt); //mostrando o calculo 
		system("pause");
	}
	
	
	if(y->opc == 2) // aqui a verificação para saber se o ponto de interpolção pertende ao f(x). se caso for ele simplesmente inverte o sinal de cima para que use a linha de f(x) em vez de x
	{
		for(i=0;i<y->pont_tabela;i++)  // aqui ja estramos no calculo
		{
			if(y->pont_inter == *(y->pont_fx+i))  // um if para ver se o ponto de interpolação ja nao esta presente na tabela.
			{
				vt = *(y->pont_x+i);
				break;
			}
			
			aux = 0;
			cj = 0;
			for(j=0;j<y->pont_tabela;j++)
			{
				if(i!=j)  // if para verficar se o i nao é igual o j. 
				{
					cj = (y->pont_inter - *(y->pont_fx+j)) / (*(y->pont_fx+i) - *(y->pont_fx + j));
				}
				else
				{
					cj = 1;
				}
				
				if(aux == 0 )
				{
					aux = cj;
				}
				else
				{
					aux = aux * cj;
				}
				
			}
			
				if(y->pont_inter == *(y->pont_fx+i))
				{
					printf("\n__\n");
				}
				else
				{
					printf("\n Valor de l[%i] e %.3f\n",i,aux);
					vt = vt + aux * *(y->pont_x+i);
			    }
		}
		
		printf("\n Valor de e %.3f",vt);	
		system("pause");
	}
}


