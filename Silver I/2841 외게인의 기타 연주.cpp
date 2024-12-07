#include<iostream>
#include<stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack <int> s[7];
    int N,P,ans=0;
    cin>>N>>P;
    for(int i=0,a,b;i<N;i++){
        cin>>a>>b;
        if(s[a].empty()){
            s[a].push(b);
            ans++;
        }else{
            while(!s[a].empty() && s[a].top() > b){
                ans++;
                s[a].pop();
            }
            if(!s[a].empty() && s[a].top() == b) continue;
            s[a].push(b);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}