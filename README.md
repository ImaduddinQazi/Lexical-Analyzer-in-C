# Lexical Analyzer in C

A beginner-friendly implementation of a lexical analyzer (the first 
phase of a compiler) built in C as a learning project.

## What it does
Takes a C-like expression as input and breaks it down into tokens:
- Keywords (int, while, switch ...)
- Identifiers (variable names)
- Integers
- Operators (+, -, =, ...)
- Unidentified tokens (e.g. 0y)

## How to run
gcc lexer.c -o lexer
./lexer

## Sample Output
For Expression "int a = b + c":
Token: Keyword,    Value: int
Token: Identifier, Value: a
Token: Operator,   Value: =
Token: Identifier, Value: b
Token: Operator,   Value: +
Token: Identifier, Value: c

## Concepts practiced
- String parsing in C
- Pointers and malloc
- Sliding window / two-pointer technique
- Compiler design basics
