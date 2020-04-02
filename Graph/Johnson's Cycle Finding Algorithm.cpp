/*
Complexity O(E+V)*(Cycle + 1)
*/

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const int N=105;
set<int>V[N];
vector<int>component[N];
int n,m,id;
int vis[N];
stack<int>st;

void dfs1(int s){
    vis[s]=1;
    for(int u:V[s]){
        if(u<0 or vis[u]) continue;
        dfs1(u);
    }
    st.push(s);
}

void dfs2(int s){
    vis[s]=id;
    for(int u:V[s]){
        u=-u;
        if(u<0 or vis[u]) continue;
        dfs2(u);
    }
}

void SCC(){
    MEM(vis,0);
    FOR(i,1,n) if(vis[i]==0 and V[i].size()>0) dfs1(i);
    MEM(vis,0);
    id=0;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(vis[u]) continue;
        id++;
        dfs2(u);
    }
    FOR(i,1,n){
        component[i].clear();
        for(int j:V[i]){
            if(j<0) continue;
            if(vis[i]==vis[j]) component[i].pb(j);
        }
    }
}

int blocked[N];
vector<int>blocked_map[N];
int cnt=0;
vector<int>cycle[N*N];

void unblock(int s){
    if(!blocked[s]) return;
    blocked[s]=0;
    for(int u:blocked_map[s]) unblock(u);
    blocked_map[s].clear();
}

bool dfs(int s,int start,vector<int>&cy){
    cy.pb(s);
    blocked[s]=1;
    bool found=false;
    for(int u:component[s]){
        if(u==start){
            for(int v:cy) cycle[cnt].pb(v);
            cycle[cnt].pb(u);
            cnt++;
            found=true;
        }
        if(blocked[u]) continue;
        found |= dfs(u,start,cy);
    }
    if(!found){
        for(int u:component[s]){
            blocked_map[u].pb(s);
        }
    }
    else{
        unblock(s);
    }
    cy.pop_back();
    return found;
}

void Johnson(){
    FOR(node,1,n){
        SCC();
        vector<int>cy;
        MEM(blocked,0);
        dfs(node,node,cy);
        for(int u:V[node]){
            if(u<0) V[-u].erase(node);
            else V[u].erase(-node);
        }
        V[node].clear();
    }
}

int main()
{
    cin >> n >> m;
    REP(i,m)
    {
        int u,v;
        cin >> u >> v;
        V[u].insert(v);
        V[v].insert(-u);
    }
    Johnson();
    REP(i,cnt){
        cout << "--> ";
        for(int u:cycle[i]) cout << u << ' ';
        cout << '\n';
    }
}
/*
9 15
1 2
1 5
1 8
2 9
2 7
2 3
3 1
3 2
3 4
3 6
4 5
5 2
6 4
8 9
9 8
*/
