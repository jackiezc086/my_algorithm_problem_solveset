//虽然AC了，但是不简洁和优美的写法
class Solution {
public:
    string predictPartyVictory(string senate) {

        //如果有人有不同意见，行使第一项权利，禁止别的参议员的权利
        int D = 0,R = 0;
        for (auto it = senate.begin(); it != senate.end(); it ++){
            if(*it == 'R' && R >= 0){
                D--;
            }
            if(*it == 'R' && R < 0){
                R++;
                *it = 'E';
            }
            if(*it == 'D' && D >= 0){
                R--;
            }
            if(*it == 'D' && D < 0){
                D ++;
                *it = 'E';
            }
        }
        while(D!= 0 || R != 0){
            for (auto it = senate.begin(); it != senate.end(); it ++){
                if(*it == 'R' && R >= 0){
                    D--;
                }
                if(*it == 'R' && R < 0){
                    R++;
                    *it = 'E';
                }
                if(*it == 'D' && D >= 0){
                    R--;
                }
                if(*it == 'D' && D < 0){
                    D ++;
                    *it = 'E';
                }
            }

        //如果所有人意见一致，行使第二项权利，宣布胜利
        //如果所有人非R即E，宣布Radient胜利
        for (auto it = senate.begin(); it != senate.end(); it ++){
            if(*it != 'R' && *it != 'E'){break;}
            if(it == senate.end() - 1){
                return "Radiant";
            }
        }

        //如果所有人非D即E，宣布Dire胜利
        for (auto it = senate.begin(); it != senate.end(); it ++){
            if(*it != 'D' && *it != 'E'){break;}
            if(it == senate.end() - 1){
                return "Dire";
            }
        }
           
        }
        return predictPartyVictory(senate);
    }       
};

