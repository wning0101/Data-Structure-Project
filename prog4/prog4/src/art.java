import java.util.Scanner;

class art extends event {

    protected int price;    //the price for entering this event

    public void add() {
        Scanner input = null;;
        input = new Scanner(System.in);

        System.out.println("What's the name of the event?");
        this.name = input.nextLine();

        System.out.println("What's the price?");
        this.price = input.nextInt();

    }   //add

    @Override
    public void adda(String dd, int gg) {
        this.name = dd;
        this.price = gg;
    }

    public void diaplay() {
        System.out.println("Art name: " + this.name + " keyword: " + this.keyword + " Price: " + this.price);

    }   //display

}
