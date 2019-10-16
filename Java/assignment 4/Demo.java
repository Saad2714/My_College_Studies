import animation.Scene;
import animation.SceneObject;
import demo.DemoSceneObject;
import demo.TextView;

// Driver class to set up and exercise the animation
public class Demo {

	public static void main(String[] args) {
		Scene scene = new Scene() {  // replace with appropriate derived class
			protected void checkScene() {}
		};
		
		scene.setView(new TextView()); // can be replaced with other Views that will be provided
		
		// populate the scene with objects implemented by the team
		for(int i=0;i<6;i++) {
			SceneObject s = new DemoSceneObject();
			s.setPosition(i*50, i*50);  
			scene.addObstacle(s); // using appropriate derived classes
		}
			
		for(int i=0;i<6;i++) {
			SceneObject s = new DemoSceneObject();
			s.setPosition(500 - i*50, 300 + i*50);  // these will be changed for the demo
			s.setDestPosition(0, 0);
			scene.addActor(s); // using appropriate derived classes
		}
		
		scene.animate();
	}

}
