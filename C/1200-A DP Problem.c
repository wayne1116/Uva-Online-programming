#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, num=0, num1x=0, num2x=0, temp1=0, temp2=0, flag=0;
	char line[512], *ptr;
	scanf("%d",&a);
	while(a--){
		scanf("%s",line);
		ptr=line; temp1=temp2=num1x=num2x=0;
		if(*ptr=='x'){
			num=1; temp1+=1;
		}
		else if(*ptr=='-'&&*(ptr+1)=='x'){
			num=-1; temp1-=1; ptr++;
		} 
		else{
			num=atoi(ptr); temp1+=num;
		}
		flag=0;
		while(*ptr){
			if(*ptr=='x'){
				if(flag==0) num1x+=num;
				else num2x+=num;	
			}
			else if(*ptr=='+'){
				num=atoi(ptr);ptr++;
				if(*ptr!='x'){
					if(flag==0)temp1+=num;
					else temp2+=num;
				}
				else{
					if(flag==0) {
						++temp1;
						++num1x;
					}
					else{
						++temp2;
						++num2x;
					}
				}
			}
			else if(*ptr=='-'){
				num=atoi(ptr);ptr++;
				if(*ptr!='x'){
					if(flag==0) temp1+=num;
					else temp2+=num;
				}
				else{
					if(flag==0){
						--temp1;
						--num1x;
					}
					else{
						--temp2;
						--num2x;
					}
				}
			}
			else if(*ptr=='='){
				flag=1; ptr++;
				if(*ptr=='x'){
					num=1; temp2+=1; num2x+=1;
				}
				else if(*ptr=='-'&&*(ptr+1)=='x'){
					num=-1; temp2-=1;
				} 
				else{
					num=atoi(ptr); temp2+=num;
				}
			}
			ptr++;
		}
		temp1-=num1x; temp2-=num2x;
		num1x-=num2x; temp2-=temp1;
		if(num1x==0 && temp2!=0) printf("IMPOSSIBLE\n");
		else if(num1x==0 && temp2==0) printf("IDENTITY\n");
		else printf("%d\n", temp2/num1x>0?(temp2/num1x):(temp2%num1x==0?temp2/num1x:(temp2/num1x-1)));
	}
	return 0;
}
