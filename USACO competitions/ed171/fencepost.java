public class fencepost {

    public static boolean ifprime(int n){
        return true;
    }
    public static void sol(int max){
        int mn = 2;
        int mx = 0;
        for (int i = 0; i < max; i++){
            if (isprime(i+1) && i > mx){
                mx = i;
            }
        }
        for (int i = 0; i < mx-1; i++){
            
        }
    }
    public static void main(String[] args){
        
    }
}
