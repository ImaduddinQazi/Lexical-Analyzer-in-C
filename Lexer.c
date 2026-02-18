#include <ctype.h>    // for isdigit(), isalpha()
#include <stdbool.h>  // for boolean values (true or flase)
#include <stdio.h>    
#include <stdlib.h>  // for malloc()
#include <string.h>  // for strlen(), strcmp(), strncpy()

#define MAX_LENGTH 100

//function to check if character is a Delimiter
bool isDelimiter(char chr){
    return (chr == ' ' || chr == '+' || chr == '-'
        || chr == '*' || chr == '/' || chr == ','
        || chr == ';' || chr == '%' || chr == '>'
        || chr == '<' || chr == '=' || chr == '('
        || chr == ')' || chr == '[' || chr == ']'
        || chr == '{' || chr == '}');
    }

//function to check if character is an Operator
bool isOperator(char chr){
    return (chr == '+' || chr == '-' || chr == '*'
        || chr == '/' || chr == '>' || chr == '<'
        || chr == '=');
    }