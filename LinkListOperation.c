#include <stdio.h>
typedef struct Node {
    struct Node * next;
    int a;
} Node;


void createList(Node * head) {
    if (head == NULL) {
        return;
    }
    Node *Pcur = head;
    while (1) {
        int temp;
        scanf("%d", &temp);
        if (temp == -1) {
            return;
        }
        Node *node = (Node *)malloc(sizeof(Node));
        if (node == NULL) {
            return;
        }
        node->a = temp;
        node->next = NULL;
        Pcur->next = node;
        Pcur = node;
    }
}

void printList(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *temp = head->next;
    while (temp != NULL) {
        printf("%d", temp -> a);
        temp = temp->next;
    }
}

void resert(Node * head){
    if(head == NULL || head->next == NULL || head->next->next == NULL )
    {
        
        return;
    }
    
    
    Node * temp ;
    Node * Pcur = head->next->next;
    Node * Ppre = head->next;
    Ppre->next = NULL;
    
    
    while(Pcur != NULL){
        temp = Pcur->next;
        Pcur->next = Ppre;
        
        
        Ppre = Pcur;
        Pcur = temp;
    }
    head->next = Ppre;
    


}


int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        return -1;
    }
    head->next = NULL;
    printf("请输入链表");
    createList(head);
    resert(head);
    printList(head);
    return 0;
}