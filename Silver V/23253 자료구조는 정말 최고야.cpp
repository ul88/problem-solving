#include<iostream>
#include<stack>
#define MAX 200000
using namespace std;
stack<int> s[MAX+1];
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0,k;i<M;i++){
        cin>>k; 
        for(int j=0,a;j<k;j++){
            cin>>a;
            s[i].push(a);
        }
    }

    bool flag = true;
    for(int i=0;i<M;i++){
        int temp = 0;
        while(!s[i].empty()){
            int now = s[i].top();
            s[i].pop();
            if(temp > now){
                flag = false;
            }
            temp = now;
        }
        if(!flag) break;
    }

    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}