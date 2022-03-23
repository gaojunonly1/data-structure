#ifndef _Gqueue_h_



#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Gqueue_node{
	T data;
	Gqueue_node<T> *nxt;
	Gqueue_node<T> *pre;
};

template<typename T>
class Gqueue {
	public:
		Gqueue();
		~Gqueue();
		Gqueue<T>& Ginsert_head(T item);
		Gqueue<T>& Ginsert_tail(T item);
		Gqueue<T>& Greverse();
		void Gshow()const;
	private:
		Gqueue_node<T> jyl;//一个空节点 
		size_t sz;
};

template<typename T>
Gqueue<T>::Gqueue() {
	jyl.nxt=&jyl;
	jyl.pre=&jyl;
	sz=0;
}

template<typename T>
Gqueue<T>::~Gqueue() {
	Gqueue_node<T> *oo=jyl.nxt;
	while(oo!=&jyl) {
		oo=oo->nxt;
		delete oo->pre;
	}
	jyl.nxt=&jyl;
	jyl.pre=&jyl;
	sz=0;
}

template<typename T>
Gqueue<T>& Gqueue<T>::Ginsert_head(T item) {
	Gqueue_node<T> *oo=new Gqueue_node<T>;
	oo->data=item;
	oo->nxt=jyl.nxt;
	oo->pre=&jyl;
	jyl.nxt=oo;
	oo->nxt->pre=oo;
	sz++;
	return *this;
}

template<typename T>
Gqueue<T>& Gqueue<T>::Ginsert_tail(T item) {
	Gqueue_node<T> *oo=new Gqueue_node<T>;
	oo->data=item;
	oo->nxt=&jyl;
	oo->pre=jyl.pre;
	jyl.pre=oo;
	oo->pre->nxt=oo;
	sz++;
	return *this;
}

template<typename T>
Gqueue<T>& Gqueue<T>::Greverse() {
	Gqueue_node<T> *oo=nullptr;
	Gqueue_node<T> *wwx=jyl.nxt; //头结点
	while(wwx!=&jyl) {
		oo=wwx->nxt;
		wwx->nxt=wwx->pre;
		wwx->pre=oo;
		wwx=oo;
	}
	oo=jyl.nxt;
	jyl.nxt=jyl.pre;
	jyl.pre=oo;
	return *this;
}

template<typename T>
void Gqueue<T>::Gshow() const{
	Gqueue_node<T> *oo=jyl.nxt;
	while(oo!=&jyl) {
		cout<<oo->data<<"<==>";
		oo=oo->nxt;
	}
	puts("");
}



#endif
