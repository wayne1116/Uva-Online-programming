#include<stdio.h>
#include<stdlib.h>
#include<float.h>
struct node{
	float x,y;
};
int cmp(const void *x, const void *y)
{
	return *(float*)x>*(float*)y;
}
int main()
{
	int a=0, i=0, j=0, count=0, max=0, result=0, temp=0, k=0;
	char line[1024];
	struct node lnode[1024];
	float s[1024];
	
	scanf("%d",&a);
	getchar();
	fgets(line,1024,stdin);
	while(a--){
		if(k>0) printf("\n");
		count=0;
		while(fgets(line,1024,stdin)&&line[0]!='\n'){
			sscanf(line,"%f%f",&lnode[count].x,&lnode[count].y);
			count++;
		}
		max=0;
		for(i=0; i<count; i++){
			temp=0;
			for(j=0; j<count; j++){
				if(i==j) continue;
				else if((lnode[i].x-lnode[j].x)==0) s[temp++]=FLT_MAX;
				else s[temp++]=(lnode[i].y-lnode[j].y)/(lnode[i].x-lnode[j].x);
			}
			qsort(s,temp,sizeof(float),cmp);
			result=1;
			for(j=1; j<temp; j++){
				if(s[j]==s[j-1]) result++;
				else{
					if(max<result) max=result;
					result=1;
				}
			}	
			if(max<result) max=result;
		}
		printf("%d\n", max+1);
		k++;
	}
	return 0;
}
