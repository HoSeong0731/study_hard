using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class ScoreManager : MonoBehaviour
{
    [SerializeField]
    private Text text;
    [SerializeField]
    private InputField input_name;

    int count;  //To read the last line
    string Path;

    public GameObject Scoretext;    //using Score Object
    public static int score = 0;    //first Score is 0

    public GameObject Cheer;        //for comments

    

    void Start(){
        Path = Application.persistentDataPath;
        count = File.ReadAllLines(Path + "/currentscore.txt").Length;
        string[] str = File.ReadAllLines(Path + "/currentscore.txt");

        score = int.Parse(str[count-1]);
        Scoretext.GetComponent<Text>().text = "Your Score: " + score;

        if(score < 0)Cheer.GetComponent<Text>().text = "You're a hacker.";  //a score below 0 = crack
        else if(score < 50)Cheer.GetComponent<Text>().text = "TRY AGAIN!";  //a score below 50
        else if(score < 100)Cheer.GetComponent<Text>().text = "CHEER UP!";  //a score below 100
        else if(score < 150)Cheer.GetComponent<Text>().text = "NOT BAD.";   //a score below 150
        else if(score < 202)Cheer.GetComponent<Text>().text = "GREAT!";     //a score below 202
        else if(score == 202)Cheer.GetComponent<Text>().text = "PERFECT!";  //The score is 202 = Maximun score
        else Cheer.GetComponent<Text>().text = "You're a hacker.";          //So this is crack
    }

    public void Input(){
        string name;
        name = input_name.text;
        
        FileStream f = new FileStream(Path +"/gamehistory.txt", FileMode.Append, FileAccess.Write);
        StreamWriter writer = new StreamWriter(f, System.Text.Encoding.Unicode);
        writer.WriteLine("Date: " + DateTime.Now + ", Score: " + score + ", Name: " + name);    //write to gamehistory file
        writer.Close();

        
        FileStream f2 = new FileStream(Path + "/bestscore.txt", FileMode.Append, FileAccess.Write);
        StreamWriter best_writer = new StreamWriter(f2, System.Text.Encoding.Unicode);
        best_writer.WriteLine(score +", "+ name);   //write to bestscore file
        best_writer.Close();
        
        SceneManager.LoadScene ("Best Score");
    }
    

}
