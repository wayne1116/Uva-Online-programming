#include<iostream>
#include<algorithm>
using namespace std;
struct node{
        int x;
        int y;
        int h;
}lnode[300];
bool cmp(const node &x, const node &y)
{
        if(x.x==y.x)
                return x.y<y.y;
        return x.x<y.x;
}
int main()
{
        int num=0, case1=1;
        while((cin >> num)){
                if(num==0)
                        break;
                int count=0;
                for(int i=0; i<num; i++){
                        int num1=0, num2=0, num3=0;
                        cin >> num1 >> num2 >> num3;
                        lnode[count++]={num1,num2,num3};
                        lnode[count++]={num2,num1,num3};
                        lnode[count++]={num2,num3,num1};
                        lnode[count++]={num3,num2,num1};
                        lnode[count++]={num1,num3,num2};
                        lnode[count++]={num3,num1,num2};
                }
                sort(lnode, lnode+count, cmp);
                int LIS[300], max=0;
                for(int i=0; i<count; i++){
                        LIS[i]=lnode[i].h;
                        for(int j=0; j<i; ++j){
                                if(lnode[i].x>lnode[j].x && lnode[i].y>lnode[j].y && LIS[j]+lnode[i].h > LIS[i])
                                        LIS[i]=LIS[j]+lnode[i].h;
                        }
                        if(max<LIS[i])
                                max=LIS[i];
                }
                cout << "Case " << case1++ << ": maximum height = " << max << endl;
        }
        return 0;
}

