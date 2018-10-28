
/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

/*
题目分析
设cnt=n+m，a[]为nums1和nums2的合并数组，
若cnt为偶数，中间数应该是第(a[cnt/2-1]+a[cnt/2])/2；
若cnt为奇数，中间数应该是a[cnt/2]；
*/
#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt = nums1.size()+nums2.size();
        int a[cnt];

        for (int i = 0, j = 0, k = 0; i < nums1.size() || j < nums2.size();) {
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] <= nums2[j]) {
                    a[cnt++] = nums1[i++];
                } else {
                    a[cnt++] = nums2[j++];
                }
            } else if (i < nums1.size()) {
                a[cnt++] = nums1[i++];
            } else {
                a[cnt++] = nums2[j++];
            }
        }

        if (cnt%2 == 0) {
            return (double)(a[cnt/2-1]+a[cnt/2])/2;
        } else {
            return (double)a[cnt/2];
        }
    }
};


/*
编写测试用例
*/
int main() {
    vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> nums2 = { 10 };

    Solution sl = Solution();
    double ret = sl.findMedianSortedArrays(nums1, nums2);

    return 0;
}

/*
正确性证明
*/


