#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> >que;
int n;
ll wwx[100005],jyl=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	ll oo,pp,qq;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>oo;
		que.push(oo);
	}
	if(n==1) {
		puts("0");
		return 0;
	}
	while(que.size()>1) {
		pp=que.top();
		que.pop();
		qq=que.top();
		que.pop();
		wwx[++*wwx]=pp+qq;
		jyl+=wwx[*wwx];
		que.push(pp+qq);
	}
	cout<<jyl<<endl;
	for(i=*wwx;i>1;i--)
		cout<<wwx[i]<<" ";
	cout<<wwx[1];
	return 0;
}
