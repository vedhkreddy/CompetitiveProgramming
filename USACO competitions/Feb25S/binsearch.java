import java.util.*;
public class binsearch {
    public static void main(String[] args){
        int[] arr = {1, 2, 5, 6, 7, 9, 11, 13};
        int target = 9;
        int result = bsearchrecursive(arr, target, 0, arr.length - 1);
        System.out.println(result);
    }
    public static int bsearch(int[] arr, int target){
        int lo = 0; int hi = arr.length - 1;
        while(lo < hi){
            if (arr[lo] == target) return lo;
            if (arr[hi] == target) return hi;
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
    public static int bsearchrecursive(int[] arr, int target, int lo, int hi){
        if (lo >= hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[lo] == target) return lo;
        if (arr[hi] == target) return hi;
        if (arr[mid] < target) return bsearchrecursive(arr, target, mid + 1, hi);
        else return bsearchrecursive(arr, target, lo, mid - 1);
    }
}