#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
inline ll read()
{
    ll s=0; bool f=0; char ch=' ';
    while(!isdigit(ch))    {f|=(ch=='-'); ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
    return (f)?(-s):(s);
}
#define R(x) x=read()
inline void write(ll x)
{
    if(x<0) {putchar('-'); x=-x;}
    if(x<10) {putchar(x+'0'); return;}
    write(x/10); putchar((x%10)+'0');
}
#define W(x) write(x),putchar(' ')
#define Wl(x) write(x),putchar('\n')
int n,m;
vector<int>G[100005];
bool vis[100005];
int tim=0,rus[100005],chs[100005];
int cnt=0;
struct node {
	int u,v;
	bool operator<(const node tmp)const {
		return v<tmp.v;
	}
}jyl[100005];
void dfs(int u);
int main() {
	int i;
	R(n);
	R(m);
	for(i=0;i<m;i++) {
		int u,v;
		R(u);
		R(v);
		G[u].pb(v);
		G[v].pb(u);
	}
	for(i=1;i<=n;i++)
		if(!vis[i]) {
			vis[i]=1;
			dfs(i);
		}
	for(i=1;i<=n;i++) {
		W(rus[i]);
		Wl(chs[i]);
	}
	sort(jyl+1,jyl+cnt+1);
	Wl(cnt);
	for(i=1;i<=cnt;i++) {
		W(jyl[i].u);
		Wl(jyl[i].v);
	}
    return 0;
}
void dfs(int u) {
	rus[u]=++tim;
	for(int i=0;i<(size_t)G[u].size();i++) {
		int v=G[u][i];
		if(!vis[v]) {
			jyl[++cnt]=(node){u,v};
			vis[v]=1;
			dfs(v);
		}
	}
	chs[u]=++tim;
}
