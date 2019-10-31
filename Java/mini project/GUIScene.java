package imt2018067;
import animation.*;
// import imt2018067.Scene;
// import imt2018067.SceneObject;

import java.util.ArrayList;

public class GUIScene extends Scene
{
    public void checkScene(){
        ArrayList<SceneObject> actorArrray = getActors();
        ArrayList<SceneObject> obstracleArrray = getObstacles();
        for(SceneObject samp : actorArrray){
            for(SceneObject obs: obstracleArrray){
                if(samp.getBBox().intersects(obs.getBBox())){
                    actorArrray.remove(samp);
                    break;
                }
            }
        }
        for(SceneObject samp1 : actorArrray){
            for(SceneObject samp2 : actorArrray){
                if(!samp1.equals(samp2)){
                    if(samp1.getBBox().intersects(samp2.getBBox()))
                        actorArrray.remove(samp2);
                }
            }
        }
    }
}