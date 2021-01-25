using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;

public class HistoryManager : MonoBehaviour
{
    public GameObject History;

    string Path;
    int count;
    string[] str;
    public int i = 0;

    void Awake(){
        Path = Application.persistentDataPath + "/gamehistory.txt";
        count = File.ReadAllLines(Path).Length;
        str = File.ReadAllLines(Path);
        if(count == 0){                 //When there is no Data
            History.GetComponent<Text>().text = "No Data!";
        }
        else{                           //else
            History.GetComponent<Text>().text = "" + str[i];
        }
        
    }

    void Update(){
        if(count == 0){                 //When there is no Data
            History.GetComponent<Text>().text = "No Data!";
        }
        else{                           //else
            History.GetComponent<Text>().text = "" + str[i];
        }
    }

    public void next(int j){
        switch (j){
            case(0):            //click Prev Button
                if(i == 0)break;
                i--;
                break;
            default:            //click Next Button
                if(i == count-1)break;
                i++;
                break;
        }
    }
}
