import java.sql.SQLOutput;
import java.util.Scanner;

public class Node {
    protected array [] data1;        //linear linked list for the same event
    protected Node next;        //next pointer
    protected String keyword;
    protected int size;

    public Node() {         //constructor
        this.data1 = null;
        this.keyword = null;
    }

    public void addwa(String targ, int c, String d, int g) {                 //add

        if(this.data1 == null) {
            this.size = 5;
            data1 = new array[this.size];
            data1[0] = new array();
            data1[0].add(targ, c, d, g);
        }
        else {
            for (int i = 0; i<this.size; ++i){
                if (data1[i] == null){
                    data1[i] = new array();
                    data1[i].add(targ, c, d, g);
                    return;
                }
            }
            System.out.println("The category is full.");
        }
    }

    public void addw(String targ) {                 //add
        Scanner input = new Scanner(System.in);

        if(this.data1 == null) {
            System.out.println("What's the size of this keyword category?   " + targ);
            this.size = input.nextInt();
            data1 = new array[this.size];
            data1[0] = new array();
            data1[0].add(targ);
        }
        else {
            for (int i = 0; i<this.size; ++i){
                if (data1[i] == null){
                    data1[i] = new array();
                    data1[i].add(targ);
                    return;
                }
            }
            System.out.println("The category is full.");
        }
    }

    public void remove(){                   //remove one
        Scanner input = null;
        input = new Scanner(System.in);
        System.out.println("What do you want to delete? ");
        String temp = input.nextLine();
        for(int i = 0; i<this.size; ++i)
        {
            if(this.data1[i].name().equals(temp)){
                this.data1[i] = null;
                return;
            }
        }
    }




    public void display(){                      //display
        if(this.data1 == null) {
            System.out.println("This keyword category is empty. (" + this.keyword + ")" );
            return;
        }
        for(int i =0; i<this.size; ++i)
        {
            if(this.data1[i] != null) {
                this.data1[i].display();
            }
        }
    }

    public void set_next(Node next){
        this.next = next;
    }
}
