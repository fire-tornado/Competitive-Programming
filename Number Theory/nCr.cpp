#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const LL MOD=1e9+7;
const int N=200005;
LL fact[N],inv[N];

LL BigMod(LL B,LL P,LL M){
    LL R=1;
    while(P>0){
        if(P & 1) R=(R*B)%M;
        P=P>>1;
        B=(B*B)%M;
    }
    return R%M;
}

LL nCr(int n,int r){
    LL up=fact[n];
    LL down=(inv[r]*inv[n-r])%MOD;
    return (up*down)%MOD;
}

void pre(){
    fact[0]=1;
    FOR(i,1,N-1) fact[i]=(fact[i-1]*(LL)i)%MOD;
    inv[N-1]=BigMod(fact[N-1],MOD-2,MOD);
    ROF(i,N-2,1) inv[i]=(inv[i+1]*(i+1))%MOD;
    inv[0]=1;
}

int main(){

}
