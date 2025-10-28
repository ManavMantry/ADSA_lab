#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for characters
char stack[MAX];
int top = -1;

// Stack for integers (evaluation)
int evalStack[MAX];
int evalTop = -1;

// Push to char stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Pop from char stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Peek top of char stack
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix (handles multi-digit operands)
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char c = infix[i];

        if (isdigit(c)) {
            // extract full number
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // space separator
            i--; // step back since loop will increment
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}

// ---------- Evaluation of Postfix ----------

// Push integer
void evalPush(int val) {
    evalStack[++evalTop] = val;
}

// Pop integer
int evalPop() {
    return evalStack[evalTop--];
}

// Evaluate postfix expression (handles multi-digit)
int evaluatePostfix(char* postfix) {
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            evalPush(num);
        }
        else if (isOperator(postfix[i])) {
            int val2 = evalPop();
            int val1 = evalPop();
            switch (postfix[i]) {
                case '+': evalPush(val1 + val2); break;
                case '-': evalPush(val1 - val2); break;
                case '*': evalPush(val1 * val2); break;
                case '/': evalPush(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    evalPush(res);
                    break;
                }
            }
            i++;
        }
        else {
            // skip spaces
            i++;
        }
    }
    return evalPop();
}

// ---------- Main ----------
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression : ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
