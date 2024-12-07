#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s;
        queue <int> q;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                q.push(i);
            }else{
                if(q.empty()){
                    q.push(i);
                    break;
                }
                q.pop();
            }
        }

        if(q.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}