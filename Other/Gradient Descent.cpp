//https://codeforces.com/contest/106/problem/E

#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);

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

int main()
{
    FastRead
    int n;
    cin >> n;
    double x[n],y[n],z[n];
    REP(i,n) cin >> x[i] >> y[i] >> z[i];
    double px=0.0,py=0.0,pz=0.0,alpha=1.0;
    REP(loop,100000)
    {
        int idx=0;
        double dis=-1.0;
        REP(i,n)
        {
            double tmp=SQ(x[i]-px)+SQ(y[i]-py)+SQ(z[i]-pz);
            if(tmp>dis) {
                dis=tmp;
                idx=i;
            }
        }
        px+=alpha*(x[idx]-px);
        py+=alpha*(y[idx]-py);
        pz+=alpha*(z[idx]-pz);
        alpha*=0.999;
    }
    cout << px << ' ' << py << ' ' << pz;
}

