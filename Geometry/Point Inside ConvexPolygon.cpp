#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define LL              long long
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int n;
struct point{
    LL x,y;
    int triarea(const point a,const point b){
        LL d=x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y);
        if(d>0) return 1; //Counterclock
        else if(d<0) return -1; //Clock
        return d; //Linear
    }
}P[MAX];

bool bi_search(const point p){
    ///Very important: Looking if point lies below initial two lines.
    ///For this points should be given in counter clockwise.
    ///Exclude colinear then <= & >=
    if(P[0].triarea(P[1],p)<=0 or P[0].triarea(P[n-1],p)>=0) return false;
    point o=P[0];
    int l=1,h=n-1,m;
    while(h-l>1)
    {
        m=(l+h)>>1;
        int d=o.triarea(P[m],p);
        if(d<0) h=m;
        else l=m;
    }
    if(o.triarea(P[l],p)<0) return false;
    if(P[l].triarea(P[h],p)<0) return false;
    if(P[h].triarea(o,p)<0) return false;
    ///Exclude colinear points
    if(P[l].triarea(p,P[h])==0) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    REP(i,n) scanf("%lld %lld",&P[i].x,&P[i].y);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        point p;
        scanf("%lld %lld",&p.x,&p.y);
        if(bi_search(p)) printf("y\n");
        else printf("n\n");
    }
}
