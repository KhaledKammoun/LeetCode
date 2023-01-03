# Valid Parentheses

This is a C++ class that provides a method to check if a given string of parentheses is valid.

### Input

A string s containing only the characters " ( , ) , [ , ] , { , } ".
The string can have a length of up to 10^4.

### Output

Returns true if the string is valid and false otherwise.

## Implementation
The method iterates through the characters in the string and uses a stack data structure to store the opening parentheses.
If a closing parenthesis is encountered, it checks if the corresponding opening parenthesis is at the top of the stack.
If it is, the top element is popped from the stack. Otherwise, the string is invalid and false is returned. If the loop ends and the stack is empty, the string is valid and true is returned.
Otherwise, the string is invalid and false is returned.

## Complexity

### Time: O(n) - The method traverses the string once.
### Space: O(n) - The stack can store up to n elements.

## Requirements
I wrote the code in C++ and it has no external dependencies. It should be compatible with any C++ compiler.
