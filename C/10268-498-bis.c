#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int number[1000000];
int main()
{
    long long int x, i;
    int index;
    char c;
    long long int result;
    long long int mul=0;
    while(scanf("%lld", &x)!=EOF) {
        index=0;
        while (scanf("%lld%c",&number[index++], &c)) {
            if (c!=' ')
                break;
        }
        
        result=0;
        mul=1;
        for(i=index-2; i>=0; i--){
            result+=(index-i-1)*number[i]*mul;
            mul*=x;
        }
        printf("%lld\n", result);   
    }
    return 0;
}
