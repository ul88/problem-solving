#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool binary_search(vector<int>& v,int n){
    int start = 0, end = v.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(v[mid] == n) return true;
        
        if(v[mid] > n){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        vector<int> v;
        int N,M;
        cin>>N;
        for(int i=0;i<N;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }

        sort(v.begin(),v.end());

        cin>>M;
        for(int i=0;i<M;i++){
            int a;
            cin>>a;
            cout<<binary_search(v, a)<<"\n";
        }
    }
    return 0;
}