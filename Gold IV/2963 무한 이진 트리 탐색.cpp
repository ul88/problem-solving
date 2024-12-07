#include<iostream>
#include<string>
#include<vector>
using namespace std;
void add(vector<int>& v,vector<int> v1){
    for(int i=0;i<v.size();i++){
        if(i< v1.size())
            v[i] += v1[i];
        if(v[i] >= 10){
            if(i == v.size()-1){
                v.push_back(1);
            }else{
                v[i+1]++;
            }
        }
        v[i] %= 10;
    }
}
void mul(vector<int>& v, int n){
    for(int i=0;i<v.size();i++){
        v[i] *= n;
    }
    
    for(int i=0;i<v.size()-1;i++){
        v[i+1] += v[i]/10;
        v[i] %= 10;
    }
    if(v[v.size()-1] >= 10){
        v.push_back(v[v.size()-1]/10);
        v[v.size()-2] %= 10;
    }
}
void print(vector<int> v){
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
}
int main()
{
    string str;
    vector <int> ans;
    vector <int> cnt;
    cin>>str;
    
    ans.push_back(1);
    cnt.push_back(1);
    
    for(auto iter : str){
        if(iter == 'L'){
            mul(ans,2);
        }else if(iter == 'R'){
            mul(ans,2);
            add(ans,cnt);
        }else if(iter == '*'){
            mul(ans,5);
            add(ans,cnt);
            mul(cnt,3);
        }
    }

    print(ans);
    
    return 0;
}