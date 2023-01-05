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
    int max_elem;
    double m;
    n=mat->r;

    for(i = 0; i < n; i++){
        max_elem=i;
        for(j = i + 1; j < n; j++) {
            if (abs(mat->data[max_elem][i]) < abs(mat->data[j][i])) {
                max_elem = j;
            }
        }
        if (max_elem != i) {
            double *tmp = mat->data[i];
            mat->data[i] = mat->data[max_elem];
            mat->data[max_elem] = tmp;

            double *b_tmp = b->data[i];
            b->data[i] = b->data[max_elem];
            b->data[max_elem] = b_tmp;
        }
        for(j = i + 1; j < n; j++){
            if(mat->data[i][i] == 0){
                return 1;
            }

            m = mat->data[j][i] / mat->data[i][i];
            for(k = i; k < n; k++){
                mat->data[j][k] = mat->data[j][k] -m * (mat->data[i][k]);
            }
            b->data[j][0] = b->data[j][0] - m * (b->data[i][0]);
        }
    }

    return 0;
}
