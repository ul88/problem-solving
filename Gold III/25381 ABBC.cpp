#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
    queue <int> q;
    int B=0,cnt=0;
    string S;
    cin>>S;
    for(int i=0;i<S.length();i++){
        if(S[i]=='B'){
            q.push(i);
        }else if(S[i]=='C' && !q.empty()){
            S[q.front()]='N';
            q.pop();
            cnt++;
        }
    }
    for(int i=S.length()-1;i>=0;i--){
        if(S[i]=='B'){
            B++;
        }else if(S[i]=='A' && B!=0){
            B--;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}