package network;

import java.util.ArrayList;

public class Network {

	public Network() {
		attachedPhones = new ArrayList<>();
	}
	
	// maintain a list of attached phones
	void addPhone(Phone phone) {
		if(!attachedPhones.contains(phone)) {
			attachedPhones.add(phone);
		}
	}
	
	// check if the called number is attached, and call the phone with that number
	boolean connectCall(int fromNumber, int toNumber) {
		Phone p = findPhone(toNumber); 
		boolean status = false;
		if(p != null) {		
			status = p.recieveCall(fromNumber);
		}
		return status;
	}
	
	// Handle hangup request. 
	// Send a message to the phone with the given number asking it to hangup
	void hangup(int number) {
		Phone p = findPhone(number); 
		if(p!= null) {
			p.hangup(false);
		}
	}
	
	// find Phone with given number
	private Phone findPhone(int number) {
		for(Phone p: attachedPhones) {
			if(p.getNumber() == number) {
				return p;
			}
		}
		return null;
	}
	
	ArrayList<Phone> attachedPhones;
}
