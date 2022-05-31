#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,p1,p2;
	int i,j,k;
	cin>>n;
	vector<int>fa(n);
	fa[1]=1;
	for(i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		fa[v]=u;
	}
	vector<int>dep(n);
	dep[1]=1;
	for(i=2;i<=n;i++)
		dep[i]=dep[fa[i]]+1;
	cin>>p1>>p2;
	int pp1=p1,pp2=p2;
	int lca;
	if(dep[p1]<dep[p2])
		swap(p1,p2);
	while(dep[p1]>dep[p2])
		p1=fa[p1];
	if(p1==p2)
		lca=p1;
	else {
		while(p1!=p2) {
			p1=fa[p1];
			p2=fa[p2];
		}
		lca=p1;
	}
	p1=pp1;
	p2=pp2;
	int wwx=0;
	while(p1!=lca) {
		p1=fa[p1];
		wwx+=3;
	}
	while(p2!=lca) {
		p2=fa[p2];
		wwx+=2;
	}
//	cout<<p1<<" "<<p2<<" "<<"lca="<<lca<<endl;
	cout<<wwx<<endl;
    return 0;
}
/*
5
1 2
2 3
1 4
4 5
*/
