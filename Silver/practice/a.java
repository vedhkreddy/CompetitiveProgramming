import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the cost of a new car: ");
        double costOfNewCar = scanner.nextDouble();

        System.out.print("Enter the estimated miles driven per year: ");
        double milesDrivenPerYear = scanner.nextDouble();

        System.out.print("Enter the estimated gas price: ");
        double gasPrice = scanner.nextDouble();

        System.out.print("Enter the efficiency in miles per gallon: ");
        double efficiency = scanner.nextDouble();

        System.out.print("Enter the estimated resale value after 5 years: ");
        double resaleValueAfter5Years = scanner.nextDouble();

        int years = 5;
        int milesPerYear = 15000;

        double totalCost = costOfNewCar + (milesDrivenPerYear / efficiency * gasPrice * years) - resaleValueAfter5Years;

        System.out.println("Total cost of owning the car for five years: $" + totalCost);
        scanner.close();
    }
}
