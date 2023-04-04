#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*push function*/
void push(char *stack,char data,int *top)
{
    static int s = 1;/* to keep track current size of stack */
    if(*top + 1 == s)
    {
        s*=2;/* if stack is full increase stack size twice */
        stack = realloc(stack,s);/* using realloc increase size */
    }
    stack[++*top] = data;/* push data in top and increase 'top' */
}

void pop(char stack[],int *top,char *data)
{
    if(*top == -1 )
    {
        printf("\n EMPTY !");
    }
    else
    *data = stack[(*top)--];/* delete element from top and decrease 'top' value */
}

/* function to check precedence of operator or operand */
int prec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;

    case '/':
    case '*':
    case '%':
        return 2;

    case '(':
    case ')':  
        return 3;

    default:
        return 0;
    }
}

/* main function */
int main()
{
    int top = -1,j=0;
    char input[150],data = '\0';
    char* stack = (char*)malloc(sizeof(char));
    
    printf("\n ENTER DATA : ");
    scanf("%[^\n]",input);

    char* postfix = (char*)malloc((strlen(input)+1)*sizeof(char));/*  store postfix expression */

    for(int i = 0; input[i] != '\0'; i++)
    {
        
        if(prec(input[i]) == 0)/* if an operand */
        postfix[j++] = input[i];

        else if(input[i] == '(') /* if opening bracket , push in stack */
        push(stack, input[i], &top);

        else if(input[i] == ')') /* if it is a closing bracket , pop element  and store until we get opening bracket */
        {
            while (data != '(' )
            {
                pop(stack, &top, &data);
                if(data != '(')
                postfix[j++] = data;
            }
            data = '\0';
        }

        else if ((prec(input[i]) > prec(stack[top]))  || (top == -1) || stack[top] == '(')
        push(stack, input[i], &top);/* if stack is empty or it is opening bracket in top or recent character have more precedence than top of stack then push recent value*/

        else/* else pop element from top of stack and store in postfix[] and push input[i] value */
        {
            pop(stack, &top, &data);
            postfix[j++] = data;
            push(stack, input[i], &top);
        }
    }

    while (top != -1)/* pop and store elements until stack is empty*/
    {
        pop(stack, &top, &data);
        postfix[j++] = data;
    }
    
    postfix[j] = '\0';/* at the end of postfix add NULL('\0') */

    printf("\n");
    for(int i = 0; postfix[i] != '\0'; i++)/* print postfix expression */
    printf("%c",postfix[i]);

 return 0;
}