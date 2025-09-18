#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) { printf("Memory error\n"); exit(1); }
    p->data = val;
    p->next = NULL;
    return p;
}

void insertAtBeginning(int val) {
    Node *p = createNode(val);
    p->next = head;
    head = p;
    printf("%d inserted at beginning\n", val);
}

void insertAtEnd(int val) {
    Node *p = createNode(val);
    if (!head) { head = p; printf("%d inserted at end\n", val); return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = p;
    printf("%d inserted at end\n", val);
}

void insertBefore(int target, int val) {
    if (!head) { printf("List is empty\n"); return; }
    if (head->data == target) { insertAtBeginning(val); return; }
    Node *prev = NULL, *cur = head;
    while (cur && cur->data != target) { prev = cur; cur = cur->next; }
    if (!cur) { printf("Target %d not found\n", target); return; }
    Node *p = createNode(val);
    prev->next = p;
    p->next = cur;
    printf("%d inserted before %d\n", val, target);
}

void insertAfter(int target, int val) {
    Node *cur = head;
    while (cur && cur->data != target) cur = cur->next;
    if (!cur) { printf("Target %d not found\n", target); return; }
    Node *p = createNode(val);
    p->next = cur->next;
    cur->next = p;
    printf("%d inserted after %d\n", val, target);
}

void deleteFromBeginning() {
    if (!head) { printf("List is empty\n"); return; }
    Node *p = head;
    head = head->next;
    printf("%d deleted from beginning\n", p->data);
    free(p);
}

void deleteFromEnd() {
    if (!head) { printf("List is empty\n"); return; }
    if (!head->next) { printf("%d deleted from end\n", head->data); free(head); head = NULL; return; }
    Node *prev = NULL, *cur = head;
    while (cur->next) { prev = cur; cur = cur->next; }
    prev->next = NULL;
    printf("%d deleted from end\n", cur->data);
    free(cur);
}

void deleteNode(int target) {
    if (!head) { printf("List is empty\n"); return; }
    if (head->data == target) { Node *p = head; head = head->next; printf("%d deleted\n", p->data); free(p); return; }
    Node *prev = NULL, *cur = head;
    while (cur && cur->data != target) { prev = cur; cur = cur->next; }
    if (!cur) { printf("Node %d not found\n", target); return; }
    prev->next = cur->next;
    printf("%d deleted\n", cur->data);
    free(cur);
}

void searchNode(int target) {
    Node *cur = head;
    int pos = 1;
    while (cur) {
        if (cur->data == target) { printf("Node %d found at position %d\n", target, pos); return; }
        cur = cur->next; pos++;
    }
    printf("Node %d not found\n", target);
}

void displayList() {
    if (!head) { printf("List is empty\n"); return; }
    Node *cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int choice, val, target, mode;
    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert before/after a node\n4.Delete from beginning\n5.Delete from end\n6.Delete a specific node\n7.Search a node\n8.Display\n9.Exit\nEnter choice: ");
        if (scanf("%d", &choice)!=1) return 0;
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter target value: "); scanf("%d", &target);
                printf("Enter 1 to insert before, 2 to insert after: "); scanf("%d", &mode);
                if (mode!=1 && mode!=2) { printf("Invalid mode\n"); break; }
                printf("Enter value to insert: "); scanf("%d", &val);
                if (mode==1) insertBefore(target, val); else insertAfter(target, val);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter value to delete: "); scanf("%d", &target);
                deleteNode(target);
                break;
            case 7:
                printf("Enter value to search: "); scanf("%d", &target);
                searchNode(target);
                break;
            case 8:
                displayList();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
