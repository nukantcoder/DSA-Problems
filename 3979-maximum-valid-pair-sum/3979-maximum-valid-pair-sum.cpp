class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
      //This is the pattern

// This belongs to a very common interview pattern:

// Maintain the best previous value

// Whenever you see

// For every current index,
// find the best previous index satisfying some condition.  

// The main idea behind the optimal approach is instead of recomputing the maximum element again and again in nested loops just maintain a previous maximum and update it with the current element if it is larger than previous sum

//The mental checklist

// When you see a two-pointer or pair problem, run through this checklist:

// Can I fix one endpoint?
// What does the other endpoint need to satisfy?
// Among all valid candidates, what property do I actually need?
// Maximum?
// Minimum?
// Count?
// Sum?
// Does the valid set only grow or only shrink as I move?
// If yes, can I maintain that property incrementally instead of recomputing it?

// For LeetCode 3979, the answers are:

// Fix j. ✔️
// Need i <= j-k. ✔️
// Need the maximum nums[i]. ✔️
// The valid set only grows. ✔️
// Therefore, maintain a running maximum. ✔️

// That's the intuition interviewers are looking for: not memorizing this exact solution, but recognizing the broader "best previous value over a growing prefix" pattern. Just wrote this to remeber for next problems

int n = nums.size();
   int left = 0;
   int maxvalue = 0;
   int i = 0;
   int j = 1;

   while(j < n)
   {
     while(i <= j - k)
     {
        left = max(left,nums[i]);
        maxvalue = max(maxvalue,left + nums[j]);
        i++;
     }
     j++;
   }
   return maxvalue;
    }
};