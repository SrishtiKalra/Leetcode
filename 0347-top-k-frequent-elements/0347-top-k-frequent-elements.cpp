class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    














        unordered_map<int,int> mp;

        for(int num:nums){
            mp[num]++;
        }

        // vector<vector<int>> count(nums.size()+1);
        // for(auto it: mp){
        //     count[it.second].push_back(it.first);
        // }
        // vector<int> res;

        // for(int i=nums.size();i>=0;i--){
        //     if(count[i].size()!=0){
        //         for (int num : count[i]) {
        //         res.push_back(num);
        //         k--;
        //         if (k == 0) return res;
        //     }
                
        //     }
        // }
        // return res;


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;

        

        








    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    //     for(auto it: mp){
            
    //         pq.push({it.second,it.first});
            
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
    // vector<int> res;
    //     while(!pq.empty()){
    //         res.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return res;





        // unordered_map<int, int> frequency; // Frequency map

        // // Count the frequency of each element
        // for (int num : nums) {
        //     frequency[num]++;
        // }

        // // Min-heap to store the top k elements
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // // Push elements into the heap based on their frequency
        // for (auto& entry : frequency) {
        //     minHeap.push({entry.second, entry.first}); // {frequency, number}
        //     if (minHeap.size() > k) {
        //         minHeap.pop(); // Remove the least frequent element
        //     }
        // }

        // // Extract the k most frequent elements
        // vector<int> result;
        // while (!minHeap.empty()) {
        //     result.push_back(minHeap.top().second); // Get the element (number)
        //     minHeap.pop();
        // }

        // return result;
    }
};

