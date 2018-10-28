/*
题目
https://oj.leetcode.com/problems/largest-number/

题意
given [3, 30, 34, 5, 9], the largest formed number is 9534330

思路
这道题本质是排序，比如9 > 5 > 34 > 3 > 30
问题转换为如何判断两个数谁更“大”
一种通过的思路是，如果比较3和30，可以组合成330和303
显然330>303，所以结果是3>30
1001和10比较可以组合成100110和101001
我们的做法是用字符来比较，其实只要用longlong类型可能更快


记录
WA3次
Input:	[0,0]
Output:	"00"
Expected:	"0"
没有去掉前缀0


Input:	[824,938,1399,5607,6973,5703,9609,4398,8247]
Output:	"9609938824782469735703560743981399"
Expected:	"9609938824824769735703560743981399"

8247
824
两个数应该是824更大，应该8 > 7


Input:	[121,12]
Output:	"12112"
Expected:	"12121"

12其实比121更大
1301其实比13011更大 
130113011
130111301

更直观的思路是把两个数字的数组按两种情况拼在一起
v1在前的情况的数字>v2在前的情况的数字，说明v1大
否则说明v2大


注意：求整数位数中log10的参数不能为0，否则结果是-无穷大
int aDigits = (a == 0 ? 1 : floor(log10(abs(a))) + 1);


*/


#include <iostream>
#include <vector>
#include <String>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class VectorCategory {
public:
	void printVector(vector<int> &v) {
		for (vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

};

/*
定制comp
相当于if (v1 > v2) {v2排到前面去} 即进行升序
这里*iter1 > *(iter2-1)和*(iter1-1) > *iter2
如果iter1指向30,iter2指向3
则满足(iter1 < v1.end()), return *iter1 > *(iter2-1) 相当于return 0 > 3  所以3排在30前面
如果iter1指向3,iter2指向30
则满足(iter2 < v2.end()), return *(iter1-1) > *iter2 相当于return 3 > 0  所以3排在30前面

comp的用法是comp(T t1, T t2)
return t1 > t2 意思是满足该条件则t1在前，t2在后，否则t2在前，t1在后，缓过来想就是保证>

*/

class Solution {
public:
    string largestNumber(vector<int> &num) {
		vector< vector<int> > myVector;
    	for (vector<int>::iterator iter = num.begin(); iter < num.end(); ++iter) {
    		vector<int> ansVector = devideInterger(*iter);
    		myVector.push_back(ansVector);
    	}
    	sort(myVector.begin(), myVector.end(), larger);

    	// VectorCategory vc;
    	// for (vector< vector<int> >::iterator it = myVector.begin(); it < myVector.end(); ++it)
    	// 	vc.printVector(*it);

    	stringstream ss;
    	for (vector< vector<int> >::iterator iter = myVector.begin(); iter < myVector.end(); ++iter)
    		for (vector<int>::iterator i = iter->begin(); i < iter->end(); ++i)
    			ss << *i;
    	string ans = ss.str();
    	return ans[0] == '0' ? "0" : ans; // "00" should output "0"
    }

    vector<int> devideInterger(int num) {
    	vector<int> ansVector;
    	for (;;) {
    		ansVector.push_back(num % 10);
    		num /= 10;
    		if (num == 0) {
    			reverse(ansVector.begin(), ansVector.end());
    			return ansVector;
    		}
    	}
    }

    static bool larger(vector<int> &v1, vector<int> &v2) {
   	    vector<int> v1First, v2First;
   	    v1First.insert(v1First.end(), v1.begin(), v1.end());
   	    v1First.insert(v1First.end(), v2.begin(), v2.end());
   	    v2First.insert(v2First.end(), v2.begin(), v2.end());
   	    v2First.insert(v2First.end(), v1.begin(), v1.end());
   	    for (int i = 0; i < v1First.size(); ++i) {
   	    	if (v1First[i] > v2First[i])
   	    		return true;
   	    	else if (v1First[i] < v2First[i])
   	    		return false;
   	    }
   	    return false;
    }

    string largestNumber2(vector<int> &num) {
    	sort(num.begin(), num.end(), myComp);
    	stringstream ss;
    	for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter)
    		ss << *iter;
    	string ans = ss.str();
    	return ans[0] == '0' ? "0" : ans;
    }
    static bool myComp(int a, int b) {
    	long long aFirst, bFirst;
    	int aDigits = (a == 0 ? 1 : floor(log10(abs(a))) + 1);
    	int bDigits = (b == 0 ? 1 : floor(log10(abs(b))) + 1);
    	aFirst = a * (long long)pow(10, bDigits) + b;
    	bFirst = b * (long long)pow(10, aDigits) + a;
    	return aFirst > bFirst;
    }
};


int main(int argc, char const *argv[])
{
//	static const int a[] = {3, 30, 34, 5, 9, 0, 300, 330, 0};
//	static const int a[] = {3, 30};
//	static const int a[] = {3, 30, 34, 5, 9};
//	static const int a[] = {0, 0, 1, 12, 3, 11, 10, 414, 15};
//	static const int a[] = {0, 0};
//	static const int a[] = {824,938,1399,5607,6973,5703,9609,4398,8247};
//	static const int a[] = {121,12};
//	static const int a[] = {13011, 1301};
//	static const int a[] = {121,12,12};
	static const int a[] = {1,2,3,4,5,6,7,8,9,0};
//	static const int a[] = {0, 1};
	vector<int> v1(a, a + sizeof (a) / sizeof (a[0]));

	Solution solution;

	cout << solution.largestNumber2(v1) << endl;

	return 0;
}


