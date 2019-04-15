#include<bits/stdc++.h>
using namespace std;
 
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
#define MAX             100005
#define MOD             1000000007
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};
 
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);
 
#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>
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
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
 
//// ***************************************************** TEMPLETE ***************************************************** ////
 
 
//const int NUM=1000005;bool flag[NUM];vector <int> prime;void sieve(){flag[1]=true;for(int i=4; i<NUM; i+=2)flag[i]=true;for(int i=3; i*i<=NUM; i+=2){if(!flag[i]){for(int j=i*i; j<NUM; j+=(i<<1))flag[j]=true;}}prime.pb(2);for(int i=3; i<NUM; i+=2)if(!flag[i])prime.pb(i);return;}
 
//int NOD(ll n){int div=1;for(int i=0; prime[i]*prime[i]<=n; i++){if(n%prime[i]==0){int cnt=0;while(n%prime[i]==0){n/=prime[i];cnt++;}div*=(cnt+1);}}if(n>1){div*=2;}return div;}
 
//ll BigMod(ll B,ll P,ll M){ll R=1;while(P>0){if(P & 1)R=(R*B)%M;P=P>>1;B=(B*B)%M;}return R%M;}
 
 
//// ***************************************************** NUMBER THEORY ***************************************************** ////
 
 
//inline void build(int L,int R,int pos){if(L==R){tree[pos]=arr[L];return;}int mid=(L+R)/2;build(L,mid,pos*2+1);build(mid+1,R,pos*2+2);tree[pos]=min(tree[pos*2+1],tree[pos*2+2]);return;}
 
//inline int query(int ql,int qr,int L,int R,int pos){if(ql>R or qr<L) return MAX;else if(ql<=L and qr>=R) return tree[pos];int mid=(L+R)/2;int p=query(ql,qr,L,mid,2*pos+1);int q=query(ql,qr,mid+1,R,2*pos+2);return min(p,q);}
 
//void updateRange(int b,int e,int L,int R,int pos,ll val){if(lazy[pos]!=0){tree[pos]+=(R-L+1)*lazy[pos];if(L!=R){lazy[2*pos+1]+=lazy[pos];lazy[2*pos+2]+=lazy[pos];}lazy[pos]=0;}if(L>R or L>e or R<b) return;if(L>=b and R<=e){tree[pos]+=(R-L+1)*val;if(L!=R){lazy[2*pos+1]+=val;lazy[2*pos+2]+=val;}return;}int mid=(L+R)/2;updateRange(b,e,L,mid,2*pos+1,val);updateRange(b,e,mid+1,R,2*pos+2,val);tree[pos]=tree[2*pos+1]+tree[2*pos+2];return;}
 
//ll getSum(int ql,int qr,int L,int R,int pos){if(lazy[pos]!=0){tree[pos]+=(R-L+1)*lazy[pos];if(L!=R){lazy[2*pos+1]+=lazy[pos];lazy[2*pos+2]+=lazy[pos];}lazy[pos]=0;}if(L>R or ql>R or qr<L) return 0;if(L>=ql and qr>=R) return tree[pos];int mid=(L+R)/2;return getSum(ql,qr,L,mid,2*pos+1)+getSum(ql,qr,mid+1,R,2*pos+2);}
 
 
//// ***************************************************** SEGMENT TREE ***************************************************** ////
 
 
//inline void bfs(int s){MEM(vis,0);vis[s]=1;queue<int>Q;Q.push(s);while(!Q.empty()){int x=Q.front();Q.pop();REP(i,V[x].size()){if(!vis[V[x][i]]){vis[V[x][i]]=1;Q.push(V[x][i]);}}}return;}
 
//int cell[100][100]; int d[100][100],vis[100][100];int row,col;inline void bfs(int sx,int sy){ MEM(vis,0);vis[sx][sy]=1;queue<pii>q; q.push(pii(sx,sy));while(!q.empty()){pii top=q.front();q.pop();for(int k=0; k<4; k++){int tx=top.ff+fx[k];int ty=top.ss+fy[k]; if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0){vis[tx][ty]=1;d[tx][ty]=d[top.ff][top.ss]+1;q.push(pii(tx,ty)); }}}return;}
 
//inline void bi_dfs(int s,int c){if(vis[s]) return;vis[s]=1;color[s]=c;REP(i,V[s].size()) dfs(V[s][i],1-c);return;}
 
