#include <stdio.h>
#include <stdlib.h>
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);


int main(int argc, char *argv[]) {
    float mat[3][4]={{7,2,3,5},{6,1,8,9},{14,11,12,5}}; 
    float menor;
    int indi,indj;
    min_matriz(mat, &menor, &indi,  &indj);
    printf("o local é x=%i y=%i e o menor numero = %.2f", indi, indj, menor);


    return 0;
}
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    int i,j;
    //float min = mat[0][0];
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            if(*pMin>mat[i][j]){
                *pMin = mat[i][j];
                *pI=i;
                *pJ=j;
            }
        }
    }
}
