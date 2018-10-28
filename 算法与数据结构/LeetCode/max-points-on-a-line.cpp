/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


 /*
 WA 3次
 Input:	[(0,0)]
Output:	0
Expected:	1
只有一点结果是1

Input:	[(84,250),(0,0),(1,0),(0,-70),(0,-70),(1,-1),(21,10),(42,90),(-42,-230)]
Output:	9
Expected:	6
相同的点不能确定一条线
if (i->x == j->x && i->y == j->y)
	continue;


 Input:	[(0,0),(0,0)]
Output:	0
Expected:	2
和第一次一样的错误
如果一个点都不能确定（此时max==0），说明这些点都是重复的，包括只有一个点的情况
所以return max == 0 ? points.size() : max;


解法一
暴力枚举
太简单粗暴无脑了。。。都不好意思说了，虽然没超时，但在C++中也是垫底的速度了
这种方法就是思路简单，代码短而清晰。
三种或者说两种特殊情况要考虑。
一是，n个点中，有且有部分点是重复的，我们需要保证insameLine(i, j, k)的i和j是不同的点，这样才能形成一条线
二是，n个点种，全部是重复的，其实也包括第三种情况就是只有一个点。这种情况显然不能形成一条线，所以max一直没有更新。
所以return max == 0 ? points.size() : max;

解法二
对于每个点，求其它点到该点的斜率k，如果斜率相同，则map[k]++
注意i.x == j.x时斜率值可以写成INT_MAX（垂直线就是无穷斜，INT_MAX代表无穷，水平线斜率是0）

值得讨论的是，这个斜率必须用浮点数表示，而浮点数是有精度的。
k = (4-1)/(2-0)即3/2 而同一直线的点(7,4)的斜率k' = (7-1)/(4-0) 即6/4
注意到了没有，这里一定会有一个倍数的关系（因为点的坐标是int类型）
3.0/2.0和6.0/4.0结果不一定相同
但是double(3/2)和double(6/4)却一定相同


特殊情况一
我们把重复的点（包括自身），另外计数，不参与映射
特殊情况二
如何全部都是重复的，那么映射表.size就是0，那么max的值也不会被修改

所以return max == 0 ? points.size() : max;


有些人使用unordered_map
unordered_map是哈希表
而map是平衡二叉树实现的
把map改成unordered_map时间由49ms变成45ms


 */


#include <iostream>
#include <vector>
#include <String>
#include <algorithm>
#include <cstdlib>
#include <cstring>


#include <map>
#include <climits>

#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    void print() {
    	cout << "(" << x  << "," << y << ")";
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	int max = 0;
    	int count;
    	for (vector<Point>::iterator i = points.begin(); i != points.end(); i++) {
    		for (vector<Point>::iterator j = i+1; j != points.end(); j++) {
    			if (i->x == j->x && i->y == j->y)
    				continue;

    			count = 0;

    			// cout << "------" << endl;
    			// cout << "i=";
    			// i->print();
    			// cout << "j=";
    			// j->print();
    			// cout << endl;
    			// cout << "i & j make a line";
    			// getchar();

    			for (vector<Point>::iterator k = points.begin(); k != points.end(); k++) {
    				if (inSameLine(*i, *j, *k)) {
    					++count;

    					// k->print();
    					// cout << " in this line" << endl;;

    				}
    			}

//   			cout << "count=" << count << endl << endl;

    			if (count > max)
    				max = count;
    		}
    	}
    	// max == 0 说明一条线都不能确定，那么这些点都是重复的（包括只有一个点的情况）
    	return max == 0 ? points.size() : max;
    }

    static bool inSameLine(Point &a, Point &b, Point &k) {
    	return (b.x-a.x) * (k.y-a.y) == (b.y-a.y) * (k.x-a.x);
    }


	int maxPoints2(vector<Point> &points) {

		int max = 0;
		for (vector<Point>::iterator i = points.begin(); i != points.end(); ++i) {
			unordered_map<double, int> hashMap;
			hashMap.clear();

			int samePointCount = 0;

			for (vector<Point>::iterator j = points.begin(); j != points.end(); ++j) {

				if (i->x == j->x && i->y == j->y) {
					samePointCount++;
					continue;
				}

				double k = i->x == j->x ? (double)INT_MAX : (double)(j->y - i->y) / (j->x - i->x);

    			// cout << "------" << endl;
    			// cout << "i=";
    			// i->print();
    			// cout << "j=";
    			// j->print();
    			// cout << endl;
    			// cout << "count k == " << k << endl;
    			// getchar();

				hashMap[k]++;
			}
//			cout << "samePointCount=" << samePointCount << endl;
			for (unordered_map<double, int>::iterator i = hashMap.begin(); i != hashMap.end(); ++i) {
//				cout << "i->first = " << i->first << "  :  " << "i->second = " << i->second << endl;
				if (max < i->second+samePointCount)
					max = i->second+samePointCount;
			}
//			cout << "max=" << max << endl;
		}
		return max == 0 ? points.size() : max;
	}
};


int main(int argc, char const *argv[])
{
	// Point p1(84,250),p2(0,0),p3(1,0),p4(0,-70),p5(0,-70),p6(1,-1),p7(21,10),p8(42,90),p9(-42,-230);
	// Point temp[] = {p1, p2, p3, p4, p5, p6, p7, p8, p9};
	Point p1(5,0), p2(1,1), p3(2,1), p4(2,2), p5(3,2), p6(2,3), p7(1,4), p8(3,4);
	Point temp[] = {p1, p2, p3, p4, p5, p6, p7, p8};

	// Point p1(0,0), p2(1,1), p3(1,-1);
//	Point p1(0,0), p2(0,0), p3(2, 3);
//	Point temp[] = {p1, p1, p1, p2, p2};

	vector<Point> points(temp, temp + sizeof (temp) / sizeof (temp[0]));

	Solution solution;

	cout << solution.maxPoints2(points) << endl;
	 //vector<Point> pointzzz;
	// cout << solution.maxPoints(pointzzz) << endl;

	return 0;
}




