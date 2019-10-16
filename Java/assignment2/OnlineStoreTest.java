import java.util.Scanner;
import storesuppliers.*;

public class OnlineStoreTest {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		boolean lastTransaction = false;
		int numBakeries = sc.nextInt();
		int numDairies = sc.nextInt();
		
		Store store = new Store(numBakeries, numDairies);
		
		while(!lastTransaction) {
			String item = sc.next();
			if(item.equals("End")) {
				lastTransaction = true;
				store.processOrders();
			} else {
				int units = sc.nextInt();
				store.placeOrder(item, units);
			}
		}
				
		sc.close();
	}

}

/*
 * Sample Input 
1 2
Bread 2
Milk 4
Butter 2
Cake 3
Milk 6
Milk 1
Bread 5
Butter 5
End

*/
