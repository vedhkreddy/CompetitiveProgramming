import java.util.*;

public class decitobin {
    public static void main(String[] args) {
        printBinary(155);
        System.out.println();
        System.out.println(bintodec("11011110"));
    }
    public static void printBinary(int n){
        if (n == 0) {
            System.out.print(0);
        }
        if (n == 1){
            System.out.print(1);
        }
        else {
            printBinary(n/2);
            System.out.print(n%2);
        }
    }
    public static int bintodec(String a){
        if (a.length() == 0){
            return 0;
        }
        else{
            return Integer.parseInt(a.substring(0, 1)) * (int)Math.pow(2, a.length()-1) + bintodec(a.substring(1));
        }
    }

}