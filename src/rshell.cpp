#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <pwd.h>

using namespace std;
using namespace boost;

void user_prompt()
{
  string input;
  
  if (getlogin() != NULL)
  {
    cout << getlogin() << "@";
  }
  
  char servername[64] = {0};
  
  if (gethostname(servername, 64) != -1)
  {
    gethostname(servername, 64);
    cout << servername << " ";
  }
    cout <<"$ ";
}

void parse_commands(vector<string> &vec, const string &str)
{
  //takes in a vector of strings and a string (used in the delimmiter)
    
   typedef tokenizer <char_separator<char> > tokenizer;
   char_separator<char> delimiter(" ", ";&|#"); //space is the thing ignored. the other arguments are things that /stay/
   //the delimiter defines characters to be "ignored" in boost parsing
   
   tokenizer tokens(str, delimiter); //spaces are now ignored
   
   //the commands themselves are now inserted into a vector
   //tokens use iterators, but so auto is used for simplicity
   for (auto it = tokens.begin(); it != tokens.end(); it++) 
   {
     if(*it == "#")
     {
       break; //comment detected (used for killing beginning comments)
     }

     vec.push_back(*it);
     //cout << (*it) << endl;
   }
}

void parse_separators(vector<string> &new_vec, vector<string> &v2, vector<vector<string>> &commandpacks, vector<string> &commands)
//vectorseparators , vectorcommands, commands separated, commands individual
{
  //pushes back everything that isn't a connector currently
  //cout << "Hello" << endl;
  //the vector from parsecommands is passed into here
  //the separators are now in their own vector (new_vec)
  
  //while a connector is not found when iterating, concatinate the elemends I have
  //when I find an element, I push back everything together
  //then I clear the temporary variable
  //stop when I reach the end of the vector

  //string s = "";
  
  for(int i = 0; i < v2.size(); i++)
  {
    //cout << "Hello" << endl;
    if (i == v2.size() - 1)
    {
      commands.push_back(v2.at(i));
      new_vec.push_back(v2.at(i));
      commandpacks.push_back(commands);
    }
    
    else if(i > 0 && ((v2.at(i) == ";") || (v2.at(i) == "&" && v2.at(i-1) == "&") || (v2.at(i) == "|" && v2.at(i-1) == "|" ) || (v2.at(i) == "#")))
    {
        //s += v2.at(i) + " ";
        new_vec.push_back(v2.at(i));
        commandpacks.push_back(commands);
        commands.clear(); //clears it for future use
    }
    
    else if ((v2.at(i) != "&" && v2.at(i) != "|"))
    {
      commands.push_back(v2.at(i));
    }
      //cout << v2.at(i) << endl; 
  }

    //else
    //{
      //new_vec.push_back(s);
      //s = "";
    //}
}




bool exit_terminal(vector<vector<string>>& v3, int pos)
{
  if(v3.at(pos).at(0) == "exit") // checks the vector inserted if it contains "exit"
  {
    return true; //if true, then break out of the while loop and end the program
  }
  return false; //otherwise the looping continues
}
  
bool exec_check(vector<char*> &input)
{
  int c_pid = fork();
  int status;
  
  //if c_pid is less than 0, the child is an error
  // "zombie" process : -1
  if (c_pid < 0)
  {
    perror("Error: The Fork Failed");
    exit(1);
  }
  
  //if c_pid is equal to 0 then the child
  else if (c_pid == 0)
  {
    //cout << "Hello" << endl;
    if (execvp(input.at(0), &(input[0])) == -1)
    {
      perror("Error: Exec Failed");
      exit(1);
    }
    exit(0);
  }
  
  else if (c_pid > 0)
  {
    if(wait(&status) == -1)
    {
      perror("Error: Wait Failed");
    }
    if(status != 0)
    {
      return false;
    }
  }
  return true;
}


//takes in a vector of commands (including separators)
//scans the connectors
//status comes from the exec check
//execvp returns -1 (failed) or anything else (didn't fail)

//vector with commands
//this checks if I go on (true) or not (false) in order to do the while loop for execvp again
bool connector_test(bool status, vector<string> &v4, int j)
{
  if(v4.size() <= j)
  {
    return false;
  }

  if(v4.at(j) == "&") //if true, go ahead and execvp again
  {
    return status;
  }
    
  else if(v4.at(j) == "|") //if false execvp again
  {
    return !status;
  }
    
  else if(v4.at(j) == ";") //keep going for execvp again
  {
    return true;
  }
    
  else if(v4.at(j) == "#")
  {
    return false; //quits reading, so no need for break
    //break;
  }
    
  else
  {
    return false;
  }
}

void string_char_conversion(vector<string> &v5, vector<char*> &new_vec2)
{
  char* s2;
  for(int k = 0; k < v5.size(); k++)
  {
    s2 = new char[v5.at(k).size() + 1];
    memcpy(s2, v5.at(k).c_str(), v5.at(k).size() + 1);
    new_vec2.push_back(s2);
  }
  new_vec2.push_back('\0');
}


int main()
{
  //cout << "Hello World" << endl; //testing
  while(true) //the shell is an infinite loop until it exits (breaks)
  {
    vector<string> vector_input; //parses the commands
    vector<string> vector_input2; //parses separators
    vector<string> commands; // second command vector
    vector<vector<string>> commandpacks; // 2D Vector
    vector<char*> char_vector; // contents of vector_input but converted
    string input; //user input
    bool exec = false;
  
    user_prompt(); //user_prompt works
    getline (cin, input);
    parse_commands(vector_input, input);
    //cout << "Hello World" << endl;
    
    
    while(!vector_input.empty())
    { 
      //vector_input2 is currently empty (inserts contents from vector_input)
      //vector_input2 now has no separator, execvp analyzes these.
      parse_separators(vector_input2, vector_input, commandpacks, commands);
      for (int i = 0; i < commandpacks.size(); i++)
      {
        if(exit_terminal(commandpacks,i))
        {
          return 0;
        }

        string_char_conversion(commandpacks.at(i), char_vector);
        exec = exec_check(char_vector); //execvp -1 or anything else
        
        if(connector_test(exec, vector_input2, i) == false)
        {
          break;
        }
        
        char_vector.clear();
      }
      vector_input.clear();
    }
  }
  return 0;
}

//NOTES:

//execvp(command, flag) - ls -a, etc.
//put the first command
//ls -a && echo a

//ls
//-a
//execvp reports if error or not - stores the number

//the connectors have to be handled manually right
//&
//&
//after the connectors - look if it's NOT an error (-1) or whatever I store
//if that's the case, then do it again for echo A

//echo
//a
//execvp - takes a single command and does it
//it does NOT recognize separators


//while loop that goes through exec check again


//execvp return value is -1 if it's command failed
//if it did work, and I have an && separator then I go on
//if it DIDN'T work, then I stop.

//It's the OPPOSITE for ||

//semi colon just goes on

// # breaks it

