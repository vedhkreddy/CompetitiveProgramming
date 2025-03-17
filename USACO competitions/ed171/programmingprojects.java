import java.util.*;
public class programmingprojects {
    //roman numerals project
    public static void RomanNumerals(){
        Scanner inp = new Scanner(System.in);
        String[] digits = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        System.out.print("Enter the number to be converted: ");
        int n = inp.nextInt();
        while (n > 0){
            if (n >= 1000){
                System.out.print("M");
                n -= 1000;
            }
            else if (n >= 500){
                System.out.print("D");
                n -= 500;
            }
            else if (n >= 100){
                System.out.print("C");
                n -= 100;
            }
            else if (n >= 10){
                System.out.print("X");
                n -= 10;
            }
            else{
                System.out.print(digits[n-1]);
                break;
            }
        }
    }
    //compare college project
    public static void comparecollege(){
        Scanner inp = new Scanner(System.in);
        System.out.print("Please enter Student 1's GPA, SAT, and ACT scores in that respective order: ");
        double gpa1 = inp.nextDouble(); double sat1 = inp.nextDouble(); double act1 = inp.nextDouble();
        System.out.print("Please enter Student 2's GPA, SAT, and ACT scores in that respective order: ");
        double gpa2 = inp.nextDouble(); double sat2 = inp.nextDouble(); double act2 = inp.nextDouble();
        double comb1 = ((gpa1 / 4.00 * 100) + (sat1 / 1600 * 100) + (act1 / 36 * 100)) / 300;
        double comb2 = ((gpa2 / 4.00 * 100) + (sat2 / 1600 * 100) + (act2 / 36 * 100)) / 300;
        if (comb1 > comb2){
            System.out.print("Student 1 is more qualified");
        }
        if (comb2 > comb1){
            System.out.print("Student 2 is more qualified");
        }
        else{
            System.out.print("Equally qualified");
        }
    }
    //caesar cipher project
    public static void caesarcipher(){
        Scanner inp = new Scanner(System.in);
        System.out.print("Your message? ");
        String s = inp.nextLine();
        System.out.print("Encoding key? ");
        int shift = inp.nextInt();
        String res = " ";
        s = s.toUpperCase();
        System.out.println(s);
        for (int i = 0; i < s.length(); i++){
            int x = (int) s.charAt(i);
            if (s.charAt(i) == ' '){
                res += ' ';
                continue;
            }
            x -= 65;
            x += shift;
            x = x % 26; 
            res += (char) (x+65);
        }
        System.out.print("Your message:" + res);
    }

    //pascals triangle project
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

    public static void pascal() {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter the size of the pascal's triangle: ");
        int n = inp.nextInt();
        System.out.println();
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
    //catch typing errors project
    public static void checkdigit(){
        Scanner inp = new Scanner(System.in);
        System.out.print("Please enter your student code: ");
        String s = inp.next();
        int a = (char)s.charAt(0) - '0';
        int b = (char)s.charAt(1) - '0';
        int c = (char)s.charAt(2) - '0';
        int d = (char)s.charAt(3) - '0';
        int e = (char)s.charAt(4) - '0';
        int f = (char)s.charAt(5) - '0';
        System.out.println("The check digit is: " + ((a + 2*b + 3*c + 4*d + 5*e + 6*f)%10));
    }
    //birthday comparison project
    public static void birthdays(){
        Scanner inp = new Scanner(System.in);
        System.out.print("Please enter person 1 birthday month (numerical): ");
        int a = inp.nextInt();
        System.out.print("Please enter person 1 birthday day: ");
        int b = inp.nextInt();
        System.out.print("Please enter person 2 birthday month (numerical): ");
        int c = inp.nextInt();
        System.out.print("please enter person 2 birthday day: ");
        int d = inp.nextInt();
        System.out.print("Please enter today's month (numerical): ");
        int e = inp.nextInt();
        System.out.print("Please enter today's day: ");
        int f = inp.nextInt();
        int[] days = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int absoluteday1 = 0;
        if (a > 1){
            absoluteday1 += days[a-2];
        }
        absoluteday1 += b;
        int absoluteday2 = 0;
        if (c > 1){
            absoluteday2 += days[c-2];
        }
        absoluteday2 += d;
        int curday = 0;
        if (e > 1){
            curday += days[e-2];
        }
        curday += f;
        int daysfrom1 = 0;
        if (curday > absoluteday1){
            daysfrom1 = 365 - curday + absoluteday1;
        }
        else{
            daysfrom1 = absoluteday1 - curday;
        }
        int daysfrom2 = 0;
        if (curday > absoluteday2){
            daysfrom2 = 365 - curday + absoluteday2;
        }
        else{
            daysfrom2 = absoluteday2 - curday;
        }
        System.out.println("Days from bday 1: " + daysfrom1);
        System.out.println("Days from bday 2: " + daysfrom2);
        if (daysfrom2 > daysfrom1){
            System.out.println("Bday 1 is close than bday 2");
        }
        else if (daysfrom1 > daysfrom2){
            System.out.println("Bday 2 is closer than bday 1");
        }
        else{
            System.out.println("Both bdays are on the same day!");
        }
    }
    public static void main(String[] args) {
        RomanNumerals();
        System.out.println();
        comparecollege();
        System.out.println();
        caesarcipher();
        System.out.println();
        pascal();
        System.out.println();
        checkdigit();
        System.out.println();
        birthdays();
    }
}
