#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N,M,k,D,B=0;
        cin>>N>>M>>k>>D;
        B = N*M*((M-1)*k+M*(N-1))/2;
        if(D/B<=0){
            cout<<"-1\n";
        }else{
            cout<<D/B*B<<"\n";
        }
    }
    return 0;
}