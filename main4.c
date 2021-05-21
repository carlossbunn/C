#include <stdio.h>
#include <stdlib.h>
void cacula_hora(int totalMinutos, int *ph, int *pm);



int main(int argc, char *argv[]) {
	int min;
	int h=0,m=0;
	printf("digite os minutos\n");
	scanf("%i",&min);
	min *= 60;
	cacula_hora(min,&h,&m);
	printf("%d %i",h,m);
	
	

	return 0;
}
void cacula_hora(int totalMinutos, int *ph, int *pm){
	int rest;
	*ph = totalMinutos/3600;
	rest = totalMinutos % 3600;
	*pm = rest /60;
	 
	}

