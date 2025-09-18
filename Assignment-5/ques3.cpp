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
    printf("\n");
}

void findMiddle() {
    if (!head) { printf("List is empty\n"); return; }
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle: %d\n", slow->data);
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

    printf("Linked List: ");
    displayList();

    findMiddle();

    return 0;
}
