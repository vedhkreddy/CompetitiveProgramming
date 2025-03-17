import java.util.*;
public class proj {
    static double findangle(double sideA, double sideB, double sideC){
        return Math.acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2 * sideA * sideB))  * 180 / Math.PI ;
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.print("Please enter the lengths of the sides of your triangle: ");
        double a = s.nextDouble();
        double b = s.nextDouble();
        double c = s.nextDouble();
        System.out.println();
        System.out.print("The angles are as follows ");
        System.out.print(findangle(a, b, c) + " ");
        System.out.print(findangle(b, c, a) + " ");
        System.out.print(findangle(a, c, b) + " ");
        System.out.println();
    }
}
