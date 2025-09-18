#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void insertAtEnd(int val) {
    Node *p = createNode(val);
    if (!head) { head = p; return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = p;
}

void displayList() {
    Node *cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf("->");
        cur = cur->next;
    }
    printf("->NULL\n");
}

void reverseList() {
    Node *prev = NULL, *cur = head, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        insertAtEnd(val);
    }

    printf("Original List: ");
    displayList();

    reverseList();

    printf("Reversed List: ");
    displayList();

    return 0;
}
