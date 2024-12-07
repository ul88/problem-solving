#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string,int> m1;
    map<int,string> m2;
    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        m1[str]=i+1;
        m2[i+1] = str;
    }
    for(int i=0;i<M;i++){
        string str;
        cin>>str;
        
        if(str[0] >='0' && str[0] <='9'){
            cout<<m2[stoi(str)]<<"\n";
        }else{
            cout<<m1[str]<<"\n";
        }
    }
    return 0;
}