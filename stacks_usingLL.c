#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node_t, *Node;

Node newNode(int data, Node next)
{
    Node node = (Node)calloc(1, sizeof(Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void printList(Node node)
{
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void push(Node *pnode, int data)
{
    *pnode = newNode(data, *pnode);
}

int pop(Node *pnode)
{
    if (*pnode == NULL)
        return INT_MAX;

    Node node = *pnode;
    *pnode = node->next;
    int data = node->data;
    free(node);
    return data;
}

int peek(Node top)
{
    return top->data;
}

int main()
{
    Node top = NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    printList(top);
    pop(&top);
    pop(&top);
    printList(top);
    int ans = peek(top);
    printf("%d \n",ans);
}