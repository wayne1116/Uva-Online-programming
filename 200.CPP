#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> order[26];
int visited[26], result[26], count=0;
void dfs(int start)
{
	int i=0;
	if(visited[start]==1) return ;
	visited[start]=1;
	for(i=0; i<order[start].size(); i++){
		if(visited[order[start][i]]!=2){
			dfs(order[start][i]);
		}
	}
	visited[start]=2;
	result[count++]=start+65;
}
int main()
{
	int i=0, used[26];
	char line1[1024], line2[1024], *ptr1, *ptr2;
	for(i=0; i<26; i++) visited[i]=used[i]=0;
	scanf("%s",&line1);
	while(scanf("%s",&line2) && line2[0]!='#'){
		ptr1=line1; ptr2=line2;
		while(*ptr1 && *ptr2){
			if(used[*ptr1-65]==0)used[*ptr1-65]=1;
			if(used[*ptr2-65]==0)used[*ptr2-65]=1;
			if(*ptr1!=*ptr2){
				order[*ptr1-65].push_back(*ptr2-65);
				used[*ptr2-65]=2;
				break;
			}
			ptr1++;ptr2++;
		}
		strcpy(line1,line2);
	}
	for(i=0; i<26; i++){
		if(used[i]==1){
			dfs(i);
			break;
		}
	}
	for(i=count-1; i>=0; i--) printf("%c",result[i]);
	printf("\n");
	return 0;
}
