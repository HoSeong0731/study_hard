#pragma warning (disable: 4996)

#include "Manager.h"
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const char* area[]{
    "Gwangju", "Daegu", "Seoul",
    "Busan", "Daejeon", "Incheon", "Ulsan"  //area BSTLocation
};

Manager::Manager()
{
    ds_queue = new queue<PatientNode*>; //make Constructor
    ds_bst = new LocationBST;          //new LocationNode;
    ds_patient = new PatientBST[7];
}

Manager::~Manager()
{
    //delete ds_bst;
    //delete ds_queue;
}

void Manager::run(const char* command)
{
    fin.open(command);              //command file open
    flog.open("log.txt", ios::app); //log file open
    if (!fin)                        //if file not found
    {
        flog << "File Open Error" << endl;  //error!
        return;                             //end run function
    }

    char cmd[100];                  //100 * char(input command)
    char* context = NULL;           //input token(ex. ADD "10")

    while (!fin.eof())              //repeat end of file
    {
        fin.getline(cmd, 100);      //Inputed in single line     
        char* tmp = strtok_s(cmd, " ", &context);  //Slice a string based on the space bar.

        if (strcmp(tmp, "LOAD") == 0)    //tmp = LOAD
        {
            if (LOAD())                  //LOAD success
            {
                PrintSuccess(tmp);
            }
            else
            {
                PrintErrorCode(100);    //LOAD fail
            }
        }

        else if (strcmp(tmp, "ADD") == 0)        //tmp = ADD
        {
            if (ADD(context))
            {
                PrintSuccess(tmp);              //ADD success
            }
            else
            {
                PrintErrorCode(200);            //ADD fail
            }
        }

        else if (strcmp(tmp, "QPOP") == 0)   //tmp = QPOP
        {

            if (QPOP(context))
            {
                PrintSuccess(tmp);          //QPOP success
            }
            else
            {
                PrintErrorCode(300);        //QPOP fail
            }
        }

        else if (strcmp(tmp, "SEARCH") == 0)    //tmp = SEARCH
        {
            if (SEARCH(context))
            {
                PrintSuccess(tmp);              //SEARCH success
            }
            else
            {
                PrintErrorCode(400);            //SEARCH fail
            }
        }

        else if (strcmp(tmp, "PRINT") == 0) //tmp = PRINT
        {
            if (PRINT(context))
            {
                PrintSuccess(tmp);          //PRINT success
            }
            else
            {
                PrintErrorCode(500);        //PRINT fail
            }
        }

        else if (strcmp(tmp, "BPOP") == 0)       //tmp = BPOP
        {
            if (BPOP())
            {
                PrintSuccess(tmp);              //BPOP success
            }
            else
            {
                PrintErrorCode(600);            //BPOP fail
            }
        }

        else if (strcmp(tmp, "EXIT") == 0)   //tmp = EXIT
        {
            PrintSuccess(tmp);              //always EXIT
            break;
        }

        else
        {
            flog << "========== ERROR ==========" << endl;          //error
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
        }
    }
    fin.close();        //close the input
    flog.close();       //close the log
}

bool Manager::LOAD()
{
    LocationNode* location = new LocationNode;

    char data[100];                 //To receive textfile entry
    char* token = NULL;
    if (ds_queue->size() > 0)            //LOAD Duplicate Exception Processing
        return 0;                   //error code 100

    ifstream ifs;                   //data file read
    ifs.open("data.txt");           //load data

    if (!ifs.is_open()) {                //failed to open file
        ifs.close();                    //data file close
        return 0;                       //error code 100
    }

    while (!ifs.eof()) {            //end of file
        ifs.getline(data, 100);     //Receive line by line
        char* token = NULL;

        char* Name = strtok_s(data, " ", &token);   //token = Temp + Cough + Loc
        char* Temp = strtok_s(NULL, " ", &token);   //token = Cough + Loc
        char* Cough = strtok_s(NULL, " ", &token);  //token = Loc
        char* Loc = strtok_s(NULL, " ", &token);    //token = NULL

        float num = (float)atof(Temp);                     //char* to float

        char Cough2[10];                            //char* to char
        strcpy(Cough2, Cough);                      //copy the Cough

        //queue
        PatientNode* patient = new PatientNode;

        patient->SetName(Name);                     //SetName  tom, emily...
        patient->SetTemp(num);                      //SetTemp  32.2, 36.5...
        patient->SetCough(*Cough2);                 //SetCough Y, N...
        patient->SetLoc(Loc);                       //SetLoc   Seoul, Incheon...
        ds_queue->push(patient);                    //push(patient) (tom, 32.2, Y, Seoul)...
    }

    ifs.close();                        //data file close

    return 1;                           //LOAD success
}

