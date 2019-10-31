package imt2018504;
import java.util.ArrayList;
import animation.Scene;
import animation.BBox;
import animation.SceneObject;

public class Scene1 extends Scene {

	public Scene1() {
	   super();
	}



	// override this if additional processing is needed before each render
	// should flag actors that intersect with other obstacles or objects
	protected void checkScene()
  {
    System.out.println("inside Check Scene");
    //Scene s=new Scene1();
		//s=Scene1.getScene();
    ArrayList<SceneObject> actor=Scene.getScene().getActors();
    ArrayList<SceneObject> obstacle=Scene.getScene().getObstacles();

        for(int i=0;i<actor.size();i++)
    {
      int flag=0;
      for(int j=0;j<actor.size();j++)
      {
        if(i!=j)
        {
          BBox one=	actor.get(i).getBBox();
          BBox two=actor.get(j).getBBox();
          if(one.intersects(two)==true)
          flag=1;
        }
      }
      for(int j=0;j<obstacle.size();j++)
      {
          BBox one=	obstacle.get(j).getBBox();
          BBox two=actor.get(i).getBBox();
          if(one.intersects(two)==true)
          flag=1;

      }
			//Collision detected
      if(flag==1)
			{
      System.out.println("collision detected at "+ actor.get(i).getPosition().getX()+ " , "+actor.get(i).getPosition().getY());
			//Remove from simulation
			Scene.getScene().getActors().remove(i);
		}
    }
    }
  }
