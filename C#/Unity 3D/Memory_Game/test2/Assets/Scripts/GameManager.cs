using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class GameManager : MonoBehaviour
{
    public Sprite[] cardFace;
    public Sprite cardBack;
    public GameObject[] cards;
    public Text matchText;

    private bool _init = false;
    private int _matches = 0;

    public GameObject Timetext;
    public int secondsLeft = 0;
    public bool takingAway = false;

    public GameObject Scoretext;
    public static int score = 0;
    
    string Path;

    void Awake(){
        Path = Application.persistentDataPath + "/currentscore.txt";
        if(cards.Length == 4){                              //Level 1
            score = 0;
        }
        Scoretext.GetComponent<Text>().text = "" + score;   //initialization
    }
    
    void Start(){
        secondsLeft = cards.Length*5;                       //initialize Time
        Timetext.GetComponent<Text>().text = "Time: " + secondsLeft + " sec";        
    }

    IEnumerator TimerTake(){                                //Timer
        takingAway = true;
        yield return new WaitForSeconds(1);
        secondsLeft -= 1;
        Timetext.GetComponent<Text>().text = "Time: " + secondsLeft + " sec";
        takingAway = false;
    }

    void Update(){
        if(takingAway == false && secondsLeft > 0){     //Time greater than 0 seconds
            StartCoroutine(TimerTake());
        }

        if(secondsLeft == 0){                           //game over (Time out)
            FileStream f = new FileStream(Path, FileMode.Append, FileAccess.Write);
            StreamWriter writer = new StreamWriter(f, System.Text.Encoding.Unicode);
            writer.WriteLine(score);
            writer.Close();
            f.Close();
            SceneManager.LoadScene ("Result");
        }
        
        if(!_init)                                      //initialize Card
            initializeCards();
        if(Input.GetMouseButtonUp(0))                   //click Card
            checkCards ();
    }

    void initializeCards(){
        _matches = cards.Length/2;
        int ran = 0;
        ran = Random.Range (0, 52-cards.Length);        //Random Image
        for(int id = 0; id < 2; id++){                  //Set to Pair
            for(int i = 1; i < (cards.Length/2)+1; i++){
                bool test = false;
                int choice = 0;
                while(!test){
                    choice = Random.Range (0, cards.Length);
                    test = !(cards [choice].GetComponent<Card>().initialized);
                }
                cards [choice].GetComponent<Card> ().cardValue = i+ran; 
                cards [choice].GetComponent<Card> ().initialized = true;
            }
        }
        foreach (GameObject c in cards){
            c.GetComponent<Card> ().setupGraphics();    //Set to Graphic
        }        
        if(!_init)
            _init = true;
    }

    public Sprite getCardBack(){
        return cardBack;                //Back Image
    }

    public Sprite getCardFace(int i){
        return cardFace[i-1];           //Front Image
    }

    void checkCards(){
        List<int> c = new List<int> ();

        for(int i = 0; i < cards.Length; i++){
            if(cards[i].GetComponent<Card>().state == 1)
                c.Add(i);
        }
        if(c.Count == 2)
            cardComparison (c);
    }

    void cardComparison (List<int> c){
        Card.DO_NOT = true;

        int x = 0;

        if(cards[c[0]].GetComponent<Card>().cardValue == cards[c[1]].GetComponent<Card>().cardValue){
            x = 2;
            _matches --;
            matchText.text = "Number of Matches: "  + _matches;
            score += cards.Length;
            Scoretext.GetComponent<Text>().text = "" + score;

            if(_matches == 0){              //Game clear
                if(cards.Length == 4){
                    SceneManager.LoadScene ("Level2");  //Go to Level 2
                }
                else if(cards.Length == 8){
                    SceneManager.LoadScene ("Level3");  //Go to Level 3
                }
                else if(cards.Length == 18){            //Go to Result 
                    FileStream f = new FileStream(Path, FileMode.Append, FileAccess.Write);
                    StreamWriter writer = new StreamWriter(f, System.Text.Encoding.Unicode);
                    writer.WriteLine(score);
                    writer.Close();
                    SceneManager.LoadScene ("Result");
                }
                else{                                   //Exception handling
                    score = 0;
                    SceneManager.LoadScene ("Menu");
                }
            }
        }

        for(int i =0; i < c.Count; i++){
            cards[c[i]].GetComponent<Card>().state = x;
            cards[c[i]].GetComponent<Card>().falseCheck ();
        }
    }

}
