#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float cal(char *find, char target)
{
	float temp;
	while(*find){
		if(*find>='0'&&*find<='9') break;
		find++;
	}
	temp=atof(find);
	while(*find){
		if(*find==target||*find=='m'||*find=='k'||*find=='M') break;
		find++;
	}
	if(*find=='m') temp*=0.001;
	else if(*find=='k') temp*=1000;
	else if(*find=='M') temp*=1000000;
	return temp;
}
int main()
{
	int a=0, count=0;
	char line[1024], *find;
	float Pvalue, Ivalue, Vvalue;
	scanf("%d",&a);
	getchar();
	while(a--){
		printf("Problem #%d\n", ++count);
		fgets(line,1024,stdin);
		Pvalue=Vvalue=Ivalue=-1;
		find=strstr(line,"I=");
		if(find!=NULL) Ivalue=cal(find,'A');
		
		find=strstr(line,"P=");
		if(find!=NULL) Pvalue=cal(find,'W');
		
		find=strstr(line,"U=");
		if(find!=NULL) Vvalue=cal(find,'V');
		
		if(Pvalue==-1) printf("P=%.2fW\n", Vvalue*Ivalue);
		else if(Vvalue==-1) printf("U=%.2fV\n",Pvalue/Ivalue);
		else printf("I=%.2fA\n",Pvalue/Vvalue);
		printf("\n"); 
	}
	return 0;
} 
