import animation.Scene;
import animation.SceneObject;
import animation.View;
import imt2018504.SceneObject1;
import imt2018504.Scene1;


// Driver class to set up and exercise the animation
public class Demo {

	public static void main(String[] args) {
		Scene scene = new Scene1(); // replace with your implementation

		// populate the scene with objects implemented by the team
		for (int i = 0; i < 6; i++) {
			SceneObject s = new SceneObject1(); // replace with your implementation
			s.setPosition(i * 50, i * 50);
			scene.addObstacle(s); // using appropriate derived classes
		}

		for (int i = 0; i < 6; i++) {
			SceneObject s = new SceneObject1(); // replace with your implementation
			s.setPosition(500 - i * 50, 300 + i * 50); // these will be changed for the demo
			s.setDestPosition(0, 0);
			scene.addActor(s); // using appropriate derived classes
		}

		// View view = new DemoTextView();
		View view = new DemoSwingView();

		scene.setView(view);

		view.init();

	}

}
