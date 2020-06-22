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
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)

struct point{
    double x,y,z;
    point(double x=0,double y=0,double z=0):x(x),y(y),z(z){};
    point operator + (point &p){
        return point(x+p.x,y+p.y,z+p.z);
    }
    point operator - (point &p){
        return point(x-p.x,y-p.y,z-p.z);
    }
    point operator * (double d){
        return point(x*d,y*d,z*d);
    }
    point operator / (double d){
        return point(x/d,y/d,z/d);
    }
    point operator * (point &p){  ///Cross Product
        return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);
    }
    double operator ^ (point &p){ ///Dot Product
        return x*p.x+y*p.y+z*p.z;
    }
    void cap(){ ///Convert to a unit vector
        double len = sqrt(SQ(x) + SQ(y) + SQ(z));
        x/=len,y/=len,z/=len;
    }
};

int main(){
    
}
