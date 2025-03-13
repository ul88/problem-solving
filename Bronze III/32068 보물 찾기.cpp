#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int L, R, S;
        cin>>L>>R>>S;
        
        cout<<min(abs(S-L)*2+1, abs(R-S)*2)<<"\n";
    }
    return 0;
}