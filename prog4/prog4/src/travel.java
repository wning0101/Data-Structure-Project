import java.util.Scanner;

class travel extends event {

    protected int date; //The best date for this event

    public void add() {
        Scanner input = null;;
        input = new Scanner(System.in);

        System.out.println("What's the name of the event?");
        this.name = input.nextLine();

        System.out.println("What's the date ?");
        this.date = input.nextInt();
    }   //add

    @Override
    public void adda(String dd, int gg) {
        this.name = dd;
        this.date = gg;
    }

    public void diaplay() {
        System.out.println("Travel name: " + this.name + " keyword: " + this.keyword + " Date: " + this.date);

    }   //display

}
