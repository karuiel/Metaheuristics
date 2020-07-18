#ifndef __DATA_CONTAINER_H__
#define __DATA_CONTAINER_H__

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <locale>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#define MAX_STREAM numeric_limits<streamsize>::max()

/*
 *  Class to define a 'locale' feature for ifstream to treat '@' , '%', '\''
 *  and ',' like tokens. This simplifies reading the arff files.
 */
class my_ctype : public std::ctype<char> {
  mask my_table[table_size];
public:
  my_ctype(size_t refs = 0) : std::ctype<char>(&my_table[0], false, refs) {
    std::copy_n(classic_table(), table_size, my_table);
    my_table[','] = (mask)space;
  }
};
using namespace std;

//=============================================================================
// E X A M P L E
//=============================================================================

struct Example {
  vector<float> data;
  string class_name = "";

  Example &operator=(const Example &other);
  inline float operator[](const unsigned i) { return data.at(i); };
  inline float operator[](const unsigned i) const { return data.at(i); };
  inline unsigned int Size() { return data.size(); }
  inline unsigned int Size() const { return data.size(); }
};

//=============================================================================
// E X A M P L E   C O N T A I N E R
//=============================================================================

struct ExampleContainer {
  vector<Example> example_vector;
  string db_name;
  map<string, vector<unsigned int>> class_index;

  ExampleContainer &operator=(const ExampleContainer &other);
  inline Example operator[](const unsigned i) { return example_vector.at(i); };
  inline Example operator[](const unsigned i) const {
    return example_vector.at(i);
  };
  void PushBack(const Example &other);
  void ReadData(const string &path);
  inline unsigned int Size() { return example_vector.size(); };
  inline unsigned int Size() const { return example_vector.size(); };
};

#endif
