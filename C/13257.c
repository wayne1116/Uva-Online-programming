#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int value[100000];
    int order[100000];
    int count;
    short visited;
}lnode[26];

int main()
{
    int a, i, j;
    int len;
    int unness;
    int value;
    int index;
    int count;
    int result;
    char line[100001];

    scanf("%d", &a);
    while(a--){
        scanf("%s", line);
        len=strlen(line);
        if(len<3) printf("0\n");
        else{
            unness=0;
            value=0;
            for(i=0; i<26; i++){
                lnode[i].count=0;
                lnode[i].visited=0;
            }
            for(i=len-1; i>0; i--){
                index=line[i]-'A';
                count=lnode[index].count;
                lnode[index].value[count]=value-unness;
                lnode[index].order[count]=i;
                ++value;
                if(lnode[index].count!=0) ++unness;
                ++lnode[index].count;
            }

            result=0;

            for(i=0; i<len-2; i++){
                index=line[i]-'A';
                if(!lnode[index].visited){
                    if(lnode[index].count>0 && i>0) --lnode[index].count;
                    for(j=0; j<26; j++){
                        count=lnode[j].count-1;
                        if(lnode[j].order[count]>i){
                            result+=lnode[j].value[count];
                        }
                    }
                } 
                else --lnode[index].count;
                lnode[index].visited=1;
            }
            printf("%d\n", result);
        }
    }
    return 0;
}
