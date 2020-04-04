/*
https://www.spoj.com/problems/QTREE/
https://blog.anudeep2011.com/heavy-light-decomposition/
Complexity - O(nlog^2(n))
*/

#include<bits/stdc++.h>
using namespace std;

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

const int N=10005;
vector<pii>adj[N];
vector<int>indexx[N];
int P[N][18],subtree[N],depth[N];
int chainNo,chainHead[N],chainID[N];
int base[N],posInBase[N],id;
int tree[4*N],edge[N];

void dfs(int s,int pr,int d)
{
    P[s][0]=pr;
    subtree[s]=1;
    depth[s]=d;
    int i=0;
    for(pii p:adj[s]){
        if(p.ff!=pr){
            edge[indexx[s][i]]=p.ff;
            dfs(p.ff,s,d+1);
            subtree[s]+=subtree[p.ff];
        }
        i++;
    }
    return;
}

void HLD(int s,int pr,int val)
{
    if(chainHead[chainNo]==-1){
        chainHead[chainNo]=s;
    }
    chainID[s]=chainNo;
    posInBase[s]=id;
    base[id++]=val;

    int sc=-1,c=0;
    for(pii p:adj[s]){
        if(p.ff!=pr){
            if(sc==-1 or subtree[sc]<subtree[p.ff]){
                sc=p.ff;
                c=p.ss;
            }
        }
    }

    if(sc!=-1) HLD(sc,s,c);

    for(pii p:adj[s]){
        if(p.ff!=pr and p.ff!=sc){
            chainNo++;
            HLD(p.ff,s,p.ss);
        }
    }
    return;
}

void seg_build(int L,int R,int pos)
{
    if(L==R){
        tree[pos]=base[L];
        return;
    }
    int mid=(L+R)/2;
    seg_build(L,mid,pos*2+1);
    seg_build(mid+1,R,pos*2+2);
    tree[pos]=max(tree[pos*2+1],tree[pos*2+2]);
    return;
}

int seg_query(int ql,int qr,int L,int R,int pos)
{
    if(ql>R or qr<L) return -1;
    else if(ql<=L and qr>=R)
        return tree[pos];
    int mid=(L+R)/2;
    int p=seg_query(ql,qr,L,mid,2*pos+1);
    int q=seg_query(ql,qr,mid+1,R,2*pos+2);
    return max(p,q);
}

void seg_update(int idx,int L,int R,int pos,int val)
{
    if(idx>R or idx<L) return;
    else if(idx<=L and idx>=R){
        tree[pos]=val;
        return;
    }
    int mid=(L+R)/2;
    seg_update(idx,L,mid,2*pos+1,val);
    seg_update(idx,mid+1,R,2*pos+2,val);
    tree[pos]=max(tree[pos*2+1],tree[pos*2+2]);
    return;
}

void lca_build()
{
    REP(i,N) FOR(j,1,17) P[i][j]=1;
    for(int j=1;(1<<j)<N;j++){
        REP(i,N){
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
    return;
}

int lca(int p,int q)
{
    if(depth[p]<depth[q]) swap(p,q);
    ROF(i,17,0) if(depth[P[p][i]]>=depth[q]) p=P[p][i];
    if(p==q) return p;
    ROF(i,17,0){
        if(P[p][i]!=P[q][i]){
            p=P[p][i];
            q=P[q][i];
        }
    }
    return P[p][0];
}

int query_up(int u,int v)
{
    if(u==v) return 0;
    int uchain,vchain=chainID[v],ans=-1;
    while(1){
        uchain=chainID[u];
        if(uchain==vchain){
            if(u==v) break;
            ans=max(ans,seg_query(posInBase[v]+1,posInBase[u],0,id-1,0));
            break;
        }
        ans=max(ans,seg_query(posInBase[chainHead[uchain]],posInBase[u],0,id-1,0));
        u=chainHead[uchain];
        u=P[u][0];
    }
    return ans;
}

int query(int u,int v)
{
    int p=lca(u,v);
    int a=query_up(u,p);
    int b=query_up(v,p);
    return max(a,b);
}

void update(int u,int val)
{
    u=edge[u];
    seg_update(posInBase[u],0,id-1,0,val);
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t){
        int n;
        scanf("%d",&n);

        id=0;
        chainNo=0;
        FOR(i,1,n){
            adj[i].clear();
            indexx[i].clear();
            chainHead[i]=-1;
        }

        FOR(i,1,n-1){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            indexx[u].pb(i);
            indexx[v].pb(i);
        }

        dfs(1,0,0);
        HLD(1,0,-1);
        seg_build(0,id-1,0);
        lca_build();

        while(1){
            char str[10];
            scanf("%s",str);
            if(str[0]=='D') break;
            int a,b;
            scanf("%d %d",&a,&b);
            if(str[0]=='C') update(a,b);
            else printf("%d\n",query(a,b));
        }
    }
}

