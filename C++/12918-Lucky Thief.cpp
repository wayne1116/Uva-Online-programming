#include<iostream>
using namespace std;
int main()
{
    int a;
    long long int n, m;
    long long int result=0;

    cin >> a;
    while(a-->0) {
        cin >> n >> m;
        result=(m-n)*n;
        result+=(n-1)*n/2;
        cout << result << endl;    
    }
    return 0;
}
