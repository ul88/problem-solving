#include<iostream>
using namespace std;
int main()
{
    int alpa[26] = {0,};
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i]-='a'-'A';
        }
        alpa[str[i]-'A']++;
    }
    
    int minIdx = 0;
    bool flag = false;
    for(int i=1;i<26;i++){
        if(alpa[minIdx] < alpa[i]){
            flag = false;
            minIdx = i;
        }else if(alpa[minIdx] == alpa[i]) flag = true;
    }

    if(flag) cout<<"?";
    else cout<<static_cast<char>(minIdx+'A');
    return 0;
}