#include<stdio.h>
#include<stdlib.h>

int main()
{
    int h1, m1;
    int h2, m2;
    int time1, time2;
    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)!=EOF){
        if(h1+m1+h2+m2==0) break;
        time1=h1*60+m1;
        time2=h2*60+m2;
        printf("%d\n", (time2-time1+1440)%1440);
    }
    return 0;
}
