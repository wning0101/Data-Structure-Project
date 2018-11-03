import java.util.Scanner;

public class array {

    private event al;

    public array(){
        al = null;
    }
    public void clear() //clear
    {
        al = null;
    }
    public void add(String targ, int c, String d, int g){
        int type = 0;
        type = c;

        if (type == 1) {
            this.al = new sport();
            this.al.keyword = targ;
        }
        if (type == 2) {
            this.al = new travel();
            this.al.keyword = targ;
        }
        if (type == 3) {
            this.al = new art();
            this.al.keyword = targ;
        }
        this.al.adda(d, g);
    }
    public void add(String targ){
        int type = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter the type of the event. 1-sport 2-travel 3-art");
        type = input.nextInt();

        if (type == 1) {
            this.al = new sport();
            this.al.keyword = targ;
        }
        if (type == 2) {
            this.al = new travel();
            this.al.keyword = targ;
        }
        if (type == 3) {
            this.al = new art();
            this.al.keyword = targ;
        }
        this.al.add();
    }

    public void display()       //display
    {
        al.diaplay();
    }

    public String name()
    {
        return al.name;
    }

}
