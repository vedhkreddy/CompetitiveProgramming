public class demo {
    public static void main(String[] args){
        RangeInput range = new RangeInput(0,0);
        range.toggleFirstSwitch();
        range.toggleSecondSwitch();
        range.toggleFirstSwitch();
        System.out.println(range.getLampState());
        System.out.println("Expected: 0");
    }
}
