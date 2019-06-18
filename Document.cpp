/* Yakir Amar 204590095 */
#include "Document.h"

Document::Document(){
    currentLine=-1;

}
//return -1 if s1 is not substring of s2 and another number if yes
int isSubstring(string s1, string s2){
    int M = s1.length(); 
    int N = s2.length(); 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 
// a command
void Document::a(){
    string line;
    while(getline(cin, line)){
        if(line=="."){break;}//we want to appent until we see  "." 
        lines.insert(lines.begin()+currentLine+1,line);
        currentLine++;//update the currentLine
      }
    
}
// p command
void Document::p(){
    cout << lines[currentLine] << endl;
}
// %num command
void Document::changeLine(string num){
    currentLine=atoi(num.c_str());//convert the string to int
    currentLine=currentLine-1;// because the lines start from 0
    cout << lines[currentLine] << endl;
}
// n command
void Document::n(){
    cout << currentLine+1 << "  "<< lines[currentLine] << endl;
}
// i command
void Document::i(){
    string line;
    while(getline(cin, line)){
        if(line=="."){break;}  
        lines.insert(lines.begin()+currentLine,line);
        currentLine++;
    }
    
}
// c command
void Document::c(){
    string line;
    while(getline(cin, line)){
        if(line=="."){break;}
        lines[currentLine]=line;
    }
}
// d command
void Document::d(){
    auto i=lines.begin()+currentLine;//we use auto to get access to the vector
    lines.erase(i);//delet the currentLine
    
}
// /text command
void Document::oneSlash(string line){
    string word=line.substr(1,line.length()-1);
    int res;
    for(int i=0;i<lines.size();i++){
        res=isSubstring(word,lines[i]);
        if(res!=-1){cout<<lines[i]<<endl;}
        
        
    }
    
}
// s/old/new/ 
void Document::treeSlash(string line){
    //first we want to find the old and the new word
    int start=2,end=2,i=3;
    while(line[i]!='/'){
        end++;
        i++;
    }
    string oldWord=line.substr(start,end-1);
    i++;
    start=end+2;
    end=0;
    while(line[i]!='/'){
        end++;
        i++;
    }
    string newWord=line.substr(start,end);
   //now we want to switc the old with the new one.
    int res;
    for(i=0;i<lines.size();i++){
       res=isSubstring(oldWord,lines[i]);
       if(res!=-1){
           size_t found=lines[i].find(oldWord);
           lines[i].replace(found, oldWord.length(), newWord);
       }
       
    }
   
}
// %p command
void Document::printDocument(){
    for(int i=0;i<lines.size();i++){
        cout << lines[i] << endl;
    }
}