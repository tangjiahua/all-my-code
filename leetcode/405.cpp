class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, count = 0;
        while(i < flowerbed.size()){
            if(flowerbed[i] == 1){
                i = i+2;
                continue;
            } else{
                if(i+1 == flowerbed.size() || flowerbed[i+1] == 0){
                    count++;
                    i = i+2;
                }else{
                    i = i+3;
                }
                
            }
        }
        return n <= count;


    }
};
