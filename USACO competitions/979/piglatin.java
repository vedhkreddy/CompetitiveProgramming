import java.util.*;
public class piglatin{

    public static String piglatin(String s){
        String res = "";
        String word = "";
        for (int i = 0; i < s.length(); i++){
            if (s.substring(i, i+1).equals(" ") || i == s.length() - 1){
                if (i == s.length() - 1){
                    word += s.substring(i, i+1);
                }
                int x = 0;
                for (int j = 0; j < word.length(); j++){
                    if (word.substring(j, j+1).toLowerCase().equals("a") || word.substring(j, j+1).toLowerCase().equals("e") || word.substring(j, j+1).toLowerCase().equals("i") || word.substring(j, j+1).toLowerCase().equals("o") || word.substring(j, j+1).toLowerCase().equals("u")){
                        x = j;
                        break;
                    }
                }
                res += word.substring(x,word.length());
                res += "-";
                res += word.substring(0, x);
                res += "ay ";
                word = "";
                x = 0;
            }
            else{
                word += s.substring(i, i+1);
            }
        }
        return res;
    }

    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        String total = "";
        while (true){
            String s = inp.nextLine();
            if (s == "")
                break;
            total += piglatin(s);
            total += "\n";
        }
        System.out.print(total);
    } 
}