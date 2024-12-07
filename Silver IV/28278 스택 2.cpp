#include<iostream>
#include<stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    stack<int> s;
    cin>>N;
    while(N--){
        int a;
        cin>>a;
        if(a==1){
            int x;
            cin>>x;
            s.push(x);
        }else if(a==2){
            if(s.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }else if(a==3){
            cout<<s.size()<<"\n";
        }else if(a==4){
            cout<<s.empty()<<"\n";
        }else{
            if(s.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<s.top()<<"\n";
            }
        }
    }
    return 0;
}