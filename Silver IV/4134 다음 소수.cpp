#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	unsigned long long n=0;
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		while(1){
			int tmp=0;
			if(n==0 || n==1){
				n=2;
				break;
			}else{
				for(int j=2;j<=sqrt(n);j++){
					if(n%j==0){
						tmp=1;
						break;
					}
				}
				if(tmp!=1){
					break;
				}
			}
			n++;
		}
		cout<<n<<endl;
	}
	
	return 0;
}
