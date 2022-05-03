#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005],b[100005];
struct node {
	int id,pos;
	ll num;
	bool operator<(const node &oo) const{
		return num>oo.num;
	}
};
priority_queue<node>que;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
		que.push((node){i,1,a[i]*b[1]});
	for(i=1;i<n;i++) {
		cout<<que.top().num<<" ";
		node tmp=que.top();
		tmp.pos++;
		tmp.num=a[tmp.id]*b[tmp.pos];
		que.pop();
		que.push(tmp);
	}
	cout<<que.top().num;
	return 0;
}
