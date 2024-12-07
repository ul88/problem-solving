#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        int ans = 1;
        for(int i=0;i<b;i++){
            ans*=a;
            ans%=10;
        }
        if(ans == 0){
            cout<<10<<"\n";
        }
        else cout<<ans<<"\n";
    }

    return 0;
}