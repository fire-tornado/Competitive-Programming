//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3729

#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define eps             1e-8

struct point
{
    double x,y;
    point(double _x=0,double _y=0){
        x=_x,y=_y;
    }
    point operator+(const point &p) const{
        return {x+p.x,y+p.y};
    }
    point operator-(const point &p) const{
        return {x-p.x,y-p.y};
    }
    point operator/(const double val) const{
        return {x/val,y/val};
    }
    bool operator<(const point &p)const{
        if(fabs(x-p.x)>eps) return x<p.x;
        return y<p.y;
    }
    double dist(const point &p){
        return hypot(x-p.x,y-p.y);
    }
    double dot(const point &p){
        return x*p.x+y*p.y;
    }
    double cross(const point &p){
        return x*p.y-y*p.x;
    }
};

void ConvexHull(vector<point>p,vector<point>&h)
{
    sort(p.begin(),p.end());
    int m=0,n=p.size();
    h.resize(n+n+2);
    for(int i=0; i<n; i++)
    {
        while(m>1 and ((h[m-1]-h[m-2]).cross(p[i]-h[m-2]))<=0.0) m--;
        h[m++]=p[i];
    }
    int k=m;
    for(int i=n-2; i>=0; i--)
    {
        while(m>k and ((h[m-1]-h[m-2]).cross(p[i]-h[m-2]))<=0.0) m--;
        h[m++]=p[i];
    }
    if(n>1) m--;
    while(h.size()>m) h.pop_back();
    return;
}

void RotatingCallipars(vector<point>&p)
{
    int n=p.size(),l=1,r=1,u=1;
    double peremeter=1e9,area=1e9;
    for(int i=0;i<n;i++){
        point edge = (p[(i+1)%n]-p[i])/p[i].dist(p[(i+1)%n]);

        while(edge.dot(p[r%n]-p[i]) < edge.dot(p[(r+1)%n]-p[i])) r++;
        while(u<r || edge.cross(p[u%n]-p[i]) < edge.cross(p[(u+1)%n]-p[i])) u++;
        while(l<u || edge.dot(p[l%n]-p[i]) > edge.dot(p[(l+1)%n]-p[i])) l++;

        double w = edge.dot(p[r%n]-p[i]) - edge.dot(p[l%n]-p[i]);
        double h = fabs((p[i]-p[u%n]).cross(p[(i+1)%n]-p[u%n]))/p[i].dist(p[(i+1)%n]);

        area = min(area,w*h);
        peremeter = min(peremeter,2.0*(w+h));
    }
    cout << fixed << setprecision(2) << area << ' ' << peremeter << '\n';
}
int main()
{
    FastRead
    int n,tc=0;
    while(cin >> n)
    {
        if(n==0) break;
        vector<point>v(n),h;
        for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
        ConvexHull(v,h);
        RotatingCallipars(h);
    }
    return 0;
}
