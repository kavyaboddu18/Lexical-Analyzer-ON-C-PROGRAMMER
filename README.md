# Lexical-Analyzer-ON-C-PROGRAMMER
## Definition of Lexical Analyzer :
     A lexical analyzer(also called a lexer or tokenization) is like a scanner for computer code.It reads your source code character by character and breaks it down into meaningful chunks called 'tokens'.Think of it like breaking a sentence into words-but for programming languages.

## Why Do We Need It?
***First Step in Compilation : Before a computer can run your code,it needs to understand it.The lexical analyzer is the first step in this process.
***Error Detection : It helps catch basic syntax errors early, like invalid variable names or misspelled keywords.
***Preparation for Parsing : It prepares the code for the next compilation step by converting raw text into a format the computer can better process.

## Where is it Used?
> Compilers for programming languages
> Code editors for syntax highlighting
> Static code analysis tools
> Language processing tools
> IDEs (Integrated Development Environment)

## How Does Our Implementation Work?
This lexical analyzer can identify :
1.*Keywords* : Words like 'if', 'while', 'int', 'float'
2.*Identifiers* : Variable names
3.*Operators* : +,-,*,/,=,%,etc.
4.*Numbers* : Both integers and decimal numbers
5.*Delimiters* : Spaces,brackets,semicolons

### Example Usage
     char str[100] ="float x=a+1b";
//This will identity:
//-'float' as a keyword
//-'x' as an identifier
//-'=' as an operation
//-'a' as an identifier
//-'+' as an operator
//-'1b' as an invalid identifier

## Core Functions
1.*isValidDelimiter* : Checks for spaces, operators, and brackets
2.*isValidOperator* : Identifies mathematical and comparison operators
3.*isValidIdentifier* : Checks if variable names follow 'C' rules
4.*isValidKeyword* : Recognizes 'C' language keywords
5.*isValidInteger* : Validates whole numbers
6.*isRealNumber* : Validates decimal numbers
7.*detectTokens* : Main function that processes the input

### Requirements
> C compiler (like GCC)
> Basic C libraries(stdio.h, string.h, stdlib.h, stdbool.h)

### Current Limitations
> Fixed input size(100 characters)
> Basic error handling
> No support for string or comments
> Single-line input only

## how to use it-
1.*Complie* : bash gcc lexical_analyzer.c -o lexical_analyzer
2.*Run* : bash./lexical_analyzer
3.*Input* : Program comes with a test string:"float x=a+1b"
4.*output* : Shows each token identified with its type

## Project Value
1.**Educational** : Learn about:
-Compiler design basics
-Token recognition
-Input processing
-Error handling
2.**Practical** : Can be used as :
-Basic for a simple compiler
-Code analysis tool
-Teaching tool for compiler concepts

## Future Improvements Possible
> Support for :
-Multiple lines of code
-String literals
-Comments
-More operators
> Better error handling
> File input/output
> Dynamic memory management

### Tools Used For Project
>>> LEX - Reads in a collection of regular expressions & uses it to write a C-Program that will perform lexical analysis.
>>> FLEX - [Fast Lexical Analyzer Generator] is a tool generating lexers/scanners.

### Summary
   This lexical analyzer is a fundamental tool that demonstrates basic compiler design principles.While simple, it effectively shows how programming languages break down code into meaningful parts, making it an excellent learning tool for understanding how compilers work at a basic level.
