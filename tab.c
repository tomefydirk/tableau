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

double* tab(double** reso, int a,int b) {
    double* tab = malloc(a * sizeof(double));
    int c = a / 2;
    for (int i = 0; i < b; i++) {
        if (i == (b - 1) && (c*2) != a) {
            tab[i] = reso[i][0];
        } else {
            tab[i] = (reso[i][0]+reso[i][1])/2;
        }
    }
    return tab;
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
void print_tab(double* tab, int b) {
    for (int i = 0; i < b; i++) {
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

int  main(){
    int a = 15;
    int b=nb_tab(a);
    double*tabi=malloc(a*sizeof(double));
    tabi[0]=51;
    tabi[1]=27;
    tabi[2]=56;
    tabi[3]=32;
    tabi[4]=53;
    tabi[5]=13;
    tabi[6]=80;
    tabi[7]=96;
    tabi[8]=76;
    tabi[9]=72;
    tabi[10]=53;
    tabi[11]=99;
    tabi[12]=16;
    tabi[13]=59;
    tabi[14]=42;

    double** res = reso(tabi, a);
    double* tab1=tab(res,a,b);
    print_reso(res, a);
    free_reso(res, a);
    print_tab(tab1,b);
    return 0;
}