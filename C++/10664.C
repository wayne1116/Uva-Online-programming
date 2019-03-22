#include<stdio.h>
#include<stdlib.h>
int cmp(const void *x, const void *y)
{
		return *(int *)y-*(int *)x;
}
int main()
{
		char line[1024], line1[1024], *ptr;
		int i=0, a=0, count=0, sum=0, j=0, number[1024];
		while(fgets(line, 1024, stdin)!=NULL){
				a=atoi(line);
				for(i=0; i<a; i++){
						fgets(line1, 1024, stdin);
						ptr=line1;
						number[0]=atoi(ptr);
						sum=number[0];
						count=1;
						while(*ptr){
								if(*ptr==' '){
										ptr++;
										number[count]=atoi(ptr);
										sum+=number[count];
										count++;
								}
								ptr++;
						}
						if(sum%2!=0){
								printf("NO\n");
						}
						else{
								sum=sum/2;
								qsort(number, count, sizeof(int), cmp);
								if(number[0]>sum)
										printf("NO\n");
								else{
										for(j=0; j<count; j++){
												if(sum>=number[j])
														sum-=number[j];
										}
										if(sum==0)
												printf("YES\n");
										else
												printf("NO\n");
								}
						}
				}
		}
		return 0;
}
