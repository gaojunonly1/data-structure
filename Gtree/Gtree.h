#ifndef _Gtree_h_



#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Gtree_node{
	T data;
	Gtree_node<T> *lft;
	Gtree_node<T> *rig;
};

template<typename T>
class Gtree {
	public:
		Gtree();
		~Gtree();
	private:
		Gtree_node<T> jyl;
		size_t sz;
};

template<typename T>
Gtree<T>::Gtree() {
	sz=0;
	jyl=nullptr;
}

template<typename T>
Gtree<T>::~Gtree() {
	Gtree_node<T> *oo=jyl;
	while(sz) {
		
	}
}


#endif
