// Leetcode Problem : https://leetcode.com/problems/target-sum/
// Modification of { countSubsetWithGivenDifference }

class Solution {
public:
    int my_dp(vector<int>& nums, int sum)
    {
        int n = nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1] == 0)        // Skipping the zeroes in the vector as we will handle it separately
                {
                    dp[i][j] = dp[i-1][j];
                }
                else if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0)      // Check the size of the vector, if 0 return 0
        {
            return 0;
        }
        int sum = 0, noOfZeroes=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]==0)          // Count the number of zeroes in the vector
                noOfZeroes++;
        }
        // Most important part
        // 1. If the vector sum is less than the given sum then it is not possible to create any subset
        // 2. If the vector sum and given sum both are even or both are odd then only subset creation is possible i.e. if((sum+S)%2!=0) then we would never get the difference S by partitioning the array into two subsets.
        if(sum < S || (sum+S)%2!=0)
        {
            return 0;
        }
        int s_1 = (S+sum)/2;
        return pow(2,noOfZeroes) * my_dp(nums,s_1);       // By multiplying pow(2,noOfZeroes) will consider all the subsets of 0
    }
};