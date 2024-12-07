#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#define MAX 20000
using namespace std;
bool compare(string a,string b){
    if(a.length() == b.length()){
        return a<b;
    }
    return a.length() < b.length();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> s;
    int N;
    string str[MAX+1];
    cin>>N;

    int cnt = 0;
    for(int i=0;i<N;i++){
        string temp;
        cin>>temp;
        if(s.find(temp) == s.end()){
            s.insert(temp);
            str[cnt++]=temp;
        }
    }

    sort(str,str+cnt,compare);

    for(int i=0;i<cnt;i++){
        cout<<str[i]<<"\n";
    }
    return 0;
}