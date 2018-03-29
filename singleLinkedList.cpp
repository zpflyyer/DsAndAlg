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
void reverseList(node** singleLinkedList){
    node* list = *singleLinkedList;
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
    (*singleLinkedList)-> next = q;
}
void insertHead(node** listHeadRef, int new_data)
{
	if((*listHeadRef) != NULL || (*listHeadRef)->value >= 0){
	    ((*listHeadRef)->value) ++;
	    node* newNode = new node;
	    newNode->value = new_data;
	    newNode->next = (*listHeadRef)->next;
	    (*listHeadRef)->next = newNode;
	}
}

void insertAfter(node* head, node* prev_node, int new_data)
{
    (head->value)++;
	node* newNode = new node;
	newNode->value = new_data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;
}

void append(node** head_ref, int new_data)
{
    (*head_ref)->value ++;
	node* last = *head_ref;
	while(last->next != NULL){
	    last = last->next;
	}
	last->next = new node;
	last->next->next = NULL;
	last->next->value = new_data;
}

void remove(node* singleLinkedList, int key, bool onlyFirst){
    node* temp = singleLinkedList->next;
    node* prev = singleLinkedList;
    node* del = NULL;
    while(temp != NULL){
        if(temp->value != key){
            prev = temp;
            temp = temp->next;
        } else {
            del = temp;
            temp = del->next;
            prev->next = del->next;
            delete del;
            (singleLinkedList->value)--;
            if(onlyFirst){
                break;
            }
        }
    }
}

void removeAt(node* singleLinkedList, int position){
    node* del = singleLinkedList->next;
    node* prev = singleLinkedList;
    int index = 1;
    while(index < position && del != NULL){
        index++;
        prev = del;
        del = del->next;
    }
    if(del != NULL){
        prev->next = del->next;
        delete del;
        singleLinkedList->value --;
    }
}
//iteractive
void correctLength(node* singleLinkedList){
    node* p = singleLinkedList->next;
    int length = 0;
    while(p!=NULL){
        length++;
        p = p->next;
    }
    singleLinkedList->value = length;
    cout << "length: " << length << endl;
}
//recursive
int  getLength(node* head){
   if(head != NULL ) {
       return 1+getLength(head->next);
   } else {
       return 0;
   }
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
	reverseList(&singleLinkedList);
	printSingleLinkedList(singleLinkedList);
	append(&singleLinkedList, 6);
	printSingleLinkedList(singleLinkedList);
    insertHead(&singleLinkedList, 7);
    printSingleLinkedList(singleLinkedList);
    insertHead(&singleLinkedList, 1);
    printSingleLinkedList(singleLinkedList);
    append(&singleLinkedList, 4);
    printSingleLinkedList(singleLinkedList);
    insertAfter(singleLinkedList, singleLinkedList->next, 8);
    printSingleLinkedList(singleLinkedList);
	return 0;
}