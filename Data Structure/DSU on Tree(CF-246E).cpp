#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);

#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

string str[MAX];
vector<int>G[MAX];
vector<pii>Q[MAX];
int L[MAX],ans[MAX];

void dfs(int v,int d)
{
    L[v]=d;
    for(int i:G[v])
    {
        dfs(i,d+1);
    }
    return;
}

void dsu(int v,map<int,set<string>>&mp)
{
    for(int i:G[v])
    {
        map<int,set<string>>s;
        dsu(i,s);
        if(s.size()>mp.size()) swap(mp,s);
        for(auto it:s)
        {
            mp[it.ff].insert(all(it.ss));
        }
    }
    if(v!=0) mp[L[v]].insert(str[v]);
    for(pii p:Q[v])
    {
        ans[p.ss]=mp[p.ff].size();
    }
    return;
}

int main()
{
    //FastRead
    int n;
    cin >> n;
    FOR(i,1,n)
    {
        int u;
        cin >> str[i] >> u;
        G[u].pb(i);
    }
    dfs(0,0);
    int q;
    cin >>q;
    FOR(i,1,q)
    {
        int v,k;
        cin >> v >> k;
        Q[v].pb(pii(k+L[v],i));
    }
    map<int,set<string>>mp;
    dsu(0,mp);
    FOR(i,1,q)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
