#include<iostream>
using namespace std;
int main()
{
    int ans = 0;
    for(int i=0;i<8;i++){
        string str;
        cin>>str;
        for(int j=0;j<8;j++){
            if((i+j)%2 == 0){
                if(str[j] == 'F') ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}