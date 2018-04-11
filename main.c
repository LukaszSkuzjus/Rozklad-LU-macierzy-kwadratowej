#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

float abv(float v){
if(v>=0)return v;
else return (-1)*v;
}
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
float** Tr(float** l, int rozmiar_macierzy){
    float** A;

float x;
int i,j,k;

A=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    //*(A+i)=malloc((n+1)*sizeof(float));
    A[i]=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}

for(i=1;i<=rozmiar_macierzy;++i){
    for(j=1;j<=rozmiar_macierzy;++j){
           x=l[i][j];
           A[i][j]=l[j][i];
           l[j][i]=x;

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
    float f;

    int rozmiar_macierzy;

    printf("rozmiar macierzy: ");
    scanf("%d",&rozmiar_macierzy);

    int i,j,k,p;
    int j_max,j2,b,c;
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

float**P=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(P+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
float**G=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(G+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}

     for(i=1;i<=rozmiar_macierzy;i++){


        for(j=1;j<=rozmiar_macierzy;j++)
     {
       l[i][j]=0;
       u[i][j]=0;
       G[i][j]=0;
       P[i][j]=0;

     }
     }
     for(i=1;i<=rozmiar_macierzy;i++)
     {

       G[i][i]=1;
       P[i][i]=1;
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

wyswietl_macierz(a,'a',rozmiar_macierzy);



for(k=1;k<=rozmiar_macierzy;++k){

               for( j=k;j<=rozmiar_macierzy;++j){
                   u[k][j]=a[k][j];

                     for(p=1;p<=k-1;++p){

                            u[k][j]-= l[k][p]*u[p][j];

                     }

        }
        j_max=k;
for(j2=k+1;j2<=rozmiar_macierzy;++j2){
                        if(abv(u[k][j2])>abv(u[k][j_max]))
                           j_max=j2;

                   }
                   for(b=1;b<=rozmiar_macierzy;++b){
                         f=u[b][j_max];
                    u[b][j_max]=u[b][k];
                   u[b][k]=f;
                   }
                   for(b=1;b<=rozmiar_macierzy;++b){
                         f=a[b][j_max];
                    a[b][j_max]=a[b][k];
                   a[b][k]=f;
                   }
               for( i=k+1;i<=rozmiar_macierzy;++i){
                    l[i][k]=a[i][k];
                  for(p=1;p<=k-1;++p){
    l[i][k]-=l[i][p]*u[p][k];

               }
l[i][k]/=u[k][k];
               }

               for( i=1;i<=rozmiar_macierzy;++i){
                for( j=1;j<=rozmiar_macierzy;++j){
                    G[i][j]=0;
                }
                 G[i][i]=1;

               }

for(c=1;c<=rozmiar_macierzy;++c){
                         f=G[j_max][c];
                    G[j_max][c]=G[k][c];
                   G[k][c]=f;
                   }
P=ab(P,G,rozmiar_macierzy);
}


printf("Metoda Dolittle'a:\n\n");
    wyswietl_macierz(l,'l',rozmiar_macierzy);

    wyswietl_macierz(u,'u',rozmiar_macierzy);

wyswietl_macierz(P,'P',rozmiar_macierzy);


    wyswietl_macierz(ab(ab(l,u,rozmiar_macierzy),P,rozmiar_macierzy),'a',rozmiar_macierzy);


    return 0;
}
