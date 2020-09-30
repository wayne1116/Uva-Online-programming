#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a, i, j, k;
    int m, n, count;
    int x[128], y[128];
    while(scanf("%d",&a)&&a){
        for(i=0; i<2*a; i++)
            scanf("%d%d", &x[i], &y[i]);
        
        m=n=1;
        for(i=-500; i<=500; i++) {
            for(j=0; j<=500; j++) {
                m=i;
                n=j;
                count=0;
                for(k=0; k<2*a; k++) {
                    if(m*x[k]+n*y[k]==0)
                        break;
                    else if(m*x[k]+n*y[k]>0)
                        ++count;
                }
                if(k>=2*a && count==a)
                    break;
            }
            if(k>=2*a && count==a)
                break;
        }

        printf("%d %d\n", m, n);
    }
    return 0;
}
