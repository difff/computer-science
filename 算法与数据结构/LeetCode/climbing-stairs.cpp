#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
    	int a[1024];
    	ask(a, 1024);
    	return a[n];
    }

    void ask(int *a, int n) 
    {	
    	a[0] = 0, a[1] = 1, a[2] = 2;
    	for (int i = 3; i < n; ++i)
    		a[i] = a[i-1] + a[i-2];
    }
};


int main(int argc, char const *argv[])
{
	Solution so;
	cout <<	so.climbStairs(1023) << endl;


	return 0;
}