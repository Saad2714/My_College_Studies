package network;

public abstract class Phone {
	public Phone(int num) {
		number = num;
	}

	public int getNumber() {
		return number;
	}

	public abstract String getModem();

	public void attach(Network net) {
		if (net != null) {
			net.addPhone(this);
			currNet = net;
		}
	}

	// call a number by sending call request to the network
	public boolean makeCall(int number) {
		boolean status = false;
		if (!isBusy && (currNet != null)) {
			status = currNet.connectCall(getNumber(), number);
			if (status == true) {
				setStatus(true, number);
			}
		}
		return status;
	}

	// handle incoming call request from network
	boolean recieveCall(int number) {
		if (!isBusy) {
			setStatus(true, number);
			return true;
		} else
			return false;
	}

	// handle hangup request from user or network
	public void hangup(boolean fromUser) {
		if (isBusy) {
			if (fromUser) {
				currNet.hangup(connectedNumber);
			}
			setStatus(false, 0);
		}
	}

	private void setStatus(boolean status, int otherNumber) {
		isBusy = status;
		connectedNumber = otherNumber;

	}

	private int number;
	private Network currNet;

	boolean isBusy = false; // true iff phone is in use
	private int connectedNumber; // if isBusy, number of connected phone

}
