# ifndef _Gstasck_h_


#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Gstack_node{
	T data;
	Gstack_node<T> *pre;
};

template<typename T>
class Gstack {
	public:
		Gstack();
		~Gstack();
		void Gpush(T tmp);
		T Gtop();
		void Gpop();
	private:
		Gstack_node<T> jyl; //a vacant node
		size_t Gsize;
};

template<typename T>
Gstack<T>::Gstack() {
	jyl.pre=&jyl;
	Gsize=0;
}

template<typename T>
Gstack<T>::~Gstack() {
	Gstack_node<T> *oo=jyl.pre;
	while(oo!=&jyl) {
		auto pp=oo->pre;
		delete oo;
		oo=pp;
	}
	Gsize=0;
	jyl.pre=&jyl;
}

template<typename T>
void Gstack<T>::Gpush(T tmp) {
	Gstack_node<T> *oo=new Gstack_node<T>;
	oo->data=tmp;
	oo->pre=jyl.pre;
	jyl.pre=oo;
	Gsize++;
}

template<typename T>
void 


#endif
