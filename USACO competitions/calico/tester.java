public class tester {
    public static void main(String[] args) {
        RangeInput controller = new RangeInput(0,0);

        testSwitchCombinations(controller);
    }

    private static void testSwitchCombinations(RangeInput controller) {
        for (int firstSwitch = 0; firstSwitch <= 1; firstSwitch++) {
            for (int secondSwitch = 0; secondSwitch <= 1; secondSwitch++) {
                controller.FirstSwitchState = firstSwitch;
                controller.SecondSwitchState = secondSwitch;

                System.out.println("Testing Switch Combination: First Switch = " +
                        controller.getFirstSwitchState() + ", Second Switch = " +
                        controller.getSecondSwitchState());

                System.out.println("Before Toggle - Lamp State: " + controller.getLampState());

                controller.toggleFirstSwitch();
                controller.toggleSecondSwitch();

                System.out.println("After Toggle - Lamp State: " + controller.getLampState());

                System.out.println("------------------------------------------");
            }
        }
    }
}