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

//function to check if the str is a valid identifier
// valid: abc, _abc, abc123 
// invalid: 123abc, 1abc, @abc, abc@, abc#123
bool isValidIdentifier(char* str){
    return (str[0] != '0' && str[0] != '1' && str[0] != '2' &&
        str[0] != '3' && str[0] != '4' && 
        str[0] != '5' && str[0] != '6' && 
        str[0] != '7' && str[0] != '8' && 
        str[0] != '9' && !isDelimiter(str[0]) 
    );
}

// 32 Keywords are checked in this function and return the result accordingly
// given str parameter is compared with the all the keywords and if it matches then return true otherwise false in the end of the function
bool isKeyword(char* str)
{
    const char* keywords[]
        = { "auto",     "break",    "case",     "char",
            "const",    "continue", "default",  "do",
            "double",   "else",     "enum",     "extern",
            "float",    "for",      "goto",     "if",
            "int",      "long",     "register", "return",
            "short",    "signed",   "sizeof",   "static",
            "struct",   "switch",   "typedef",  "union",
            "unsigned", "void",     "volatile", "while" };
    for (int i = 0;
         i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// function to check interger
bool isInteger(char* str){
    if (str == NULL || *str == '\0'){
        return false;
    }
    int i=0;
    while(isdigit(str[i])){
        i++;
    }
    return str[i]=='\0';
}
