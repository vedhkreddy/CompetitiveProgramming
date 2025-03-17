import java.util.*;
public class proj2 {


    public static void main(String[] args){
        System.out.print("First Name: ");
        Scanner inp = new Scanner(System.in);
        String firstname = inp.next();
        System.out.println();
        System.out.print("Last Name: ");
        String lastname = inp.next();
        System.out.println();
        System.out.println("Username: " + username(firstname, lastname));
        System.out.print("Password: " + password());
    }
    public static String username(String firstname, String lastname){
        return firstname.substring(0, 1).toUpperCase() + lastname.substring(0,1).toUpperCase() + lastname.substring(1,lastname.length());
    }
    public static String password(){
        String CHAR_STR="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";
        String psw = "";
        for (int i = 0; i < 11; i++){
            int randomNumber = (int) Math.floor(Math.random()*69);
            psw += CHAR_STR.substring(randomNumber, randomNumber+1);
        }
        return psw;
    }  
}
