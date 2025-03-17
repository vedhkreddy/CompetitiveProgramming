import java.util.*;
public class pascaltriangle {

    public static int factorial(int n){
        int x = 1;
        for (int i = 2; i <= n; i++){
            x *= i;
        }
        return x;
    }

    public static int choose(int n, int r){
        return factorial(n) / (factorial(r) * factorial(n-r));
    }
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 3*(n-i); j++){
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++){
                System.out.printf("%6d", choose(i, j));
                System.out.printf(" ");
            }
            System.out.println();
        }
    }
}
