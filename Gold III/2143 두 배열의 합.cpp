#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;
int A[MAX]={0,}, B[MAX]={0,};
vector <int> pSA;
vector <int> pSB;
int T,n,m;
void input(){
    cin>>T;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        int s = 0;
        for(int j=i;j<n;j++){
            s+=A[j];
            pSA.push_back(s);
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    for(int i=0;i<m;i++){
        int s=0;
        for(int j=i;j<m;j++){
            s+=B[j];
            pSB.push_back(s);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    ll ans=0;
    input();

    sort(pSA.begin(),pSA.end());
    sort(pSB.begin(),pSB.end());
    
    int left = 0,right = pSB.size()-1;
    while(left<pSA.size() && right >= 0){
        ll hapA = pSA[left] , hapB = pSB[right];
        ll hap = hapA+hapB;
        if(T == hap) {
            ll idxA=0, idxB=0;
            while(left<pSA.size() && hapA == pSA[left]){
                left++;
                idxA++;
            }
            while(right>=0 && hapB == pSB[right]){
                right--;
                idxB++;
            }
            ans += idxA*idxB;
        }
        if(hap > T) right--;
        else if(hap < T) left++;
    }
    cout<<ans;
    return 0;
}