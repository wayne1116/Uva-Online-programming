#include<iostream>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
int graph[256][256];
int main()
{
    int n, m, i;
    int v1, v2;
    int count;
    int value;
    int index=0;
    string city1, city2;
    int weight[256];
    map<string, int> mmap;
    queue<int> qu;
    while(cin>>n>>m){
        if(n+m==0) break;
        memset(graph, 0, sizeof(graph));
        mmap.clear();
        count=0;
        while(m--){
            cin >> city1 >> city2 >> value;
            if(mmap.find(city1)==mmap.end()) mmap[city1]=count++;
            v1=mmap[city1];
            if(mmap.find(city2)==mmap.end()) mmap[city2]=count++;
            v2=mmap[city2];
            graph[v1][v2]=value;
            graph[v2][v1]=value;
        }
        cin >> city1 >> city2;
        v1=mmap[city1];
        v2=mmap[city2];
        memset(weight, 0, sizeof(weight));
        qu.push(v1);
        weight[v1]=20000;
        while(!qu.empty()){
            v1=qu.front();
            qu.pop();
            for(i=0; i<n; i++){
                if(graph[v1][i]>0){
                    value=min(weight[v1], graph[v1][i]);
                    if(value>weight[i]){
                        qu.push(i);
                        weight[i]=value;
                    }
                }
            }
        }
        cout << "Scenario #" << ++index << endl;
        cout <<  weight[v2] << " tons" << endl << endl;
    }
    return 0;
}
