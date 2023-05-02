#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

typedef struct stack
{
    int top;
    unsigned capacity;
    char *arr;
} Stack_t, *Stack;

Stack newStack(unsigned capacity)
{
    Stack st = (Stack)calloc(1, sizeof(Stack_t));
    st->top = -1;
    st->capacity = capacity;
    st->arr = (char *)calloc(capacity, sizeof(char));

    return st;
}

void push(Stack st, char data)
{
    if (st->top + 1 == st->capacity)
    {
        return;
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }
}

char pop(Stack st)
{
    // printf("%d\n",st->top);
    if (st->top == -1)
    {
        return -1;
    }
    else
    {
        char ele = st->arr[st->top];
        st->top--;
        return ele;
    }
}

char peek(Stack st)
{
    if (st->top == -1)
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
    for (int i = 0; i <= st->top; i++)
    {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char * reverseString(char *str)
{
    int i = 0;
    char *copy = (char*)calloc(strlen(str)+1,sizeof(char));
    for(int j = strlen(str)-1;j>=0;j--)
    {
        copy[i++]=str[j];
    }
    copy[i]='\0';
    return copy;
}

char *infixToPostfix(char *input)
{
    int i, j;
    input = reverseString(input);
    int len = strlen(input);
    char *ans = (char *)calloc(len + 2, sizeof(char));
    Stack st = newStack(len);

    for (i = 0, j = 0; i < len; i++)
    {
        if (input[i] == ' ')
            continue;

        else if (isalnum(input[i]))
        {
            ans[j++] = input[i];
        }
        else if (input[i] == ')')
        {
            push(st, input[i]);
        }
        else if (input[i] == '(')
        {
            while (st->top > -1 && peek(st) != ')')
            {
                ans[j++] = peek(st);
                pop(st);
            }
            pop(st);
        }
        else if (isOperator(input[i]))
        {
            while (st->top > -1 && (precedence(input[i]) < precedence(peek(st))) || (precedence(input[i]) <= precedence(peek(st)) && precedence(input[i])==3))
            {
                ans[j++] = peek(st);
                pop(st);
            }
            push(st, input[i]);
        }
    }

    while (st->top > -1)
    {
        ans[j++] = peek(st);
        pop(st);
    }

    ans[j] = '\0';
    return reverseString(ans);
}

int main()
{
    char infix[100] = "K+L-M*N+(O^P)*W/U/V*T+Q";

    // Function call
    char *postfix = infixToPostfix(infix);
    printf("%s\n",postfix);
    free(postfix);
    return 0;
}