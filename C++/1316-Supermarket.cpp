#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
    int price;
    int deadline;
} lnode[10002];
bool cmp(struct Node &x, struct Node &y) {
    if(x.deadline==y.deadline)
        return x.price>y.price;
    return x.deadline<y.deadline;
}
int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > pq;

    while(cin >> n) {
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        
        for(int i=0; i<n; i++)
            cin >> lnode[i].price >> lnode[i].deadline;

        sort(lnode, lnode+n, cmp);
        lnode[n].deadline=-1;
        lnode[n].price=-1;
        
        int start=0;
        int end=1;
        int deadline=lnode[0].deadline;
        for(int i=1; i<=n; i++) {
            if(lnode[i].deadline==lnode[i-1].deadline)
                ++end;
            else{
                while(pq.size()<deadline && start<end){
                    pq.push(lnode[start].price);
                    ++start;
                }
                while(start<end) {
                    if(pq.top()>lnode[start].price)
                        break;
                    pq.pop();
                    pq.push(lnode[start].price);
                    ++start;
                }
                deadline=lnode[i].deadline;
                start=i;
                end=start+1;
            }
        }

        int result=0;
        while(pq.size()>0){
            result+=pq.top();
            pq.pop();
        }
        
        cout << result << endl;
    }

    return 0;
}
