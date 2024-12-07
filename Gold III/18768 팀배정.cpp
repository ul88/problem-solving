#include<iostream> 
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct ability{
	int A;
	int B;
	int cnt;
}abi; abi p[1000010];
bool com(abi fir, abi sec){
	return fir.cnt>sec.cnt;
}
void input(int N){
	for(int i=0;i<N;i++){
		scanf("%d",&p[i].A);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&p[i].B);
		p[i].cnt=abs(p[i].A-p[i].B);
	}
}
int main()
{
	int T=0;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		long long hap=0;
		int n=0,k=0;
		scanf("%d %d",&n,&k);
		input(n);
		
		sort(p,p+n,com);
		int tmpA=0,tmpB=0,tmpMax=0,t=0;
			
		if(n%2==1 && k%2==1){
			tmpMax=n-n/2+k/2;
		}else tmpMax=n/2+k/2;
		
		for(int i=0;i<n;i++){
			if(tmpA>=tmpMax){
				hap+=(long long)p[i].B;
			}else if(tmpB>=tmpMax){
				hap+=(long long)p[i].A;
			}else{	
				if(p[i].A>=p[i].B){
					tmpA++;
					hap+=(long long)p[i].A;
				}else{
					tmpB++;
					hap+=(long long	)p[i].B;
				}
			}
		}
		
		printf("%lld\n",hap);
	}
	return 0;
}
