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
vector<int>G[50005];
vector<pii>wwx;
int tim=0;
vector<pii>jyl;
void dfs(int u);
int main() {
	int i;
	R(n);
	R(m);
	for(i=1;i<=m;i++) {
		int p,q;
		R(p);
		R(q);
		p--;
		q--;
		G[p].pb(q);
		G[q].pb(p);
	}
	wwx.resize(n);
	for(i=0;i<n;i++)
		if(!wwx[i].fi)
			dfs(i);
	for(i=0;i<n;i++) {
		W(wwx[i].fi);
		Wl(wwx[i].se);
	}
	Wl(jyl.size());
	sort(jyl.begin(),jyl.end());
	for(auto oo:jyl) {
		W(oo.se+1);
		Wl(oo.fi+1);
	}
    return 0;
}
void dfs(int u) {
	wwx[u].fi=++tim;
	for(auto v:G[u]) {
		if(wwx[v].fi)
			continue;
		jyl.pb(pii(v,u));
		dfs(v);
	}
	wwx[u].se=++tim;
}
