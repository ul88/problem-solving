#include<iostream>
#include<string>
using namespace std;
bool check(string n,string ans){
    int idx = 0;
    for(auto iter : ans){
        if(n[idx] == iter){
            idx++;
        }
    }
    
    if(idx == n.length()) return true;
    else return false;
}
int main()
{
    string n;
    cin>>n;
    
    int ans = 2;
    string str = "1";
    
    while(!check(n,str)){
        str += to_string(ans);
        ans++;
    }
    
    cout<<ans-1;
    
    return 0;
}