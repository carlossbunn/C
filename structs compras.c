#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//carlos BUnn e Lucas Gesser

struct Data{
	int dia, mes, ano;
};
struct Inicio{
	int i_hora;
	int i_minuto;
};
struct Fim{
	int f_hora;
	int f_minuto;
};
struct Rodrigo{//fazer uma copia
	char descricao[20];
	char local[20];
	struct Data quando;
	struct Inicio q_comeca;
	struct Fim q_fim;
};

void ordena_hora(struct Rodrigo *p, int k);
void ordena_dta(struct Rodrigo *p, int k);

void o_evento(struct Rodrigo *p);
int check_na_onda(struct Rodrigo *p , int k);//usar em 2 e 3, 3 usar filtro

int daumaolhada(struct Rodrigo x);

int main(int argc, char *argv[]) {
	int i=0, n=0;
	
	int d,m,a;
	int hora, min;
	
	int cont = 0,contt = 0;
	
	int leitor;
	char str[20];
	
	struct Rodrigo *p = NULL;

    do{
    	
		printf("\n-----AGENDA DE EVENTOS-----\n");
        printf("1-> colocar um novo evento\n");
        printf("2-> mostrar os eventos da lista;\n");
        printf("3-> achar o evento por um dia\n");
        printf("4-> acar o evento por uma descricao\n");
        printf("5-> apagar eventos\n");
        printf("6. Sair do programa\n");
		
		fflush(stdin);
        scanf("%d", &leitor);
        fflush(stdin);
		switch(leitor){
			case( 1):
            
            n++;
            p = realloc( p, sizeof(struct Rodrigo) * n);
            
            o_evento(&p[n-1]);

            ordena_dta(p, n);
            
            ordena_hora(p, n);
            
            if(n > 1){
            	if(check_na_onda(p,n)==0){
            		printf("sinto muito mas ja tem coisa nessa hora\n");
            		n--;
            		p = realloc( p, sizeof(struct Rodrigo) * n);
            		
				}
			}
		system("CLS");
		break;
		case(2):
		for(i=0;i<n;i++){
			daumaolhada(p[i]);
		}		
		break;
		
		case(3):
			printf("\ndigite o dia\n");
			scanf("%i",&d);
			printf("\ndigite o mes\n");
			scanf("%i",&m);
			printf("\ndigite o ano\n");
			scanf("%i",&a);
			i=0;
			while(i!=(n-1)){
			if(a==p[i].quando.ano){
				if(m == p[i].quando.mes){
					if(d == p[i].quando.dia){
						daumaolhada(p[i]);
					}
				}
			}
		i++;		
		}
		break;
		
			case(4):
			printf("\ncoloque a descricao para procurar\n");
			scanf("%i",&str);
			i =0;
			while(i != (n-1)){
				if(strcmp(str,p[i].descricao)==0){// verifica por string.h 
				i++;
		
		//amem
				}else{
				printf("nenhum evento encontrado");
				}
     		}

		}
		break;
        
      }while(leitor != 6);

    
    free(p);

    return 0;
}
int daumaolhada(struct Rodrigo x){
	
	printf("dia: %d\nmes: %d\nano: %d\n",x.quando.dia,x.quando.mes,x.quando.ano);
	
	printf("quando comeca: ");
	printf("%d",x.q_comeca.i_hora);
	printf(":%d\n",x.q_comeca.i_minuto);
	
	printf("horario de termino: %i:%i\n",x.q_fim.f_hora,x.q_fim.f_minuto);
	
	printf("descrecao: %s\n",x.descricao);
	
	printf("local: %s\n",x.local);
}
void o_evento(struct Rodrigo *p){
	
	
	printf("dia:");
	scanf("%d",&p->quando.dia);
	printf("mes:");
	scanf("%d",&p->quando.mes);//data
	printf("ano:");
	scanf("%d",&p->quando.ano);
	
	printf("\nque hora começa: ");
	scanf("%d",&p->q_comeca.i_hora);//inicio
	printf("\nque minuto começa: ");
	scanf("%d",&p->q_comeca.i_minuto);
	
	
	printf("\nque hora termina: ");
	scanf("%d",&p->q_fim.f_hora);//fim
	printf("\nque minuto termina: ");
	scanf("%d",&p->q_fim.f_minuto);
	
	printf("qual o nome do local ");
	scanf(" [^\n]%s",p->local);
	
	printf("digite a descricao: ");
	fflush(stdin);
	gets(p->descricao);
	fflush(stdin);
}
void ordena_hora(struct Rodrigo *p, int k){
	int i=0,j;
	struct Rodrigo casa;
	while(i<k){
		for(j=0;j<(k-1);j++){
			if(p[j].quando.ano == p[j+1].quando.ano){
				if(p[j].quando.mes == p[j+1].quando.mes){
					if(p[j].quando.dia==p[1+j].quando.dia){
						if(p[j+1].q_comeca.i_hora<=p[j].q_comeca.i_hora){
							casa =p[j];
							p[j]= p[j+1];
							p[j+1]=casa;
							
						}
					}
				}
			}
		}
	i++;	
	}
}
void ordena_dta(struct Rodrigo *p, int k){
	
		int i=0,j;
	struct Rodrigo casa;
	while(i<k){
		for(j=0;j<(k-1);j++){
			if(p[j].quando.ano == p[j+1].quando.ano){
				if(p[j].quando.mes == p[j+1].quando.mes){		
						if(p[j+1].q_comeca.i_hora<=p[j].q_comeca.i_hora){
							casa =p[j];
							p[j]= p[j+1];
							p[j+1]=casa;
						
						}
					
				}
			}
		}
	i++;	
	}
}

int check_na_onda(struct Rodrigo *p, int k){
	
	int i=k,j;
	while(i!=0){
		for(j=(k-1);j>=0; j--){
			if(p[j].quando.ano == p[j-1].quando.ano){
				if(p[j].quando.mes==p[j-1].quando.mes){
					if(p[j].q_comeca.i_hora>=p[j-1].q_comeca.i_hora){
						if(p[j].q_comeca.i_hora<=p[j-1].q_fim.f_hora){
							if(p[j].q_comeca.i_minuto >= p[j-1].q_comeca.i_minuto){
								return 0;
							}
						}
					}
				}
			}
		}
	i--;	
	}
}
