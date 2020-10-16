#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i, n, j, k, count, row, total, temp1, temp, l, cur, temp2;
	int num[128], result[128];
	int flag[128];
	while(cin>>n){
		count=n*(n-1)/2;
		total=0;
		for(i=0; i<count; i++){
			cin>>num[i];
			total+=num[i];
		}
		sort(num,num+count);
		
		if(total%(n-1)!=0) cout << "Impossible" << endl;
		else{
			temp=num[0]+num[1]; //x2-x3
			for(i=2; i<count; i++){
				for(j=0; j<count; j++) flag[j]=0;
				flag[0]=flag[1]=1;
				if((temp-num[i])%2==0){
					result[0]=(temp-num[i])/2;
					result[1]=num[0]-result[0];
					result[2]=num[1]-result[0];
					flag[i]=1;
					//for(j=2; j<=i; j++){
					//		result[j]=num[j-1]-result[0];
					//		flag[j-1]=1;
					//}
					cur=3;
					for(j=2; j<count; j++){
						temp1=num[j]-result[0];
						for(k=0; k<cur; k++){
							temp2=temp1+result[k];
							for(l=0; l<count; l++){
								if(flag[l]==0&&temp2==num[l]){
									flag[l]=2;
									break;
								}
							}
							if(l>=count) break;
						}
						if(k>=cur){
							result[cur++]=temp1;
							for(k=0; k<count; k++) if(flag[k]==2) flag[k]=1;
						}
						else{
							for(k=0; k<count; k++) if(flag[k]==2) flag[k]=0;
						}
					}
					if(cur>=n) break;
				}
				
			}
			//cout << j << endl;
			if(cur!=n) cout << "Impossible" << endl;
			else{
				for(i=0; i<n-1; i++) cout << result[i] << " " ;
				cout << result[i] << endl;
			}
		} 
	}
	return 0;
}
