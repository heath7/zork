#include "Attack.h"
#include <iostream>
#include <string>
using namespace std;

Attack::Attack()
{
  object = "";
  print = "";
  status = "";
}


string Attack::getStatus()
  {
    return status;
  }

  void Attack::setStatus(string newStatus)
  {
    status = newStatus;
  }
 
 string Attack::getObject()
  {
    return object;
  }

  void Attack::setObject(string newObject)
  {
    object = newObject;
  }
 

 string Attack::getPrint()
  {
    //std::cout << print << std::endl;
    return print;
  }

  void Attack::setPrint(string newPrint)
  {
    print = newPrint;
    // std::cout << print << std::endl;

  }
