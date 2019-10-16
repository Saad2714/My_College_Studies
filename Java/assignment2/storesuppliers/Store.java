package storesuppliers;

import java.util.ArrayList;

public class Store {

	public Store(int numBakeries, int numDairies) {
		bakeries = new ArrayList<Supplier>(numBakeries);
		dairies = new ArrayList<Supplier>(numDairies);
		for(int i=1;i<=numBakeries;i++) {
			bakeries.add(new Supplier("Bakery " + i));
		}
		for(int i=1;i<=numDairies;i++) {
			dairies.add(new Supplier("Dairy " + i));
		}
		nextBakery = 0;
		nextDairy = 0;
	}

	public void placeOrder(String item, int units) {
		Order order = new Order(item, units);
		switch(item) {
		case "Bread":
		case "Cake":
		case "MUffin":
			Supplier bakery = bakeries.get(nextBakery);
			bakery.addOrder(order);
			nextBakery++;
			if(nextBakery == bakeries.size())
				nextBakery = 0;
			break;
		case "Milk":
		case "Butter":
			Supplier dairy = dairies.get(nextDairy);
			dairy.addOrder(order);
			nextDairy++;
			if(nextDairy == dairies.size())
				nextDairy = 0;
			break;
		default:
			break;
		}
		
	}
	
	public void processOrders() {
		for(Supplier bakery: bakeries) {
			bakery.processOrders();
			bakery.printProcessedOrders();
		}
		for(Supplier dairy: dairies) {
			dairy.processOrders();
			dairy.printProcessedOrders();
		}
	}
	
	private ArrayList<Supplier> bakeries;
	private ArrayList<Supplier> dairies;
	private int nextBakery, nextDairy;

}
