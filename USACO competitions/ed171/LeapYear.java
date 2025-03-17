import java.util.*;
public class LeapYear {
    public static void main(String[] args) {
      Scanner console = new Scanner(System.in);      
      System.out.print("Enter a year: ");  // prompt
      int year = console.nextInt();
      
      if (isLeapYear(year))
        System.out.println(year + " is a Leap Year");  
      else
        System.out.println(year + " is NOT a Leap Year");     
    }
    
    public static boolean isLeapYear(int year){
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
      else 
        return false;
    }
  }