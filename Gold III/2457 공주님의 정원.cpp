#include<stdio.h>
#include<algorithm>
#define MAX 100000
using namespace std;
typedef struct flower{
    int start;
    int end;
}flower_t;
int ans = 0;

bool compare(flower_t a, flower_t b){
    return a.start < b.start;
}

int main()
{
    flower_t flow[MAX+1]={};
    int N,ans=0;
    scanf("%d",&N);
    for(int i=0,a,b,c,d;i<N;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        flow[i].start = a*100+b;
        flow[i].end = c*100+d;
    }

    sort(flow,flow+N,compare);

    int now = 301;
    for(int i=0;i<N;i++){
        if(now > 1130) break;
        int period = 0;
        for(int j=0;j<N;j++){
            if(flow[j].start > now) continue;
            if(flow[j].end <= now) continue;
            period = max(period, flow[j].end);
        }
        if(period != 0){
            ans++;
            now = period;
        }
    }

    if(now <= 1130) ans = 0;

    printf("%d",ans);

    return 0;
}