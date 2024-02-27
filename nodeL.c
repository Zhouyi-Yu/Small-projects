#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
    int data;
    struct Node *next;
};
struct List{
    size_t len;
    struct Node *head;
};

struct List *createList(){
 struct List *ret = malloc(sizeof(struct List));
 ret -> head = NULL;
 ret -> len = 0;
 return ret;
}

//write a function called addToFront, for adding front of an existing List
//val is the data
struct List *addFront(struct List *l, int val){
    //save the val into a node first
    //uhh node doesnt have anywhere to go?
    //and where is the next of the node?? incomplete node
    struct Node *node = malloc(sizeof(struct Node));
    node -> data = val;
    node -> next = l -> head; // what l point as head rn will be replaced by the new node
    l -> head = node;
    (l -> len)++;
}

//write a function called ith that returns the ith content of that node
int ith(struct List *l, size_t ind){
    assert (ind < l -> len);
    //initialize current
    struct Node *cur = l -> head;
    for (int i = 0; i < ind; i++, cur = cur -> next);
    return cur -> data;
}

//write a function called removeItem such that it removes the item that ind corresponds to.
struct List *removeItem(struct List *l, size_t ind){
    assert (ind < l -> len);
    if (ind == 0){
        struct Node *temp = l -> head;
        l -> head = l -> head -> next;
        free(temp);
        (l -> len)--; 
    }
    //need a prev and a current
    struct Node *prev = NULL;
    struct Node *cur = l -> head;
    for (int i = 0; i<ind; i++, prev= cur, cur= cur -> next); //cur -> next = cur -> next -> next;
    //free(prev); in the slide they did.. 
    //my way is wrong, cuz its not skipping element i, but skipping i+1
    prev->next = cur->next;
    free(cur);
    (l->len)--;
    return l;
}

void deleteNode(struct Node *n){
    if (!n) return;
    deleteNode(n -> next);
    free(n);//你先free到底是要上哪裏去找next啦白癡
}

void deleteList(struct List *l){
    if (!l) return;
    deleteNode(l->head);
    free(l);
}

//now make a List with 1,2,3
int main() {
    // struct List *l = createList();
    // addFront(l,3);
    // addFront(l,2);
    // addFront(l,1);
    // for(int i =0; i<l->len; ++i){
    //     printf("%d\n", ith(l, i));
    // }
    // deleteList(l);
    struct List l; struct Node n1;
    struct Node n2;
    n1.next = &n2; n2.next = &n1;
    l.head=&n1;
}