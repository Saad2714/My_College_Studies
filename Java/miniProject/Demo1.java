import animation.Scene;
import animation.SceneObject;
import animation.View;
import imt2018504.SceneObject1;
import imt2018504.Scene1;
import imt2018067.Obj1;
import imt2018041.DemBBox;
import imt2018041.DemSceneObject;
import imt2018527.myObject;
import imt2018527.myBBox;
import imt2018057.TestObject;
import imt2018507.SceneObjectext;


// Driver class to set up and exercise the animation
public class Demo1 {

	public static void main(String[] args) {
		Scene scene = new Scene1() ;
		//{  // replace with appropriate derived class protected void checkScene() {}};

	// populate the scene with objects implemented by the team

			SceneObject s = new SceneObject1();
			s.setPosition(1000-110, 100+110);
			scene.addObstacle(s);
			SceneObject k=new Obj1();
			k.setPosition(1000-120,100+120);
			scene.addObstacle(k);// using appropriate derived classes
			SceneObject l=new DemSceneObject();
			l.setPosition(1000-120,100+120);
			scene.addObstacle(l);
			SceneObject m=new myObject();
			m.setPosition(1000-130,100+130);
			scene.addObstacle(m);
			SceneObject n=new TestObject();
			n.setPosition(1000-140,100+140);
			scene.addObstacle(n);
			SceneObject o=new SceneObjectext();
			o.setPosition(1000-150,100+150);
			scene.addObstacle(o);


			SceneObject p = new SceneObject1();
			p.setPosition(500 - 150, 300 + 150);  // these will be changed for the demo
			scene.addActor(p);
			SceneObject q=new Obj1();
			q.setPosition(500 - 160, 300 + 160);  // these will be changed for the demo
			scene.addActor(q);
			SceneObject r=new DemSceneObject();
			r.setPosition(1000-160,100+160);
			scene.addActor(r);
			SceneObject t=new myObject();
			t.setPosition(1000-170,100+170);
			scene.addActor(t);
			SceneObject u=new TestObject();
			u.setPosition(1000-180,100+180);
			scene.addActor(u);
			SceneObject v=new SceneObjectext();
			v.setPosition(1000-190,100+190);
			scene.addActor(v);

    System.out.println(Scene.getScene().getActors().size());
    View view = new DemoSwingView();

		scene.setView(view);

		view.init();
}
}
