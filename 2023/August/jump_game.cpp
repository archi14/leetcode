/**
 * At first I thought it was a dp question, since the current state depends upon the 
 * pervious states, if any of the index's value before i can help reach i given that
 * we can reach j itself, is the condition that we want.
 * if(dp[j]&& i+count[j]>=i)
 * {
 *      dp[i]=1;
 *  }
 * if we are able to reach the end, then our job is done.
 * 
 * The i was like do we really need dp in this, if we start moving from 0th index we want to have 
 * greatest count in our hand, so when we start moving, we can keep the num we started moving with, 
 * or pick up the count from the current index, turing the problem into a greedy problem.
 * 
 * **/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
        {
            return true;
        }
        int maxElement = nums[0];
        if(maxElement==0)
        {
            return false;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>=maxElement)
            {
                maxElement = nums[i];
            }else
            {
                maxElement--;
            }
            if(maxElement==0)
            {
                return false;
            }
        }
        return true;
    }
};