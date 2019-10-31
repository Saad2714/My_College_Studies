package test;
//package IMT2018505;


import animation.*;
import java.util.*;

public class TestObject extends SceneObject 
{
    Point position=new Point(0,0);
    Point destination=new Point(0,0);
    Point minPoint=new Point(0,0);
    Point maxPoint=new Point(0,0);
    RectangularBBox boundary;
    final int breadth = 10;
    final int length = 15;
    private static int nameCount = 1;
    private String name;


    public TestObject()
    {
	    super();
        boundary = new RectangularBBox();
	name = "Rectangle "+nameCount++;
    }



    public String getObjName()
    {
        return name;

    }

    public Point getPosition()
    {

        return position;
    }
    @Override
    public void setPosition(int x,int y)
    {

       this.position.setPos(x,y);
    }

    public void setDestPosition(int x,int y)
    {

        destination.setPos(x,y);
    }

    public BBox getBBox()
    {

        return boundary;
    }
    
    
    public ArrayList<Point> getOutline()
    {

        ArrayList<Point> bndry = new ArrayList<>();
        bndry.add(new Point(position));
        bndry.add(new Point(position.getX()+breadth,position.getY()));
        bndry.add(new Point(position.getX()+breadth,position.getY()+length));
        bndry.add(new Point(position.getX(),position.getY()+length));

	boundary = new RectangularBBox(position, breadth, length);
        return bndry;

    }
    
    public void updatePos(int deltaT)
    {

        ArrayList<SceneObject> actors = Scene.getScene().getActors();
        ArrayList<SceneObject> obstacles = Scene.getScene().getObstacles();
      //  int[] moves=new int[5];
       
        int count=0;
	int a1=0,a2=0;
       if(position.getX()!=destination.getX() && position.getY()!=destination.getY())
       {	       
	if(destination.getY() > position.getY())
	{
 
            a1=1;
	    position.setPos(position.getX(),position.getY()+(deltaT/100));
	}

	//down
        else if(destination.getY() < position.getY())
	{
            
            a1=2; 
	    position.setPos(position.getX(),position.getY()-deltaT/100);
	}

	//right
        if(destination.getX() > position.getX())
	{
            a2=1;
	    position.setPos(position.getX()+ deltaT/100, position.getY());
	}

	//left
        else if(destination.getX() < position.getX())
	{
        
        	a2=2;
		position.setPos(position.getX()-deltaT/100, position.getY());
	}
	if(!validMove(this,actors,obstacles))
	{
		if(a1==1 && a2==1)
			position.setPos(position.getX()-deltaT/100,position.getY()-deltaT/100);
		else if(a1==1 && a2==2)
			 position.setPos(position.getX()+deltaT/100,position.getY()-deltaT/100);
		else if(a1==2 && a2==2)
			 position.setPos(position.getX()+deltaT/100,position.getY()+deltaT/100);
		else if(a1==2 && a2==1)
			 position.setPos(position.getX()-deltaT/100,position.getY()+deltaT/100);




	}
       }

	else if(destination.getX()==position.getX() && destination.getY()!=position.getY())
	{
		if(destination.getY()>position.getY())
			a1=1;
		else
			a1=2;
		if(a1==1)
			position.setPos(position.getX(),position.getY()+(deltaT/100));
		else if(a1==2)
			position.setPos(position.getX(),position.getY()-(deltaT/100));
		if(!validMove(this,actors,obstacles))
		{
			if(a1==1)
				 position.setPos(position.getX(),position.getY()-(deltaT/100));
			else if(a1==2)
				 position.setPos(position.getX(),position.getY()+(deltaT/100));
		}
	}

	else if((destination.getX()!=position.getX() && destination.getY()==position.getY()))
	{
		System.out.println("Happy");
		 if(destination.getX()>position.getX())
                        a2=1;
                else
                        a2=2;

		if(a2==1)
			position.setPos(position.getX()+ deltaT/100, position.getY());
		else if(a2==2)
			 position.setPos(position.getX()-deltaT/100, position.getY());
		 if(!validMove(this,actors,obstacles))
                {
                        if(a2==1)
                                 position.setPos(position.getX()-deltaT/100,position.getY());
                        else if(a2==2)
                                 position.setPos(position.getX()+deltaT/100,position.getY());
                }

	}
       else if((destination.getX()==position.getX() && destination.getY()==position.getY()))
	       position.setPos(destination.getX(),destination.getY());
        



    }

class RectangularBBox implements BBox
{
	RectangularBBox(Point position, int breadth, int length){
		minPoint = new Point(position);
		maxPoint = new Point(position.getX()+breadth,position.getY()+length);
	}

	RectangularBBox(){}
        
	public Point getMinPt()
	{
            minPoint.setPos(position.getX(), position.getY());
            return minPoint;

        }

        public Point getMaxPt()
	{
            maxPoint.setPos(position.getX()+breadth,position.getY()+length);
            return maxPoint;

        }

        public boolean intersects(BBox b)
        {
            Point min = getMinPt(),max = getMaxPt();
            if(min.getX() <= b.getMinPt().getX() && min.getY() <= b.getMinPt().getY() && b.getMinPt().getX() <= max.getX() && b.getMinPt().getY() <= max.getY())
	    {

                return true;
	    }
            else if(min.getX() <= b.getMaxPt().getX() && min.getY() <= b.getMaxPt().getY() && b.getMaxPt().getX() <= max.getX() && b.getMaxPt().getY() <= max.getY())
	    {

                return true;
	    }
            else if(b.getMinPt().getX() <= min.getX() && b.getMinPt().getY() <= min.getY() && min.getX() <= b.getMaxPt().getX() && min.getY() <= b.getMaxPt().getY())
	    {

		    return true;
	    }
            else if(b.getMinPt().getX() <= max.getX() && b.getMinPt().getY() <= max.getY() && max.getX() <= b.getMaxPt().getX() && max.getY() <= b.getMaxPt().getY())
	    {

		    return true;
	    }
            
	    return false;
        }    
}  

public boolean validMove(SceneObject actor,ArrayList<SceneObject> actors,ArrayList<SceneObject> obstacles)
{
            for(SceneObject ob: obstacles)
	    {
                if(actor.getBBox().intersects(ob.getBBox()))
		        {

                    return false;
                }

            }

	{
            for(SceneObject s1 : actors)
	    {
                if(!actor.equals(s1))
		{

                    if(actor.getBBox().intersects(s1.getBBox()))
		    {
			    return false;
		    }
                }
            }
        }
        return true;
    }
   
}
