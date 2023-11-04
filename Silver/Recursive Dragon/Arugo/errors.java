import java.util.Scanner; 

public class errors {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String a = s.nextLine();
        String b = s.nextLine();
        int c = Integer.parseInt(a);
        int d = Integer.parseInt(b);
        System.out.println(c+d);
        s.close();
    }
}