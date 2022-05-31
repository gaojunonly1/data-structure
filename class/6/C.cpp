#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
inline ll read()
{
    ll s=0; bool f=0; char ch=' ';
    while(!isdigit(ch)) {f|=(ch=='-'); ch=getchar();}
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
int main() {
	int T;
	R(T);
	while(T--) {
		int n,m;
		R(n);
		R(m);
		vector<pii>wwx(n+5);
		int i;
		for(i=1;i<=n;i++) {
			wwx[i].fi=i-1;
			wwx[i].se=i+1;
		}
		wwx[1].fi=n;
		wwx[n].se=1;
		while(m--) {
			char ch=' ';
			while(0==isupper(ch))
				ch=getchar();
			int x,y;
			R(x);
			R(y);
			#define pre(x) wwx[x].fi
			#define nxt(x) wwx[x].se
			if('A'==ch) {
				wwx[pre(x)].se=nxt(x);
				wwx[nxt(x)].fi=pre(x);
				wwx[pre(y)].se=x;
				pre(x)=pre(y);
				nxt(x)=y;
				pre(y)=x;
			}
			else if('B'==ch) {
				wwx[pre(x)].se=nxt(x);
				wwx[nxt(x)].fi=pre(x);
				wwx[nxt(y)].fi=x;
				nxt(x)=nxt(y);
				nxt(y)=x;
				pre(x)=y;
			}
			else {
				if(0==x)
					Wl(pre(y));
				else
					Wl(nxt(y));
			}
		}
	}
    return 0;
}
