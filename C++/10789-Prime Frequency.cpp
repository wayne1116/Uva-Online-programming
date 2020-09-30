#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<set>
using namespace std;
int main()
{
	int i=0, j=0, temp=0, state=0, result=0, a=0, count[128];
	set<int> set1;
	char line[2048], *ptr;
	for(i=2; i<=2001; i++){
		temp=sqrt(i); state=1;
		for(j=2; j<=temp; j++){
			if(i%j==0){
				state=0;
				break;
			}
		}
		if(state) set1.insert(i);
	}
	scanf("%d", &a);
	for(i=1; i<=a; i++){
		scanf("%s", line);
		ptr=line;
		for(j=0; j<128; j++) count[j]=0;
		while(*ptr){
			count[*ptr]++;
			ptr++;
		}
		result=0;
		printf("Case %d: ", i);
		for(j=0; j<128; j++)
			if(set1.count(count[j])){
				printf("%c", j);
				result++;
			}
		if(result==0) printf("empty");
		printf("\n");
	}
	return 0;
}
