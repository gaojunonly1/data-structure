#include <bits/stdc++.h>
using namespace std;
int n,a[200005],now;
int fa[200005],dep[200005];
//记录答案 
int wwx,jyl=0,wy[200005];
struct tree_node {
	int node;
	tree_node *ls;
	tree_node *rs;
};
//建树 
void build(tree_node* &pos);
//找路径 
void dfs(tree_node* &pos);
//找节点
void dfs1(tree_node* &pos); 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n*2+1;i++)
		cin>>a[i];
	now=1;
	tree_node *rt=nullptr;
	build(rt);
	dep[rt->node]=0;
	fa[rt->node]=0;
	dfs(rt);
	for(i=1;i<=n;i++)
		wwx=max(wwx,dep[i]);
	dfs1(rt);
	cout<<wwx<<endl;
	while(fa[jyl]) {
		wy[++*wy]=jyl;
		jyl=fa[jyl];
	}
	wy[++*wy]=jyl;
	for(i=*wy;i>1;i--)
		cout<<wy[i]<<" ";
	cout<<wy[1];
	return 0;
}
void build(tree_node* &pos) {
	if(a[now]==-1) {
		pos=nullptr;
		now++;
		return;
	}
	else {
		pos=(struct tree_node*)malloc(sizeof(struct tree_node));
		pos->node=a[now++];
		build(pos->ls);
		build(pos->rs);
	}
}
void dfs(tree_node* &pos) {
	if(pos->node==-1)
		return;
	if(pos->ls) {
		dep[pos->ls->node]=dep[pos->node]+1;
		fa[pos->ls->node]=pos->node;
		dfs(pos->ls);
	}
	if(pos->rs) {
		dep[pos->rs->node]=dep[pos->node]+1;
		fa[pos->rs->node]=pos->node;
		dfs(pos->rs);
	}
}
void dfs1(tree_node* &pos) {
	if(pos->node==-1||jyl!=0)
		return;
	if(dep[pos->node]==wwx) {
		jyl=pos->node;
		return;
	}
	if(pos->rs)
		dfs1(pos->rs);
	if(pos->ls)
		dfs1(pos->ls);
}
