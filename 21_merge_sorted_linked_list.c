#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int val;
    struct node_ *next;
} node;

void print_list(node *head) {
    printf("\n");
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

// insert at head
node *insert(node *head, int key) {
    node *ptr = calloc(1, sizeof(node)); 
    ptr->val = key;

    if (head == NULL) {
        return ptr;
    }

    ptr->next = head;
    head = ptr;
    
    return head;
}


node* mergeTwoLists(node* l1, node* l2) {
    node *rv = NULL;
    node *rv_head = NULL;
    
    while(l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            if (rv == NULL) {
                rv_head = l1;
                rv = l1;
            } else {
                rv->next = l1;
                rv = l1;
            }
            l1 = l1->next;
        } else {
            if (rv == NULL) {
                rv_head = l2;
                rv = l2;
            } else {
                rv->next = l2;
                rv = l2;
            }
            l2 = l2->next;            
        }
    } // while ends

    if (l1 == NULL && l2 != NULL) {
        if (rv == NULL) {
            rv = l2;
            rv_head = l2;
        } else {
            rv->next = l2;
        }
    }

    if (l2 == NULL && l1 != NULL) {
        if (rv == NULL) {
            rv = l1;
            rv_head = l1;
        } else {
            rv->next = l1;
        }
    }

    return rv_head;
}


int main() {
    node *h1 = NULL, *h2 = NULL;
    node *rv = NULL;
    h1 = insert(h1, 4);
    h1 = insert(h1, 2);
    h1 = insert(h1, 1);
    print_list(h1);
    h2 = insert(h2, 4);
    h2 = insert(h2, 3);
    h2 = insert(h2, 1);
    print_list(h2);

    rv = mergeTwoLists(h1, h2);
    print_list(rv);
    return 0;
}
