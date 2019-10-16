public class SavingsAccount{
        private String name;
        private double interest;
        private int balance;
       public SavingsAccount(String sname,double sinterest,int sbalance)
        {
             name = sname;
             interest = (1/12.0)*sinterest;
             balance = sbalance;
        }
        
        public int getbalance() { return balance; }
        public void deposit(int amount) { balance+=amount; }
        public void addInterest() { balance+=balance*interest*0.01;}
        public int withdraw(int amount) 
        {
            if(amount<=balance)
            {
                    balance-=amount;
                    return amount;  
            }
            else
            {
                return 0;
            }

        }
        public String getName(){return name;}
        public static void main(String[] args){
            SavingsAccount s1= new SavingsAccount("Newton",15,10000);
            s1.deposit(2000);
            int t=s1.withdraw(5000);
            int t1=s1.withdraw(10000);
            s1.addInterest();
            System.out.println("Account owned by " + s1.getName() + " has a balance of " + s1.getbalance());



        }




}





	
