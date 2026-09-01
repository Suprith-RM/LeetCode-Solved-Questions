/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int peak(MountainArray &arr){
        int l = 0, h = arr.length() - 1, ans = -1;
        while(l < h){
            int mid = l + (h - l)/2;
            if(arr.get(mid) > arr.get(mid-1)){
                l = mid + 1;
            }
            else h = mid;
        }
        return l;
    }
    int bs(MountainArray &arr, int h, int target){
        int l = 0;
        while(l <= h){
            int mid = l + (h-l)/2;
            int midE = arr.get(mid);
            if(midE == target) return mid;
            else if(midE < target){
                l = mid+1;
            }
            else h = mid-1;
        }
        return -1;
    }
    int bsr(MountainArray &arr, int l, int target){
        int h = arr.length()-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            int midE = arr.get(mid);
            if(midE == target) return mid;
            else if(midE > target){
                l = mid+1;
            }
            else h = mid-1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int pk = peak(arr), ans = -1;
        ans = bs(arr, pk, target);
        if(ans != -1) return ans;
        ans = bsr(arr, pk, target);
        return ans; 
    }
};