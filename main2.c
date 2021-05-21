#include <stdio.h>
#include <stdlib.h>
void troca_valor(float *x, float *y);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float x,y;
	scanf("%f",&x);
	scanf("%f",&y);
	printf("%f %f\n",x,y);
	troca_valor(&x,&y);
	printf("%f %f",x,y);
	
	return 0;
}
void troca_valor(float *x, float *y){
	float k;
	 k = *y;
	*x = *y;
	*y = *x;
}
