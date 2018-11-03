import java.util.Scanner;

public class bst {
    protected Node root;    //root for BST

    public bst(){
        this.root = null;
    }   //constructor

    public void add(){

        Scanner input = null;;
        input = new Scanner(System.in);
        String tag;

        System.out.println("What's the keyword of the event that you are adding?");
        tag = input.nextLine();
        this.root = addw(tag, this.root);
        }   //add

    public Node addw(String targ, Node tar)     //wrapper function for add
    {
        if(tar == null)
        {
            tar = new Node();
            tar.keyword = targ;
            tar.addw(targ);
            return tar;
        }
        else if(tar.keyword.compareTo(targ) > 0)
        {
            tar.set_left(addw(targ, tar.left));
        }
        else if(tar.keyword.compareTo(targ) < 0)
        {
            tar.set_right(addw(targ, tar.right));
        }

        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.addw(targ);
            return tar;
        }
        return tar;
    }
    public void adda(String bb, int cc, String dd, int gg){             //add for data loading

        this.root = addwa(bb, this.root, cc, dd, gg);
    }   //add

    public Node addwa(String targ, Node tar, int cc, String dd, int gg)     //wrapper function for adda
    {
        if(tar == null)
        {
            tar = new Node();
            tar.keyword = targ;
            tar.addwa(targ, cc, dd, gg);
            return tar;
        }
        else if(tar.keyword.compareTo(targ) > 0)
        {
            tar.set_left(addwa(targ, tar.left, cc, dd, gg));
        }
        else if(tar.keyword.compareTo(targ) < 0)
        {
            tar.set_right(addwa(targ, tar.right, cc, dd, gg));
        }

        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.addwa(targ, cc, dd, gg);
            return tar;
        }
        return tar;
    }

    public  void display(){                         //display all
        if(this.root == null)
        {
            System.out.println("It's empty.");
            return;
        }
        displayw(this.root);
    }

    public void displayw(Node tar){                 //wrapper function for display
        if(tar == null)
            return;
        tar.display();
        displayw(tar.left);
        displayw(tar.right);
    }

    public  void remove(){                          //remove one
        Scanner input = null;;
        input = new Scanner(System.in);
        String tag1;
        System.out.println("What's the keyword of the event are you removing?");
        tag1 = input.nextLine();
        this.root = removew(tag1, this.root);
    }   //remove one

    public Node removew(String targ, Node tar)      //wrapper function for remove
    {
        if(tar == null)
        {
            return tar;
        }
        else if(tar.keyword.compareTo(targ) > 0)
        {
            tar.set_left(removew(targ, tar.left));
        }
        else if(tar.keyword.compareTo(targ) < 0)
        {
            tar.set_left(removew(targ, tar.right));
        }

        else if(tar.keyword.compareTo(targ) == 0)
        {
            tar.remove();
            return tar;
        }
        return tar;
    }

    public  void remove_all(){
        this.root = null;
    }   //remove all
}
