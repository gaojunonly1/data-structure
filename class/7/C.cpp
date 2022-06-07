#include <bits/stdc++.h>
using namespace std;
int tot=0;
struct TrieNode {
	int son[26];
	int wwx;
}a[200001];
void Insert(string word);
int Ask(string word);
int main() {
	int n,m;
	cin>>n>>m;
	string s;
	while(n--) {
		cin>>s;
		Insert(s);
	}
	while(m--) {
		cin>>s;
		cout<<Ask(s)<<endl;
	}
    return 0;
}
void Insert(string word) {
	int pp=0;
	for(auto ch:word) {
		int oo=ch-'a';
		if(0==a[pp].son[oo])
			a[pp].son[oo]=++tot;
		pp=a[pp].son[oo];
		a[pp].wwx++;
	}
}
int Ask(string word) {
	int pp=0;
	for(auto ch:word) {
		int oo=ch-'a';
		if(0==a[pp].son[oo])
			return 0;
		pp=a[pp].son[oo];
	}
	return a[pp].wwx;
}
