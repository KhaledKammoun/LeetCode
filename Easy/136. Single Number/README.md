# Single Number Finder
This is a C++ class that provides a method that return an interger that appears only once in the input vector.
All the other elements appear at least twice.

## Input
The input is a vector of integers, nums.

## Output
The output is an integer representing the only element in the input vector that appears only once.

## Implementation
The singleNumber method uses a map object to count the number of occurrences of each element in the input vector.
Then, it iterates over the elements of the vector and returns the first element that appears only once (according to the counts stored in the map).

## Complexity
#### Time: O(n)
##### The method iterates over the input vector twice, once to count the elements and once to find the single element.

#### Space: O(n)
##### The map uses space proportional to the number of elements in the input vector.
