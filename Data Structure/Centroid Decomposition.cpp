#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,q;
set<int>G[N];
int sub[N],par[N];

void dfs(int node,int pr)
{
    sub[node]=1;
    for(int i:G[node])
    {
        if(i==pr) continue;
        dfs(i,node);
        sub[node]+=sub[i];
    }
}

int centroid(int node,int pr,int sz)
{
    for(int i:G[node])
    {
        if(i==pr) continue;
        if(sub[i]>sz) return centroid(i,node,sz);
    }
    return node;
}

void decompose(int node,int pr)
{
    dfs(node,-1);
    int c=centroid(node,-1,(sub[node]+1)/2);
    par[c]=pr;
    for(int i:G[c])
    {
        G[i].erase(c);
        decompose(i,c);
    }
}

int main()
{
    cin >> n >> q;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    decompose(1,-1);
    return 0;
}
