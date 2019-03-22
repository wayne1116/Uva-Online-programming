#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[8][8];
	int play1[16], play2[16], max1=0, max2=0, i=0, flower1[4], flower2[4], rank1=0, rank2=0;
	int count=0, temp1[4], temp2[4];
	
	while(scanf("%s%s%s%s%s",line[0],line[1],line[2],line[3],line[4])!=EOF){
		for(i=0; i<13; i++) play1[i]=play2[i]=0;
		for(i=0; i<4; i++) flower1[i]=flower2[i]=0;
		for(i=0; i<5; i++){
			if(line[i][0]=='A') ++play1[0];
			else if(line[i][0]=='T') ++play1[9];
			else if(line[i][0]=='J') ++play1[10];
			else if(line[i][0]=='Q') ++play1[11];
			else if(line[i][0]=='K') ++play1[12];
			else ++play1[line[i][0]-48-1];
			
			if(line[i][1]=='C') ++flower1[0];
			else if(line[i][1]=='D') ++flower1[1];
			else if(line[i][1]=='H') ++flower1[2];
			else ++flower1[3];
		}
		/*High card*/ 
		rank1=1; max1=-1;
		for(i=0; i<13; i++)if(play1[i]>0 && max1<i) max1=i;
		if(play1[0]>0) max1=13;
		/*Pair two pairs*/ 
		count=0;
		for(i=0; i<13; i++){
			if(play1[i]==2){
				if(count==0){
					rank1=2;
					count++;
				}
				else rank1=3;
			}
		}
		/*three of a kind*/ 
		for(i=0; i<13; i++){
			if(play1[i]==3){
				if(rank1==2) rank1=7; /*full house*/
				else rank1=4;
				if(i!=0)max1=i;
				else max1=13;
				break;
			}
		}
		/*straight*/
		for(i=0; i<13; i++){
			if(play1[i%13]==1&&play1[(i+1)%13]==1&&play1[(i+2)%13]==1&&play1[(i+3)%13]==1&&play1[(i+4)%13]==1) rank1=5;
		}
		/*flush*/
		for(i=0; i<4; i++) {
			if(flower1[i]==5){
				if(rank1!=5) rank1=6;
				else rank1=9;
			}
		}
		/*four of a kind*/
		for(i=0; i<13; i++){
			if(play1[i]==4){
				if(i!=0)max1=i;
				else max1=13;
				rank1=8;
				break;
			}
		}
		
		scanf("%s%s%s%s%s",line[0],line[1],line[2],line[3],line[4]);
		for(i=0; i<5; i++){
			if(line[i][0]=='A') ++play2[0];
			else if(line[i][0]=='T') ++play2[9];
			else if(line[i][0]=='J') ++play2[10];
			else if(line[i][0]=='Q') ++play2[11];
			else if(line[i][0]=='K') ++play2[12];
			else ++play2[line[i][0]-48-1];
			
			if(line[i][1]=='C') ++flower2[0];
			else if(line[i][1]=='D') ++flower2[1];
			else if(line[i][1]=='H') ++flower2[2];
			else ++flower2[3];
		}
		/*High card*/ 
		rank2=1; max2=-1;
		for(i=0; i<13; i++)if(play2[i]>0 && max2<i) max2=i;
		if(play2[0]>0) max2=13;
		/*Pair two pairs*/ 
		count=0;
		for(i=0; i<13; i++){
			if(play2[i]==2){
				if(count==0){
					rank2=2;
					count++;
				}
				else rank2=3;
			}
		}
		/*three of a kind*/ 
		for(i=0; i<13; i++){
			if(play2[i]==3){
				if(rank2==2) rank2=7; /*full house*/
				else rank2=4;
				if(i!=0)max2=i;
				else max2=13;
				break;
			}
		}
		/*straight*/
		for(i=0; i<13; i++){
			if(play2[i%13]==1&&play2[(i+1)%13]==1&&play2[(i+2)%13]==1&&play2[(i+3)%13]==1&&play2[(i+4)%13]==1) rank2=5;
		}
		/*flush*/
		for(i=0; i<4; i++) {
			if(flower2[i]==5){
				if(rank2!=5) rank2=6;
				else rank2=9;
			}
		}
		/*four of a kind*/
		for(i=0; i<13; i++){
			if(play2[i]==4){
				if(i!=0)max2=i;
				else max2=13;
				rank2=8;
				break;
			}
		}
	
		if(rank1>rank2) printf("Black wins.\n");
		else if(rank1<rank2) printf("White wins.\n");
		else{
			if(rank1==3){
				for(i=0, count=0; i<13; i++)if(play1[i]==2)temp1[count++]=i;
				for(i=0, count=0; i<13; i++)if(play2[i]==2)temp2[count++]=i;
				if(temp1[1]>temp2[1]) printf("Black wins.\n");
				else if(temp1[1]<temp2[1]) printf("White wins.\n");
				else if(temp1[0]<temp2[0]) printf("White wins.\n");
				else if(temp1[0]>temp2[0]) printf("Black wins.\n");
				else{
					for(i=0; i<13; i++) if(play1[i]==1) max1=i;
					if(max1==0) max1=13;
					for(i=0; i<13; i++) if(play2[i]==1) max2=i;
					if(max2==0) max2=13;
					if(max1>max2) printf("Black wins.\n");
					else if(max1<max2) printf("White wins.\n");
					else printf("Tie.\n");
				}
			}
			else if(rank1==1||rank1==5||rank1==6||rank1==9){
				for(i=13; i>0; i--){
					if(play1[i%13]>play2[i%13]){
						printf("Black wins.\n");
						break;
					}
					else if(play1[i%13]<play2[i%13]){
						printf("White wins.\n");
						break;
					}
				}
				if(i==0) printf("Tie.\n");
			}
			else if(rank1==2){
					for(i=0; i<13; i++){
							if(play1[i]==2){
									if(i!=0) max1=i;
									else max1=13;
									break;
							}
					}
					for(i=0; i<13; i++){
							if(play2[i]==2){
									if(i!=0) max2=i;
									else max2=13;
									break;
							}
					}
					if(max1>max2) printf("Black wins.\n");
					else if(max1<max2) printf("White wins.\n");
					else{
							for(i=13; i>0; i--){
									if(play1[i%13]>play2[i%13]){
											printf("Black wins.\n");
											break;
									}
									else if(play1[i%13]<play2[i%13]){
											printf("White wins.\n");
											break;
									}
							}
							if(i==0) printf("Tie.\n");
					}
			}
			else{
				if(max1>max2) printf("Black wins.\n");
				else if(max1<max2) printf("White wins.\n");
				else printf("Tie.\n");
			}
		}
	}
	return 0;
}
