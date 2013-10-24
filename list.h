#include <cstddef>

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};
	
template <class T>
struct List {
    Node<T>* head;
};

template <class T>
void initialize(List<T>& s){
	s.head=NULL;
}

template <class T>
void destroy(List<T>& s){
	if(s.head==NULL)
		return;
	Node<T>* del=s.head;
	del->prev->next=NULL;
	while(s.head!=NULL)
	{
		del=s.head->next;
		delete s.head;
		s.head=del;
	}
}

template <class T>
void append(List<T>& s,T val){
	Node<T>* newNode=new Node<T>;
	newNode->data=val;
	if(s.head==NULL){
		newNode->next=newNode;
		newNode->prev=newNode;
		s.head=newNode;
		return;
	}
	newNode->next=s.head;
	newNode->prev=s.head->prev;
	s.head->prev->next=newNode;
	s.head->prev=newNode;
}

template <class T>
bool contains(List<T> s,T val){
	if(s.head==NULL)
		return false;
	Node<T>* walker=s.head;
	if (walker->data==val)
		return true;
	walker=walker->next;
	while(walker->data!=s.head->data){
		if (walker->data==val)
			return true;
		walker=walker->next;
	}
	return false;
}

template <class T>
bool isEmpty(List<T> s){
	return s.head==NULL;
}

template <class T>
int  getSize(List<T> s){
	if(s.head==NULL)
		return 0;
	Node<T>* walker=s.head;
	int count=1;
	walker=walker->next;
	while(walker->data!=s.head->data){
		count++;
		walker=walker->next;
	}
	return count;
}

template <class T>
T    getNth(List<T> s,int n){
	Node<T>* walker=s.head;
	for(int i=1; i<n; i++)
	{
		walker=walker->next;
	}
	return walker->data;
}

template <class T>
void removeNth(List<T>& s,int n){
	Node<T>* del=s.head;
	if (n==1)
		s.head=s.head->next;
	for (int i=1; i<n; i++)
	{
		del=del->next;
	}
	del->prev->next=del->next;
	del->next->prev=del->prev;
	delete del;
}