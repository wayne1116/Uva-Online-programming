#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    int depth;
    int ball;
    while(scanf("%d", &a)!=EOF){
        if(a==-1) break;
        while(a--){
            scanf("%d %d", &depth, &ball);
            int modu=1<<(depth-1);
            ball=(ball-1)%modu;
            ball+=1;
            int start=1;
            while(--depth){
                if(ball%2==1) start=(start<<1);
                else start=(start<<1)+1;
                ball=(ball+1)>>1;
            }
            printf("%d\n", start);
        }
    }
    return 0;
}
