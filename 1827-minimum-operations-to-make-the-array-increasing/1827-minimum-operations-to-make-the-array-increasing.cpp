class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
           if(nums[i]<nums[i-1]){
            int d=nums[i-1]-nums[i];
            nums[i]=nums[i]+d+1;
            cnt=cnt+d+1;
           }
           if(nums[i]==nums[i-1]){
            cnt+=1;
            nums[i]++;
           }
        }
        return cnt;
    }
};