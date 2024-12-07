#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> v, vector<int> reverseV, vector<int> temp){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i] == temp[j]){
                bool flag = true;
                for(int k=0;k<v.size();k++){
                    if(v[(i+k)%v.size()] != temp[(j+k)%v.size()]){
                        flag = false;
                    }
                }
                if(flag) return true;
            }
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(reverseV[i] == temp[j]){
                bool flag = true;
                for(int k=0;k<v.size();k++){
                    if(reverseV[(i+k)%v.size()] != temp[(j+k)%v.size()]){
                        flag = false;
                    }
                }
                if(flag) return true;
            }
        }
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    vector<int> reverseV;
    vector< vector<int> > ans;
    int N,M;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    for(int i=N-1;i>=0;i--){
        if(v[i] == 1){
            reverseV.push_back(3);
        }else if(v[i] == 2){
            reverseV.push_back(4);
        }else if(v[i] == 3){
            reverseV.push_back(1);
        }else{
            reverseV.push_back(2);
        }
    }

    cin>>M;
    for(int i=0;i<M;i++){
        vector<int> temp;
        for(int j=0,a;j<N;j++){
            cin>>a;
            temp.push_back(a);
        }

        if(check(v,reverseV,temp)){
            ans.push_back(temp);
        }
    }

    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        for(auto iter : ans[i]){
            cout<<iter<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}