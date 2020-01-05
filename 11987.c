#include<stdio.h>
#include<stdlib.h>
int parent[100001];
int connect_set[100001];
int number[100001];
int sum[100001];

int find(int node)
{
    int node1;
    if(node!=parent[node]){
        node1=find(parent[node]);
        parent[node]=node1;
        node=node1;
    }
    return node;
}
int main()
{
    int n, com, command, set;
    int p, q, v1, v2;
    int i;
    while(scanf("%d %d", &n, &com)!=EOF){
        for(i=1; i<=n; i++){
            parent[i]=connect_set[i]=sum[i]=i;  // parent -> set ; connect_set -> node
            number[i]=1;                       
        }
        set=n+1;
        while(com--){
            scanf("%d %d", &command, &p);
            if(command==1){
                scanf("%d", &q);
                v1=find(connect_set[p]);
                v2=find(connect_set[q]);
                if(v1!=v2){
                    parent[v1]=v2;
                    number[v2]+=number[v1];
                    sum[v2]+=sum[v1];
                    number[v1]=sum[v1]=0;
                }
            }
            else if(command==2){
                scanf("%d", &q);
                v1=find(connect_set[p]);
                v2=find(connect_set[q]);
                connect_set[p]=set++;
                parent[connect_set[p]]=v2;
                number[v2]+=1;
                number[v1]-=1;
                sum[v1]-=p;
                sum[v2]+=p;
            }
            else{
                v1=find(connect_set[p]);
                printf("%d %d\n", number[v1], sum[v1]);
            }
        }
    }
    return 0;
}
