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
int n=0;
struct question {
	int opt,num,id;
}tt[1000005];
int she[1000005];
int a[1000005];
struct Tree {
	int s[1000005];
	#define lowbit(x) ((x)&(-x))
	inline void Add(int x,int w) {
		for(;x<=n;x+=lowbit(x))
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
	int Q;
	int i;
	map<int,int>mmp;
	R(Q);
	for(i=1;i<=Q;i++) {
		R(tt[i].opt); R(tt[i].num);
		if(tt[i].opt==2)
			continue;
		a[++*a]=tt[i].num;
	}
	sort(a+1,a+*a+1);
	mmp[a[1]]=++n;
	she[n]=a[1];
	for(i=2;i<=*a;i++)
		if(a[i]!=a[i-1]) {
			mmp[a[i]]=++n;
			she[n]=a[i];
		}
	for(i=1;i<=Q;i++)
		if(2!=tt[i].opt)
			tt[i].id=mmp[tt[i].num];
	for(i=1;i<=Q;i++) {
		if(1==tt[i].opt)
			T.Add(tt[i].id,1);
		else if(2==tt[i].opt){
			int l1=1,r1=n;
			while(l1<=r1) {
				int mid=(l1+r1)>>1;
				if(T.Ask(mid)>=tt[i].num)
					r1=mid-1;
				else
					l1=mid+1;
			}
			Wl(she[l1]);
		}
		else
			T.Add(tt[i].id,-1);
	}
	return 0;
}
