#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    string str1 = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    map <char, char> m;
    m.insert({' ',' '});
    m.insert({'\n','\n'});
    for(int i=0;i<str.length();i++){
        m.insert({str[i],str1[i]});
    }
    char c=0;
    while( (scanf("%c",&c)) != EOF ){
        printf("%c",m[c]);
    }
    return 0;
}