public class a{
    public static void main(){
        int[] a = {1, 7, 5, 6, 4, 14, 11};
        for (int i = 1; i < a.length; i++){
            if (a[i] > a[i-1]){
                a[i] = 2 * a[i];
            }
        }
        for (int i = 0; i < a.length; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}