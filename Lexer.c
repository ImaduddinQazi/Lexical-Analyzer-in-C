#include <ctype.h>    // for isdigit(), isalpha()
#include <stdbool.h>  // for boolean values (true or flase)
#include <stdio.h>    
#include <stdlib.h>  // for malloc()
#include <string.h>  // for strlen(), strcmp(), strncpy()

#define MAX_LENGTH 100

//function to check if character is a Delimiter
bool isDelimiter(char ch){
    return (ch == ' ' || ch == '+' || ch == '-'
        || ch == '*' || ch == '/' || ch == ','
        || ch == ';' || ch == '%' || ch == '>'
        || ch == '<' || ch == '=' || ch == '('
        || ch == ')' || ch == '[' || ch == ']'
        || ch == '{' || ch == '}');
    }

//function to check if character is an Operator
bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*'
        || ch == '/' || ch == '>' || ch == '<'
        || ch == '=');
    }