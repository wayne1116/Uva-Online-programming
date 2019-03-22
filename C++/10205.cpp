#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[1024];
	int a, b, num, i, j, poker[128][128], order[52], temp[52], flower, number;
	fgets(line,1024,stdin);
	a=atoi(line);
	fgets(line,1024,stdin);
	while(a--){
		scanf("%d",&num);
		for(i=0; i<num; i++){
			for(j=0; j<52; j++) scanf("%d",&poker[i][j]);
		}
		fgets(line,1024,stdin);
		for(i=2,j=0; i<=13; i++,j++) order[j]=i;
		order[j++]=1;
		for(i=15; i<=26; i++,j++) order[j]=i;
		order[j++]=14;
		for(i=28; i<=39; i++,j++) order[j]=i;
		order[j++]=27;
		for(i=41; i<=52; i++,j++) order[j]=i;
		order[j++]=40; 
		while(fgets(line,1024,stdin)!=NULL && line[0]!='\n'){
			b=atoi(line);
			for(i=0; i<52; i++)temp[i]=order[poker[b-1][i]-1]; //將數字poker[b-1][i]放進位置 i
			for(i=0; i<52; i++)order[i]=temp[i];
		}
		for(i=0; i<52; i++){
			flower=order[i]/13;
			number=order[i]%13;
			switch(number){
				case 0:
					printf("King");
					break;
				case 1:
					printf("Ace");
					break;
				case 11:
					printf("Jack");
					break;
				case 12:
					printf("Queen");
					break;
			    case 2:
			    case 3:
			    case 4:
			    case 5:
			    case 6:
			    case 7:
			    case 8:
			    case 9:
			    case 10:
			    	printf("%d",number);
			    	break;
			}
			printf(" of ");
			if(flower==0||(flower==1&&number==0)) printf("Clubs");
			else if(flower==1||(flower==2&&number==0)) printf("Diamonds");
			else if(flower==2||(flower==3&&number==0)) printf("Hearts");
			else printf("Spades");
			printf("\n");
		}
		if(a) printf("\n");
	}
	return 0;
}
