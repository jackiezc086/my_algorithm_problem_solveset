//这题的难点是想清楚从A数变换成B数，以怎样的策略可以使用最少操作数。（我的做法是，手动在草稿纸上手动尝试不同的组合“加倍”和“减一”，完成样例，寻找规律）

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue){
            if(target % 2 == 0){
                target /= 2; 
                ans ++;
            }
            else{
                target ++;    
                ans ++;
            }
        }
        return ans + startValue - target;
    }
};

