import network.Phone;

public class FeaturePhone extends Phone {

	public FeaturePhone(String modem, int num) {
		super(num);
		chipManufacturer = modem;
	}

	@Override
	public String getModem() {
		// TODO Auto-generated method stub
		return chipManufacturer;
	}

	private String chipManufacturer;
}
