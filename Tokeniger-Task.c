#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "char", "double", "return", "if", "else", "while", "for"};
    int i;
    for(i = 0; i < 9; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

int isSeparator(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')');
}

int main() {
    char str[] = "This is a int sum = 10; and a + b = 20;";
    char *token;

    token = strtok(str, " ");

    while(token != NULL) {
        if(isKeyword(token)) {
            printf("%s : Keyword\n", token);
        }
        else if(isdigit(token[0])) {
            printf("%s : Constant (Integer)\n", token);
        }
        else if(strlen(token) == 1 && isOperator(token[0])) {
            printf("%s : Operator\n", token);
        }
        else if(strlen(token) == 1 && isSeparator(token[0])) {
            printf("%s : Separator\n", token);
        }
        else {
            printf("%s : Identifier\n", token);
        }

        token = strtok(NULL, " ");
    }

    return 0;
}
