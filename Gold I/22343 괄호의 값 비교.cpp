#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#define MAX 3000000
using namespace std;
int m = 0;
vector<int> solve(string str){
    vector<int> v;
    v.reserve(m+1);
    vector<int> ret(m+1);
    int temp = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            temp++;
        }else{
            temp--;
            if(str[i-1] == '('){
                ret[temp]++;
            }
        }
    }

    for(int i=0;i<ret.size()-1;i++){
        ret[i+1] += ret[i]/2;
        ret[i]%=2;
    }

    return ret;
}

char compare(vector<int>& a, vector<int>& b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i] > b[i]) return '>';
        if(a[i] < b[i]) return '<';
    }
    return '=';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string A, B;
        cin>>A>>B;
        m = max(A.length(), B.length());
        m/=2;
        vector<int> ans1 = solve(A), ans2 = solve(B);
        cout<<compare(ans1,ans2)<<"\n";
    }
    return 0;
}