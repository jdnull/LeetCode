#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        const char* s = str.c_str();
        size_t len = str.size();
        int flag = 1;
        long num = 0;
        long flag_num = 0;
        if(len > 0)
        {
            while(isspace(*s))
            {
                s++;
            }
            if(*s == '-')
            {
                flag = -1;
            }
            if(*s == '-' || *s == '+')
            {
                s++;
                if(*s == '-' || *s == '+')
                {
                    return 0;
                }
            }
            
            while((*s >='0')&& (*s <= '9'))
            {
                num = num * 10 + *s - '0';
                s++;
                flag_num = flag * num;
                
                if(flag_num >= INT_MAX)
                {
                    flag_num = INT_MAX;
                    break;
                }
                if(flag_num <= INT_MIN)
                {
                    flag_num = INT_MIN;
                    break;
                }
            }
        }
        return flag_num;
    }
};

int main() {
    Solution s;
    cout << s.atoi(" -1") << endl;
    
    return 0;
}
