#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    vector<int> v(26, 0);
    int N, ans = 0;
    cin>>N;
    
    for(int i=0;i<N;i++){
        string a;
        cin>>a;

        if(i==0){
            for(int j=0;j<a.length();j++){
                v[a[j]-'A']++;
            }

        }else{
            vector<int> v2(26,0);
            for(int j=0;j<a.length();j++){
                v2[a[j]-'A']++;
            }

            int temp = 0, cnt = 0;
            for(int j=0;j<26;j++){
                temp += v[j] - v2[j];
            }
            if(-1 <= temp && temp <= 1) ans++;
        }
    }

    cout<<ans;
    return 0;
}