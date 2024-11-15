#include<stdio.h>
#include<stdlib.h>

int nb_tab(int b){
    int a=((b+1)/2);
    return a;
}

double**reso(double*tab, int a){
    int b=nb_tab(a);
    int c=a/2;
    double** reso=malloc(b*sizeof(double*));

    for(int i = 0; i < b; i++) {
        double* val;
        if((c*2)!= a && i == (b - 1)) {
            val = malloc(sizeof(double));
            val[0] = tab[i];
        }else {
            val = malloc(2 * sizeof(double));
            val[0] = tab[i];
            val[1] = tab[a - 1 - i];
        }
        reso[i]=val;
    } 
    
    return reso;
}


void print_reso(double**reso, int a){
    int b = nb_tab(a);
    int c=a/2;
    
    for(int i = 0; i < b; i++) {
        double* val=reso[i];
        if((c*2)!= a && i == (b-1) ) {
            printf("reso [%d] = [%lf]\n", i, val[0]);
        }else {
            printf("reso [%d] = [%lf, %lf]\n", i, val[0], val[1]);
        }
        
    } 
}

double* tab1d(double** reso, int a) {
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

void free_reso(double** reso, int a) {
    int b = nb_tab(a);

    for(int i = 0; i < b; i++) {
        double* val = reso[i];
        free(val);
    } 
    free(reso);
}

int main(){
    int a = 2;
    double*tab=malloc(a*sizeof(double));
    tab[0]=1;
    tab[1]=2;
   
   
 
    double** res = reso(tab, a);
     double* tabi = tab1d(res, a);
  

 
    print_reso(res, a);
     print_tab(tabi, a);

    free_reso(res, a);
    free(tabi);
    return 0;
    
}