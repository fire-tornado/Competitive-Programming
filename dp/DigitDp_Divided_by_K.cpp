//http://lightoj.com/volume_showproblem.php?problem=1068

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int len,id,inp[10],k;
int dp[10][85][85][2];
int vis[10][85][85][2];

int call(int pos,bool isSmall,int val,int rem)
{
    if(pos==len) {
        if(val==0 and rem==0) return 1;
        else return 0;
    }
    if(vis[pos][val][rem][isSmall]==id) return dp[pos][val][rem][isSmall];
    vis[pos][val][rem][isSmall]=id;
    int last=9;
    if(!isSmall) last=inp[pos];

    int ret=0;
    for(int i=0;i<last;i++) ret+=call(pos+1,1,(val*10+i)%k,(rem+i)%k);
    if(!isSmall) ret+=call(pos+1,0,(val*10+last)%k,(rem+last)%k);
    else ret+=call(pos+1,1,(val*10+last)%k,(rem+last)%k);
    return dp[pos][val][rem][isSmall]=ret;
}

int solve(int x)
{
    if(x<0) return 0;
    if(k>83) return 0; //Though only 10 digit, digit sum can be maximum 82
    if(k==1) return x;
    len=0;
    while(x){
        inp[len++]=x%10;
        x/=10;
    }
    reverse(inp,inp+len);
    id++;
    return call(0,0,0,0);
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        int lo,hi;
        scanf("%d %d %d",&lo,&hi,&k);
        printf("Case %d: %d\n",tc,solve(hi)-solve(lo-1));
    }
}
