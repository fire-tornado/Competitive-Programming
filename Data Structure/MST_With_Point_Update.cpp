//https://toph.co/p/yet-another-xinversion

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N=1e5+5;
int arr[N];
ordered_set<pii>mst[4*N];

void build(int node,int L,int R)
{
    if(L==R){
        mst[node].insert({arr[L],L});
        return;
    }
    FOR(i,L,R) mst[node].insert({arr[i],i});
    int mid=(L+R)/2;
    build(node*2,L,mid);
    build(2*node+1,mid+1,R);
}

int query(int node,int L,int R,int l,int r,int val)
{
    if(r<L or R<l) return 0;
    if(l<=L and R<=r){
        int cnt=mst[node].order_of_key({val,N+5});
        return cnt;
    }
    int mid=(L+R)/2;
    int x=query(node*2,L,mid,l,r,val);
    int y=query(node*2+1,mid+1,R,l,r,val);
    return x+y;
}

void update(int node,int L,int R,int i,int v,int nw)
{
    if(i<L or R<i)  return;
    if(L==i and R==i)
    {
        mst[node].erase(mst[node].find({v,i}));
        mst[node].insert({nw,i});
        return;
    }
    int mid=(L+R)/2;
    update(node*2,L,mid,i,v,nw);
    update(node*2+1,mid+1,R,i,v,nw);
    mst[node].erase(mst[node].find({v,i}));
    mst[node].insert({nw,i});
}

vector<int>V[N];
int id;
int Dis[N],Lev[N],node[N];
void dfs(int s,int pr)
{
    Dis[s]=++id;
    arr[id]=node[s];
    for(int u:V[s]){
        if(u==pr) continue;
        dfs(u,s);
    }
    Lev[s]=id;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    for(int i=1;i<=n;i++) scanf("%d",&node[i]);

    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        V[u].pb(v);
        V[v].pb(u);
    }

    dfs(1,0);
    build(1,1,n);

    while(q--)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==2)
        {
            int l,r,u;
            scanf("%d",&u);
            l=Dis[u];
            r=Lev[u];
            int ans=query(1,1,n,l,r,node[u]);
            printf("%d\n",r-l+1-ans);
        }
        else
        {
            int u,v;
            scanf("%d %d",&u,&v);
            node[u]=v;
            u=Dis[u];
            update(1,1,n,u,arr[u],v);
            arr[u]=v;
        }

    }
    return 0;
}
