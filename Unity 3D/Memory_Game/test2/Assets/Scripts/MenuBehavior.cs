using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuBehavior : MonoBehaviour
{
    public void triggerMenuBehavior(int i){
        switch (i){
            case(0):            //click Start Button
                SceneManager.LoadScene ("Level1");
                break;
            case(1):            //click Best score Button
                SceneManager.LoadScene ("Best Score");
                break;
            case(2):            //click Quit Button
                Application.Quit ();
                break;    
            case(3):            //click Back Button
                SceneManager.LoadScene ("Menu");
                break;
            default:            //click Game History Button
                SceneManager.LoadScene ("Game History");
                break;
        }
    }
}
