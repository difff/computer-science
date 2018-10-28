/*
题目
https://oj.leetcode.com/problems/two-sum/

题意
给定数组和给定目标数，数组中能且只能找到两个数，它们的和等于目标数。
要求函数返回一个vector，升序地包括这两个数的坐标（从1开始）。

思路
直观的思路是枚举。
如果这个整数是正数则比较好优化（把大于目标数的正数直接去掉）

可以考虑先排序。
思路一：
二分查找差值，比如目标是9，数组第一个数是-2，则查找11。这仍是枚举的思路。
总的效率是nlogn


WA一次：
Input:	[0,4,3,0], 0
Output:	1, 1
Expected:	1, 4


*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class VectorCategory {
public:
	void printVector(vector<int> &v) {
		for (vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		int index1, index2;
		vector<int> copyVector(numbers), ansVector;

		sort(copyVector.begin(), copyVector.end());
		for (vector<int>::iterator iter = copyVector.begin(); iter < copyVector.end(); ++iter) {
			int left = target - *iter;
			if (binary_search(iter, copyVector.end(), left)) {
				vector<int>::iterator foundIter = lower_bound(iter, copyVector.end(), left);

				vector<int>::iterator originalIter1, originalIter2;
				originalIter1 = find(numbers.begin(), numbers.end(), *iter);
				originalIter2 = find(numbers.begin(), numbers.end(), *foundIter);
				if (originalIter1 == originalIter2) // 比如2+2=4，那么两个2的坐标不一样相同
					originalIter2 = find(originalIter2+1, numbers.end(), *foundIter);
				index1 = originalIter1-numbers.begin() + 1;
				index2 = originalIter2-numbers.begin() + 1;
				ansVector.push_back(index1);
				ansVector.push_back(index2);
				sort(ansVector.begin(), ansVector.end());
				break;
			}
		}
		return ansVector;
    }
};



int main(int argc, char const *argv[])
{
	Solution solution;

	//static const int a[] = {4, -41, 51, 551, 53, 15, 9, 515, 45, 67, 73, -52, -4, -5};
	static const int a[] = {0, 4, 3, 0};

	vector<int> v1(a, a + sizeof (a) / sizeof (a[0]));

	vector<int> ans = solution.twoSum(v1, 0);

	VectorCategory vc;
	vc.printVector(ans);

	return 0;
}