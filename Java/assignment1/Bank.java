import java.util.Scanner;
public class Bank{
    
   public Bank(){}
   public  SavingsAccount addaccount(String name,double interest,int balance){
        SavingsAccount a= new SavingsAccount(name,interest,balance);
        return a;
    }
    
    public void printaccount(SavingsAccount[] accarray,int l)
    {
        int i=0;
        while(i<l)
        {
            System.out.println("Owner: " + accarray[i].getName() + " Balance: " + accarray[i].getbalance());
            i++;

        }
    }
    public static void main(String[] args)
    {
        String t="";
        int l=0;
        SavingsAccount[] s1= new SavingsAccount[10];
        
        Bank icici=new Bank();
        
        Scanner sc= new Scanner(System.in);
        while(t.compareTo("X")!=0)
        {
            
            t=sc.nextLine();
            String f[]=t.split(" ");
            
            
            if(f[0].compareTo("N")==0)
            {

                SavingsAccount k=icici.addaccount(f[1],Double.parseDouble(f[2]),Integer.parseInt(f[3]));
                s1[l]=k;
                l++;
            }
            else if (f[0].compareTo("D")==0)
            {
                s1[l-1].deposit(Integer.parseInt(f[1]));

            }
            else if(f[0].compareTo("W")==0)
            {
                int g=s1[l-1].withdraw(Integer.parseInt(f[1]));
            }
           
        }
        int y=0;
        while(y<l)
        {
            s1[y].addInterest();
            y++;

        }
        icici.printaccount(s1,l);

    }

}


