//
//
//
//  main.cpp
//  search suggestions
//
//  Created by Ed cox on 7/2/17.
//  Copyright © 2017 Ed cox. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string checkdictionary(){
    //return array of strings
    return 0;
}

void arrayboost(char arr[],int &length){
    //create new array bigarray, copy old array to big array, delete old array
    length = length*2;
    char *bigarray = new char [length];
    for (int i=0;i<length/2;i++){
        bigarray[i]=arr[i];
        cout << bigarray[i];
    }
    arr = bigarray;
    delete[] bigarray;
}

void findwords(char word[],int length,string d[],int diclength){
    ifstream input;
    int count=0;
    string dic;
    input.open("dictionary.txt");
    while (input >> dic){
        bool match = true;
        for (int i=0;i<length;i++){
            if (word[i]!=dic[i]){
                match = false;
            }
        }
        if (match==true){
            if (count>=diclength-1){
                diclength=diclength*2;
                string *bigd = new string [diclength];
                for (int i=0;i<count;i++){
                    bigd[i]=d[i];
                }
                delete[] d;
                d = bigd;
            }
            d[count]=dic;
            count++;
        }
    }
    for (int print=0;print<diclength;print++){
        if (d[print]!=""){
            cout << d[print] << endl;
        }
    }
    input.close();
}

int main() {
    // insert code here...
    int resultset=0;
    int arrlength = 5;
    string word;
    int count=0;
    int diclength=10;
    char letter;
    string enteredwords;
    char array[arrlength];
    
    char found='N';
    cout << "Let's play Word Wizard! Enter a sequence of characters to find word matches" << endl;
    while(true){
        for (int i=0;i<count;i++){
            cout << array[i];
        }
        cout << endl;
        cout << "waiting for next letter " << endl;
        cin >> letter;
        array[count]=letter;
        count++;
        if(count>=arrlength){
            arrayboost(array,arrlength);
        }
        
        
        char *p = new char[count]; //putting the bigger array into a perfect fit array
        //enteredwords[count]=*p;
        for (int j=0;j<count;j++){
            p[j]=array[j];//or *(p+j)=array[j] array/pointer duality
        }
        string *d = new string[diclength]{"NULL"};
        findwords(p,count,d,diclength);
        if (*d=="NULL"){
            cout << " There are no more word matches :( " << endl;
            break;
        }
        delete[] p;
        
        
    }

    
    //modularity, array contents, inside while loop, check each word in the dictionary.txt for match
    
}
