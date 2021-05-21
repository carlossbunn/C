#include <stdio.h>
#include <stdlib.h>
void inc_dec (int *a, int *b);


int main(int argc, char *argv[]) {
	int a,b;
	scanf("%i",&a);
	scanf("%i",&b);
	printf("%i %i\n",a,b);
	inc_dec(&a,&b);
	printf("%i %i",a,b);

}
void inc_dec (int *a, int *b){
	(*a)++;
	(*b)--;
}
