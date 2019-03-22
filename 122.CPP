#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
	int num;
	char com[512];
};
int cmp(const void *x, const void *y)
{
	int len1=strlen(((struct Node*)x)->com);
	int len2=strlen(((struct Node*)y)->com);
	if(len1==len2) return strcmp(((struct Node*)x)->com,((struct Node*)y)->com);
	return len1-len2;
}
int main()
{
	char line[512], *ptr;
	int state=0, count=0, len=0, number=0, i=0, flag=0, j=0;
	Node lnode[256];
	
	while(cin>>line){
		if(line[0]=='(' && line[1]==')'){
			if(state) cout << "not complete" << endl;
			else{
				qsort(lnode,count,sizeof(struct Node),cmp);
				if(lnode[0].com[0]!='\0') cout << "not complete" << endl;
				else{
					flag=0;
					for(i=1; i<count; i++){
						flag=1;
						for(j=i-1; j>=0; j--){
							if(strlen(lnode[i].com)-1==strlen(lnode[j].com) && !strncmp(lnode[i].com,lnode[j].com,strlen(lnode[j].com))){
								flag=0;
								break;
							}
						}
						if(flag){
							cout << "not complete" << endl;
							break;
						}
					}
					if(!flag){
						for(i=0; i<count-1; i++) cout << lnode[i].num << " ";
						cout << lnode[i].num << endl; 
					}
				}
			}
			state=count=0;
		}
		else{
			ptr=line; len=strlen(line);
			line[len-1]='\0'; flag=0;
			while(*ptr){
				if(*ptr>='0' && *ptr<='9'){
					flag=1;
					number=atoi(ptr);		
					break;
				}
				ptr++;
			}
			while(*ptr){
				if(*ptr==',') break;
				ptr++;
			}
			ptr++;
			if(flag){
				for(i=0; i<count; i++){
					if(strcmp(lnode[i].com,ptr)==0 && *ptr!='\0'){
						state=1; break;
					}
				}
				if(!state){
					lnode[count].num=number;
					strcpy(lnode[count].com,ptr);
					count++;
				}
			}
			else state=1;
		}
	}
	return 0;
}
