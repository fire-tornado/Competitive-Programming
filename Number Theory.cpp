#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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

const int NUM=1000005;
bool flag[NUM];
vector <int> prime;
void sieve()
{
    flag[1]=true;
    for(int i=4; i<NUM; i+=2)
        flag[i]=true;
    for(int i=3; i*i<=NUM; i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i; j<NUM; j+=(i<<1))
                flag[j]=true;
        }
    }
    prime.pb(2);
    for(int i=3; i<NUM; i+=2)
        if(!flag[i])
            prime.pb(i);
    return;
}

int NOD(ll n)
{
    int div=1;
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            div*=(cnt+1);
        }
    }
    if(n>1)
    {
        div*=2;
    }
    return div;
}

ll BigMod(ll B,ll P,ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P & 1)
            R=(R*B)%M;
        P=P>>1;
        B=(B*B)%M;
    }
    return R%M;
}


int main()
{

}
