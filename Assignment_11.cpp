#include<bits/stdc++.h>
using namespace std;
/*
Question 1

Given a non-negative integer `x`, return *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You must not use any built-in exponent function or operator.

- For example, do not use `pow(x, 0.5)` in c++ or `x ** 0.5` in python

*/
int sqrt(int x){
     if (x == 0)
            return x;
        int si = 1, ei = x;
        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                ei = mid - 1;
            }
            else {
                si = mid + 1;
            }
        }
        return ei;
}

/*
<aside>
💡 **Question 2**

A peak element is an element that is strictly greater than its neighbors.

Given a **0-indexed** integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.

</aside>
*/

int peak(int *arr,int size){
    if(size==1){
        return 0;
    }
    
}

/*
<aside>
💡 **Question 3**

****

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

</aside>
*/
 int missingNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int s = 0, e = nums.size()-1;
      
      while(s<=e){
        int mid = s + (e - s)/2;
        if(nums[mid] == mid){
          s = mid + 1;
        }
        else{
          e = mid - 1;
        }
      }
      return s;
    }

/*
<aside>
💡 **Question 4**

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return *this repeated number*.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

</aside>
*/
int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for(int i = 1; i <= nums.size() - 1; i++)
        {
            if(nums[i - 1] == nums[i])
                return nums[i];
        }

        return -1;

    }

/*
<aside>
💡 **Question 5**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

</aside>
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size(),i=0,j=0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i=0,int j=0;i<l1 && j<l2;){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums2[j]>nums1[i]){
                i++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
}

/*
<aside>
Question 6**

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n) time.`

</aside>
*/
int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;
        
        while(low<high){
            if(nums[low] <= nums[high]) return nums[low];
            int mid = low + (high-low)/2;
            if(nums[low] > nums[mid]){
                high=mid;
            } else if(nums[mid] > nums[high]) {
                low=mid+1;
            } 
        }
        if(nums[low] <= nums[high]) return nums[low];
        return -1;
}


/*
<aside>
💡 **Question 7**

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

</aside>
*/
vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int end = nums.size()-1;
        vector<int>v{-1,-1};

        while(start<=end){
            int mid=start +(end-start)/2;
            if(target <nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                v[0]=mid;
                end=mid-1;
            }
        }


        start=0;
        end = nums.size()-1;
        while(start<=end){

            int mid=start +(end-start)/2;
            if(target <nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                v[1]=mid;
                start=mid+1;
            }
        }

        return v;
    }





/*
<aside>
💡 **Question 8**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

</aside>
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size(),i=0,j=0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i=0,int j=0;i<l1 && j<l2;){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums2[j]>nums1[i]){
                i++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
}