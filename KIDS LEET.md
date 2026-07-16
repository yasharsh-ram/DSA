LeetCode - 1431. Kids With the Greatest Number of Candies

Problem Statement

You are given an integer array "candies", where "candies[i]" represents the number of candies the "iᵗʰ" child has, and an integer "extraCandies".

For each child, determine whether giving them all the "extraCandies" would make them have the greatest number of candies among all children.

Return a boolean array where each element indicates whether that child can have the greatest number of candies.

Approach

1. Find the maximum number of candies currently owned by any child.
2. Traverse the array.
3. For each child, check if:
   candies[i] + extraCandies >= maximumCandies
4. If the condition is true, store "true"; otherwise, store "false".
5. Return the resulting boolean array.

Algorithm

- Find the maximum element in the array using "max_element".
- Create a boolean result vector.
- Iterate through the array:
  - If "candies[i] + extraCandies" is greater than or equal to the maximum value, store "true".
  - Otherwise, store "false".
- Return the result vector.

C++ Solution

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end());

        vector<bool> ans(candies.size());

        for (int i = 0; i < candies.size(); i++) {
            ans[i] = (candies[i] + extraCandies >= greatest);
        }

        return ans;
    }
};

Complexity Analysis

- Time Complexity: O(n)
  
  - One pass to find the maximum element.
  - One pass to build the answer.

- Space Complexity: O(n)
  
  - Result vector of size "n".
