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
const int power=4;
const int base=10000;
struct Bignum {
    int a[30];
    Bignum() {
		memset(a, 0, sizeof a);
	}
    inline void add(int x) {
		if(x||a[0]) a[++a[0]]=x;
	}
    inline void print() {
        printf("%d",a[a[0]]);
        for(int i=a[0]-1;i>=1;i--)
        	printf("%0*d", power, a[i]);
        printf("\n");
    }
};
inline Bignum operator +(const Bignum &p,const Bignum &q) {
    Bignum pp;
    pp.a[0]=max(p.a[0],q.a[0]);
    for(int i=1;i<=pp.a[0];i++) {
        pp.a[i]+=p.a[i]+q.a[i];
        pp.a[i+1]+=pp.a[i]/base;
        pp.a[i]%=base;
    }
    if(pp.a[pp.a[0]+1])
		pp.a[0]++;
    return pp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	R(n);
	R(m);
	vector<int>a(n);
	int i;
	for(i=0;i<n;i++)
		R(a[i]);
	vector<int>G[10005];
	vector<int>deg(n,0);
	for(i=0;i<m;i++) {
		int u,v;
		R(u);
		u--;
		R(v);
		v--;
		G[u].pb(v);
		deg[v]++;
	}
	vector<Bignum>jyl(n);
	queue<int>que;
	vector<ll>dist(n,0);
	for(i=0;i<n;i++)
		if(0==deg[i]) {
			que.push(i);
			jyl[i].add(1);
			dist[i]=a[i];
		}
	int bo=n;
	while(0==que.empty()) {
		int u=que.front();
		que.pop();
		bo--;
		for(auto v:G[u]) {
			deg[v]--;
			if(0==deg[v])
				que.push(v);
			if(dist[v]<dist[u]+a[v]) {
				dist[v]=dist[u]+a[v];
				jyl[v]=jyl[u];
			}
			else if(dist[v]==dist[u]+a[v])
				jyl[v]=jyl[v]+jyl[u];
		}
	}
	if(0!=bo) {
		puts("0");
		return 0;
	}
	int mx=0;
	Bignum wwx;
	for(i=0;i<n;i++) {
		if(dist[i]>mx) {
			mx=dist[i];
			wwx=jyl[i];
		}
		else if(dist[i]==mx)
			wwx=wwx+jyl[i];
	}
	Wl(mx);
	wwx.print();
	return 0;
}
