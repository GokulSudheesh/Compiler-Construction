#include <stdio.h>
#include <stdlib.h>

struct array_dim{
    int val;
    struct array_dim *next;
    
};
struct array_dim * head = NULL;
struct array_dim * create(int val){
    struct array_dim * temp = (struct array_dim *)malloc(sizeof(struct array_dim));
    temp->val = val;
    return temp;
}
struct array_dim * insert(struct array_dim * current,int val){
    head = current;
    struct array_dim * node = create(val);
    if(head == NULL){
        return node;
    }
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = node;
    return head;
}
void display(struct array_dim * current){
    while(current!=NULL){
        printf("%d, ",current->val);
        current=current->next;
    }
}
int main()
{
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    display(head);

    return 0;
}
