public class proj3 {


    public static void printtree(int number, int height){
        int halfdistance = (number*2 + 1 + height*2) / 2;
        for(int i = 0; i < number; i++){
            for (int h = 0; h < height; h++){
                for (int l = (h*2 + 1 + i*2)/2; l < halfdistance; l++){
                    System.out.print(" ");
                }
                for (int j = 0; j < h*2 + 1 + i*2; j++){

                    System.out.print("*");
                }
                System.out.println();
            }
        }
    }
    public static void printbottom(int size){
        
    }
    public static void main(String[] args){
        int number  = 3; int height = 4;
        printtree(number, height);
        printbottom((number*2 + 1 + height*2) / 2);
    }
}
