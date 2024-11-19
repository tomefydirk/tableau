#include <stdio.h>
#include <stdlib.h>
int nb_tab(int b) {
    return (b + 1) / 2; 
}

double** reso(double* tab, int a) {
    int b = nb_tab(a - 1); // tsy cotina ny tabi[0]
    double** reso = malloc(b * sizeof(double*));
    int c=(a-1)/2;

    for (int i = 0; i < b; i++) {
        double* val;
        if (i == b - 1 &&  c* 2 != (a-1)) { 
            val = malloc(2 * sizeof(double));
            val[0] = 1;        
            val[1] = tab[i + 1];  
        } else {
            val = malloc(3 * sizeof(double));
            val[0] = 2;               
            val[1] = tab[i + 1];    
            val[2] = tab[a - 1 - i];   
        }
        reso[i] = val;
    }

    return reso;
}

double* tab(double** reso, int a) {
    int b = nb_tab (a - 1) ; // moyenne
    double* tab = malloc(b * sizeof(double));
    int c=(a-1)/2;
    for (int i = 0; i < b; i++) {
        if (i == (b - 1) && c*2 != (a-1)) {
            tab[i] = reso[i][1];
        } else {
            tab[i] = (reso[i][1]+reso[i][2])/2;
        }
    }
    return tab;
}      
void print_reso(double** reso, int a) {
    int b = nb_tab(a - 1);
    int c=(a-1)/2;
    for (int i = 0; i < b; i++) {
        double* val = reso[i];
        
        if (i == b - 1 && (c)*2 != (a-1)) { 
            printf("reso [%d] = [{taille: %lf}, %lf]\n", i, val[0], val[1]);
        } else {
            printf("reso [%d] = [{taille: %lf}, %lf, %lf]\n", i, val[0], val[1], val[2]);
        }
    }
}
void print_tabi(double* tabi, int a) {
    
    for (int i = 0; i < a; i++) {
        printf("tabi[%d] = %lf\n", i, tabi[i]);
    }
}

void free_reso(double** reso, int a) {
    int b = nb_tab(a - 1); 

    for (int i = 0; i < b; i++) {
        free(reso[i]);
    }
    free(reso);
}

int main() {
    int a = 16; 
    double* tabi = malloc(a * sizeof(double));
    tabi[0] = a-1 ;  
    tabi[1]=51;
    tabi[2]=27;
    tabi[3]=56;
    tabi[4]=32;
    tabi[5]=53;
    tabi[6]=13;
    tabi[7]=80;
    tabi[8]=96;
    tabi[9]=76;
    tabi[10]=72;
    tabi[11]=53;
    tabi[12]=99;
    tabi[13]=16;
    tabi[14]=59;
    tabi[15]=42;
 
 
   
   

    double** res = reso(tabi, a);
    double*moy = tab(res,a);
    printf("Contenu du tableau tabi :\n");  
    print_tabi(tabi,a);
    
    printf("voici les contenus de reso: \n");
    print_reso(res, a);
    
    printf("voici la moyenne de chaque extrème: \n");
    print_tabi(moy,nb_tab(a-1));
    free_reso(res, a);
    free(tabi);

    return 0;
}
