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
    if (!cur) { printf("Empty\n"); return; }
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf("->");
        cur = cur->next;
    }
    printf("\n");
}

int deleteOccurrences(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node *temp = head;
        head = head->next;
        free(temp);
        count++;
    }
    Node *cur = head, *prev = NULL;
    while (cur) {
        if (cur->data == key) {
            Node *temp = cur;
            prev->next = cur->next;
            cur = cur->next;
            free(temp);
            count++;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return count;
}

int main() {
    int n, val, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        insertAtEnd(val);
    }
    printf("Enter key: ");
    scanf("%d", &key);

    printf("Original List: ");
    displayList();

    int count = deleteOccurrences(key);
    printf("Count: %d\n", count);

    printf("Updated List: ");
    displayList();

    return 0;
}
