import java.util.Scanner;

public class x
{
   public static void main(String[] args)
   {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter a number ");
    int myInt = in.nextInt();
    myInt += 456;   
    System.out.println(myInt);
   }
}