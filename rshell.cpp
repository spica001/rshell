#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <vector>

//FIRST PUSH - still buggy etc

using namespace std;

int min2(int a, int b)
{
  if (a < 0)
  {
    return b;
  }
  if (b < 0)
  {
    return a;
  }
  
  if(a < b)
  {
    return a;
  }
  else
  return b;
}

// returns the least of three numbers
int min3(int a, int b, int c)
{
  if(a < 0)
  {
    return min2(b,c);
  }
  
  if(b < 0)
  {
    return min2(a,c);
  }
  
  if(c < 0)
  {
    return min2(a,b);
  }
  
  if(a < b)
  {
    if(a < c)
    {
      return a;
    }
    else 
    return c;
  }
  else if(b < c)
  {
    return b;
  }
  else
  return c;
}



int main()
{
 // ; , || and &&
 // look for each of them to check
 
  string input;
  string com; //individual commands from the vector
  int semicolon = 0;
  int bar = 0;
  int ands = 0;
  int sharp = 0;
  int start = 0; //location of the string as the loop moves along.
  int otherStart = 0; // stores the old value of start.
  vector<string> commands; //vector to store the commands inside.
  const vector<char*> execcommands;
  
  
  while(true) // want infinite loop until break
  {
    
	  cout <<"$ ";
	  getline (cin, input);
     
    sharp = input.find("#", start);
    input = input.substr(0, sharp); //this gets everything from 0 to before sharp - so this is the input?
  
    
     
 
   while(true)
   {
      //these finds are used to get the commands
      semicolon = input.find(";",start);
      bar = input.find("||",start);
      ands = input.find("&&",start);
      
  
      //cout << min3(semicolon,bar,ands) << endl; - testing purposes
    
      start = min3(semicolon,bar,ands)+1;
      
      if(input[start] == '#' || input[otherStart] == '#')
      {
        break;
      }
      
      
      
      if(input[otherStart] == '|' || input[otherStart] == '&')
      {
        otherStart+=1; //if the current start has a non-semicolon
      }
      com = input.substr(otherStart,(start-otherStart-1)); //start-1 because it would include the separators
      commands.push_back(com);
      
    
      otherStart = start; //otherstart now becomes the position of Start, which is used for the next iteration
      
      if(start == 0)
      {
        break;
      }
   }
      
   for(int i = 0; i != commands.size(); i++)
   {
     cout << commands.at(i) << endl;
   }
   
  //syscall stuff
  
  for(int j = 0; j != commands.size() ; j++)
  {
    char* temp = const_cast <char*> (commands.at(j).c_str());
    char* args[2] = {temp, NULL};
    pid_t c_pid, pid;
    int status;

    c_pid = fork();
  
    if( c_pid < 0)
    {
      perror("fork failed");
      exit(1);
    }

    else if (c_pid == 0)
    {
      printf("Child: executing j\n");            
      execvp(args[0], args);                                             
      perror("execvp failed");
    }
    
    else if (c_pid > 0)
    {
      if((pid = wait(&status)) < 0)
      {
        perror("wait");
        exit(1);
      }

      printf("Parent: finished\n");

    }
    
   }
}
    //ls; mkdir directory; cd directory; touch myfile.txt; ls
  return 0;
}




