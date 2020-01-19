#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int bingo[]={31,992,31744,1015809,32505856,1082401,2164802,4329604,8659208,17318416,17043521,1118480};
int map[25];
int main()
{
    int a, i, j, b, v;
    int mark, step, find;
    int num, num1, num2, num3, num4;
    int flag[128];
    int map[128];
    int order[128];
    map[1]=1;
    for(i=2; i<=25; i++) map[i]=map[i-1]<<1;

    scanf("%d", &a);
    while(a--){
        memset(flag, 0, sizeof(flag));
        for(i=0; i<2; i++){
            for(j=1; j<=5; j++){
                scanf("%d", &num);
                flag[num]=i*5+j;
            }
        }
        scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
        flag[num1]=11;
        flag[num2]=12;
        flag[num3]=14;
        flag[num4]=15;
        for(i=3; i<5; i++){
            for(j=1; j<=5; j++){
                scanf("%d", &num);
                flag[num]=i*5+j;
            }
        }
        for(i=0; i<75; i++) scanf("%d", &order[i]);

        mark=step=b=0;
        mark=mark|4096;
        for(i=0; i<75; i++){
            ++step;
            find=flag[order[i]];
            if(find>0) mark=mark|map[find]; 
            for(j=0; j<12; j++){
                if((mark&bingo[j])==bingo[j]){
                   b=1;
                   break; 
                }
            }
            if(b) break;
        }
        printf("BINGO after %d numbers announced\n", step);
    }
    return 0;
}
