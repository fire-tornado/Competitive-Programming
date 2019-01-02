//Complexity O(|S|)
//https://rezwanarefin01.github.io/posts/palindromic-tree-01/

#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int tree[N][26],len[N],link[N],idx,t;
char str[N]; // 1-indexed

void extend(int p)
{
    while(str[p-len[t]-1]!=str[p]) t=link[t];
    int x=link[t];
    while(str[p-len[x]-1]!=str[p]) x=link[x];
    int c=str[p]-'a';
    if(!tree[t][c])
    {
        tree[t][c]=++idx;
        len[idx]=len[t]+2;
        link[idx]=len[idx]==1?2:tree[x][c];
    }
    t=tree[t][c];
}

void build()
{
    len[1]=-1,link[1]=1;
    len[2]=0,link[2]=1;
    idx=t=2;
    int len=strlen(str+1);
    for(int i=1; i<=len; i++) extend(i);
}

int main()
{
    scanf("%s",str+1);
    build();

}
