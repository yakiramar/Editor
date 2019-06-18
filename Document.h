/* Yakir Amar 204590095 */
using namespace std;
// #include "Editor.h"
#include<string>
#include <vector>
#include <iostream>
#include <cstdlib> 

class Document {
    vector<string> lines;//all the lines in the file that we want to save
    int currentLine;// save the current line 
public:
    Document();//constructor
    void a();// append new text after the current line and update the currentLine
    void p();//print the current line
    void n();//prints line number of current line followed by TAB followed by current line
    void i();//append new text before the current line and update the currentLine
    void c();//changes the current line for text that follows
    void d();//deletes the current line 
    void oneSlash(string line);//searches forward after current line for the specified text and print this line.
    void treeSlash(string line);//replaces old string with new in current line
    void changeLine(string num);//change the current line to the number and print this line
    void printDocument();//print all the document that we save.
    
};
