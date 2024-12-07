#include<iostream>
#include<string>
using namespace std;
string str;
int f(int left,int right){
    while(left<right){
        if(str[left] != str[right]){
            return 2;
        }
        left++,right--;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin>>T;
	while(T--){
        cin>>str;
		int left=0,right=str.length()-1,ans=0;
		while(left<right){
			if(str[left]==str[right]){
				++left,--right;
			}else{ // 3 6
				ans = f(left+1,right); //4 6
				if(ans == 2){
                    ans = f(left,right-1); // 3 5
                }
				break;
			}
		}
		cout<<ans<<"\n";
    }
	return 0;
}