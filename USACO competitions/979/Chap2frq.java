public class Chap2frq {
    public static final int SIZE = 7;
    public static void main(String[] args){
        line();
        top();
    }
    public static void line(){
        System.out.print("+");
        for (int i = 0; i < SIZE * 2 - 1; i++){
            System.out.print("-");
        }
        System.out.print("+");
        System.out.println();
    }
    public static void top(){
        for (int i = 0; i < SIZE-1; i++){
            System.out.print("|");
            for (int j = 0; j < SIZE - i - 1; j++){
                System.out.print(" ");
            }
            for (int j = 0; j < i; j++){
                System.out.print("/");
            }
            System.out.print("*");
            for (int j = 0; j < i; j++){
                System.out.print("\\");
            }
            for (int j = 0; j < SIZE - i - 1; j++){
                System.out.print(" ");
            }
            System.out.print("|");
            System.out.println();
        }
    }
}
