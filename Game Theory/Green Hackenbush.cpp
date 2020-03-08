//http://lightoj.com/volume_showproblem.php?problem=1355

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int n;
vector<pii>G[1000];

int dfs(int s,int pr)
{
    int nim=0;
    REP(i,G[s].size())
    {
        int u=G[s][i].ff;
        int w=G[s][i].ss;

        if(u==pr) continue;
        int tmp=dfs(u,s);
        if(w==1) nim^=(tmp+1);
        else nim^=tmp^(w & 1);
    }
    return nim;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        scanf("%d",&n);
        FOR(i,1,n-1)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u].pb(pii(v,w));
            G[v].pb(pii(u,w));
        }
        if(dfs(0,-1))
        {
            printf("Case %d: Emily\n",tc);
        }
        else{
            printf("Case %d: Jolly\n",tc);
        }
        REP(i,n) G[i].clear();
    }
}
