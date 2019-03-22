#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0, j=0, n=0, count=0, num[1024], temp;
	while(scanf("%d",&n)!=EOF){
		for(i=0; i<n; i++) scanf("%d",&num[i]);
		count=0;
		for(i=0; i<n; i++){
			for(j=0; j<n-1-i; j++){
				if(num[j]>num[j+1]){
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
					++count;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", count);
	}
	return 0;
}
