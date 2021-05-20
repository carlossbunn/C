#include <stdio.h>
#include <stdlib.h>
void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(int argc, char *argv[]) {
	int v[4]={3,1,2,6,4}, t;
	int min, max;
	t = 5;
	max_min( v, t, &min, &max);
	printf("%i %i",min,max);
	
	return 0;
}
void max_min(int vet[], int tam, int *pMin, int *pMax){
	int i;
	for(i=0;vet[i]!='\0';i++){
		if(vet[i] > vet[i+1])
			*pMax = vet[i];
		if(vet[i] < vet[i+1])
			*pMin = vet[i];
	}
}
