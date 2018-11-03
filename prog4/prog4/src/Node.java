import java.sql.SQLOutput;
import java.util.Scanner;

public class Node {
    protected Node left;    //left child
    protected Node right;   //right child
    protected list head;        //linear linked list for the same event
    protected String keyword;

    public Node() {         //member
        this.left = null;
        this.right = null;
        this.head = null;
    }

    public void addw(String targ) {                 //add
        Scanner input = new Scanner(System.in);
        int type = 0;
        System.out.println("Please enter the type of the event. 1-sport 2-travel 3-art");
        type = input.nextInt();

        event data = null;
        if (type == 1) {
            data = new sport();
            data.keyword = targ;
        }
        if (type == 2) {
            data = new travel();
            data.keyword = targ;
        }
        if (type == 3) {
            data = new art();
            data.keyword = targ;
        }
        data.add();
        if(this.head == null) {
            head = new list(data);
        }
        else {
            this.head.add(data);
        }
    }
    public void addwa(String targ, int cc, String dd, int gg) {             //add for data loading
        int type;
        type = cc;

        event data = null;
        if (type == 1) {
            data = new sport();
            data.keyword = targ;
        }
        if (type == 2) {
            data = new travel();
            data.keyword = targ;
        }
        if (type == 3) {
            data = new art();
            data.keyword = targ;
        }
        data.adda(dd, gg);
        if(this.head == null) {
            head = new list(data);
        }
        else {
            this.head.add(data);
        }
    }

    public void remove(){                   //remove one
        Scanner input = null;
        input = new Scanner(System.in);
        System.out.println("What do you want to delete? ");
        String temp = input.nextLine();
        if(this.head == null){
            System.out.println("Not found");
            return;
        }
        if(this.head.next == null)
        {
            if(this.head.data.name.equals(temp))
            {
                this.head = null;
                return;
            }
            else{
                System.out.println("Not found");
                return;
            }
        }
        if(this.head.data.name.equals(temp)){
            this.head = this.head.get_next();
        }
        else
        {
            removew(temp, this.head, this.head.get_next());
        }
    }

    public list removew(String temp, list tar, list prv) {             //wrapper function

        if (prv == null) {
            System.out.println("Not found");
            return tar;
        }
        if (prv.data.name.equals(temp)) {
            tar.next = prv.get_next();
            return tar;
        }
        return removew(temp, tar.get_next(), prv.get_next());
    }




    public void display(){                      //display
        if(this.head == null) {
            System.out.println("This keyword category is empty. (" + this.keyword + ")" );
            return;
        }
        this.head.display();
    }

    public void set_left(Node left)     // go left
    {
        this.left = left;
    }

    public void set_right(Node right)       // go right
    {
        this.right = right;
    }

    public Node get_left()
    {
        return this.left;
    }

    public Node get_right(){
        return this.right;
    }
}
