#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<char> set1[8];
	set<char>::iterator iter1, iter2, iter3, iter4, iter5;
	int a, n, i, j, k, count, size;
	string line1[8], line2[8];
	bool flag=false;
	cin >> a;
	while(a--){
		cin >> n;
		size=1;
		for(i=0; i<6; i++) cin >> line1[i];
		for(i=0; i<6; i++) cin >> line2[i];
		for(i=0; i<5; i++){
			for(j=0; j<6; j++){
				for(k=0; k<6; k++){
					if(line1[j][i]==line2[k][i]) set1[i].insert(line1[j][i]);
				}
			}
			size*=set1[i].size();
		}
		if(size<n) cout << "NO" << endl;
		else{
			flag=false;
			count=0;
			for(iter1=set1[0].begin(); iter1!=set1[0].end(); ++iter1){
				for(iter2=set1[1].begin(); iter2!=set1[1].end(); ++iter2){
					for(iter3=set1[2].begin(); iter3!=set1[2].end(); ++iter3){
						for(iter4=set1[3].begin(); iter4!=set1[3].end(); ++iter4){
							for(iter5=set1[4].begin(); iter5!=set1[4].end(); ++iter5){
								++count;
								if(count==n){
									cout << *iter1 << *iter2 << *iter3 << *iter4 << *iter5 << endl;
									flag=true;
									break;
								}
							}
							if(flag) break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
		}
		for(i=0; i<5; i++) set1[i].clear();
	}
	return 0;
}
