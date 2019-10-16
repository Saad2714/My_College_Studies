import network.Phone;

public class SmartPhone extends Phone {

	public SmartPhone(String CPU, String modem, int num) {
		super(num);
		CPUManfufacturer = CPU; 
		modemManufacturer = modem;
	}

	@Override
	public String getModem() {
		return modemManufacturer;
	}

	private String CPUManfufacturer;
	private String modemManufacturer;
}
