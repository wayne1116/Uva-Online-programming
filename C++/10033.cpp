#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[1024];
	int mem[1024], a, index, i, reg[10], pc, result, op, rs, rt;
	fgets(line,1024,stdin);
	a=atoi(line);
	fgets(line,1024,stdin);
	while(a--){
		index=0;
		for(i=0; i<1000; i++) mem[i]=0;
		while(fgets(line,1024,stdin)!=NULL && line[0]!='\n'){
			mem[index++]=atoi(line);
		}
		for(i=0; i<10; i++) reg[i]=0;
		pc=0;
		result=0;
		while(1){
			op=mem[pc]/100;
			rs=(mem[pc]/10)%10;
			rt=mem[pc]%10;
			++result;
			++pc;
			if(op==1) break;
			else if(op==2) reg[rs]=rt;
			else if(op==3) reg[rs]=(reg[rs]+rt)%1000;
			else if(op==4) reg[rs]=(reg[rs]*rt)%1000;
			else if(op==5) reg[rs]=reg[rt];
			else if(op==6) reg[rs]=(reg[rs]+reg[rt])%1000;
			else if(op==7) reg[rs]=(reg[rs]*reg[rt])%1000;
			else if(op==8) reg[rs]=mem[reg[rt]];
			else if(op==9) mem[reg[rt]]=reg[rs];
			else if(reg[rt]!=0) pc=reg[rs];	
		}
		printf("%d\n", result);
		if(a>0) printf("\n");
	}
	return 0;
}
