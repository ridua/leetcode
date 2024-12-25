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

int count_nodes(node * head)
{
    int rv = 0;
    while (head) {
        rv++;
        head = head->next;
    }
    return rv;
}

//returns the head of new list
node* rotateRight(node *head, int k) {
    // n = count the no of nodes in list
    // set k = k %n
    // let ptr_1 = find the node at n - k -1
    // ptr_2 = ptr_1->next; ptr_1->next = NULL
    // go to the last node of ptr_2 and set its next to head
    // head = ptr_2,
    // return head

    int n = count_nodes(head);
    int i = 0;
    node *ptr1, *ptr2, *ptr2_end;

    if (n == 0 || n == 1) {
        return head;
    }
    k = k%n;

    ptr1 = head;
    while (i < (n-k-1)) {
        ptr1 = ptr1->next;
        i++;
    }
    
    ptr2 = ptr1->next;
    if (!ptr2) {
        return head;
    }

    ptr1->next = NULL;
    ptr2_end = ptr2;
    while(ptr2_end && ptr2_end->next != NULL) {
        ptr2_end = ptr2_end->next;
    }

    ptr2_end->next = head;
    return ptr2;
}


int main() {
    node *h1 = NULL;
    node *rv = NULL;
    int k = 4;
    // h1 = insert(h1, 5);
    // h1 = insert(h1, 4);
    // h1 = insert(h1, 3);
    // h1 = insert(h1, 2);
    // h1 = insert(h1, 1);
    
    h1 = insert(h1, 2);
    h1 = insert(h1, 1);
    h1 = insert(h1, 0);
    
    print_list(h1);

    rv = rotateRight(h1, k);
    print_list(rv);
    return 0;
}
