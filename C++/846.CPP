#include<iostream>
using namespace std;
int main()
{
	int a=0, x=0, y=0, differ=0, step=0, incr=0;
	cin >> a;
	while(a--){
		cin >> x >> y;
		differ=y-x;
		if(differ>=4){
			differ-=4; step=3; incr=2;
			while(differ>0){
				if(differ>=incr+incr+1){
					step+=2;
					differ=differ-incr-incr-1;
					incr++;
				}
				else if(differ>=incr+1){
					step+=2;
					break;
				}
				else{
					step++;
					break;
				}
			}
			cout << step << endl;
		} 
		else cout << differ << endl;
	}
	return 0;
}
