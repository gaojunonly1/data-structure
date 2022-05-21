#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
void calc_f(string s,vector<int> &a);
int kmp_find(string s,string t,const vector<int> &a);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,t;
	cin>>s;
	cin>>t;
	s='#'+s;
	int i;
	vector<int>f((size_t)s.size()+5);
	calc_f(s,f);
//	for(i=1;i<(size_t)s.size();i++)
//		cout<<f[i]<<" ";
//	cout<<endl;
	cout<<kmp_find(s,t,f)<<endl;
    return 0;
}
void calc_f(string s,vector<int> &a) {
	a[1]=0;
	int i;
	for(i=2;i<(size_t)s.size();i++) {
		a[i]=a[i-1];
		while(s[a[i]+1]!=s[i]&&a[i])
			a[i]=a[a[i]];
		if(s[a[i]+1]==s[i])
			a[i]++;
	}
	a[0]=-1;
}
int kmp_find(string s,string t,const vector<int> &fail) {
	if(s.size()<1||t.size()<1||s.size()<t.size())
		return -1;
	int i,j;
	j=-1;
	for(i=1;i<(size_t)s.size();i++) {
		while(j>=0&&t[j+1]!=s[i])
			j=fail[j];
		if(t[j+1]==s[i])
			j++;
		if(j==t.size()-1)
			return i-j;
	}
	return -1;
}
