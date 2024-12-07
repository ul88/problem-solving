#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <pair<int,int>> v;
    int N,M;
    cin>>N>>M;
    for(int i=0,a;i<M;i++){
        cin>>a;
        bool flag = false;
        for(int j=0;j<v.size();j++){
            if(v[j].first == a){
                v[j].second++;
                flag = true;
                break;
            }
        }
        if(v.size() < N && !flag){
            v.push_back({a,1});
        }else if(!flag){
            int minIdx=0;
            for(int j=0;j<v.size();j++){
                if(v[minIdx].second > v[j].second){
                    minIdx = j;
                }
            }

            for(int j=minIdx;j<v.size()-1;j++){
                v[j] = v[j+1];
            }

            v[v.size()-1] = {a, 1};
        }
    }

    sort(v.begin(),v.end());

    for(auto iter : v){
        cout<<iter.first<<" ";
    }
    return 0;
}