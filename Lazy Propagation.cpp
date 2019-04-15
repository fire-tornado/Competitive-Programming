#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define MOD             1000000007
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
#define TC              int t;cin >> t;FOR(tc,1,t)
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)


#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

const int N=100005;
ll tree[4*N],lazy[4*N];

void updateRange(int b,int e,int L,int R,int pos,ll val)
{
    if(lazy[pos]!=0)
    {
        tree[pos]+=(R-L+1)*lazy[pos];
        if(L!=R)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(L>R or L>e or R<b)
        return;
    if(L>=b and R<=e)
    {
        tree[pos]+=(R-L+1)*val;
        if(L!=R)
        {
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
    }
    int mid=(L+R)/2;
    updateRange(b,e,L,mid,2*pos+1,val);
    updateRange(b,e,mid+1,R,2*pos+2,val);
    tree[pos]=tree[2*pos+1]+tree[2*pos+2];
    return;
}

ll getSum(int ql,int qr,int L,int R,int pos)
{
    if(lazy[pos]!=0)
    {
        tree[pos]+=(R-L+1)*lazy[pos];
        if(L!=R)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(L>R or ql>R or qr<L)
        return 0;
    if(L>=ql and qr>=R)
        return tree[pos];
    int mid=(L+R)/2;
    return getSum(ql,qr,L,mid,2*pos+1)+getSum(ql,qr,mid+1,R,2*pos+2);
}

int main()
{

}
