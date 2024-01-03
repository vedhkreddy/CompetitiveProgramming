public class BankAccountTester
{
    public static void main(String[] args)
    {
        BankAccount harrysChecking = new BankAccount();
        harrysChecking.deposit(2000);
        harrysChecking.withdraw(500);
        System.out.println(harrysChecking.getBalance());
        System.out.println("Expected harrysChecking: 1500");
        BankAccount myChecking = new BankAccount(1000);
        harrysChecking.withdraw(0);
        myChecking.deposit(800);
        System.out.println(myChecking.getBalance());
        System.out.println("Expected myChecking: 1800");
    }
}