bool Manager::ADD(char* data)
{
    PatientNode* patient = new PatientNode;     //new PatientNode
    char* token = NULL;                         //receive the token

    char* Name = strtok_s(data, " ", &token);   //Decomposition 1
    char* Temp = strtok_s(NULL, " ", &token);   //Decomposition 2
    char* Cough = strtok_s(NULL, " ", &token);  //Decomposition 3
    char* Loc = strtok_s(NULL, " ", &token);    //Decomposition 4

    if (Loc != NULL) {                          //Sufficient information
        float num = (float)atof(Temp);                 //char* to float

        char Cough2[10];                        //char* to char
        strcpy(Cough2, Cough);                  //copy the Cough

        patient->SetName(Name);                 //SetName  input name
        patient->SetTemp(num);                  //SetTemp  input Temp
        patient->SetCough(*Cough2);             //SetCough input Cough
        patient->SetLoc(Loc);                   //SetLoc   input Loc
        ds_queue->push(patient);                //push(patient) (tom, 32.2, Y, Seoul)...

        // printf("%s %s %s %s \n", Name, Temp, Cough, Loc);

        return 1;                               //ADD success
    }
    else
        return 0;                               //Insufiicient information(ADD fail)
}

bool Manager::QPOP(char* number)
{
    size_t num = atoi(number);                          //new size_t
    PatientNode* patient = new PatientNode;             //new PatientNode
    PatientBSTNode* bst_patient = new PatientBSTNode;   //new PatientBSTNode

    if (ds_queue->size() < num)
        return 0;                           //Not enough queues.(QPOP fail)

    while (ds_queue->size() > 0) {
        patient = ds_queue->front();            //insert BST
        ds_queue->pop();

        bst_patient->SetName(patient->GetName());
        if (patient->GetTemp() > 37.5) {        //calculate +, - 
            bst_patient->SetDisease(patient->GetCough() == 'Y' ? '+' : '-');
        }
        else
            bst_patient->SetDisease('-');

        // printf("%s [%c] \n", bst_patient->GetName(), bst_patient->GetDisease());
    }

    for (int i = 0; i < 7; i++) {
        if (!strcmp(patient->GetLoc(), area[i])) {
            ds_patient[i].Insert(bst_patient);      //insert patinet node
            break;
        }
    }

    for (int i = 0; i < 7; i++)
        (ds_bst->SearchLoc(ds_bst->GetRoot(), (char*)area[i]))->SetBST(&ds_patient[i]);
    //insert patient area

    return 1;       //return true
}

bool Manager::SEARCH(char* data)
{
    for (int i = 0; i < 7; i++)
        if (ds_patient[i].Search(ds_patient[i].GetRoot(), data))    //data name search
            return true;

    return false;       //return false
}

bool Manager::PRINT(char* data)
{
    char* token = NULL;
    char* B = strtok_s(data, " ", &token);
    //Execute according to one command of tokenization.
    if (string(B) == "B") {
        //cout << "BST" << endl;
        if (string(token) == "PRE") {
            void Print_PRE();
        }
        else if (string(token) == "IN")
        {
            //cout << "IN" << endl;
        }
        else if (string(token) == "POST")
        {
            //cout << "POST" << endl;
        }
        else if (string(token) == "LEVEL")
        {
            //cout << "LEVEL" << endl;
        }
        else if (token == NULL)
        {
            //cout << "any order" << endl;
        }
        else {
            return 0;
        }
    }
    else if (string(B) == "H") {
        return 0;
    }
    else {
        return 0;
    }

    return 1;
}

bool Manager::BPOP()
{
    return 0;   //fail(sorry...)
}

void Manager::PrintErrorCode(int num)
{
    flog << "========== ERROR ==========" << endl;          //flog print
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(char* act)
{
    flog << "========== " << act << " ==========" << endl;  //flog print
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}