#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
struct ChainNode {
	T val;
	ChainNode<T>* next;
	ChainNode() {};
	ChainNode(const T& val) : val(val) { }
	ChainNode(const T& val,  ChainNode<T>* next): val(val),next(next) {	}//构造函数初始值列表不需要提供this指针进行说明
};
template<class T>
class Chain {
public:
	Chain() {
		head = NULL;
		listlength = 0;	
	}
	Chain(const Chain<T>& chain);
	~Chain();

	class iterator {
	public:
		iterator(ChainNode<T>* theNode = NULL) {
			node = theNode;
		}
		T& operator*()const {
			return this->node->val;
		}
		T* operator->() const {
			return &this->node->val;
		}
		iterator& operator++() {
			node = node->next;
			return *this;					//返回值并非局部变量，可以进行返回引用
		}
		iterator operator++(int) {
			iterator old = *this;
			node = node->next;
			return old;
		}	
		bool operator!=(const iterator& right)const {
			return this->node != right.node;
		}
		bool operator==(const iterator& right)const {
			return this->node == right.node;
		}
	protected:
		ChainNode<T>* node;
	};
	//使用iterator需要在定义iterator类之后！！
	iterator begin() {
		return iterator(head);				//变量为局部变量，不能够返回引用类型
	}
	iterator end() {
		return iterator(NULL);				//,尾后迭代器为空
	}
	bool empty() { return this->listlength == 0; }
	int size() { return this->listlength; }
	T& get(int index)const;
	void insert(int index, const T& val);
	void erase(int index);
	void output(ostream& out) const;
	friend ostream& operator<<(ostream& out, const Chain<T>& chain);


protected:
	bool checkIndex(int index) const;
	ChainNode<T>* head;
	int listlength;
};
//复制构造函数
template<class T>
Chain<T>::Chain(const Chain<T>& chain) {
	listlength = chain.listlength;
	if (listlength == 0)
		head = NULL;
		return;
	ChainNode<T>* source = chain.head;
	head = new ChainNode<T>(source->val);
	ChainNode<T>* target = head;
	while (source->next != NULL) {
		source = source->next;
		target->next = new ChainNode<T>(source->val);
		target = target->next;
	}
	target = NULL;
}
//析构函数
template<class T>
Chain<T>::~Chain() {
	while (head != NULL) {
		ChainNode<T>* tempnext = head->next;
		delete head;
		head = tempnext;
	}
}
//get
template<class T>
T& Chain<T>::get(int index)const {
	if (checkIndex())
		throw("index out of range");
	ChainNode<T>* pcur = this->head;
	for (int i = 0; i < index; i++)
		pcur = pcur->next;
	return pcur->val;
}
//insert element
template<class T>
void Chain<T>::insert(int index, const T& val)  {
	if (index<0 || index>this->listlength)
	{
		cout << "index out of range! " << endl;
		return;
	}
	if (index == 0) {
		this->head = new ChainNode<T>(val,head);

	}
	else {
		ChainNode<T>* pcur = this->head;
		for (int i = 0; i < index - 1; i++)
				pcur = pcur->next;
		pcur->next = new ChainNode<T>(val, pcur->next);
	}
	listlength++;
	
}
// check Index
template<class T>
bool Chain<T>::checkIndex(int index) const {
	if (index < 0 || index >= this->listlength)
		return true;
	else
		return false;
}

//erase by index
template<class T>
void Chain<T>::erase(int index) {
	if (checkIndex(index))
		throw("index out of range");
	if (index == 0) {
		ChainNode<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	else {
		ChainNode<T>* pcur = this->head;
		for (int i = 0; i < index - 1; i++)
			pcur = pcur->next;
		ChainNode<T>* temp = pcur->next;
		pcur->next = temp->next;
		delete temp;
	}
	listlength--;
}
//output
template<class T>
void Chain<T>::output(ostream& out) const {
	if (head == NULL){
		out << "list is empty!" << endl;
		return;
	}
	int i = 0;
	for (ChainNode<T>* pcur = this->head; pcur != NULL; pcur = pcur->next){
		out  << pcur->val <<"index:  " <<i<< endl;
		i++;
	}
	
}

template<class T>
ostream& operator<<(ostream& out, const Chain<T>& chain) {
	chain.output();
	return out;
}
