#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = newdata;
    new_node->next = NULL;
    return new_node;

}

struct Node* insertFront(struct Node* head, int newdata) {
    struct Node* new_node = createNode(newdata);
    new_node->next = head;
    return new_node;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
int main () {
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(7);

    int newdata = 1;
    head = insertFront(head, newdata);
    printList(head);

    return 0;
}