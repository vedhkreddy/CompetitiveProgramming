import java.util.Arrays;

public class b {
    public static void main(String[] args) {
        testMergeFunctions();
    }

    public static void testMergeFunctions() {
        int[] a1 = {12, 34, 56};
        int[] a2 = {7, 8, 9, 10};
        int[] a3 = {444, 222, -1};

        int[] mergedArray1 = merge(a1, a2);
        System.out.println(Arrays.toString(mergedArray1));

        int[] mergedArray2 = merge3(a1, a2, a3);
        System.out.println(Arrays.toString(mergedArray2));
    }

    public static int[] merge(int[] arr1, int[] arr2) {
        int[] result = new int[arr1.length + arr2.length];
        int index = 0;
        for (int value : arr1) {
            result[index++] = value;
        }
        for (int value : arr2) {
            result[index++] = value;
        }
        return result;
    }

    public static int[] merge3(int[] arr1, int[] arr2, int[] arr3) {
        int[] result = new int[arr1.length + arr2.length + arr3.length];
        int index = 0;
        for (int value : arr1) {
            result[index++] = value;
        }
        for (int value : arr2) {
            result[index++] = value;
        }
        for (int value : arr3) {
            result[index++] = value;
        }
        return result;
    }
}
