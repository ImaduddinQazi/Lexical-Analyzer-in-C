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

//function to trim substring from a given String
// start and end are two parameters given to the function
char* getSubstring(char* str, int start, int end){
    int sublength= end - start + 1;
    char* subStr=(char*)malloc((sublength+1)*(sizeof(char)));
    strncpy(subStr, str+start, sublength);
    subStr[sublength]='\0';
    return subStr;
}

//function that takes input
int lexicalAnalyzer(char* input){
    int left=0; 
    int right=0;
    int len=strlen(input);

    while(right<=len && left<=right){
        if(!isDelimiter(input[right])){
            right++;
        }
        if(isDelimiter(input[right]) && left==right){
            if(isOperator(input[right])){
                printf("Token: Operator, Value: %c\n", input[right]);
            }
            right++;
            left=right;
        }
        else if ((isDelimiter(input[right]) && left!=right) || (right!=len && left!=right)){
            char* subStr=getSubstring(input, left, right-1);

            if(isKeyword(subStr)){
                printf("Token: Keyword, Value: %s\n", subStr);
            }
            else if(isInteger(subStr)){
                printf("Token: Integer, Value: %s\n", subStr);
            }
            else if(isValidIdentifier(subStr) && !isDelimiter(input[right-1])){
                printf("Token: Identifier, Value: %s\n", subStr);
            }
            else if(!isValidIdentifier(subStr) && !isDelimiter(input[right-1])){
                printf("Token: UnIdentified, Value: %s\n", subStr);
                left==right;
            }
        }
        return 0;
    }

}

//main function
int main(){
    //input
    char lex_input[MAX_LENGTH]="int a = x + y";
    printf("For expression \"%s\":\n", lex_input);
    lexicalAnalyzer(lex_input);
    printf(" \n");

    return 0;
}