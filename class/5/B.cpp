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
struct Tree {
	int s[1000005];
	#define lowbit(x) ((x)&(-x))
	inline void Add(int x,int w) {
		for(;x<1000000;x+=lowbit(x))
			s[x]+=w;
	}
	inline int Ask(int x) {
		int y=0;
		for(;x>0;x-=lowbit(x))
			y+=s[x];
		return y;
	}
}T;
int main() {
	int n;
	int i;
	R(n);
	ll wwx=0;
	vector<int>a(n);
	for(i=0;i<n;i++)
		R(a[i]);
	for(i=n-1;i>=0;i--) {
		wwx+=T.Ask(a[i]-1);
		T.Add(a[i],1);
	}
	Wl(wwx);
    return 0;
}
