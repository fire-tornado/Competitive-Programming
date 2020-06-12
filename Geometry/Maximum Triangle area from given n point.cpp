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

struct point
{
    LL x,y;
    bool operator < (const point &p) const
    {
        return x<p.x || (x==p.x && y<p.y);
    }
    LL triarea(const point a,const point b)
    {
        LL d=x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y);
        return d;
    }
} P[50005],C[50005];

inline LL Cross(point &o,point &a,point &b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

void ConvexHull(int np,int &nc)
{
    sort(P,P+np);
    REP(i,np)
    {
        while(nc>=2 and Cross(C[nc-2],C[nc-1],P[i])<=0)
            nc--;
        C[nc++]=P[i];
    }
    int t=nc+1;
    ROF(i,np-1,1)
    {
        while(nc>=t and Cross(C[nc-2],C[nc-1],P[i-1])<=0)
            nc--;
        C[nc++]=P[i-1];
    }
    nc--;
    return;
}

int main()
{
    while(true){
        int nc=0,np;
        scanf("%d",&np);
        if(np==-1) break;
        REP(i,np) scanf("%lld %lld",&P[i].x,&P[i].y);
        ConvexHull(np,nc);

        int i = 0, j = 1, k = 2;
        LL area = 0;
        while(i<nc){
            LL now = C[i].triarea(C[j],C[k]);
            while(true){
                while(true){
                    LL tmp = C[i].triarea(C[j],C[(k+1)%nc]);
                    if(tmp>=now) {
                        k = (k+1)%nc;
                        now = tmp;
                    }
                    else break;
                }
                LL tmp = C[i].triarea(C[(j+1)%nc],C[k]);
                if(tmp>=now) {
                    j = (j+1)%nc;
                    now = tmp;
                }
                else break;
            }
            i++;
            if(i==j) j=(j+1)%nc;
            if(j==k) k=(k+1)%nc;
            area = max(area,now);
        }
        printf("%.2lf\n",(double)area/2.0);
    }
    return 0;
}
