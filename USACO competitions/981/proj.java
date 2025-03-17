import java.util.*;

public class proj {
    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter the # of triangle rows ");
        int size = inp.nextInt();
        System.out.println();
        printTriangleA(size);
        System.out.println();
        printTriangleB(size);
        System.out.println();
        printTriangleC(size);
        System.out.println();
    }
    public static void printTriangleA(int n){
        for (int line = 0; line < n; line++){
            for (int space = 0; space < (n - line - 1)* 2 - 1; space++){
                System.out.print(" ");
            }
            for(int i = 0; i < (line + 1); i++){
                if (i == 0 && line == n-1){
                    System.out.print(line + 1);
                }
                else{
                    System.out.print(" " + (line+1));
                }
            }
            System.out.println();
        }
    }
    public static void printTriangleB(int n){
        for (int i = 0; i < n; i++){
            int x = i - 1;
            for (int j = 0; j < x + 1; j++)
                System.out.print(" ");
            int y = n+1 - i;
            for (int j = 1; j < (y+1)/2; j++){
                System.out.print(j + " ");
            }
            for (int j = y/2; j >= 1; j--){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void printTriangleC(int n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < ((n - 1) * 2 - i*2)/2; j++){
                System.out.print(" ");
            }
            for (int j = 0; j < i+1; j++){
                System.out.print(n-i + " ");
            }
            System.out.println();
        }
    }
}