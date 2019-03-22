#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a=0, n=0, m=0, i=0, j=0;
	int max=0, count=0, temp=0, index=0;
	while(scanf("%d",&a)!=EOF){
		while(a--){
			scanf("%d %d",&n, &m);
			max=0;
			for(i=n; i<=m; i++){
				temp=sqrt(i); count=0;
				for(j=1; j<=temp; j++)
					if(i%j==0){
						if(i/j==j) count++;
						else count+=2;
					}
				if(max<count){
					index=i;
					max=count;
				} 
			}
			printf("Between %d and %d, %d has a maximum of %d divisors.\n", n, m, index, max);
		}
	}
	return 0;
}
