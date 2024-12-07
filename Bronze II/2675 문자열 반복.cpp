#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int N;
        string str;
        cin>>N>>str;
        for(int i=0;i<str.length();i++){
            for(int j=0;j<N;j++){
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}