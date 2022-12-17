#include <iostream>
#include <list>

#define ROWS 5
#define COLUMNS 5

struct Data {
  int col;
  int row;
  int value;
};

void printList(const std::list<Data>& sparseList) {
  for (auto it = sparseList.begin(); it != sparseList.end(); it++) {
    std::cout << "Col = " << (*it).col << "; Row = " <<  (*it).row << "; Value = " << (*it).value << std::endl;
  }
}

int main() {
  int sparseMatrix[ROWS][COLUMNS] = {
    { 0, 0, 6, 0, 0  },
    { 0, 0, 9, 0, 0  },
    { 0, 0, 0, 2, 0  },
    { 0, 10, 4, 0, 0  },
    { 0, 7, 0, 0, 8  },
  };

  std::list<Data> sparseList = std::list<Data>();

  for (int i = 0; i < ROWS; i++) {
    for ( int j = 0; j < COLUMNS; j++) {
      if (sparseMatrix[i][j] != 0) {
        sparseList.push_back(Data{
          .col = i,
          .row = j,
          .value = sparseMatrix[i][j]
        });
      }
    }
  }

  printList(sparseList);
  
  return 0;
}
