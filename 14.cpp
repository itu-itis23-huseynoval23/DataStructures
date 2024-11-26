#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchKey(struct Node* head, int key) {
    struct Node* curr = head;

    while(curr != NULL) {
        if(curr->data == key) 
            return true;

        curr = curr->next;
    }
    return false;
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
    struct Node* head = createNode(2);
    head->next = createNode(21);
    head->next->next = createNode(13);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(10);

    printList(head);

    int key = 13;
    

    if (searchKey(head,key)) 
        printf("Yes\n");
    else 
        printf("No\n");
    

    return 0;
}