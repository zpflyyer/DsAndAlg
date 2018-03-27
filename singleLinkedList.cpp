#include <iostream>
using namespace std;
struct node {
    int value = 0;
    node * next = NULL;
};
void printSingleLinkedList(node* list){
    node* p = list;
    if(p!=NULL){
        for (int i = 0; i < list->value; i++) {
            p=p->next;
            cout << p->value << "\t";
        }
        cout << endl;
    }  
}
node* reverseList(node* list){
    node* q = NULL;
    if(list != NULL && list->value >0){
        node* p = list->next;//first node;
        node* t = NULL;
        while(p != NULL){
            t = p->next;//just use one temporarry pointer remember the unreversed list.
            p->next = q;//reverse current node
            //both pointer move forward one more step.
            q = p;
            p = t;
        }
    }
    list->next = q;
    return list;
}
int main() {
	node* singleLinkedList = new node;
	node* p = singleLinkedList;
	cin >> singleLinkedList->value;
	for (int i = 0; i < singleLinkedList->value; i++) {
	    p->next = new node;
	    p = p->next;
	    cin >> p->value;
	}
	printSingleLinkedList(singleLinkedList);
	singleLinkedList = reverseList(singleLinkedList);
	printSingleLinkedList(singleLinkedList);
	return 0;
}