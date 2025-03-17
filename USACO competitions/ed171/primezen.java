public class primezen{
    public static boolean isPrime(int number) {
        if (number <= 1) return false;
        if (number <= 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) return false;
        }
        return true;
    }
    public static void main(String[] args){
        System.out.print("The primes up to 300 are: 2, ");
        for (int i = 3; i < 300; i++){
            if (isPrime(i))
                System.out.print(", " + i);
        }
    }
}