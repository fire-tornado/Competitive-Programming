#include <bits/stdc++.h>
using namespace std;

const int N = 2000006;
const int M = 22;

int n, stp, sfxMv, sfx[N], tmp[N];
int sfxSum[N], sfxCnt[N], Rank[M][N];
int lcp[N], rnk[N];
char in[N];

char a[N], b[N];

inline bool Equal(const int &u, const int &v){
    if(!stp) return in[u] == in[v];
    if(Rank[stp-1][u] != Rank[stp-1][v]) return false;
    int a = u + sfxMv < n ? Rank[stp-1][u+sfxMv] : -1;
    int b = v + sfxMv < n ? Rank[stp-1][v+sfxMv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sfxSum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        sfx[i] = tmp[i];
        if(i && !Equal(sfx[i], sfx[i-1])) {
            Rank[stp][sfx[i]] = ++rnk;
            sfxSum[rnk+1] = sfxSum[rnk];
        }
        else Rank[stp][sfx[i]] = rnk;
        sfxSum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) sfxCnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < sfxMv; i++){
        int idx = Rank[stp - 1][n - i - 1];
        int x = sfxSum[idx];
        tmp[x + sfxCnt[idx]] = n - i - 1;
        sfxCnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = sfx[i] - sfxMv;
        if(idx < 0)continue;
        idx = Rank[stp-1][idx];
        int x = sfxSum[idx];
        tmp[x + sfxCnt[idx]] = sfx[i] - sfxMv;
        sfxCnt[idx]++;
    }
    update();
    return;
}

inline bool cmp(const int &a, const int &b){
    if(in[a]!=in[b]) return in[a]<in[b];
    return false;
}

void print(){
    for(int i=0;i<n;i++) { for(int j=sfx[i];j<n;j++) printf("%c", in[j]); printf("\n"); }
}

void suffixArray() {
    int i;
    for(i = 0; i < n; i++) tmp[i] = i;
    sort(tmp, tmp + n, cmp);
    stp = 0;
    update();
    ++stp;
    for(sfxMv = 1; sfxMv < n; sfxMv <<= 1) {
        Sort();
        stp++;
    }
    stp--;
    for(i = 0; i <= stp; i++) Rank[i][n] = -1;
}



void kasai() {
    for(int i=0;i<n;i++) rnk[ sfx[i] ] = i;
    for(int i = 0, k = 0; i < n; i++, k ? k-- : 0) {
        if(rnk[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sfx[ rnk[i] + 1 ];
        while(i + k < n && j + k < n && in[i + k] == in[j + k]) k++;
        lcp[ rnk[i] ] = k;
    }
}

int main()
{
    scanf("%s",in);
    n=strlen(in);

    suffixArray();
    print();
    kasai();

    for(int i=0;i<n;i++) cout << lcp[i] << '\n';

    return 0;
}
