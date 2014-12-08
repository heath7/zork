#ifndef ATTACK_H_
#define ATTACK_H_
#include <string>
#include <vector>
#include <iostream>

using namespace std;
//using namespace rapidxml;


class Attack {
public:
  Attack();
  string getPrint();
  string setPrint(string newPrint);

  string getObject();
  string setObject(string newObject);

  string setStatus(string newStatus);
  string getStatus();
  
 private:
  string status;
  string object;
  string print;
};

#endif
