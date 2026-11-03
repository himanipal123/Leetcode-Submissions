class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lar=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>lar){
                lar=nums[i];
            }
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=lar-nums[i];
        }
        return cnt;
    }
};