#include <math.h>
#include <stdio.h>
#include "gauss.h"
#include <math.h>
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate( Matrix *mat, Matrix *b){
    int k, j, n, i;
	int maxelem;
    double d;
    n=mat->r;

    for(k = 0; k < n; k++){
        maxelem=k;
        for(j = k + 1; j < n; j++) {
            if (fabs(mat->data[maxelem][k]) < fabs(mat->data[j][k])) {
                maxelem = j;
            }
        }
        if (maxelem != k) {
            double *tmp = mat->data[k];
            mat->data[k] = mat->data[maxelem];
            mat->data[maxelem] = tmp;

            double *btmp = b->data[k];
            b->data[k] = b->data[maxelem];
            b->data[maxelem] = btmp;
        }
        for(j = k + 1; j < n; j++){
            if(mat->data[k][k] == 0){
                return 1;
            }

            d = mat->data[j][k] / mat->data[k][k];
            for(i = k; i < n; i++){
                mat->data[j][i] = mat->data[j][i] -d * (mat->data[k][i]);
            }
            b->data[j][0] = b->data[j][0] - d * (b->data[k][0]);
        }
    }

    return 0;
}
