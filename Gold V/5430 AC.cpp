#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        deque <int> dq;
        string str,str1;
        cin>>str;
        int N;
        cin>>N;
        cin>>str1;
        int temp = 0;
        if(str1.length() != 2){
            for(int i=1;i<str1.length();i++){
                if(str1[i] == ']' || str1[i] == ','){
                    dq.push_back(temp);
                    temp=0;
                }else{
                    temp*=10;
                    temp+=str1[i]-'0';
                }
            }
        }

        bool flag = false;
        int cnt = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == 'R'){
                cnt++;
            }else{
                if(dq.empty()){
                    flag = true;
                    break;
                }
                if(cnt%2 == 0){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
            }
        }

        if(flag) cout<<"error\n";
        else if(cnt%2 == 0){
            cout<<"[";
            while(!dq.empty()){
                cout<<dq.front();
                dq.pop_front();
                if(!dq.empty()) cout<<",";
                else break;
            }
            cout<<"]\n";
        }else{
            cout<<"[";
            while(!dq.empty()){
                cout<<dq.back();
                dq.pop_back();
                if(!dq.empty()) cout<<",";
                else break;
            }
            cout<<"]\n";
        }
    }
    return 0;
}