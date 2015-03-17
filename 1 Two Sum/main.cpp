#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v;
        map<int, vector<int> > m;
        for (int i = 0; i < numbers.size(); i++) {
            map<int, vector<int> >::iterator it = m.find(numbers[i]);
            if (it == m.end()) {
                vector<int> value;
                value.push_back(i+1);
                m[numbers[i]] = value;
//                m.insert(pair<int, vector<int> >(numbers[i], value));
            } else {
                it->second.push_back(i+1);
            }
        }
        
        for (map<int, vector<int> >::iterator it1 = m.begin(); it1 != m.end(); it1++) {
            map<int, vector<int> >::iterator it2 = m.find(target-(it1->first));
            if (it1 != it2) {
                if (it1 != m.end() && it2 != m.end()) {
                    if (it1->second[0] < it2->second[0]) {
                        v.push_back(it1->second[0]);
                        v.push_back(it2->second[0]);
                    } else {
                        v.push_back(it2->second[0]);
                        v.push_back(it1->second[0]);
                    }
                    break;
                }
            } else {
                if (it1->second.size() >= 2) {
                    if (it1->second[0] < it1->second[1]) {
                        v.push_back(it1->second[0]);
                        v.push_back(it1->second[1]);
                    } else {
                        v.push_back(it1->second[1]);
                        v.push_back(it1->second[0]);
                    }
                    break;
                }
            }
        }
        
        return v;
    }
};