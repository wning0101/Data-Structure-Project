import java.sql.SQLOutput;
import java.util.Scanner;
import java.io.*;


public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner input = null;;
        input = new Scanner(System.in);
        bst tree = new bst();
        int yn = 0;
        String b;
        int c;
        String d;
        int g;
        try {
                BufferedReader br = new BufferedReader(new FileReader("data.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                //process the line.
                b = line;
                line = br.readLine();
                c = Integer.parseInt(line);
                line = br.readLine();
                d = line;
                line = br.readLine();
                g = Integer.parseInt(line);
                tree.adda(b, c, d, g);
            }
            System.out.println("data loading completed.");
        } catch (Exception e){
            System.out.println("Fail reading.");

        }
        while(yn != 5)
        {
            System.out.println("What do you want to do with the tree? 1-add 2-display 3-remove one 4-remove all 5-Quit");
            yn = input.nextInt();
            if(yn == 1)
            {
                tree.add();
            }
            if(yn == 2)
            {
                tree.display();
            }
            if(yn == 3)
            {
                tree.remove();
            }
            if(yn == 4)
            {
                tree.remove_all();
            }
        }
    }
}
