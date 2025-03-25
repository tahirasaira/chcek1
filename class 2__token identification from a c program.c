#include <stdio.h>
#include <ctype.h>
#include <string.h>

void identifyToken(char token[]) {
    // List of keywords in C
    char *keywords[] = {"int", "float", "if", "else", "return", "for", "while"};
    int i, isKeyword = 0;

    // Check if the token is a keyword
    for (i = 0; i < 50; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            printf("Keyword: %s\n", token);
            isKeyword = 1;
            break;
        }
    }

    // If not a keyword, check if it's an identifier or number
    if (!isKeyword) {
        if (isdigit(token[0])) {
            printf("Number: %s\n", token);
        } else {
            printf("Identifier: %s\n", token);
        }
    }
}

int main() {
    char expression[100], token[20];
    int i = 0, j = 0;

    // Input a simple expression
    printf("Enter a simple expression (e.g., int a = 5 + 3;):\n");
    fgets(expression, 100, stdin);

    printf("\nIdentified Tokens:\n");

    while (expression[i] != '\0') {
        // If the character is a letter or digit, add it to the token
        if (isalnum(expression[i])) {
            token[j++] = expression[i];
        } else {
            // If the token is not empty, process it
            if (j > 0) {
                token[j] = '\0';  // End the token string
                identifyToken(token);
                j = 0;  // Reset token index
            }
            // Check for operators and special symbols
            if (strchr("=+-*/;()", expression[i])) {
                printf("Operator/Symbol: %c\n", expression[i]);
            }
        }
        i++;
    }

    return 0;
}
