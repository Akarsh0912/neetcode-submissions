/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    int binarySearchAsc(MountainArray &mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int binarySearchDesc(MountainArray &mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (value > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int left = binarySearchAsc(mountainArr, target, 0, peak);

        if (left != -1)
            return left;

        return binarySearchDesc(mountainArr, target, peak + 1, mountainArr.length() - 1);
    }
};