#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int K,C;
    cin>>K>>C;
    for(int i=0;i<C;i++){
        int M,N;
        cin>>M>>N;
        if(M == N) cout<<1<<"\n";
        else if(M>N && K-M+1+N+1 >= M) cout<<1<<"\n";
        else if(M<N && K-N+1+M >= N) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}