//struct point{int name,val;bool operator <(const point &p) const{return p.val < val;}};vector<int>V[105];int dis[105],cost[105][105];priority_queue<point>Q;void Dijkstra(int s){dis[s]=0;point get;get.name=s;get.val=0;Q.push(get);while(!Q.empty()){point tmp=Q.top();Q.pop();int now=tmp.name;REP(i,V[now].size()){int x=V[now][i];if(dis[now]+cost[now][x]<dis[x]){dis[x]=dis[now]+cost[now][x];get.name=x;get.val=dis[x];Q.push(get);}}}return;}
 
//struct edge{int u,v,w;bool operator < (const edge &p) const{return w < p.w;}};int pr[MAX];vector<edge>e;int find(int r){return pr[r]= (pr[r]==r) ? r:find(pr[r]);}int kruskal(int n){sort(e.begin(),e.end());FOR(i,1,n) pr[i]=i;int cnt=0,sum=0;REP(i,e.size()){int x=find(e[i].u);int y=find(e[i].v);if(x!=y){pr[x]=y;cnt++;sum+=e[i].w;if(cnt==n-1) break;}}return sum;}
 
//const int N=100005;int L[N],Pr[N],P[N][22];vector<int>V[N];void dfs(int s,int pre,int d){Pr[s]=pre;L[s]=d;for(int i:V[s]){if(i==pre) continue;dfs(i,s,d+1);}return;}void lca(){dfs(1,0,1); /*Source,Prev_Node(0/-1),Depth */ REP(i,N) REP(j,22) P[i][j]=1;FOR(i,1,N-1) P[i][0]=Pr[i];for(int j=1;(1<<j)<N;j++){REP(i,N){P[i][j]=P[P[i][j-1]][j-1];}}return;}int query(int p,int q){if(L[p]<L[q]) swap(p,q);ROF(i,21,0) if(L[P[p][i]]>=L[q]) p=P[p][i];if(p==q) return p;ROF(i,21,0){if(P[p][i]!=P[q][i]){p=P[p][i];q=P[q][i];}}return Pr[p];}
 
//// ***************************************************** GRAPH ***************************************************** ////
 
 
struct complx{
    long double real, img;
 
    inline complx(){
        real = img = 0.0;
    }
 
    inline complx(long double x){
        real = x, img = 0.0;
    }
 
    inline complx(long double x, long double y){
        real = x, img = y;
    }
 
    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }
 
    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }
 
    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }
 
    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }
 
    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};
;
 
void FFT(vector <complx> &ar, int n, int inv){
    int i, j, l, len, len2;
    const long double p = 4.0 * inv * acos(0.0);
 
    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }
 
    for(len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * inv;
        complx wlen(cos(ang), sin(ang));
        for(i = 0; i < n; i += len) {
            complx w(1);
            for(j = 0; j < len / 2; j++) {
                complx u = ar[i + j];
                complx v = ar[i + j + len / 2] * w;
                ar[i + j] = u + v;
                ar[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
 
    if (inv == -1){
        long double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp;
    }
}
 
 
vector <complx> Mul(const vector <complx> &x, const vector <complx> &y) {
    int n = 1;
    while(n <= x.size() + y.size()) n = n * 2;
    vector <complx> A(n), B(n);
    REP(i, x.size()) A[i] = x[i];
    REP(i, y.size()) B[i] = y[i];
    FFT(A, n, 1);
    FFT(B, n, 1);
    REP(i, n) A[i] = A[i] * B[i];
    FFT(A, n, -1);
    return A;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        vector<complx>v1,v2;
 
        int sign = 0;
        if(a[0] == '-'){
            sign = 1 - sign;
            a.erase(a.begin());
        }
        if(b[0] == '-'){
            sign = 1 - sign;
            b.erase(b.begin());
        }
		
        for(int i = 0;i < a.size();i++){
            int d = a[i] - '0';
            v1.push_back(complx(d));
        }
        for(int i = 0;i < b.size();i++){
            int d = b[i] - '0';
            v2.push_back(complx(d));
        }
 
        reverse(all(v1)),reverse(all(v2)); //Reverse needed if v1 is in x^n+x^n-1+.....+x^1+1 form
        vector<complx>v = Mul(v1,v2);
 
        int carry = 0;
        vector<int>answer;
        for(int i = 0;i < v.size();i++){
            int temp = round(v[i].real);
            temp += carry;
            answer.push_back(temp % 10);
            carry = temp/10;
        }
        while(answer.size() > 1 and answer.back() == 0)answer.pop_back();
        reverse(all(answer));
 
        for(int i : answer)cout << i;
        cout << "\n";
 
    }
}