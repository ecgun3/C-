#include <iostream>
using namespace std;

size_t find(const string &str,const string &toFind);

int main()
{
     string str = "They are sitting there!";
     string toFind = "there";

     if(find(str,toFind)!=string::npos)
          cout<<"The word '"<<toFind<<"' is found at: "<<find(str,toFind)<<endl;
     else 
          cout<<"The word is not exist in string."<<endl;
     
     return 0;
}

size_t find(const string &str,const string &toFind)
{
     size_t i,j;
     for(i=0;i<str.size();i++)
     {
          for(j=0;j<toFind.size();j++)
               if(str[i+j]!=toFind[j])
                    break;
          if(j==toFind.size())
               return i;
     }
     return string::npos;
}