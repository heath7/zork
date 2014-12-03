
#include <string>
#include "Item.cpp"

class Game {

typedef Border
{
  char direction;
  Room* room;  
}border;

 public:
  Room(const String &tempName, String &description);
  
  void addBorder(const string &dir, Room* const borderRoom);
  void addItem(const Item &item);
  void removeItem(string itemName);
  Room* const getNextRoom(const string &dirName);

  String getDescription();
  String getName();
  String getType();

 private:
  vector<Item> items;
  vector<border> borders;






}
