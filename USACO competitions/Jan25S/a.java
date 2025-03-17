import java.util.ArrayList;

public class a {
    public static void main(String[] args) {
        ArrayList<Integer> l1 = new ArrayList<>();
        ArrayList<Integer> l2 = new ArrayList<>();
        
        int[] a1 = {1, 4, 8, 9, 11, 15, 17, 28, 41, 59};
        int[] a2 = {4, 7, 11, 17, 19, 20, 23, 28, 37, 59, 81};
        
        for (int i : a1) l1.add(i);
        for (int i : a2) l2.add(i);

        System.out.println("List 1: " + l1);
        System.out.println("List 2: " + l2);

        System.out.println("\nIntersection: " + intersect(l1, l2));
    }

    public static ArrayList<Integer> intersect(ArrayList<Integer> l1, ArrayList<Integer> l2) {
        ArrayList<Integer> r = new ArrayList<>();
        for (int i : l1) {
            if (l2.contains(i)) {
                r.add(i);
            }
        }
        return r;
    }
}
