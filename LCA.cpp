#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const int N=100005;
int L[N],Pr[N],P[N][22];

vector<int>V[N];

void dfs(int s,int pre,int d)
{
    Pr[s]=pre;
    L[s]=d;
    for(int i:V[s])
    {
        if(i==pre) continue;
        dfs(i,s,d+1);
    }
    return;
}

void lca()
{
    dfs(1,0,1); //Source,Prev_Node(0/-1),Depth
    REP(i,N) REP(j,22) P[i][j]=1;
    FOR(i,1,N-1) P[i][0]=Pr[i];
    for(int j=1;(1<<j)<N;j++)
    {
        REP(i,N)
        {
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
    return;
}

int query(int p,int q)
{
    if(L[p]<L[q]) swap(p,q);
    ROF(i,21,0) if(L[P[p][i]]>=L[q]) p=P[p][i];
    if(p==q) return p;
    ROF(i,21,0)
    {
        if(P[p][i]!=P[q][i])
        {
            p=P[p][i];
            q=P[q][i];
        }
    }
    return Pr[p];
}

int main()
{
    int n,m;
    cin >> n;
    REP(i,n-1)
    {
        int u,v;
        cin >> u >> v;
        V[u].pb(v);
        V[v].pb(u);
    }
    lca();
    cin >> m;
    REP(i,m)
    {
        int u,v;
        cin >> u >> v;
        cout << query(u,v) << '\n';
    }
    return 0;
}
