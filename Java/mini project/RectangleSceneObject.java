package imt2018067;
import java.util.ArrayList;
import animation.*;

public class RectangleSceneObject extends SceneObject
{

    public RectangleSceneObject(){
        super();
    }
    public RectangleSceneObject(Point initial){
        super();
        position = new Point(initial);
        boundary = new RectangularBBox();
    }
    public RectangleSceneObject(Point initial,Point dest){
        super();
        position = new Point(initial);
        destination = new Point(dest);
        boundary = new RectangularBBox();
    }
    public String getObjName(){
        return "Rectangle";
    }
    public Point getPosition(){
        return position;
    }
    public void setPosition(int x,int y){
        position.setPos(x,y);
    }
    public void setDestPosition(int x,int y){
        destination.setPos(x,y);
    }
    public BBox getBBox(){
        return boundary;
    }
    class RectangularBBox implements BBox{
        RectangularBBox(){
            minPoint = new Point(position);
            maxPoint = new Point(position.getX()+breadth,position.getY()+length);
        }
        public Point getMinPt(){
            minPoint.setPos(position.getX(), position.getY());
            return minPoint;
        }
        public Point getMaxPt(){
            maxPoint.setPos(position.getX()+breadth,position.getY()+length);
            return maxPoint;
        }
        public boolean intersects(BBox b)
        {
            Point min = getMinPt(),max = getMaxPt();
            if(min.getX() <= b.getMinPt().getX() && min.getY() <= b.getMinPt().getY() && b.getMinPt().getX() <= max.getX() && b.getMinPt().getY() <= max.getY())
                return true;
            else if(min.getX() <= b.getMaxPt().getX() && min.getY() <= b.getMaxPt().getY() && b.getMaxPt().getX() <= max.getX() && b.getMaxPt().getY() <= max.getY())
                return true;
            else if(b.getMinPt().getX() <= min.getX() && b.getMinPt().getY() <= min.getY() && min.getX() <= b.getMaxPt().getX() && min.getY() <= b.getMaxPt().getY())
                return true;
            else if(b.getMinPt().getX() <= max.getX() && b.getMinPt().getY() <= max.getY() && max.getX() <= b.getMaxPt().getX() && max.getY() <= b.getMaxPt().getY())
                return true;
            return false;
        }
        Point minPoint,maxPoint;
    }
    public ArrayList<Point> getOutline(){
        ArrayList<Point> outline = new ArrayList<>();
        outline.add(new Point(position));
        outline.add(new Point(position.getX()+breadth,position.getY()));
        outline.add(new Point(position.getX()+breadth,position.getY()+length));
        outline.add(new Point(position.getX(),position.getY()+length));
        return outline;
    }
    public void updatePos(int deltaT){
        ArrayList<SceneObject> actorArrray = Scene.getScene().getActors();
        ArrayList<SceneObject> obstracleArrray = Scene.getScene().getObstacles();
        ArrayList<Integer> moves = new ArrayList<>();
        if(destination.getY() > position.getY())
            moves.add(1); //1 for moving up
        else if(destination.getY() < position.getY())
            moves.add(2); //2 for moving down
        if(destination.getX() > position.getX())
            moves.add(3); //3 moving right
        else if(destination.getX() < position.getY())
            moves.add(4); //4 moving left
        for(Integer i = 1 ; i <= 4 ; i++){
            if(!moves.contains(i))
                moves.add(i);
        }
        moves.add(0); //In worst case don't move the object all;
        for(Integer move: moves){
            if(move == 1) {
                position.setPos(position.getX(), position.getY()+2*deltaT);
                if(validMove(actorArrray, obstracleArrray))
                    break;
                position.setPos(position.getX(), position.getY()-2*deltaT);
            }
            else if(move == 2) {
                position.setPos(position.getX(), position.getY()-2*deltaT);
                if(validMove(actorArrray, obstracleArrray))
                    break;
                position.setPos(position.getX(), position.getY()+2*deltaT);
            }
            else if(move == 3) {
                position.setPos(position.getX()+2*deltaT, position.getY());
                if(validMove(actorArrray, obstracleArrray))
                    break;
                position.setPos(position.getX()-2*deltaT, position.getY());
            }
            else if(move == 4) {
                position.setPos(position.getX()-2*deltaT, position.getY());
                if(validMove(actorArrray, obstracleArrray))
                    break;
                position.setPos(position.getX()+2*deltaT, position.getY());
            }
        }
    }
    public boolean validMove(ArrayList<SceneObject> actorArrray,ArrayList<SceneObject> obstracleArrray){
        for(SceneObject samp : actorArrray){
            for(SceneObject obs: obstracleArrray){
                if(samp.getBBox().intersects(obs.getBBox())){
                    return false;
                }
            }
        }
        for(SceneObject samp1 : actorArrray){
            for(SceneObject samp2 : actorArrray){
                if(!samp1.equals(samp2)){
                    if(samp1.getBBox().intersects(samp2.getBBox()))
                        return false;
                }
            }
        }
        return true;
    }
    Point position,destination;
    RectangularBBox boundary;
    final int breadth = 10;
    final int length = 15;
}