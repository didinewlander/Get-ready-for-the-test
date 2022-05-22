/*
In this file you'll find - basic program structure and how to use the various types of variables and commands and functions in c++.
We will create a basic math and letter distance calculator using all basic concepts to start with c++
After those functions we'll run the fibonacci sequence using the result given by the rounded sqrt product of the multiplication of x and y
*/

#include <iostream> // for input-output usage
#include <cmath> // for the absolute value function
using namespace std; // for the general output functions

/*in this section i'll declare all the functions related for my program and define them after the main*/
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
float divide(int x, int y, float div);
int fibo(int x);
int charDistance (char a, char b); // for finding the distance between two characters

/*
instead of using a bunch of numbers, set the numerical value to a word
and when using it in the program, the compiler will exchange the keywords with actual numbers as set in the enum
*/
enum SELECT {math = 1, distnce = 2};
int main()
{
  // variables that would be useful for the program. NOT ALWAYS USEFUL - BE MEMORY FRIENDLY
  int x=0, y=0, select; // use unique names for your variables. x and y are common in math, and calling the selection variable 'select' makes it much easier to follow along
  char a, b;
  float divideResult; // give it a name that makes sense
  cout << "Welcome to the multi-calculator.\n 1- math calculator 2 - char distance 0 - exit" << endl; // let the user to know what you're planing to do.
  cin >> select;
  while (select < 0 || select > 2) // selection validation test
  {
    cout << "error. select again." <<endl;
    cin >> select;  
  }
  while (select) // the loop will run if different from 0
  {
    switch(select) // cases based on user's selection
    {
      case math: // as we defined with the enum at the begining of the program - we can use names to represent numerical values
        {
          cout << "enter two numbers" << endl;
          cin >> x >> y; // once the user hits 'enter' it will collect a new value.
          /* a different way for the same purpose:
            char junk;
            cin >> x >> junk >> y;
          this way the user can just hit the spacebar, without going all the way to 'enter'
          */
          cout << add(x,y) << " " << subtract(x,y) << endl << multiply (x,y) << " " << divide(x,y, divideResult) << endl; // seperate values with spaces
          cout << "the absolute value of the division is " << abs(divideResult) << endl; // make sure you balance between readability and minimizing your code lines
          // we could've seperate every output to it's own command, but sometimes it makes the program look less intriguing.
        }
        break; // the program will jump to the next class if you won't break the section
      case distnce:
        {
          cout << "enter two characters" << endl;
          cin >> a >> b; // lookup line 43 for different method for this input
          cout << "the distance between the characters is: " << charDistance (a,b) << endl;
        }
        break;
      default: break;
    }
    cout << "select again. 0 - exit, 1 - math, 2 - distance"<< endl; // repeate user selection to avoid the loop taking over
    cin >> select;
    while (select < 0 || select > 2)
    {
      cout << "error. select again \n";
      cin >> select;  
    }
  }
  cout << fibo (sqrt(multiply (x,y))); // beware to not create a endless loop, and make sure all values are intialized to some value at the start of the program
  return 0; // exiting a int function always required a
}

int add(int x, int y) { return x+y; }
int subtract(int x, int y) { return x-y; }
int multiply(int x, int y) { return x*y; }
float divide(int x, int y, float div)
{
  div = ((float)x/y); // casting a float data-type on an integer, so the division will accurate to the result we are looking for
  return div;
}
int charDistance (char a, char b)
{
  int distance = abs(a-b); // if we think about it, the distance between two things has to be a positive value, because we need to give the user a reasonable answer
  return distance;
}
int fibo(int n)
{
 if (n<=1) return n;
  return fibo(n-1) + fibo (n-2);
}

/* CODE EXAMPLE:
Welcome to the multi-calculator.
 1- math calculator 2 - char distance 0 - exit
1
enter two numbers
6
12
18 -6
72 0.5
the absolute value of the division is 0
select again. 0 - exit, 1 - math, 2 - distance
2
enter two characters
5
Y
the distance between the characters is: 36
select again. 0 - exit, 1 - math, 2 - distance
0
21

*/
