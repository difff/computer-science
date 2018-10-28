/*
题目
https://oj.leetcode.com/problems/next-permutation/

题意
求下一个升序排列，如果没有下一个排列，则下一个排序是最小排列

思路
是什么驱动着变化？当后面一段序列已经是最大排列时，就会产生变化。
从序列后面先确定一段最长非升序序列，进行反转
如果该最长非升序序列的左边元素存在，
在反转后的序列中寻找一个最小的且大于它的数（一定存在）
与之交换并退出

改进：寻找时改成bsearch更快

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	vector<int>::iterator iter = num.end()-1;
    	while (iter >= num.begin()) {
    		if (iter-1 >= num.begin() && *(iter-1) >= *iter) {
    			iter--;
    		} else {
    			break;
    		}
    	}
    	vector<int>::iterator left = iter, right = num.end()-1;
    	while (left <= right) {
    		iter_swap(left++, right--);
    	}
    	if (iter > num.begin()) {
    		for (vector<int>::iterator leftIter = iter-1; iter < num.end(); ++iter) {
    			if (*iter > *leftIter) {
    				iter_swap(iter, leftIter);
    				break;
    			}
    		}
    	}
    }

    void nextPermutation2(vector<int> &num) {
    	vector<int>::iterator iter = num.end()-1;
    	for (; iter != num.begin() && *(iter-1) >= *iter; --iter)
    		;
    	reverse(iter, num.end());
		if (iter != num.begin())
			iter_swap(iter-1, upper_bound(iter, num.end(), *(iter-1)));
	}
};


class VectorCategory {
public:
	void printVector(vector<int> &v) {
		for (vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}
};


int main(int argc, char const *argv[])
{
	static const int arr[] = {1,2,3,4,5};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]) );

	Solution solution;
	for (int i = 0; i < 200; ++i) {
		solution.nextPermutation2(v1);
		VectorCategory vc;
		vc.printVector(v1);
	}
	return 0;
}







