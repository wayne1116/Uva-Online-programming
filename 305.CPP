#include<stdio.h>
#include<stdlib.h>
int main()
{
	int result[15]={0};
	int people, i, m, cur, a;
	for(i=1; i<15; i++){
		m=i;
		while(1){
			cur=0; people=i*2;
			while(people>i){
				cur=(cur+m)%people;
				if(cur<i) break;
				cur=cur%people;
				--people;
			}
			if(people<=i){
				result[i]=m;
				break;
			}
			m++;
		}
	}
	while(scanf("%d",&a)!=EOF && a)
		printf("%d\n", result[a]+1);
	return 0;
}
