#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // binary-partition search to find the K-the element
    int findKSortedArrays(int A[], int m, int B[], int n, int K)
    {
        int med_a, med_b;
        
        if(m<=0)
        { // if A is empty, then return the k-th element of B
            return B[K-1];
        }
        else if(n<=0)
        { // if B is empty, then return the k-th element of A
            return A[K-1];
        }
        else
        {
            //get the median element of A and B and do comparison
            med_a = m/2;
            med_b = n/2;
            
            if(B[med_b] >= A[med_a])
            { // if the first half of B and the whole A have NO less than K elements, then dropped the second half of B
                if(med_a + med_b + 1 >= K)
                    return findKSortedArrays(A, m, B, med_b, K);
                else  // if the first half of B and the whole A have less than K elements, then dropped the first half of A
                    return findKSortedArrays(&A[med_a+1], m-med_a-1, B, n, K-med_a-1);
            }
            else
            {// if the first half of A and the whole B have NO less than K elements, then dropped the second half of A
                if(med_a + med_b + 1 >= K)
                    return findKSortedArrays(A, med_a, B, n, K);
                else // if the first half of A and the whole B have less than K elements, then dropped the first half of B
                    return findKSortedArrays(A, m, &B[med_b+1], n-med_b - 1, K-med_b-1);
            }
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double result =0;
        int K; // K is the median element index
        
        if(m>0 || n>0)
        {// if at least one of the arraies are non-empty
            K = (m+n+1)/2;
            result = findKSortedArrays(A, m, B, n, K); // find the K-th element by binary-partition search
            // if m+n is even, then need to find the K+1-th element and the median is the average of the k-th and k+1-th elements
            if((m+n+1)%2)
            {
                K = (m+n)/2 + 1;
                result = (result + findKSortedArrays(A, m, B, n, K))/2.0;
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    int A[3] = {1,3,5};
    int B[3] = {2,4,6};
    cout << s.findMedianSortedArrays(A, 3, B, 3) << endl;
    return 0;
}
