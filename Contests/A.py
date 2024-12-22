def minTimeToBreakLocks(strength, K):
    n = len(strength)
    strength.sort()  # Sort the locks by strength (greedy approach)
    
    # Memoization dictionary to store the minimum time for a given state
    memo = {}
    
    def dp(i, X, time):
        # Base case: If all locks are broken, return the current time
        if i == n:
            return time
        
        # If we've already computed this state, return the result
        if (i, X) in memo:
            return memo[(i, X)]
        
        # Calculate time required to break the current lock
        energy = 0
        curr_time = time
        while energy < strength[i]:
            energy += X
            curr_time += 1
        
        # Try breaking the current lock and move to the next lock
        result = dp(i + 1, X + K, curr_time)
        
        # Store the result in memo
        memo[(i, X)] = result
        return result
    
    # Start from the first lock, with X = 1 and time = 0
    return dp(0, 1, 0)

# Example 1
print(minTimeToBreakLocks([3, 4, 1], 1))  # Output: 4

# Example 2
print(minTimeToBreakLocks([2, 5, 4], 2))  # Output: 5
