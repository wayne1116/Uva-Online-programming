#include<stdio.h>
#include<stdlib.h>
int voter[1024][22];
int main()
{
	int a=0, n=0, i=0, count=0, temp=0, j=0, k=0, loc;
	int pass, result, min, index=0, index1, max;
	int state[21], number[21];
	char name[21][128], *ptr, line[256];
	
	scanf("%d",&a);
	while(a--){
		scanf("%d",&n); getchar();
		for(i=0; i<n; i++){
			fgets(name[i],128,stdin);
			state[i]=number[i]=0;
		}
		count=0;
		while(fgets(line,256,stdin)!=NULL){
			if(line[0]<'0' || line[0]>'9') break;
			ptr=line; voter[count][0]=atoi(ptr)-1;
			temp=1; ++number[voter[count][0]];
			while(*ptr){
				if(*ptr==' ')
					voter[count][temp++]=atoi(ptr)-1;
				ptr++;
			}
			voter[count][temp]=0;
			++count;
		}
		pass=count/2+1;                          /*票數需要過半*/ 
		for(k=0; k<n; k++){
			max=0; min=2147483647;
			for(i=0; i<n; i++){
				if(state[i]==0 && number[i]>max){
					max=number[i];
					index=i;
				}
				if(state[i]==0 && number[i]<min){
					min=number[i];
				}
			}
			if(max==min){                        /*如果票數都相同*/ 
				for(i=0; i<n; i++){
					if(!state[i]) printf("%s",name[i]);
				}
				break;
			}
			if(max>=pass){                      /*如果其中一個票數過半*/ 
				printf("%s",name[index]);
				break;
			}
			else{
				for(i=0; i<n; i++) if(min==number[i]) state[i]=1;   /*票數最小的*/ 
				for(i=0; i<count; i++){                             /*投給票數最小的選民票給次順位的候選人*/ 
					loc=voter[i][n];
					if(min==number[voter[i][loc]]){
						while(state[voter[i][loc]]) ++loc;
						++number[voter[i][loc]];
						voter[i][n]=loc;
					}
				}
			}
		}
		if(a) printf("\n");
	}
	return 0;
}
