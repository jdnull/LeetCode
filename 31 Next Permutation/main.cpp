#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code
    /*
     My idea is for an array:
     1, Start from its last element, traverse backward to find the first one with index i that satisfy num[i-1] < num[i]. So, elements from num[i] to num[n-1] is reversely sorted.
     2, To find the next permutation, we have to swap some numbers at different positions, to minimize the increased amount, we have to make the highest changed position as high as possible. Notice that index larger than or equal to i is not possible as num[i,n-1] is reversely sorted. So, we want to increase the number at index i-1, clearly, swap it with the smallest number between num[i,n-1] that is larger than num[i-1]. For example, original number is 121543321, we want to swap the '1' at position 2 with '2' at position 7.
     3, The last step is to make the remaining higher position part as small as possible, we just have to reversely sort the num[i,n-1]
     */
    void nextPermutation(vector<int>& num) {
        if(num.size()<=1) return;
        int i=num.size()-1,j;
        for(j=num.size()-2; j>=0; j--){
            if(num[j]<num[j+1]) break;
        }
        if(j>=0){
            while(num[i]<=num[j]) i--;
            swap(num[i], num[j]);
        }
        reverse(num.begin()+j+1, num.end());
    }
};

int main() {
    return 0;
}
