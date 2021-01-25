using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;
using UnityEngine;
using UnityEngine.UI;

public class LeaderBoardManager : MonoBehaviour
{
    public GameObject BestScore;

    string Path;
    int count; 
    string[] str;
    public int rank;

    void Start(){
        Path = Application.persistentDataPath + "/bestscore.txt";
        count = File.ReadAllLines(Path).Length;
        str = File.ReadAllLines(Path);

        if(count == 0){                         //When there is no score
            BestScore.GetComponent<Text>().text = "No Data!";
        }
        else if(count == 1){                    //When there is only one
            BestScore.GetComponent<Text>().text = "1. " + str[0];
        }
        else{
            string temp;
            char[] sep = {','};                 //Separator
            string[] Sep1, Sep2;
            for(int i = 0; i < count; i++){     //Bubble Sort
                for(int j = 0; j < count; j++){
                    Sep1 = str[i].Split(sep);
                    Sep2 = str[j].Split(sep);
                    if(int.Parse(Sep1[0]) > int.Parse(Sep2[0])){
                        temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }
                }
            }
            BestScore.GetComponent<Text>().text = "1. " + str[rank];
        }
    }

    void Update(){
        if(count == 0){                         //When there is no score
            BestScore.GetComponent<Text>().text = "No Data!";
        }
        else if(count == 1){                    //When there is only one
            BestScore.GetComponent<Text>().text = "1. " + str[0];
        }
        else{                                   //Update by file length
            BestScore.GetComponent<Text>().text = (rank+1) +". " + str[rank];
        }
    }

    public void next(int j){
        switch (j){
            case(0):                        //click Prev Button
                if(rank == 0)break;         //Do not exceed the size of the array.
                rank--;
                break;
            default:                        //click Next Button
                if(rank == count-1)break;   //Do not exceed the size of the array.
                rank++;
                break;
        }
    }
}
