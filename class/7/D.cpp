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
	multiset<int>s;
	queue<int>que;
	bool rev=0;
	int T;
	R(T);
	while(T--) {
		char ch=' ';
		while(0==isupper(ch))
			ch=getchar();
		int oo;
		if('I'==ch) {
			R(oo);
			if(1==rev)
				oo*=-1;
			s.insert(oo);
			que.push(oo);
		}
		else if('D'==ch) {
			if(1==que.empty())
				continue;
			auto it=s.find(que.front());
			s.erase(it);
			que.pop();
		}
		else if('R'==ch)
			rev^=1;
		else {
			if(1==s.empty())
				continue;
			if(1==rev)
				Wl(-*s.begin());
			else
				Wl(*s.rbegin());
		}
	}
    return 0;
}
