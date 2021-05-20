#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *uniao(int **lista, int n,int *quant, int n1, int n2);
int *intesecao(int **lista, int n,int *quant, int n1, int n2);
int *diferenca(int **lista, int n,int *quant, int n1, int n2); 
int pradif(int *vet,int n,int igual);

int verifica(int n, int c1, int c2);
//Lucas Gesser e Carlos Bunn

int main(int argc, char *argv[]) {
	
	int **lista = NULL;
	int *quant  = NULL;
	int i,j;
	int n = 0;
	int n1,n2;
	int opcao;
	do{
		printf("\n-----------------\n");
		printf("1 Cria conjunto\n2 Uniao de dois conjuntos\n3 Interseccao de 2 conjuntos\n4 Diferenca de dois conjuntos\n5 Mostrar todos os conjuntos\n6 Sair\n");
		printf("-----------------\n");
		scanf("%d", &opcao);
		switch( opcao ){
			case 1:
				n++;
				lista = realloc(lista, sizeof(4)*n);
				quant = realloc(quant, sizeof(int*)*n);
				printf("Tamanho do conjunto:\n");
				scanf("%i",&quant[n-1]);
				lista[n-1] = malloc(sizeof(4) * quant[n-1]);
					printf("Valores do conjunto:\n");
					for(i=0;i<quant[n-1];i++)
						scanf("%i",&lista[n-1][i]);
			break;						
								
			case 2:
				n++;
			 	printf("Conjuntos a serem unidos:\n");
            	scanf("%d", &n1);
            	scanf("%d", &n2);

				if(verifica(n,n1,n2)==0){
					printf("Um dos conjuntos nao existe.");
					n--;
				}else{
					quant = realloc(quant, sizeof(int)*n);
					lista = realloc(lista, sizeof(int*)*n);
					
				uniao(lista, n, quant, n1, n2);
				}
				break;
			case 3:
				n++;
				
				printf("Conjuntos para a interseccao:\n");
            	scanf("%d", &n1);
            	scanf("%d", &n2);
            	if(verifica(n,n1,n2)==0){
					printf("Um dos conjuntos nao existe.");
					n--;
				}else{
					quant = realloc(quant, sizeof(int)*n);
					lista = realloc(lista, sizeof(int*)*n);
					intesecao( lista,  n, quant,  n1, n2);
				}
				break;
			case 4:
				n++;
				
				printf("Conjuntos para a diferenca:\n");
            	scanf("%d", &n1);
            	scanf("%d", &n2);
            	if(verifica(n,n1,n2)==0){
					printf("Um dos conjuntos nao existe.");
					n--;
				}else{
					quant = realloc(quant, sizeof(int)*n);
					lista = realloc(lista, sizeof(int*)*n);
					diferenca( lista,  n, quant,  n1, n2);
					for(i=0;i<quant[n-1];i++){
						printf("%i\t",lista[n-1][i]);
					}
				}
				printf("\n");
				//esse ainda ta dando problema
				break;
            	
			case 5:
				printf("Conjuntos cadastrados:\n");
				for( i = 0 ; i < n ; i++ ){
					printf("Conjunto[%i]:\t",i);
					for(j=0;j<quant[i];j++)
						printf("%i\t",lista[i][j]);
						
					printf("\n");
				}
				
				break;
		}
		
	}while( opcao != 6 );
	
	for( i = 0 ; i < n ; i++ )
		free( lista[i] );
	free( lista );
	
	return 0;
}

int verifica(int n, int c1, int c2){

    if(c1 >= n || c2 >= n){
        return 0;
    }

    return 1;
}
int procura(int *vet, int n,int taaq){
	int i;
	
	for(i=0;i<n;i++){
		if(vet[i]==taaq)
			return i;
    }
			return 2;
	
}
int pradif(int *vet,int n,int igual){
	int i;
		for(i=0;i<n;i++){
			if(vet[i] == igual){
				return 0;
			}
		}
		return 2;
}
int *uniao(int **lista, int n, int *quant, int n1, int n2){
	int tamanho = quant[n1-1] + quant[n2-1];
	int i, j;
	int k;
	lista[n-1] = (int*) malloc(sizeof(int) * tamanho);
		for (i=0; i<quant[n1-1]; i++)
			lista[n-1][i] = lista[n1-1][i];
		for (j=0; i<tamanho; i++, j++)
			lista[n-1][i] = lista[n2-1][j];
			
		for (i=0; i<tamanho; i++){
            for (j=0; j<tamanho; j++){
                if (j != i && lista[n-1][i] == lista[n-1][j]){
                    if (j < tamanho-1){
                        for( k=j+1; k<tamanho; k++)
                            lista[n-1][k-1] = lista[n-1][k];
                            tamanho--;
                    }
                    else
                        tamanho--;
			    }
            }
		}
        lista[n-1] = realloc(lista[n-1], sizeof(int) * tamanho);
        quant[n-1] = tamanho;

        return lista[n-1];
}   //Pronto
int *intesecao(int **lista, int n,int *quant, int n1, int n2){
	int casinha = n1 - 1;
	int casa2 = n2-1;
	int tamanho;
	tamanho = 0;
	int i,j;
	lista[n-1] =0;
	  for(i=0;i<quant[casinha];i++){
		  for(j=0;j<quant[casa2];j++){
			  if(lista[casinha][i] == lista[casa2][j]){
			
			  tamanho++;
			  lista[n-1] = realloc(lista[n-1], sizeof(4)*tamanho);
			  lista[n-1][tamanho-1] = lista[n2-1][j];
		    }
		  }
	  }
	quant[n-1]=tamanho;
	
		return lista[n-1];
}   //Pronto
int *diferenca(int **lista, int n,int *quant, int n1, int n2){
	lista[n-1]=NULL;
	int i;
	int cont;
	cont = 0;
	for(i=0;i<quant[n2-1];i++){
		if(pradif(lista[n2-1],quant[n2-1],lista[n1-1][i]) == 2){
			cont++;
			lista[n-1] = realloc(lista[n-1],sizeof(4)*cont);
			lista[n-1][cont-1]= lista[n1][i];
		}
	}
	quant[n-1]=cont;
	return lista[n-1];
}
