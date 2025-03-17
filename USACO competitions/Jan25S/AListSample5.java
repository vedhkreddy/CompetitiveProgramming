import java.util.ArrayList;

public class AListSample5 {
    public static void main(String[] args) { 
        ArrayList<String> l = new ArrayList<String>();
        String[] s = { "the", "quick", "brown", "fox"};
        
        for (int i = 0; i < s.length; i++) {
            l.add(s[i]);   
        }
        
        System.out.println("Original " + l);
        addStars(l);
        System.out.println("\nAfter adding Stars " + l);
        removeStars(l);
        System.out.println("\nAfter removing Stars " + l);    
    }

    public static void addStars(ArrayList<String> l) {
        for (int i = 1; i < l.size(); i += 2) {
            l.add(i, "*");
        }
    }

    public static void removeStars(ArrayList<String> l) {
        for (int i = 1; i < l.size(); i++) {
            l.remove(i);
        }
    }
}
