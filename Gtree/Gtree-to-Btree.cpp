#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;

template<typename T>
struct Gtree_node {
	T id;
	Gtree_node<T> *left;
	Gtree_node<T> *right;
};

template<typename T>
class Gtree {
	public:
		Gtree();
		~Gtree();
		void Gbuild();
		void Gshape();
	private:
		vector<int>G[100005];
		Gtree_node<T> Grt;
		size_t sz;
};

template<typename T>
Gtree<T>::Gtree() {
	sz=0;
	Grt.left=nullptr;
	Grt.right=nullptr;
}

template<typename T>
Gtree<T>::~Gtree() {
	
}

template<typename T>
void Gtree<T>::Gbuild() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}
