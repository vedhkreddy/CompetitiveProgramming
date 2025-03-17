import java.util.*;
public class pow{
    public static void main(String[] args) {
        System.out.println("3 raised to the 4th power is: " + pow(3,4));
    }
    public static int pow(int x, int y){
        if (y == 0) return 1;
        if (y == 1) return x;
        return x * pow(x, y - 1);
    }
}
