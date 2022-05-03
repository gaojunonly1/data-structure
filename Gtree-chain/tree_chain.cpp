#include <bits/stdc++.h>
using namespace std;
int fa[100005]; //父亲节点 
int dep[100005]; //深度 
int size[100005]; //子树大小 
int son[1000005]; //重儿子 
int rk[100005]; //dfs序中的排名 
int top[100005]; //重链顶部的节点 
int id[100005]; //剖分后的新编号
#define pb push_back
vector<int>G[100005];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,pp,qq;
	cin>>n;
	for(i=1;i<n;i++) {
		cin>>pp>>qq;
		G[pp].pb(qq);
		G[qq].pb(pp);
	}
	return 0;
}
