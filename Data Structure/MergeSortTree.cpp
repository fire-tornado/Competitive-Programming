//https://codeforces.com/contest/369/problem/E

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

const int N=1e6+5;
vector<int>V[N],tree[4*N];

void build(int node,int L,int R)
{
    if(L==R){
        sort(all(V[L]));
        tree[node]=V[L];
        return;
    }
    int mid=(L+R)/2;
    build(node*2,L,mid);
    build(2*node+1,mid+1,R);
    merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node]));
}

int query(int node,int L,int R,int l,int r,int val)
{
    if(r<L or R<l or tree[node].empty()) return 0;
    if(l<=L and R<=r){
        int cnt=upper_bound(all(tree[node]),val)-tree[node].begin();
        return cnt;
    }
    int mid=(L+R)/2;
    int x=query(node*2,L,mid,l,r,val);
    int y=query(node*2+1,mid+1,R,l,r,val);
    return x+y;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    FOR(i,1,n){
        int l,r;
        scanf("%d %d",&l,&r);
        V[l].pb(r);
    }
    build(1,1,N-1);
    while(q--){
        int c,ans=0;
        scanf("%d",&c);
        int qry[c+2];
        FOR(i,1,c) scanf("%d",&qry[i]);
        qry[0]=0;
        qry[c+1]=N-1;
        FOR(i,1,c+1){
            if(qry[i-1]+1>qry[i]-1) continue;
            ans+=query(1,1,N-1,qry[i-1]+1,qry[i]-1,qry[i]-1);
        }
        printf("%d\n",n-ans);
    }
}
