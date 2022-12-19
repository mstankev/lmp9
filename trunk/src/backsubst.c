#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				
	 int n = mat -> r;
    int m = b -> r;
    if (n != m || mat->r != mat->c || b->c != 1) 
        return 2;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mat->data[i][i] == 0)
            return 1;
        double ans = b->data[i][0];
        for (int j = 0; j < n; j++)
            if (i != j) ans -= mat->data[i][j] * x->data[j][0];
        x->data[i][0] = ans / mat->data[i][i];
    }


				return 0;
}


