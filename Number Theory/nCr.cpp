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

const LL mod=10056;
const int N=1005;
LL ncr[N][N];

void NCR(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(i==0) ncr[i][j]=0;
            else if(j==0 or j==i) ncr[i][j]=1;
            else ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }
}

int main()
{
    NCR();

}
