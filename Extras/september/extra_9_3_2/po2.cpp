//Power of Two
//https://leetcode.com/problems/power-of-two/


#include<iostream>

using namespace std;

#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) {
            return true;
        } else if(n%2 != 0 || n == 0){
            return false;
        }
        //return n/2 into the function and go through if statements
        return isPowerOfTwo(n/2);
    }
};

int main()
{



    return 0;
}