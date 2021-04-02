class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> heap;
        vector<int> result;
        if(k == 0) return result;
        for(int i = 0; i < k; i++) heap.push(arr[i]);
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < heap.top()){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++){
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};
