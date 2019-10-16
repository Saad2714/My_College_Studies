package storesuppliers;


class Order {

	int getOrderId() {
		return orderId;
	}

	String getItem() {
		return item;
	}

	int getUnits() {
		return units;
	}

	Order(String itemType, int numUnits) {
		orderId = nextOrder++;
		item = itemType;
		units = numUnits;
	}
	
	@Override
	public String toString() {
		return "Order " + orderId + " " + item + " " + units;
	}
	
	private int orderId;
	private String item;
	private int units;
	
	private static int nextOrder = 1;
}
