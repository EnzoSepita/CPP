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

template<class A, class B>
void read_file_to_cont(std::ifstream& f, B& c) {
    A v;
    f.get();
    if constexpr(std::is_same<A, char>::value){
        while(f.get(v))
        {
            c.push_back(v);
            f.get();
        }
    }
    else {
        while (f >> v) {
            c.push_back(v);
        }
    }
}

template<class A, class B>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    B c = {};
    read_file_to_cont<A, B>(fi, c);
    if constexpr (std::is_same<A, int>::value){
        my_selection_sort(c.begin(),c.end(),[](int a, int b){
            if((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1))
                return a <= b ? 1 : 0;
            if (a % 2 == 0 && b % 2 == 1)
                return 1;
            if (a % 2 == 1 && b % 2 == 0)
                return 0;
            return 0;
        });
    }
    else {
        my_selection_sort(c.begin(), c.end(), [](A a, A b) {
            return a >= b;
        });
    }
    for (auto &v : c) {
        fo << v << std::endl;
    }
}

template<class C>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char container_type;
  fi >> container_type;
  fo << container_type << std::endl;
  switch (container_type) {
    case 'l':
      read_and_sort<C, std::list<C>>(fi, fo);
      break;
    case 'v':
      read_and_sort<C, std::vector<C>>(fi, fo);
      break;
    case 'd':
      read_and_sort<C, std::deque<C>>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown container");
  }
}


void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  char value_type;
  fi >> value_type;
  fo << value_type << std::endl;
  switch(value_type) {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      break;
    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
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
    default:
      throw std::runtime_error("Unknown value type");
  }
}
