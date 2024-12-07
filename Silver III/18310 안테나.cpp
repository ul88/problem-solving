#include<iostream>
#include<vector>
#include<algorithm>
#define INF INT64_MAX
#define MAX 100000
using namespace std;
typedef long long ll;
int main()
{
    vector<int> v;
    int N, ans=0,hap=0;
    ll ansValue = INF;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a; 
        hap+=a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int i=1;i<=v.back();i++){
        int temp = lower_bound(v.begin(),v.end(),i) - v.begin();
        hap += temp;
        hap -= (v.size()-temp);
        
        cout<<hap<<" ";
        if(hap < ansValue){
            ansValue = hap;
            ans = i;
        }
    }

    cout<<ans;
    return 0;
}

// 정해
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     vector<int> v;
//     int N;
//     cin>>N;
//     for(int i=0,a;i<N;i++){
//         cin>>a;
//         v.push_back(a);
//     }
    
//     sort(v.begin(),v.end());
    
//     cout<<v[(v.size()-1)/2];
//     return 0;
// }