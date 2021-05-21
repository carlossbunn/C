#include <stdio.h>
#include <stdlib.h>
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);


int main(int argc, char *argv[]) {
	int t,ind;
	float m,v[7]={2,3,4,5,7,2,6};
	t = 7;
	max_vetor(v,t,&m,&ind);
	printf("%f %i",m,ind);
	return 0;
}
void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
	int i;
	*pMax = vet[0];
	*pIndice = 0;
	for(i=0; i < tam ;i++){
		if(vet[i] > *pMax){
			*pMax = vet[i];
			*pIndice = i;
		}
			
			
	}
}
