#include "Attack.h"
#include <iostream.h>
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

  string Attack::setStatus(string newStatus)
  {
    status = newStatus;
  }
 
 string Attack::getObject()
  {
    return object;
  }

  string Attack::setObject(string newObject)
  {
    status = newObject;
  }
 

 string Attack::getPrint()
  {
    return object;
  }

  string Attack::setPrint(string newPrint)
  {
    print = newPrint;
  }