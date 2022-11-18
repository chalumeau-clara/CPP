// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful

// Push the element into the container
template <class type, class cont>
void read_file_to_cont(std::ifstream& f, cont& c) {
    type elm;
    while (f >> elm) {
        c.push_back(elm);
    }

}

template <class type, class cont>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    cont container = {};
    read_file_to_cont<type, cont>(fi, container);
    my_selection_sort(container.begin(), container.end());
    for (type &elm : container)
        fo << elm << std::endl;
}

// Second decide the container type
template <class type>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char secondLine;
  fi >> secondLine;
  fo << secondLine << std::endl;
  switch(secondLine)
  {
      case 'l':
          read_and_sort<type, std::list<type>>(fi, fo);
          break;
      case 'v':
          read_and_sort<type, std::vector<type>>(fi, fo);
          break;
      case 'd':
          read_and_sort<type, std::deque<type>>(fi, fo);
          break;
  }
}

// First decide value type
void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char firstLine;
    fi >> firstLine;
    fo << firstLine << std::endl;
    switch(firstLine)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned >(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
    }
}



