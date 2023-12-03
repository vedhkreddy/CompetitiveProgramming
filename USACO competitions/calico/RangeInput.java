class RangeInput{
    int FirstSwitchState;
    int SecondSwitchState;
    int LampState;
    public RangeInput(int first, int second){
        FirstSwitchState = first;
        SecondSwitchState = second;
    }
    public int getFirstSwitchState(){
        return FirstSwitchState;
    }
    public int getSecondSwitchState(){
        return SecondSwitchState;
    }
    public int getLampState(){
        return LampState;
    }
    public void toggleFirstSwitch(){
        if (FirstSwitchState == 0) FirstSwitchState = 1;
        else {FirstSwitchState = 0;}
        LampState = FirstSwitchState;
    }
    public void toggleSecondSwitch(){
        if (SecondSwitchState == 0) SecondSwitchState = 1;
        else {SecondSwitchState = 0;}
        LampState = SecondSwitchState;
    }
}