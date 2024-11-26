#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

int countNodes(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    return 1 + countNodes(head->next);
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(1);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    printList(head);

    printf("Count of nodes is %d\n", countNodes(head));
    return 0;
}
