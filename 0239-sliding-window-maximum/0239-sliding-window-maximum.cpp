class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;

        // analysing fist window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // analysing remaining windows

        for (int i = k; i < n; i++) {
            res.push_back(nums[dq.front()]);

            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (dq.size() > 0 && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};