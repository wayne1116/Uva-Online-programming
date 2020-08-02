#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	char word[32];
	struct node *next;
};
int main()
{
	char word[32], c;
	struct node *head=NULL, *cur=NULL, *prev=NULL, *new1=NULL;
	int number=0, i=0;
	c=getchar();
	while(1){
		if(isalpha(c)){
			i=0;
			while(isalpha(c)){
				word[i++]=c;
				c=getchar();
			}
			word[i]='\0';
			new1=(struct node *)malloc(sizeof(struct node));
			strcpy(new1->word, word);
			new1->next=head;
			head=new1; 
			printf("%s",word);
		}
		else if(isdigit(c)){
			if(c=='0') break;
			i=0;
			while(isdigit(c)){
				word[i++]=c;
				c=getchar();
			}
			word[i]='\0';
			number=atoi(word);
			cur=prev=head;
			for(i=1; i<number; i++){
				prev=cur;
				cur=cur->next;
			}
			printf("%s",cur->word);
			if(cur!=head){
				prev->next=cur->next;
				cur->next=head;
				head=cur;
			}
		}
		else {
			printf("%c", c); 
			c=getchar();
		}
	}
	return 0; 
}
