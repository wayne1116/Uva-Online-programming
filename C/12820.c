#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a, i, j;
    int flag;
    int index=1;
    int result=0;
    int count[26];
    char *ptr;
    char line[10001];

    while(scanf("%d", &a)!=EOF){
        result=0;
        while(a--){
            memset(line, '\0', sizeof(line));
            scanf("%s", line);
            memset(count, 0, sizeof(count));
            ptr=line;
            while(*ptr){
                ++count[*ptr-'a'];
                ptr++;
            }
            flag=0;
            for(i=0; i<26; i++){
                for(j=i+1; j<26; j++){
                    if(count[i]==count[j] && (count[i]!=0 || count[j]!=0)) flag=1;
                }    
            }
            if(flag==0 && strlen(line)>1) ++result;
        }
        printf("Case %d: %d\n", index++, result);
    }
    return 0;
}
