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

void free_reso(double** reso, int a) {
    int b = nb_tab(a);

    for(int i = 0; i < b; i++) {
        double* val = reso[i];
        free(val);
    } 
    free(reso);
}

void main(){
    int a = 6;
    double*tab=malloc(a*sizeof(double));
    tab[0]=0;
    tab[1]=4.4;
    tab[2]=-1.5;
    tab[3]=2;
    tab[4]=3;
    tab[5]=-1;

   


    double** res = reso(tab, a);
    print_reso(res, a);
    free_reso(res, a);
    
}