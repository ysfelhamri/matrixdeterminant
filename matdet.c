#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
long long unsigned int det(int** mat,int nbr);
int** coef(int ** mat,int nbr, int n,int m);
int main()
{
    int** mat;
    int NB,i,j;
    srand(time(NULL));
    do{
    printf("Enter the nbr of rows and colmuns: ");
    scanf("%d",&NB);
    }while(NB<2);
    mat = (int**)malloc(sizeof(int*)*NB);
    if (mat == NULL)
    {
        printf("Alloc Error");
        exit(33);
    }
    for(i=0; i<NB; i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*NB);
        if (mat[i] == NULL)
        {
            printf("Alloc Error");
            exit(33);
        }
    }
    //random fill
    /*for(i=0; i<NB; i++){ 
        for(j=0; j<NB; j++)
        {
            mat[i][j]=(rand()%4)+1;
            printf("[%d]",mat[i][j]);
        }
        printf("\n");
    }*/
    for(i=0; i<NB; i++){
        for(j=0; j<NB; j++)
        {   
            printf("Enter element [%d,%d] : ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<NB; i++){
        for(j=0; j<NB; j++)
        {
            printf("[%d]",mat[i][j]);
        }
        printf("\n");
    }
    printf("\ndet = %I64d \n",det(mat,NB));
    return 0;
}
long long unsigned int det(int** mat,int nbr)
{
    long long unsigned int res=0;
    int i;
    int ** co;
    if(nbr >2){
        for(i=0;i<nbr;i++){
            co=coef(mat,nbr,0,i);
            res+=mat[0][i]*((i%2==0)?1:-1)*det(co,nbr-1);
        for(i=0;i<nbr-1;i++)
         free(co[i]);
         free(co);
        }
        return(res);
    }
        else if(nbr==2)
            return(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
}

int** coef(int ** mat,int nbr, int n,int m){
    int **res;
    int i,j,k,l;
    res = (int**)malloc(sizeof(int*)*(nbr-1));
    if (res == NULL)
    {
        printf("Alloc Error");
        exit(33);
    }
    for(i=0; i<nbr-1; i++)
    {
        res[i] = (int*)malloc(sizeof(int)*(nbr-1));
        if (res[i] == NULL)
        {
            printf("Alloc Error");
            exit(33);
        }
    }
    for(i=0,k=0;i<nbr-1&&k<nbr;i++,k++){
        if(k==n)k++;
        for(j=0,l=0;j<nbr-1&&l<nbr;j++,l++){
            if(l==m)l++;
            res[i][j]=mat[k][l];
        }
    }
    return res;
}
