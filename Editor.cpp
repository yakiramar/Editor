/* Yakir Amar 204590095 */
#include "Editor.h"

Editor::Editor(){

}

bool Editor::isNumber(string line){
    for (int i = 0; i < line.length(); i++) 
        if (isdigit(line[i]) == false) 
            return false; //if one of the char is't a number we return false.
  
    return true; 
}
int Editor::howManySlash(string line){
    int count = 0;
    for (int i = 0; i < line.size(); i++)
    if (line[i] == '/') count++;//if we find slash count++

   return count;
}


void Editor:: loop(){
    string line;
    while (getline(cin, line)){//input line by line fron input.txt
    
        if(line=="p"){document.p();}// case "p": prints the current line
        if(line=="n"){document.n();}// case "n": prints line number of current line followed by TAB followed by current line
        if(line=="%p"){document.printDocument();}// case "%p": prints all lines
        if(isNumber(line)){document.changeLine(line);}// case isNumber: change the current line to the number and print this line
        if(line=="a"){document.a();}//case "a": appends new text after the current line
        if(line=="i"){document.i();}// case "i": inserts new text before the current line
        if(line=="c"){document.c();}// case "c": changes the current line for text that follows
        if(line=="d"){document.d();}// case "d": deletes the current line
        if(howManySlash(line)==1){document.oneSlash(line);}// case howManySlash==1: searches forward after current line for the specified text. 
        //The search wraps to the beginning of the buffer and continues down to the current line, if necessary
        if(howManySlash(line)==3){document.treeSlash(line);}// case howManySlash==2: replaces old string with new in current line
        if(line=="Q"){break;}// case "Q": Quits the editor without savingwe need to stop
    
    
    }
   
  
}