#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    string car_name;
    int lower_price;
    int upper_price;
} lnode[10000];
bool cmp(const struct Node &a, const struct Node &b) {
    return a.upper_price<b.upper_price;
}
int main()
{
    int a, n, m, price;
    cin >> a;
    while(a-->0) {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> lnode[i].car_name >> lnode[i].lower_price >> lnode[i].upper_price;
        //sort(lnode, lnode+n, cmp); 
        cin >> m;
        for(int i=0; i<m; i++) {
            cin >> price;
            int count=0;
            int index=0;
            for(int j=0; j<n; j++) {
                if(count>1)
                    break;
                if(lnode[j].lower_price<=price && lnode[j].upper_price>=price){
                    ++count;
                    index=j;
                }
            }
            if(count==1)
                cout << lnode[index].car_name << endl;
            else
                cout << "UNDETERMINED" << endl;
        }
        if(a>0)
            cout << endl;
    }
    return 0;
}
