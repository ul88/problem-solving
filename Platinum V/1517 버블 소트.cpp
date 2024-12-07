#include<iostream>
#include<vector>
#define MAX 500000
using namespace std;
using ll = long long;
ll ans = 0;

void merge(vector<int> &v, vector<int> &copy_v,int left, int right){
    int mid = (left + right)/2;
    
    int i = left;
    int j = mid+1;
    int k = left;

    while(i <= mid && j <= right){
        if(v[i] <= v[j]){
            copy_v[k++] = v[i++];
        }else{
            ans += (j - k);
            copy_v[k++] = v[j++];
        }
    }

    int temp = i>mid ? j : i;
    while(k<=right) copy_v[k++] = v[temp++];

    for(int i=left;i<=right;i++) v[i] = copy_v[i];
}

void merge_sort(vector<int> &v, vector<int> &copy_v,int left, int right){
    if(left >= right) return;

    int mid = (left + right)/2;
    merge_sort(v, copy_v, left, mid);
    merge_sort(v, copy_v, mid+1, right);
    merge(v, copy_v, left, right);
}

int main()
{
    vector<int> v;
    vector<int> copy_v;
    int N;
    cin>>N;
    v.reserve(N);
    copy_v.resize(N,0);
    
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    merge_sort(v,copy_v,0,N-1);

    cout<<ans;

    return 0;
}