#include <iostream>
using namespace std;
struct node {
    int value = 0;
    node * next = NULL;
};
void printSingleLinkedList(node* list){
    node* p = list;
    if(p!=NULL){
        while(p->next != NULL) {
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
void reverseFirstK(node** listHeadRef, int k){
    if((*listHeadRef)->value <= 1){
        return;
    }
    if(k > (*listHeadRef)->value){
        reverseFirstK(listHeadRef, (*listHeadRef)->value);
    }
    node* q = (*listHeadRef)->next;//first element
    node* p = q->next;//second selement
    
    node* t = NULL;
    for (int i = 2; i <= k; i++) {
        t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    (*listHeadRef)->next->next = p;
    (*listHeadRef)->next = q;
    
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

void removeLoop(node* loopNode, node* head){
    cout << "loopNode: " << loopNode->value << ", \theadNode: " << head->value << endl;
    node* ptr1, *ptr2;
    ptr1 = head;
    while(true){
        ptr2 = loopNode;
        while(ptr2->next != loopNode && ptr2->next != ptr1){
            ptr2 = ptr2->next;
        }
        if(ptr2->next == ptr1){
            cout << "cycle node: " << ptr1->value << endl;
            break;
        }
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
bool detectAndRemoveLoop(node** headRef){
    if((*headRef)->value < 1){
        return false;
    }
    node* slow = *headRef, *fast = *headRef;
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
         if(fast!=NULL){
             fast = fast->next;
             if(fast == slow){
                 cout << "loop node: " << slow->value << endl;
                 removeLoop(slow, *headRef);
                 return true;
             }
             cout << "slow: " << slow->value << ",\t" << "fast: " << fast->value << endl;
         } else {
             return false;
         }
    }
}
int main(){
    node *singleLinkedList1 = new node;
	node* p = singleLinkedList1;
	cin >> singleLinkedList1->value;
	for (int i = 0; i < singleLinkedList1->value; i++) {
	    p->next = new node;
	    p = p->next;
	    cin >> p->value;
	}
	printSingleLinkedList(singleLinkedList1);
	
	p->next = singleLinkedList1->next->next->next;
	
	detectAndRemoveLoop(&singleLinkedList1);
	printSingleLinkedList(singleLinkedList1);
    return 0;
}