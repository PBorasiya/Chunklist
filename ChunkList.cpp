#include "ChunkList.h"
struct NodeType
{
    ItemType info[];
    NodeType* next;
    int size;
};

ChunkList::ChunkList(){
  length = 0;
  listData = NULL;
}

bool ChunkList::IsFull() const{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

int ChunkList::GetLength() const
{
  return length;
}

void ChunkList::MakeEmpty(){
  NodeType* tempPtr;

    while (listData != NULL)
    {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
  }
  length = 0;
}
void ChunkList::PutItem(ItemType item){
  NodeType* location;

  location = new NodeType;
  location->info[size] = item;
  location->next = listData;
  listData = location;
  length++;
  size++;
}

ItemType ChunkList::GetItem(ItemType& item, bool& found)
{
  bool moreToSearch;
  NodeType* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    for(int i=0;i<8;i++)
    switch (item.ComparedTo(location->info[i]))
    {
      case LESS    :
      case GREATER : location = location->next;
                     moreToSearch = (location != NULL);
                     break;
      case EQUAL   : found = true;
                     item = location->info[i];
                     break;
    }
  }
  return item;
}

 void ChunkList::DeleteItem(ItemType item){
  NodeType* location = listData;
  NodeType* tempLocation;

 for(int i=0;i<8;i++){
  if (item.ComparedTo(listData->info[i]) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next;
  }
  else
  {
    while (item.ComparedTo((location->next)->info[i]) != EQUAL)
      location = location->next;


    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}
 }
void ChunkList::ResetList()

{
  currentPos = NULL;
}

ItemType ChunkList::GetNextItem()
{
  ItemType item;
  for(int i=0;i<8;i++){
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info[i];
  return item;
}
}

ChunkList::~ChunkList()
{
  NodeType* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}
