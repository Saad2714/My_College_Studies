package test;

import animation.*;
import java.util.*;

public class TestScene extends Scene
{

	public void checkScene()
	{

		ArrayList<SceneObject> actors = getActors();
        	ArrayList<SceneObject> obstacles = getObstacles();
        	
		for(SceneObject s : actors)
		{
			for(SceneObject ob: obstacles)
			{
				if(s.getBBox().intersects(ob.getBBox()))
				{
					actors.remove(s);
					break;
				}
			}
		}
        	for(SceneObject s0: actors)
		{
			for(SceneObject s1 : actors)
			{
				if(!s0.equals(s1))
				{
					if(s0.getBBox().intersects(s1.getBBox()))
					{
						actors.remove(s1);
					}
				}
			}
		}
	}
}
