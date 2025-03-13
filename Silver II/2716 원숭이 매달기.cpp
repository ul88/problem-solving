#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
vector<int> tree;
int depth(string str){
    int cnt = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '[') cnt++;
    }
    return pow(2,cnt-1);
}
int main()
{
    vector <string> v;
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        string str="";
        getline(cin, str);
        v.push_back(str);
    }

    for(string str : v){
        cout<<depth(str)<<"\n";
    }

    return 0;
}