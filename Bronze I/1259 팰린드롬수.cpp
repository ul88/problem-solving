#include<iostream>
using namespace std;
int main()
{
    while(1){
        string str;
        cin>>str;
        if(str == "0") break;
        int left = 0, right = str.length()-1;
        while(left <= right){
            if(str[left] != str[right]) break;
            left++;
            right--;
        }
        if(left >= right) cout<<"yes\n";
        else cout<<"no\n";
    }
    
    return 0;
}