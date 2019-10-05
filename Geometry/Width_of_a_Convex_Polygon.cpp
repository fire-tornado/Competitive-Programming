#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define PI              acos(-1.0)

struct point
{
    double x,y;
    point(double _x=0,double _y=0) {x=_x,y=_y;}
    point operator+(const point &p) {return {x+p.x,y+p.y};}
    point operator-(const point &p) {return {x-p.x,y-p.y};}
    double operator^(const point &p) {return x*p.y-y*p.x;}
    double operator*(const point &p) {return x*p.x+y*p.y;}
    bool operator<(const point &p)const {return x<p.x||(x==p.x&&y<p.y);}
    double ParallalLineDist(const point &by,const point &from) {return abs(y*(from.x-by.x)-x*(from.y-by.y))/sqrt(x*x+y*y);}
    point Rotate(double ang) {return {x*cos(ang)-y*sin(ang),x*sin(ang)+y*cos(ang)};}
};

void ConvexHull(vector<point>p,vector<point>&h)
{
    sort(p.begin(),p.end());
    int m=0,n=p.size();
    h.resize(n+n+2);
    for(int i=0; i<n; i++)
    {
        while(m>1 and ((h[m-1]-h[m-2])^(p[i]-h[m-2]))<=0.0) m--;
        h[m++]=p[i];
    }
    int k=m;
    for(int i=n-2; i>=0; i--)
    {
        while(m>k and ((h[m-1]-h[m-2])^(p[i]-h[m-2]))<=0.0) m--;
        h[m++]=p[i];
    }
    if(n>1) m--;
    while(h.size()>m) h.pop_back();
    return;
}
double RotatingCallipars(vector<point>&p)
{
    int n=p.size();
    double ans=1e9;
    int p_a=0,p_b=0;
    double rotate_angle=0.0;
    point calipar_a(1.0,0.0),calipar_b(-1.0,0.0);

    for(int i=0;i<n;i++)
    {
        if(p[i].y<p[p_a].y) p_a=i;
        if(p[i].y>p[p_b].y) p_b=i;
    }
    while(rotate_angle<PI){
        point edge_a=p[(p_a+1)%n]-p[p_a];
        point edge_b=p[(p_b+1)%n]-p[p_b];

        double angle_a=atan2(edge_a^calipar_a,edge_a*calipar_a);
        double angle_b=atan2(edge_b^calipar_b,edge_b*calipar_b);

        angle_a=fabs(angle_a);
        angle_b=fabs(angle_b);

        calipar_a=calipar_a.Rotate(min(angle_a,angle_b));
        calipar_b=calipar_b.Rotate(min(angle_a,angle_b));

        double width=0.0;
        if(angle_a<angle_b){
            p_a++;
            p_a%=n;
            width=calipar_a.ParallalLineDist(p[p_a],p[p_b]);
        }
        else {
            p_b++;
            p_b%=n;
            width=calipar_b.ParallalLineDist(p[p_b],p[p_a]);
        }
        ans=min(ans,width);
        rotate_angle+=min(angle_a,angle_b);
    }
    return ans;
}
int main()
{
    FastRead
    int n,tc=0;
    while(cin >> n)
    {
        if(!n) break;
        vector<point>v(n),h;
        for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
        ConvexHull(v,h);
        double ans=RotatingCallipars(h);
        cout << "Case " << ++tc << ": " << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}
