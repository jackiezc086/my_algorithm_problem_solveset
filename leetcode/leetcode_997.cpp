class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //建立两个数组并置零，用来记录信任互相给予的情况
        int get_trust[n + 5];
        int give_trust[n + 5];
        for(int i = 0; i < n + 5; i ++){
            get_trust[i] = 0;
            give_trust[i] = 0;
        }

        //遍历trust，同时用数组记录每个人给出的信任数，和收到的信任数
        for(int i = 0; i < trust.size(); i ++){
            give_trust[trust[i][0]] ++;
            get_trust[trust[i][1]] ++;
        }

        //遍历give_trust和get_trust两个数组，寻找是否存在符合法官条件的人，并输出结果
        int ans = -1;
        int num = 0;
        for(int i = 1; i <= n; i ++){
            if(give_trust[i] == 0 && get_trust[i] == n - 1){
                ans = i;
                num ++;
            }
        }
        if(num == 1)
            return ans;
        else
            return -1;
    }
};

