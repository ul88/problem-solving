#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> tree;
void makeTree(string str){
    
}
int main()
{
    vector <string> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }

    for(string str : v){
        makeTree(str);
    }

    return 0;
}