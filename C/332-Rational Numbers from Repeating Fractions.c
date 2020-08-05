#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int a=0, len=0, number3=0, number4=0, divid=0, numer=0, i=0, com=0, count=1;
	int number1=0, number2=0;
	char line[32];
	while(scanf("%d",&a)){
		if(a==-1) break;
		scanf("%s",line);
		len=strlen(line)-2;
		if(a==0){
			divid=1; numer=0;
			for(i=0; i<len; i++){
				divid*=10;
				numer=numer*10+line[i+2]-48;
			}
		}
		else{
			number1=number2=1; number3=0;
			for(i=0; i<len-a; i++){
				number1*=10;
				number3=number3*10+line[i+2]-48;
			}
			number4=0;
			for(i=0; i<len; i++){
				number2*=10;
				number4=number4*10+line[i+2]-48;
			}
			divid=(number2-number1);
			numer=number4-number3;
		}
		com=gcd(numer,divid); 
		printf("Case %d: %d/%d\n", count++, numer/com, divid/com);
	}
	return 0;
}
