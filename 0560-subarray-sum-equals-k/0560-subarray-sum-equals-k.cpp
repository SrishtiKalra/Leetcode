class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;
        int res=0;

        for(int i=0;i<n;i++){
            sum += nums[i];

            if(sum==k){
                res++;
            }

            if(mp.find(sum-k)!=mp.end()){
                res+=mp[sum-k];
            }

            mp[sum]++;
            
        }
        return res;
        
    }
};