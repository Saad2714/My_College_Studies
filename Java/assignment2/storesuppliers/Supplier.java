package storesuppliers;

import java.util.ArrayList;

class Supplier {
	Supplier(String name) {
		this.name = name;
		orders = new ArrayList<Order>();
		processedOrders = new ArrayList<Order>();
	}

	void addOrder(Order newOrder) {
		orders.add(newOrder);
	}

	void processOrders() {
		// find the largest unprocessed order
		while(processedOrders.size() < orders.size()) {
			int max = 0;
			Order nextOrder = null;
			for(Order order: orders) {
				if(!processedOrders.contains(order) && (order.getUnits() > max)) {
					nextOrder = order;
					max = order.getUnits();
				}
			}
			processedOrders.add(nextOrder);
		}
	}

	void printProcessedOrders() {
		System.out.println(name);
		for(Order order: processedOrders) {
			System.out.println(order);
		}
		System.out.println();
	}
	
	private String name;
	private ArrayList<Order> orders;
	private ArrayList<Order> processedOrders;

}
