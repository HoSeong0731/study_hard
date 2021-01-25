using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
public class TextManager : MonoBehaviour
{
    void Start(){
        string path = Application.persistentDataPath;
        if(File.Exists(path +"bestscore.txt") == false)File.Create(path +"bestscore.txt");
        if(File.Exists(path +"currentscore.txt") == false)File.Create(path +"currentscore.txt");
        if(File.Exists(path +"gamehistory.txt") == false)File.Create(path +"gamehistory.txt");
    }
}
