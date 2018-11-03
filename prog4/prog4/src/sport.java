import java.util.Scanner;

class sport extends event {

    protected int num;    //number of people for this sport

    public void add() {
        Scanner input = null;;
        input = new Scanner(System.in);

        System.out.println("What's the name of the event?");
        this.name = input.nextLine();

        System.out.println("What's the number of people for this sport?");
        this.num = input.nextInt();
    }   //add

    @Override
    public void adda(String dd, int gg) {
        this.name = dd;
        this.num = gg;
    }

    public void diaplay() {
        System.out.println("Sport name: " + this.name + " keyword: " + this.keyword + " Number: " + this.num);
    }   //display

}
