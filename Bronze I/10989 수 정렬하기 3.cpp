#include<iostream>
#include<algorithm>
#define MAX 10000
#define INF INT32_MAX
using namespace std;
int arr[MAX+1]={0,};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, m=INF, M=-INF;
    
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        arr[a]++;
        m = min(m,a);
        M = max(M,a);
    }

    for(int i=m;i<=M;i++){
        for(int j=0;j<arr[i];j++){
            cout<<i<<"\n";
        }
    }
}