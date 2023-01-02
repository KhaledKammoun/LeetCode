# Roman to Integer
I created this code to solve the problem of converting a Roman numeral to an integer.

## Contents

The romanToInt method takes a single argument, a string (s), which represents the Roman numeral to be converted.
The method initializes a result variable to zero and then iterates through the characters in the string, one by one.
For each character, the method uses a switch statement to determine the value of the character and update the result accordingly.

The method handles the following cases:

I: If the character is an I and the next character is a V or an X, the method subtracts 1 from the result. Otherwise, it adds 1 to the result.
V: If the character is a V, the method adds 5 to the result.

X: If the character is an X and the next character is a C or an L, the method subtracts 10 from the result. Otherwise, it adds 10 to the result.
L: If the character is an L, the method adds 50 to the result.

C: If the character is a C and the next character is a D or an M, the method subtracts 100 from the result. Otherwise, it adds 100 to the result.

D: If the character is a D, the method adds 500 to the result.
M: If the character is an M, the method adds 1000 to the result.

At the end of the loop, the method returns the result.

## Requirements

I wrote the code in C++ and it has no external dependencies. It should be compatible with any C++ compiler.
