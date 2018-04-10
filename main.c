#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
float** ab(float** l,float** u, int rozmiar_macierzy){
    float** A;
    int i,j,k;

    A=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
    for(i=0;i<=rozmiar_macierzy;++i){
        //*(A+i)=malloc((n+1)*sizeof(float));
        A[i]=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
    }
    for(i=1;i<=rozmiar_macierzy;++i){
        for(j=1;j<=rozmiar_macierzy;++j){
            A[i][j]=0;
            for(k=1;k<=rozmiar_macierzy;++k){
                //*(*(A+i)+j)=(*(*(l+i)+k))*(*(*(u+k)+j));
                A[i][j]+=l[i][k]*u[k][j];
            }
        }
    }
    return A;
}

void wyswietl_macierz(float** m,char nazwa_macierzy, int rozmiar_macierzy){
    int i,j;
    printf("%c:\n",toupper(nazwa_macierzy));
    for(j=1;j<=rozmiar_macierzy;++j){
        for(i=1;i<=rozmiar_macierzy;++i){
            printf(" %8.5f  ",m[j][i]);
    }
        printf("\n");

    }
    printf("\n\n");
}

int main()
{
    int rozmiar_macierzy;

    printf("rozmiar macierzy: ");
    scanf("%d",&rozmiar_macierzy);
    int i,j,k,p;
    float**a=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
    for(i=0;i<=rozmiar_macierzy;++i){
        *(a+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
    }
    float**l=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
    for(i=0;i<=rozmiar_macierzy;++i){
        *(l+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
    }
    float**u=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
    for(i=0;i<=rozmiar_macierzy;++i){
        *(u+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
    }

    for(i=1;i<=rozmiar_macierzy;i++)
        for(j=1;j<=rozmiar_macierzy;j++)
        {
            l[i][j]=0;
            u[i][j]=0;
        }
    for(i=1;i<=rozmiar_macierzy;i++){
        l[i][i]=1;
    }

    for(j=1;j<=rozmiar_macierzy;++j){
        printf("Napisz elementy wiersza %d macierzy A: \n",j);
        for(i=1;i<=rozmiar_macierzy;++i){
            scanf("%f",&a[j][i]);

        }
        printf("\n");

    }

    for(k=1;k<=rozmiar_macierzy;++k){

        for( j=k;j<=rozmiar_macierzy;++j){
            u[k][j]=a[k][j];
            for(p=1;p<=k-1;++p){

                u[k][j]-= l[k][p]*u[p][j];

            }
        }

        for( i=k+1;i<=rozmiar_macierzy;++i){
            l[i][k]=a[i][k];
            for(p=1;p<=k-1;++p){
                l[i][k]-=l[i][p]*u[p][k];

            }
            l[i][k]/=u[k][k];
        }


}
printf("Metoda Dolittle'a:\n\n");
    wyswietl_macierz(l,'l',rozmiar_macierzy);
    wyswietl_macierz(u,'u',rozmiar_macierzy);
    wyswietl_macierz(ab(l,u,rozmiar_macierzy),'a',rozmiar_macierzy);

    for(i=1;i<=rozmiar_macierzy;i++)
        for(j=1;j<=rozmiar_macierzy;j++)
        {
            l[i][j]=0;
            u[i][j]=0;
       }
       for(j=1;j<=rozmiar_macierzy;j++)
       {
        u[j][j]=1;

       }

       for(k=1;k<=rozmiar_macierzy;++k){

            for( i=k;i<=rozmiar_macierzy;++i){
                l[i][k]=a[i][k];
                for(p=1;p<=k-1;++p){

                    l[i][k]-= l[i][p]*u[p][k];

                }
            }

            for( j=k+1;j<=rozmiar_macierzy;++j){
                u[k][j]=a[k][j];
                for(p=1;p<=k-1;++p){
                    u[k][j]-=l[k][p]*u[p][j];

               }
                u[k][j]/=l[k][k];
            }

}
    printf("Metoda Crouta:\n\n");
    wyswietl_macierz(l,'l',rozmiar_macierzy);
    wyswietl_macierz(u,'u',rozmiar_macierzy);
    wyswietl_macierz(ab(l,u,rozmiar_macierzy),'a',rozmiar_macierzy);

    return 0;
}
