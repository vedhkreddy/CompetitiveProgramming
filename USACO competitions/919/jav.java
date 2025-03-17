import java.util.*;
public class jav{
    public static String returnfunc(String s){
        String a = "";
        for (int i = s.length() - 1; i >= 0; i--){
            a += s.substring(i, i+1);
        }
        return a;
    }
    public static void main(String[] args){
        Scanner console = new Scanner(System.in);
        System.out.print("Original String: ");
        String s = console.nextLine();
        String a = returnfunc(s);
        System.out.print("Reversed String: " + a);
    }
}