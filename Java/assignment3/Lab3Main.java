import java.util.ArrayList;

import network.*;

public class Lab3Main {

	public static void main(String[] args) {
		Lab3Main test = new Lab3Main();

		// Instantiates the network
		Network net = new Network();

		// Creates a feature phone with number 12345 and modem TI
		Phone p1 = new FeaturePhone("TI", 12345);

		// Creates a smart phone with number 23456, CPU from Samsung and modem from
		// Mediatek
		Phone p2 = new SmartPhone("Samsung", "Mediatek", 23456);

		// Creates a smartphone with number 13452, CPU and modem from Apple
		Phone p3 = new SmartPhone("Apple", "Apple", 13452);

		// Attaches all these to the network.
		test.setNet(net);
		test.addPhone(p1);
		test.addPhone(p2);
		test.addPhone(p3);

		// Makes a call from phone 12345 to phone 23456
		test.makeCall(12345, 23456);

		// Makes a call from 13452 to 12345
		test.makeCall(13452, 12345);

		// Hangs up phone 23456
		test.hangup(23456);

		// Makes a call from 13542 to 12345
		test.makeCall(13452, 12345);

	}

	// helper methods to declutter main
	private Phone getPhone(int i) {
		for (Phone p : phones) {
			if (p.getNumber() == i)
				return p;
		}
		return null;
	}

	private void makeCall(int from, int to) {
		boolean status = false;

		Phone p = getPhone(from);
		if (p != null) {
			status = p.makeCall(to);
		}
		String message;
		if (status == true) {
			message = "successful";
		} else {
			message = "not successful";
		}
		System.out.println(message);
	}

	private void hangup(int number) {
		Phone p = getPhone(number);
		if (p != null)
			p.hangup(true);
	}

	private void setNet(Network n) {
		net = n;
	}

	private void addPhone(Phone p) {
		p.attach(net);
		phones.add(p);
	}

	private Network net;
	ArrayList<Phone> phones = new ArrayList<>();
}
