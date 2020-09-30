#include<iostream>
#include<algorithm>
using namespace std;
int ans[8192];
int countbit(int i)
{
	int count=0;
	while(i>0){
		count+=i&1;
		i>>=1;
	}
	return count;
}
int main()
{
	int num[16][8];
	int result[16][16], result1[16], parent[8192];
	int i, j, k;
	int count, location, temp, temp1, temp2, bonus;
	int count1[8];
	bool flag2, flag3;
	
	while(cin>>num[0][0]){
		for(i=1; i<5; i++) cin>>num[0][i];
		for(i=1; i<13; i++){
			for(j=0; j<5; j++) cin>>num[i][j];
		}
		for(i=0; i<13; i++){
			for(j=0; j<6; j++){
				count=0;
				for(k=0; k<5; k++) if(num[i][k]==j+1) ++count;
				result[i][j]=count*(j+1);
			}
			count=0;
			for(j=0; j<5; j++) count+=num[i][j];
			result[i][6]=count;
			for(j=1; j<=6; j++) count1[j]=0;
			for(j=0; j<5; j++) ++count1[num[i][j]];
			
			for(j=7; j<13; j++) result[i][j]=0;
			for(j=1; j<=6; j++) if(count1[j]>=3) result[i][7]=result[i][6];
			for(j=1; j<=6; j++) if(count1[j]>=4) result[i][8]=result[i][6];
			for(j=1; j<=6; j++) if(count1[j]==5) result[i][9]=50;
			if(count1[3]&&count1[4]&&((count1[1]&&count1[2])||(count1[2]&&count1[5])||(count1[5]&&count1[6]))) result[i][10]=25;
			if(count1[2]&&count1[3]&&count1[4]&&((count1[1]&&count1[5])||(count1[5]&&count1[6]))) result[i][11]=35;
			flag2=flag3=false;
			for(j=1; j<=6; j++){
				if(count1[j]==3) flag3=true;
				else if(count1[j]==2) flag2=true;
			}
			if(flag3&&flag2) result[i][12]=40;
		}
		
		for(i=0; i<16; i++) result1[i]=0;
		for(i=0; i<8192; i++) ans[i]=0;
		for(i=0; i<13; i++){ //category
			for(j=0; j<8192; j++){ //mask,作用為紀錄已用過的dice編號 
				if(countbit(j)==i){
					for(k=0; k<13; k++){ // dice
						if(!((j>>k)&1)){
							temp1=j|(1<<k);
							temp2=ans[j]+result[k][i];
							bonus=0;
							if(i==5&&temp2>=63) bonus=35;
							if(ans[temp1]<temp2+bonus){
								ans[temp1]=temp2+bonus;
								parent[temp1]=k;
							}
						}
					}
				}
			}
		} 
		temp1=8191;
		for(i=12; i>=0; i--){
			result1[i]=result[parent[temp1]][i];
			temp1^=1<<parent[temp1];
		}
		temp1=bonus=0; //bonus
		for(i=0; i<6; i++) temp1+=result1[i];
		if(temp1>=63) bonus=35;
		
		for(i=0; i<13; i++) cout << result1[i] << " ";
		cout << bonus << " " << ans[8191] << endl; 
	}
	return 0;
}
