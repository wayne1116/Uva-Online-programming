#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
vector<int> vect[256];
queue<int> qu;
char dict[256][16];
int main()
{
	int a=0, i=0, j=0, k=0, step=0, len=0, num=0, temp=0, index, size=0, len1=0, len2=0, count=0;
	int state[256], flag=0;
	char line[256], *ptr, line1[256], line2[256];
	scanf("%d",&a);
	getchar(); getchar();
	while(a--){
		num=0;
		while(fgets(line,256,stdin)!=NULL && line[0]!='*'){
			len=strlen(line); line[len-1]='\0';
			strcpy(dict[num++],line);
		}
		for(i=0; i<num; i++){
			for(j=i+1; j<num; j++){
				len1=strlen(dict[i]);
				len2=strlen(dict[j]);
				if(len1==len2){
					count=0;
					for(k=0; k<len; k++) if(dict[i][k]!=dict[j][k]) count++;
					if(count==1){
						vect[i].push_back(j);
						vect[j].push_back(i);
					}
				}
			}
		}
		while(fgets(line,256,stdin)!=NULL){
			if(line[0]=='\n') break;
			len=strlen(line); line[len-1]='\0';
			ptr=strtok(line," "); strcpy(line1, ptr);
			ptr=strtok(NULL," "); strcpy(line2, ptr);
			for(i=0; i<num; i++){
				if(strcmp(dict[i],line1)==0) index=i;
				state[i]=0;
			}
			qu.push(index); state[index]=1; step=0; flag=0;
			while(strcmp(line1,line2)!=0){
				size=qu.size();
				while(size--){
					temp=qu.front(); qu.pop(); len=vect[temp].size();
					for(i=0; i<len; i++){
						if(strcmp(dict[vect[temp][i]],line2)==0){
							flag=1; step++;
							break;
						}
						else if(state[vect[temp][i]]==0){
							qu.push(vect[temp][i]);
							state[vect[temp][i]]=1;
						}
					}
					if(flag) break;
				}
				if(flag) break;
				step++;
			}
			printf("%s %s %d\n", line1, line2, step);
			while(!qu.empty()) qu.pop();
		}  
		for(i=0; i<num; i++) vect[i].clear();
		if(a) printf("\n");
	}
	return 0;
}
