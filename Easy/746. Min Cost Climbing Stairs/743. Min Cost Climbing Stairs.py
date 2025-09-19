from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """
        Calculate the minimum cost to reach the top of the staircase.
        
        Args:
            cost (List[int]): cost[i] is the cost of stepping on the i-th stair.
        
        Returns:
            int: the minimum total cost to climb to the top.
        """
        
        # Memoization dictionary (memo subproblem results).
        # because on recursion we will be calculating same subproblems multiple times.

        # Key: step index, Value: minimum cost to reach that step.
        # Base case: cost to reach step 0 or step 1 is 0,
        # because you can start from either without paying.
        memo = {0: 0, 1: 0}

        def solve(x: int) -> int:
            """
            Recursive helper function that returns
            the minimum cost to reach step x.
            """
            # Base case: reaching step 0 or 1 requires no cost.
            if x == 0 or x == 1:
                return 0
            
            # If already computed, return from memo (avoid recomputation).
            if x in memo:
                return memo[x]

            # Recurrence relation:
            # To reach step x, you must come from (x-1) or (x-2).
            # Add the cost of stepping on that stair.
            memo[x] = min(
                solve(x - 1) + cost[x - 1],
                solve(x - 2) + cost[x - 2]
            )
            return memo[x]

        # Final result: cost to reach "top".
        return solve(len(cost))
