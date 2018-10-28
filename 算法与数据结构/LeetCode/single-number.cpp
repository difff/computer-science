#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
			
    	unordered_map<int, int> map;
    	for (int i = 0; i < n; ++i)
    		map[A[i]]++;
    	for (unordered_map<int, int>::iterator i = map.begin(); i != map.end(); ++i)
    		if (i->second == 1)
    			return i->first;
	}
};

class Solution1 {
public:
    int singleNumber(int A[], int n) {
    	
		return 0;			
	}
};


int main(int argc, char const *argv[])
{
	int a[] = {3, 5,8, 8, 9, 5, 3};

	Solution s;
	cout << s.singleNumber(a, sizeof (a) / sizeof (a[0])) << endl;

	return 0;
}
