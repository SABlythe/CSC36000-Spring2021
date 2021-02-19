#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  int  myArray[] = {42, 666, 99, -7, 0 , 101};

  for (int &s:myArray)
    {
      if (s<=0) 
	s=2020;
    }
  for (int s:myArray)
    cout << s << endl;
  
  return 0;
}
