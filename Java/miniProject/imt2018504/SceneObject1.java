package imt2018504;

import java.util.ArrayList;

import animation.BBox;
import animation.Point;
import animation.SceneObject;
import animation.View;
import animation.Scene;

public class SceneObject1 extends SceneObject implements BBox{

	  String objName;
	  Point current,dest,next;
	  int hWidth,hHeight;
		static int i=0;
		//half width and half height of the diamonds
	  //all the actors are diamonds of different width and heights.
	  // the dest and current Points map to the midPoint of the diamond.
		// a unique name for the object
		public SceneObject1()
		{
			super();
			objName=Integer.toString(i);
			i++;
			current=new Point(0,0);
			dest=new Point(0,0);
			next=new Point(0,0);
			hWidth=2;
			hHeight=4;
		}
		public String getObjName()
	  {
	    return this.objName;
	  }

		// return the position of a representative Point (local origin) of the object
		// in the window coordinates where it is being displayed
		public Point getPosition()
	  {
	    return current;
	  }

		public void setPosition(int x, int y)
	  {
	    this.current.setPos(x,y);
	  }

		public void setDestPosition(int x, int y)
	  {
	    this.dest.setPos(x,y);
	  }

		public Point getMinPt()
		{
			ArrayList<Point> shape=this.getOutline();
			return new Point(shape.get(1).getX(),shape.get(2).getY());
		}

		// return the top-right corner of the bounding box
		public Point getMaxPt()
		{
			ArrayList<Point> shape=this.getOutline();
			return new Point(shape.get(3).getX(),shape.get(0).getY());
		}

		// does this box intersect/overlap the input BBox
		public boolean intersects(BBox b)
		{
		 if(this.getMinPt().getX()<=b.getMaxPt().getX()&&this.getMaxPt().getX()>=b.getMinPt().getX()&&this.getMinPt().getY()<=b.getMaxPt().getY()&&this.getMaxPt().getY()>=b.getMinPt().getY())
		 return true;
		 else
		 return false;
		}
		// return the tightest fitting BBox for the shape
		public BBox getBBox()
		{
			return this;
		}


		// return the path/name of a .png or .jpg file that contains an icon for this
		// object. If non-null, this image will be used by graphical displays to render
		// the object
		public String imageFileName() {
			return null;
		}

		// return the list of points that represent the shape of this object. The points
		// should be ordered so that by joining consecutive points, and joining the last
		// point
		// to the first point in the list, we get a closed outline of the object
		// Note: these points should represent the current position of the object
		//GIVES A DIAMOND OF WIDTH 2*hwidth and HEIGHT 2*hheight
		protected ArrayList<Point> getOutline()
	  {
	    ArrayList<Point> outline=new ArrayList<Point>();
	    outline.add(new Point(this.current.getX(),this.current.getY()+hHeight));
	    outline.add(new Point(this.current.getX()-hWidth,this.current.getY()));
	    outline.add(new Point(this.current.getX(),this.current.getY()-hHeight));
	    outline.add(new Point(this.current.getX()+hWidth,this.current.getY()));
	    return outline;
	  }

		// compute the new position of the object after it moves for deltaT
		protected void updatePos(int deltaT)
		{
		int flag=0;
		boolean bp=false,pn=false,np=false,bn=false;
		int xdiff=dest.getX()-current.getX();
		int ydiff=dest.getY()-current.getY();

		//if destination is reached
				if(xdiff==0&&ydiff==0)
		return;

		//code to move toward destination
			if(xdiff>=0)
			{
				if(ydiff>=0)
				{
					bp=true;
					this.current.setPos(this.current.getX()+1,this.current.getY()+1);
				}
			else
			{
				pn=true;

				this.current.setPos(this.current.getX()+1,this.current.getY()-1);

		}

		}
		else
		{
			if(ydiff>=0)
			{
				np=true;
				this.current.setPos(this.current.getX()-1,this.current.getY()+1);
		}
		else
		{
			bn=true;
			this.current.setPos(this.current.getX()-1,this.current.getY()-1);
	}
	}

	//code to avoid collision
    ArrayList<SceneObject> actor=Scene.getScene().getActors();
        for(int i=0;i<actor.size();i++)
    {

        if(actor.get(i).equals(this)==false)
        {

          BBox one=	actor.get(i).getBBox();
          BBox two=this.getBBox();
          if(one.intersects(two)==true)
          flag=1;
        }
      }
			for(SceneObject obstacle:Scene.getScene().getObstacles())
			{
			BBox one=	obstacle.getBBox();
			BBox two=this.getBBox();
			if(one.intersects(two)==true)
			flag=1;
			}
			//no collision
		if(flag==0)
		{}
		// backtrack in case of collision depending on where obsatcle is
		else
		{
      //replace 5 with 2*maxwidth of obstacle +1 and 9 by 2*maxheight of obstacle +1
      if(bp==true)
			this.current.setPos(current.getX()+5-1,current.getY()-9-1);
			else if(pn==true)
			this.current.setPos(current.getX()+5-1,current.getY()+9+1);
			else if(np==true)
			this.current.setPos(current.getX()-5+1,current.getY()-9-1);
			else if(bn==true)
			this.current.setPos(current.getX()-5+1,current.getY()+9+1);

		}
		}

		@Override
		public void run() {
			// default implementation. You can override this if you want to change the
			// behavior
			// of this object

			for (int i = 0; i < View.maxUpdates; i++) {
				updatePos(View.delT);
				try {
					Thread.sleep(View.delT);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}

			}

		}

	}
