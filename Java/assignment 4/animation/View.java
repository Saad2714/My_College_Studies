package animation;

// abstract class to represent the Display/Console or other output mechanism
public abstract class View {

	public abstract void clear();
	
	public abstract void render(SceneObject s);
	
	public static int maxUpdates = 10000;
	public static int delT = 500;
}
