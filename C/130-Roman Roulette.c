#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
int main()
{
	int n=0, k=0, posi=0, count=0, state=0, temp=0, i, j, temp1;
	int dead[128], pos[128];
	while(scanf("%d%d",&n,&k)&&n&&k){
		if(n==1) printf("1\n");
		else{
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					pos[j]=j;
					dead[j]=0;
				}
				count=n; posi=i; state=1;
				while(count>1){
					for(j=1; j<k; j++){
						do{
							posi++;
							if(posi>=n) posi=0;
						}while(dead[pos[posi]]);
					}
					if(pos[posi]==0){
						state=0;
						break;
					} 
					dead[pos[posi]]=1; temp=posi;
					for(j=0; j<k; j++){
						do{
							temp++;
							if(temp>=n) temp=0;
						}while(dead[pos[temp]]);
					}
					swap(pos[posi],pos[temp], temp1);
					do{
						posi++;
						if(posi>=n) posi=0;
					}while(dead[pos[posi]]);
					count--;
				}
				if(state){
					printf("%d\n", i+1);
					break;
				}
			} 
		}
	}
	return 0;
}
