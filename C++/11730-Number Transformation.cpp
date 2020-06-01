#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int number[1024][1024];
int main()
{
    int a, b;
    int index=1;
    int prime[1024];
    int count[1024];
    bool flag[2048];
    
    prime[0]=2;
    for(int i=3; i<=1000; i+=2){
        int limit=sqrt(i);
        int j=0;
        for(j=3; j<=limit; j+=2){
            if(i%j==0)
                break;
        }
        if(j>limit)
            prime[index++]=i;
    }

    for(int i=0; i<1001; i++) {
        count[i]=0;
        for(int j=0; j<index; j++) {
            if(i<=prime[j])
                break;
            if(i%prime[j]==0) {
                number[i][count[i]]=prime[j];
                ++count[i];
            }
        }
    }

    int index1=1;
    queue<int> qu;
    while(cin>>a>>b) {
        if(a==0 || b==0)
            break;

        for(int i=0; i<2048; i++)
            flag[i]=false;

        qu.push(a);
        flag[a]=true;
        int result=0;
        bool find=false;
        while(qu.size()>0) {
            int len=qu.size();
            while(len-->0) {
                int v=qu.front();
                if(v==b){
                    find=true;
                    break;
                }
                qu.pop();
                for(int i=0; i<count[v]; i++) {
                    if(number[v][i]+v<=b && !flag[number[v][i]+v]){
                        flag[number[v][i]+v]=true;
                        qu.push(number[v][i]+v);
                    }
                }
            }

            if(find) break;
            ++result;
        }

        cout << "Case " << index1++ << ": " << (find==true?result:-1) << endl;
        while(qu.size()>0)
            qu.pop();
    }

    return 0;
}
