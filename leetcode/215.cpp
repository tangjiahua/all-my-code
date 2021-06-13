class Solution {
public:

    void swap(vector<int>& nums, int x, int y){
        int t = nums[x];
        nums[x] = nums[y];
        nums[y] = t;
    }

    int partition(vector<int>& nums, int low, int high){
        // 返回值为中值所在的index
        int midValue = rand() % (high - low + 1);
        swap(nums, low, high); //先将中值放到最后，其余都是乱序
        // i代表左边小于midValue的那些元素最右边那个，由于一开始没有排序和元素，
        // 所以是从low - 1开始的。
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(nums[j] < midValue){
                swap(nums, ++i, j);
            }
        }
        swap(nums, high, i+1);
        return i+1;
    }

    int quickSort(vector<int>& nums, int k){
        int i = 0, j = nums.size() - 1;
        while(true){
            int mid = partition(nums, i, j);
            if (j - mid + 1 == k){
                return nums[mid];
            } else if (j - mid + 1 > k){
                i = mid + 1;
            } else {
                k = k - (j - mid) - 1;
                j = mid - 1;
            }
        }
        return 0;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSort(nums, k);
    }
};
