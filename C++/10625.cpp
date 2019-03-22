#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
int main()
{
	int a, b, i, j, len, step, n;
	unsigned long long number[128], temp[128], flag;
	char c, target, init[128], line[128];
	map<int,unsigned long long> mmap[128];
	map<int,unsigned long long>::iterator iter;
	 
	scanf("%d",&a);
	while(a--){
		scanf("%d",&n);
		for(i=0; i<128; i++) mmap[i].clear();
		for(i=0; i<n; i++){
			getchar();
			scanf("%c->%s",&c,line);
			len=strlen(line);
			for(j=0; j<len; j++) ++mmap[c][line[j]];
		}
		scanf("%d",&b);
		while(b--){
			scanf("%s %c %d",init,&target,&step);
			len=strlen(init);
			for(i=0; i<128; i++) number[i]=0;
			for(i=0; i<len; i++) ++number[init[i]];
			while(step--){
				for(i=33; i<=126; i++) temp[i]=0;
				for(i=33; i<=126; i++){
					flag=1;
					for(iter=mmap[i].begin(); iter!=mmap[i].end(); iter++){
						temp[iter->first]+=number[i]*iter->second;
						flag=0;
					}
					temp[i]+=number[i]*flag;
				}
				for(i=33; i<=126; i++) number[i]=temp[i];
			}
			printf("%llu\n", number[target]);
		}
		
	}
	return 0;
}
