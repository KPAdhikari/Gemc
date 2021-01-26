//http://www.cplusplus.com/reference/map/map/find/ (kpa: I modified the example from here. )
/*
To compile c++11 with g++:
        g++ -std=c++11 your_file.cpp -o your_program 
                or
        g++ -std=c++0x your_file.cpp -o your_program

We can also run it without compilation hassles at http://cpp.sh/
*/
// map::find
#include <iostream>
#include <map>

using namespace std;
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  std::cout << mymap.find('b')->first<<" => " << mymap.find('b')->second << '\n';
  std::cout << prev(mymap.find('b'),1)->first<<" => " << prev(mymap.find('b'),1)->second << '\n';
  std::cout << next(mymap.find('a'),2)->first<<" => " << next(mymap.find('a'),2)->second << '\n';
  std::cout << mymap.cbegin()->first<<" => " << mymap.cbegin()->second << '\n';
  std::cout << prev(mymap.cend(),1)->first<<" => " << prev(mymap.cend(),1)->second << '\n';
  std::cout << prev(mymap.cbegin(),1)->first<<" => " << prev(mymap.cbegin(),1)->second << '\n';


  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << mymap.find('a')->first<<" => " << mymap.find('a')->second << '\n';
  std::cout << mymap.find('c')->first<<" => " << mymap.find('c')->second << '\n';
  std::cout << mymap.find('d')->first<<" => " << mymap.find('d')->second << '\n';
  std::cout << mymap.find('b')->first<<" => " << mymap.find('b')->second << '\n';

  return 0;
}

