#include<iostream>
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
        string s;
        cin>>s;
        int len = s.length();

        int idx = 0;
        while(idx < len){
            int temp = len-1;
            string x=s;
            bool flag = true;
            // cout<<s[idx]<<" "<<s[temp]<<" "<<idx<<" "<<temp<<"\n";
            if(s[idx] == s[temp]){
                // cout<<idx<<" "<<temp<<"\n";
                for(int i=idx;i<len;i++){
                    if(temp < 0) break;
                    if(s[i] == s[temp]){
                        temp--;
                    }else{
                        flag = false;
                        break;
                    }
                }
                // cout<<flag<<"\n";
                if(flag){
                    if(temp>=0){
                        for(int i=temp;i>=0;i--){
                            x+=s[i];
                        }
                    }
                    cout<<x<<"\n";
                    break;
                }
            }
            idx++;
        }

    }
    return 0;
}