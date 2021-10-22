#include <iostream>
#include "funcs.h"
#include <cctype>
#include <fstream>


std:: string removeLeadingSpaces(std:: string line){
  bool x = false;
  std:: string result;
    for(int i =0; i <line.length(); i++){
      if(isspace(line[i])==false){
        x=true;
      }
      if(x==true){
        result+=line[i];
      }
    }
    result+="\n";
    return result;
}
int countChar(std::string line, char c){
  int counter;
  for(int i =0; i<line.length();i++){
    if(line[i]==c){
      counter++;
    }
  }
  return counter;
}
std:: string indent(std:: string x){
  std:: string result;
  std:: string line;
  std::fstream fin;
  int tabs=0;
  fin.open(x);
  while(std::getline(fin,line)){
    line=removeLeadingSpaces(line);
    int count1=countChar(line,'{');
    int count2=countChar(line,'}');
    if(line[0]=='}'){
      tabs--;
      count2--;
    }
    for(int i =0; i<tabs;i++)
      line="\t"+line;
    tabs+=count1;
    tabs-=count2;
    result+=line;
  }
  fin.close();
  return result;
}
std:: string unindent(std:: string x){
  std:: string result;
  std:: string line;
  std::fstream fin;
  fin.open(x);
  while(std::getline(fin,line)){
    result+=removeLeadingSpaces(line);
  }
  fin.close();
  return result;
}
