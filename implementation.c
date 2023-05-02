#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct stack
{
    int top;
    unsigned capacity;
    int *arr;
} Stack_t,* Stack;

Stack newStack(unsigned capacity)
{
    Stack st = (Stack)calloc(1,sizeof(Stack_t));
    st->top=-1;
    st->capacity=capacity;
    st->arr=(int*)calloc(capacity,sizeof(int));

    return st;
}

void push(Stack st,int data)
{
    if(st->top+1==st->capacity)
    {
        return ;
    }
    else
    {
        st->top++;
        st->arr[st->top]=data;
    }
}

int pop(Stack st)
{
    // printf("%d\n",st->top);
    if(st->top==-1)
    {
        return -1;
    }   
    else
    {
       int ele = st->arr[st->top];
       st->top--;
       return ele;
    }
    
}

int peek(Stack st)
{
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        return st->arr[st->top];
    }
}

void printStack(Stack st)
{
    for(int i = 0;i<=st->top;i++)
    {
        printf("%d ",st->arr[i]);
    }
    printf("\n");
    
}

int main()
{
    Stack st = newStack(5);
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    printStack(st);
    pop(st);
    pop(st);
    pop(st);
    printStack(st);
    int ans = peek(st);
    printf("%d ",ans);

}