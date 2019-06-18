/* Yakir Amar 204590095 */
using namespace std;
#include "Document.h"
#include "string"
#include <iostream>
#include <fstream>
#include <stdio.h>
class Editor {
    Document document;//field in Editor type that contain all the string that we need to save and current line
public:
    Editor();//constructor
    void loop();//we call loop from the main
    bool isNumber(string line);//function that return true if the input is a number
    int howManySlash(string line);//return how many slash in the line, halp us classify /text and s/old/new/ coomand
    
    
};