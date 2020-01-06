#include<stdio.h>
#include<stdlib.h>
long long matrix[128][128];
int main()
{
    int ne;
    int a, i, j, n, k;
    int flag;
    char c;
    scanf("%d", &a);
    getchar();
    for(i=1; i<=a; i++){
        scanf("%c = %d", &c, &n);
        ne=0;
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                scanf("%lld", &matrix[j][k]);
                if(matrix[j][k]<0) ++ne;
            }
        }
        flag=0;
        if(ne) flag=1;
        else{
            for(j=0; j<n/2; j++){
                for(k=0; k<n; k++){
                    if(matrix[j][k]!=matrix[n-j-1][n-k-1]){
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(n%2){
                for(j=0; j<n/2; j++){
                    if(matrix[n/2][j]!=matrix[n/2][n-j-1]){
                        flag=1;
                        break;
                    }
                }
            }
        }
        printf("Test #%d: ", i);
        if(flag) printf("Non-symmetric.\n");
        else printf("Symmetric.\n");
        getchar();
    }
    return 0;
}
