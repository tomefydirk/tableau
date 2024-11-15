#include <stdio.h>
#include <stdlib.h>

int nb_tab(int a) {
    return (a + 1) / 2;
}

double* tab(double** reso, int a) {
    double* tab = malloc(a * sizeof(double));
    int b = nb_tab(a);
    int c = a / 2;
    for (int i = 0; i < b; i++) {
        if (i == (b - 1) && (c*2) != a) {
            tab[i] = reso[i][0];
        } else {
            tab[i] = reso[i][0];
            tab[(a - 1) - i] = reso[i][1];
        }
    }
    return tab;
}

void print_tab(double* tab, int a) {
    for (int i = 0; i < a; i++) {
        printf("tab[%d] = %lf\n", i, tab[i]);
    }
}

int main() {
    int a = 5;
    int b = nb_tab(a);
    
    double** reso = malloc(b * sizeof(double*));
    for (int i = 0; i < b; i++) {
        reso[i] = malloc(2 * sizeof(double));
    }

    reso[0][0] = 0;
    reso[0][1]=3;
    reso[1][0]=0;
    reso[1][1]=2;
    reso[2][0]=1;

    double* tabi = tab(reso, a);
    print_tab(tabi, a);

    free(tabi);
    for (int i = 0; i < b; i++) {
        free(reso[i]);
    }
    free(reso);

    return 0;
}
