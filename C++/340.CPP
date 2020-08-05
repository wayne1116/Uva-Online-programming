#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0, j=1, a=0, result1=0, result2=0;
	int number[1024], temp[1024], loc[1024], loc1[1024], correct[1024];
	while(scanf("%d",&a)&&a){
		for(i=1; i<=9; i++) loc[i]=0;
		for(i=0; i<a; i++){
			scanf("%d",&correct[i]);
			loc[correct[i]]++;
		}
		printf("Game %d:\n", j);
		while(scanf("%d",&number[0])&&number[0]){
			for(i=1; i<=9; i++){
				temp[i]=loc[i];
				loc1[i]=0;
			}
			loc1[number[0]]++;
			for(i=1; i<a; i++){
				scanf("%d",&number[i]);
				loc1[number[i]]++;
			}
			result1=0;
			for(i=0; i<a; i++){
				if(correct[i]==number[i]){
					result1++;
					loc1[number[i]]--;
					temp[number[i]]--;
				}
			}
			result2=0;
			for(i=1; i<=9; i++){
				result2+=min(loc1[i],temp[i]);
			}
			printf("    (%d,%d)\n", result1, result2);
		}
		for(i=1; i<a; i++) scanf("%d", &number[i]);
		j++;
	}
	return 0;
}
