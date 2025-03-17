public class a {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7};
        
        int length = numbers.length;
        if (length % 2 == 1) {
            System.out.println("Middle element: " + numbers[length / 2]);
        } else {
            System.out.println("Middle elements: " + numbers[length / 2 - 1] + ", " + numbers[length / 2]);
        }

        for (int number : numbers) {
            System.out.println(number);
        }
    }
}
