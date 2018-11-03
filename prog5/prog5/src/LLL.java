import java.util.Scanner;

public class LLL {

    protected Node head;        //head for LLL
    public LLL(){               //constructor
        this.head = null;
    }

    public void remove_all(){
        this.head = null;
    }
    public void add() {

        Scanner input = null;
        input = new Scanner(System.in);
        String tag;

        System.out.println("What's the keyword of the event that you are adding?");
        tag = input.nextLine();
        this.head = addw(tag, this.head);
    }
    public void adda(String b, int c, String d, int g){
        this.head = addwa(b, this.head, c, d, g);
    }
    public Node addwa(String targ, Node tar, int c, String d, int g){
        if(tar == null)
        {
            tar = new Node();
            tar.keyword = targ;
            tar.addwa(targ, c, d, g);
            return tar;
        }
        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.addwa(targ, c, d, g);
            return tar;
        }
        else
        {
            tar.set_next(addwa(targ, tar.next, c, d, g));
        }
        return tar;
    }
    public Node addw(String targ, Node tar){
        if(tar == null)
        {
            tar = new Node();
            tar.keyword = targ;
            tar.addw(targ);
            return tar;
        }
        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.addw(targ);
            return tar;
        }
        else
        {
            tar.set_next(addw(targ, tar.next));
        }
        return tar;
    }
    public  void remove(){                          //remove one
        Scanner input = null;;
        input = new Scanner(System.in);
        String tag1;
        System.out.println("What's the keyword of the event are you removing?");
        tag1 = input.nextLine();
        removew(tag1, this.head);
    }   //remove one

    public Node removew(String targ, Node tar)      //wrapper function for remove
    {
        if(tar == null)
        {
            return tar;
        }
        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.remove();
            return tar;
        }
        return removew(targ, tar.next);
    }
    public  void display_keyword(){                          //display one
        Scanner input = null;;
        input = new Scanner(System.in);
        String tag1;
        System.out.println("What's the keyword of the event you want to display?");
        tag1 = input.nextLine();
        display_keywordw(tag1, this.head);
    }

    public void display_keywordw(String targ, Node tar){
        if(tar == null)
        {
            return;
        }
        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.display();
            return;
        }
        display_keywordw(targ, tar.next);
    }
    public  void display(){                         //display all
        if(this.head == null)
        {
            System.out.println("It's empty.");
            return;
        }
        displayw(this.head);
    }
    public void displayw(Node tar){                 //wrapper function for display
        if(tar == null)
            return;
        tar.display();
        displayw(tar.next);
    }
}


