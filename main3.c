#include <stdio.h>
#include <stdlib.h>
void calcula_circulo(float raio, float *pPerimetro, float *pArea);


int main(int argc, char *argv[]) {
	float raio,pPerimetro,pArea;
	printf("digite o raio : ");
	scanf("%f",&raio);
	calcula_circulo(raio,&pPerimetro,&pArea);
	printf("%f %f",pPerimetro,pArea);
	return 0;
}
void calcula_circulo(float raio, float *pPerimetro, float *pArea){
	*pPerimetro = 2 * 3.14 * raio;
	*pArea = 3.14 * (raio * raio);
}
