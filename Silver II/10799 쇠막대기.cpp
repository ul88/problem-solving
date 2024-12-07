#include<stdio.h>
#define MAX 100000
int main()
{
    char str[MAX+1]={};

    scanf("%s",str);
    int len=0;
    while(str[++len]!='\0');

    int a=0, ans=0;

    for(int i=0;i<len;i++){
        if(i+1 < len && str[i]=='(' && str[i+1] == ')'){
            ans+=a;
            i++;
        }
        else if(str[i] == '('){
            a++;
        }
        else{
            ans++;
            a--;
        }
    }

    printf("%d",ans);

    return 0;
}