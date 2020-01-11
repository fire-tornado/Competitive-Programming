//https://codeforces.com/contest/228/problem/E

#include<bits/stdc++.h>
using namespace std;

int n,m,id;
vector<int>G[205],RG[205],assignment;
stack<int>st;
int vis[205];

void dfs1(int s)
{
    vis[s]=1;
    for(int u:G[s])
    {
        if(!vis[u])
            dfs1(u);
    }
    st.push(s);
}

void dfs2(int s)
{
    vis[s]=id;
    for(int u:RG[s])
    {
        if(!vis[u])
            dfs2(u);
    }
}

bool solve_2SAT()
{
    for(int i=1;i<=2*n;i++) if(!vis[i])
        dfs1(i);
    memset(vis,0,sizeof(vis));
    id=1;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vis[u])
            dfs2(u),id++;
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==vis[i+n])
            return false;
        if(vis[i]>vis[i+n])
            assignment.push_back(i);
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        if(w)
        {
            // if (x1 ⊕ y1) ∧ (x2 ⊕ y2) ∧ ...  ∧ (xn ⊕ yn)
            //(x ⊕ y) <=> (x => y) and (x' => y')
            G[u].push_back(v);
            G[u+n].push_back(v+n);
            G[v].push_back(u);
            G[v+n].push_back(u+n);

            RG[u].push_back(v);
            RG[u+n].push_back(v+n);
            RG[v].push_back(u);
            RG[v+n].push_back(u+n);
        }
        else{
            // if (x1 ∨ y1) ∧ (x2 ∨ y2) ∧ ...  ∧ (xn ∨ yn)
            //(x ∨ y) <=> (x' => y) and (y' => x)
            G[u].push_back(v+n);
            G[u+n].push_back(v);
            G[v].push_back(u+n);
            G[v+n].push_back(u);

            RG[u].push_back(v+n);
            RG[u+n].push_back(v);
            RG[v].push_back(u+n);
            RG[v+n].push_back(u);
        }
    }
    bool f=solve_2SAT();
    if(f)
    {
        cout << assignment.size() << '\n';
        for(int i=0;i<assignment.size();i++) cout << assignment[i] << ' ';
    }
    else
    {
        cout << "Impossible\n";
    }
}
