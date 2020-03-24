/*
http://lightoj.com/volume_showproblem.php?problem=1140

Prob: Number of Zeros are there from lo -> hi
*/

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

int len,id,inp[10];
LL dp[10][10][2][2];
int vis[10][10][2][2];

LL call(int pos,bool isSmall,bool isStart,int total)
{
    if(pos==len) return total;
    if(vis[pos][total][isSmall][isStart]==id) return dp[pos][total][isSmall][isStart];
    vis[pos][total][isSmall][isStart]=id;
    int last=9;
    if(!isSmall) last=inp[pos];

    LL ret=0;
    if(isStart){
        for(int i=0;i<=last;i++){
            ret+=call(pos+1,isSmall | i<inp[pos],1,(i==0)+total);
        }
    }
    else{
        for(int i=1;i<=last;i++){
            ret+=call(pos+1,isSmall | i<inp[pos],1,(i==0)+total);
        }
        ret+=call(pos+1,1,0,0);
    }
    return dp[pos][total][isSmall][isStart]=ret;
}

LL solve(LL x)
{
    if(x<0) return 0;
    len=0;
    while(x){
        inp[len++]=x%10;
        x/=10;
    }
    reverse(inp,inp+len);
    id++;
    return call(0,0,0,0)+1;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        LL lo,hi;
        scanf("%lld %lld",&lo,&hi);
        printf("Case %d: %lld\n",tc,solve(hi)-solve(lo-1));
    }
}

