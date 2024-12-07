#include<iostream>
#include<string>
using namespace std;
int main()
{
    string check[8]={
        "000000",
        "001111",
        "010011",
        "011100",
        "100110",
        "101001",
        "110101",
        "111010"
    };
    int N;
    string str,ans="";
    cin>>N;
    cin>>str;

    for(int i=0;i<str.length();i+=6){
        string temp = "";
        bool flag = 0;
        int idx=0;
        for(int j=0;j<6;j++){
            temp += str[i+j];
        }
        for(int j=0;j<8;j++){
            int cnt = 0;
            for(int k=0;k<check[j].length();k++){
                if(temp[k] != check[j][k]) cnt++;
            }

            if(cnt<=1){
                flag=1;
                idx=j;
            }
        }

        if(flag == 1){
            ans+=(idx+'A');
        }else{
            cout<<i/6+1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}