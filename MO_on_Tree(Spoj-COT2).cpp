#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//template<typename T>a
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define MAX             100005
#define MOD             1000003
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);

#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector <int>
#define vl              vector <ll>
#define vp              vector<pii>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

const int N=40005;
int n,m,id,block_size=290,ans,tmp;
int arr[N],ST[N],EN[N],Pr[N],L[N],P[N][22],flag[2*N],answer[100005],cnt[N],inrange[N];
vector<int>V[N];
pair<pii,pii>qry[100005];
map<int,int>mp;

void dfs(int s,int p,int d)
{
    Pr[s]=p;
    L[s]=d;
    ST[s]=++id;
    flag[id]=s;
    for(int i:V[s])
        if(i!=p)
            dfs(i,s,d+1);
    EN[s]=++id;
    flag[id]=s;
}

void lca()
{
    dfs(1,0,1); //Source,Prev_Node(0/-1),Depth
    REP(i,N) REP(j,22) P[i][j]=1;
    FOR(i,1,N-1) P[i][0]=Pr[i];
    for(int j=1; (1<<j)<N; j++)
    {
        REP(i,N)
        {
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    if(L[p]<L[q])
        swap(p,q);
    ROF(i,21,0) if(L[P[p][i]]>=L[q])
        p=P[p][i];
    if(p==q)
        return p;
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

bool mo_cmp(pair<pii,pii>x,pair<pii,pii>y)
{
    int blk_x=x.ff.ff/block_size;
    int blk_y=y.ff.ff/block_size;
    if(blk_x!=blk_y)
        return blk_x<blk_y;
    return x.ff.ss < y.ff.ss;
}

void add(int i)
{
    if(inrange[i])
    {
        cnt[arr[i]]--;
        if(cnt[arr[i]]==0) ans--;
    }
    else
    {
        if(cnt[arr[i]]==0) ans++;
        cnt[arr[i]]++;
    }
    inrange[i]^=1;
}

int main()
{
    scanf("%d %d",&n,&m);
    FOR(i,1,n)
    {
        scanf("%d",&arr[i]);
        if(mp[arr[i]]==0)
            mp[arr[i]]=++tmp;
        arr[i]=mp[arr[i]];
    }
    FOR(i,1,n-1)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        V[u].pb(v);
        V[v].pb(u);
    }
    lca();
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        if(ST[u]>ST[v])
            swap(u,v);
        int p=query(u,v);
        if(u==p or v==p)
            qry[i]=mk(pii(ST[u],ST[v]),pii(i,0));
        else
            qry[i]=mk(pii(EN[u],ST[v]),pii(i,ST[p]));
    }
    sort(qry+1,qry+m+1,mo_cmp);
    int ml=1,mr=0;
    FOR(i,1,m)
    {
        int l=qry[i].ff.ff;
        int r=qry[i].ff.ss;
        while(mr<r)
        {
            mr++;
            add(flag[mr]);
        }
        while(mr>r)
        {
            add(flag[mr]);
            mr--;
        }
        while(ml<l)
        {
            add(flag[ml]);
            ml++;
        }
        while(ml>l)
        {
            ml--;
            add(flag[ml]);
        }
        if(qry[i].ss.ss!=0) add(flag[qry[i].ss.ss]);
        answer[qry[i].ss.ff]=ans;
        if(qry[i].ss.ss!=0) add(flag[qry[i].ss.ss]);
    }
    FOR(i,1,m) printf("%d\n",answer[i]);
    return 0;
}
