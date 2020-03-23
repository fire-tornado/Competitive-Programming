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

const int N = 2000006;
const ULL hs = 3797;

ULL F[N], FH[N], RH[N];
char str[N];
int n;

ULL Fhash(int x, int y) {
    return FH[y] - F[y - x + 1] * FH[x - 1];
}

ULL Rhash(int x, int y) {
    return RH[x] - F[y - x + 1] * RH[y + 1];
}

int main()
{
    F[0] = 1;
    for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs;

    scanf("%s", str + 1);
    n = strlen(str + 1);

    FH[0] = 0;
    FOR(i, 1, n) FH[i] = FH[i - 1] * hs + str[i];

    RH[n+1]=0;
    ROF(i, n, 1) RH[i] = RH[i + 1] * hs + str[i];
}
