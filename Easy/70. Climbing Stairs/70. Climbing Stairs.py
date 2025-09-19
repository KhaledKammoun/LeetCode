class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Calculate the number of distinct ways to climb to the top of a staircase with n steps.

        Args:
            n (int): The total number of steps in the staircase.

        Returns:
            int: The number of distinct ways to reach the top.
        """

        # Memoization dictionary to store results of subproblems.
        # because on recursion we will be calculating same subproblems multiple times.

        # Key: step index, Value: number of ways to reach that step.
        # Base case: 1 way to reach step 0 or step 1.
        # because you can start from either without taking any steps.
        memo = {}

        def solve(x: int):
            """
            Recursive helper function that returns
            the number of ways to reach step x.
            """
            # Base case: 1 way to reach step 0 or step 1.
            if (x <= 1) : 
                return 1

            # If already computed, return from memo (avoid recomputation).
            if x in memo : 
                return memo[x]

            # Recurrence relation:
            # To reach step x, you must come from (x-1) or (x -2).
            # So, the number of ways to reach step x is the sum of the ways to reach (x-1) and (x-2).
            memo[x] = solve(x - 1) + solve(x - 2)
            return memo[x]

        # Final result: number of ways to reach the top (step n).
        return solve(n)