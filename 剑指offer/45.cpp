class Solution {
public:
    static bool cmp(string& s1, string& s2){
        if(s1 + s2 < s2 + s1){
            return true;
        }
        return false;
    }

    string minNumber(vector<int>& nums) {
        vector<string> buffers;
        string ret;
        for(auto num : nums){
            buffers.push_back(to_string(num));
        }
        sort(buffers.begin(), buffers.end(), cmp);
        for(auto buffer : buffers){
            ret += buffer;
        }
        return ret;
    }

    
};
