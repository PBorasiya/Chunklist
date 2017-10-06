
#include <fstream>
const int MAX_ITEMS = 8;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
private:
  int value;
};
