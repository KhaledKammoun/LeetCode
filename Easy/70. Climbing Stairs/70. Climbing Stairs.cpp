#include <vector>

class Solution {
public:
    int recursion(int n, int curr, std::vector<int>& memo){
        if (curr > n)
            return 0;
        if (curr == n)
            return 1;
        
        if (memo[curr] != -1)
            return memo[curr];
        
        memo[curr] = recursion(n, curr + 1, memo) + recursion(n, curr + 2, memo);
        return memo[curr];
    }
    
    int climbStairs(int n) {
        std::vector<int> memo(n + 1, -1);
        return recursion(n, 0, memo);
    }
};

/***Using Fibonacci***/

/*
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1 ;
        for (int i = 0; i < n - 1; i++){
            int temp = one ;
            one+=two ;
            two = temp ;
        }
        return one ;
    }
};

*/