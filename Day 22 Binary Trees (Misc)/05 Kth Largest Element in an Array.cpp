//time: O(k+(n-k)*logk)
//space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //use min heap as kth largest
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};