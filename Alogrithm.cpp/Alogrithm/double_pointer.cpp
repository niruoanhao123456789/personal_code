#include<iostream>
#include<algorithm>
using namespace std;

//Á¦¿ÛP202
class Solution {
public:
    int powSum(int n)
    {
        int i = 0;
        int sum = 0;
        while (n)
        {
            i = n % 10;
            sum += i * i;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        slow = powSum(slow);
        fast = powSum(fast);
        fast = powSum(fast);
        while (slow != fast)
        {
            slow = powSum(slow);
            fast = powSum(fast);
            fast = powSum(fast);
        }
        if (slow == 1)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    int n = 2;
    cout << s.isHappy(n) << endl;

	return 0;
}