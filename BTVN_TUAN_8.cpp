#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float heso;
    int somu;
} DT;

typedef struct Node {
    DT infor; 
    struct Node *next;
} Node;
Node* Insert_ToHead(Node* head, DT x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->infor = x; 
    newNode->next = head;
    return newNode;
}
void Nhap(Node **f) {
    DT x;
    int i = 1;
    do {
        printf("Nhap he so vao thu %d: ", i);
        scanf("%f", &x.heso);
        if (x.heso == 0) break;
        printf("Nhap so mu: ");
        scanf("%d", &x.somu);
        *f = Insert_ToHead(*f, x);
        i++;
    } while (1);
}
void InDT(Node* f) {
    Node* temp = f;
    while (temp != NULL) {
        printf("%.1fx^%d", temp->infor.heso, temp->infor.somu);
        temp = temp->next;
        if (temp != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    Node* list = NULL;
    Nhap(&list);
    InDT(list); 
    while (list != NULL) {
        Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
