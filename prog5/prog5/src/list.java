import java.util.Scanner;

public class list {
    protected list next;    //the next node
    protected event data;   //for restore data

    public list()   //constructor
    {
        this.next = null;
        this.data = null;
    }

    public list(event data) {           //copy constructor
        this.data = data;
        this.next = null;
    }

    public void add(event to_add) {             // add
        if(this.next != null) {
            this.next.add(to_add);
        }
        else {
            this.next = new list(to_add);
        }
    }

    public void display()                       //display
    {
        data.diaplay();
        if(next != null)
            next.display();
    }

    public void display(list tar)
    {
        if(tar == null)
        {
            return;
        }
        tar.data.diaplay();
        display(tar.next);
    }


    public void set_next(list next1){
        this.next = next1;
    }   //set next

    public list get_next(){
        return this.next;
    }   //return the next
}
