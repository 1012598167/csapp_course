#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    long m,i,j,k;
    clock_t start,finish;
    double  duration;
    printf("\tijk\tjik\tjki\tkji\tkij\tikj\n");
    for(m=50;m<1000;m+=50){
        double A[m][m],B[m][m],C[m][m];
        double a;
        double sum,r;
        start=0;
        finish=0;
        printf("%ld\t",m);
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                a= rand() /(double)(RAND_MAX/10000);
                A[i][j]=a;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                a= rand() /(double)(RAND_MAX/10000);
                B[i][j]=a;
            }
        }
        start = clock();
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                sum=0.0;
                for(k=0;k<m;k++){
                    sum+=A[i][k]*B[k][j];
                }
                C[i][j]+=sum;
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\t", duration );
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                C[i][j]=0;
            }
        }
        start = clock();
        for(j=0;i<m;j++){
            for(i=0;i<m;i++){
                sum=0.0;
                for(k=0;k<m;k++){
                    sum+=A[i][k]*B[k][j];
                }
                C[i][j]+=sum;
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\t", duration );
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                C[i][j]=0;
            }
        }
        start = clock();
        for(j=0;i<m;j++){
            for(k=0;k<m;k++){
                r=B[k][j];
                for(i=0;i<m;i++){
                    C[i][j]+=A[i][k]*r;
                }
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\t", duration );
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                C[i][j]=0;
            }
        }
        start = clock();
        for(k=0;k<m;k++){
            for(j=0;j<m;j++){
                r=B[k][j];
                for(i=0;i<m;i++){
                    C[i][j]+=A[i][k]*r;
                }
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\t", duration );
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                C[i][j]=0;
            }
        }
        start = clock();
        for(k=0;k<m;k++){
            for(i=0;i<m;i++){
                r=A[i][k];
                for(j=0;j<m;j++){
                    C[i][j]+=r*B[k][j];
                }
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\t", duration );
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                C[i][j]=0;
            }
        }
        start = clock();
        for(i=0;i<m;i++){
            for(k=0;k<m;k++){
                r=A[i][k];
                for(j=0;j<m;j++){
                    C[i][j]+=r*B[k][j]; //中文书这边写错了
                }
            }
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf( "%f\n", duration );
//        for(i=0;i<m;i++){
//            for(j=0;j<m;j++){
//                C[i][j]=0;
//            }
//        }
//        int n=m,i1,j1,k1,K=8;
//        start = clock();
//        for (i = 0; i < n; i+=K)
//            for (j = 0; j < n; j+=K)
//                for (k = 0; k < n; k+=K)
//                    /* B x B mini matrix multiplications */
//                    for (i1 = i; i1 < i+K; i++)
//                        for (j1 = j; j1 < j+K; j++)
//                            for (k1 = k; k1 < k+K; k++)
//                                C[i1][j1] += A[i1][k1]*B[k1][j1];
//
//        finish = clock();
//        duration = (double)(finish - start) / CLOCKS_PER_SEC;
//        printf( "%f\n", duration );
    }
    return 0;
}
