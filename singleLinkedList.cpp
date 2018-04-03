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

void swap(node** a, node** b){
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void swapFirstOccur(node** first_ref, int key1, int key2){
    node** a=NULL;
    node** b=NULL;
    while((*first_ref) != NULL){
        if((*first_ref)->value == key1 && a == NULL){
            a = first_ref;
        }
        if((*first_ref)->value == key2 && b == NULL){
            b = first_ref;
        }
        if(a != NULL && b != NULL){
            break;
        }
        first_ref = &((*first_ref)->next);
    }
    if(a != NULL && b != NULL){
    	//what a great idea, which can handle all situations
        swap(a, b);
        swap(&((*a)->next),&((*b)->next));
    }
}

//will not break list1 or list2 down
node* sortedMerge(node* list1, node* list2){
    node* resultantList = new node;
    node* p = resultantList;
    p->value = list1->value + list2->value;
    list1 = list1->next;
    list2 = list2->next;
    while(1){
    	if(list1 == NULL){
            p->next = list2;
            break;
        }
        if(list2 == NULL){
            p->next = list1;
            break;
        }
        if(list1->value <= list2->value){
            p->next = new node;
            p->next->value = list1->value;
            list1 = list1->next;
            p=p->next;
        } else {
            p->next = new node;
            p->next->value = list2->value;
            list2 = list2->next;
            p=p->next;
        }
    }
    return resultantList;
}
// will break list into to pieces
void halve(node* list, node** leftHalf, node** rightHalf){
    node* slow = list, *fast = list;
    int leftLength = 0;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        leftLength ++;
        if(fast->next != NULL){
            fast = fast->next;
        }
    }
    *leftHalf = new node, *rightHalf = new node;
    //left part
    (*leftHalf)->value = leftLength;
    (*leftHalf)->next = list->next;
    //right part
    (*rightHalf)->value = list->value - leftLength;
    (*rightHalf)->next = slow->next;
    slow->next = NULL;
}

void mergeSort(node** list){
    if((*list)->value <= 1){
        return;
    }
    node* a, *b;
    halve(*list, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *list = sortedMerge(a, b);
    printSingleLinkedList(*list);
}

int main() {
	node *singleLinkedList1 = new node, *singleLinkedList2 = new node;
	node* p = singleLinkedList1, *q=singleLinkedList2;
	cin >> singleLinkedList1->value;
	for (int i = 0; i < singleLinkedList1->value; i++) {
	    p->next = new node;
	    p = p->next;
	    cin >> p->value;
	}
	cin >> singleLinkedList2->value;
	for (int i = 0; i < singleLinkedList2->value; i++) {
	    q->next = new node;
	    q = q->next;
	    cin >> q->value;
	}
// 	node* mergedList = sortedMerge(singleLinkedList1, singleLinkedList2);
// 	printSingleLinkedList(mergedList);
	
// 	node* a, *b;
// 	halve(mergedList, &a, &b);
// 	printSingleLinkedList(a);
// 	printSingleLinkedList(b);
	
	mergeSort(&singleLinkedList1);
	printSingleLinkedList(singleLinkedList1);
	return 0;
}

int main() {
	node *singleLinkedList1 = new node, *singleLinkedList2 = new node;
	node* p = singleLinkedList1, *q=singleLinkedList2;
	cin >> singleLinkedList1->value;
	for (int i = 0; i < singleLinkedList1->value; i++) {
	    p->next = new node;
	    p = p->next;
	    cin >> p->value;
	}
	cin >> singleLinkedList2->value;
	for (int i = 0; i < singleLinkedList2->value; i++) {
	    q->next = new node;
	    q = q->next;
	    cin >> q->value;
	}
	printSingleLinkedList(sortedMerge(singleLinkedList1, singleLinkedList2));
	return 0;
}