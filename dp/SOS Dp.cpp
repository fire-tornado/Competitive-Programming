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

#define LL              long long
#define ULL              unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
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

LL BigMod(LL B,LL P,LL M)
{
    LL R=1;
    while(P>0)
    {
        if(P & 1)
            R=(R*B)%M;
        P=P>>1;
        B=(B*B)%M;
    }
    return R%M;
}

const int N=20;
const int M=(1<<N)-1;
int F[M+5];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        F[tmp]++; //We can also assign that number
    }

    for(int i = 0; i < N; ++i)
    {
        for(int mask = 0; mask <= M; ++mask)
        {
            if(mask & (1<<i)) //Number of integer such that x or Ai = x
                F[mask] += F[mask^(1<<i)];
            /*
            if(~mask >> i & 1) //Number of integer such that x and Ai = x
                F[mask] += F[mask^(1<<i)];
            */
            //We can also calculate any submask by using max or min
        }
    }


}
