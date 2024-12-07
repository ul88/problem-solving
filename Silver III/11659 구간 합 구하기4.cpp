#include<iostream>
#define MAX 100000
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int prevSum[MAX+1]={0,};
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        prevSum[i+1] = prevSum[i] + a;
    }

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        cout<<prevSum[b]-prevSum[a-1]<<"\n";
    }
    return 0;
}