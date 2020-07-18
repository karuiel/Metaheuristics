#include "data_container.h"
#include <iostream>
#include <regex>

using namespace std;

//=============================================================================
// E X A M P L E
//=============================================================================

Example &Example::operator=(const Example &other) {
  if (this != &other) {
    data = other.data;
    class_name = other.class_name;
  }
  return *this;
}

//=============================================================================
// E X A M P L E   C O N T A I N E R
//=============================================================================

ExampleContainer &ExampleContainer::operator=(const ExampleContainer &other) {
  if (this != &other) {
    example_vector = other.example_vector;
    db_name = other.db_name;
    class_index = other.class_index;
  }
  return *this;
}

//=====================================

void ExampleContainer::PushBack(const Example &other) {
  class_index[other.class_name].push_back(example_vector.size());
  example_vector.push_back(other);
}

//=====================================

void ExampleContainer::ReadData(const string &path) {

  ifstream f_in(path.c_str());
  if (!f_in) {
    fprintf(stderr, "%s\n", path.c_str());
    perror("Error oppening file");
    exit(EXIT_FAILURE);
  }
  locale x(locale::classic(), new my_ctype);
  f_in.imbue(x);
  string param;
  string param_type;
  f_in >> param;

  unsigned number_of_attr = 0;
  unsigned class_position = 0;
  string line = "";
  // scape until database db_name
  while (!regex_match(param, regex(".*(RELATION)|(relation).*"))) {
    f_in.ignore(MAX_STREAM, '@');
    f_in >> param;
  }

  f_in.ignore(MAX_STREAM, ' ');

  // read database db_name
  getline(f_in, db_name);
  // read number of atributes and class index
  // {{{
  while (!regex_match(line, regex(".*(attribute|ATTRIBUTE).*"))) {
    getline(f_in, line);
  }
  do {
    if (regex_match(line, regex(".*\\{.*\\}.*")))
      class_position = number_of_attr;
    else {
      ++number_of_attr;
    }
    getline(f_in, line);
  } while (regex_match(line, regex(".*(attribute|ATTRIBUTE).*")));


  // }}}

  while (!regex_match(line, regex(".*(([Dd]ata)|DATA).*")))
    getline(f_in, line);

  // after @data

  unsigned examples_number = 0;
  std::string unused;

  // get number of examples
  //{{{
  int pointer = f_in.tellg();

  while (!f_in.ignore(MAX_STREAM, '\n').eof())
    ++examples_number;

  f_in.seekg(pointer, f_in.beg);
  //}}}

  example_vector.resize(examples_number);

  Example exp;
  string class_name;
  unsigned int actual_example = 0;
  vector<float> aux_caracteristics(number_of_attr, 0.0);

  while (actual_example < examples_number) {

    for (unsigned i = 0, actual_attr = 0; i <= number_of_attr; ++i)
      if (i == class_position) {
        f_in >> class_name;
        exp.class_name = class_name;
        class_index[class_name].push_back(actual_example);
      } else
        f_in >> aux_caracteristics.at(actual_attr++);

    exp.data = aux_caracteristics;

    example_vector.at(actual_example++) = exp;
  }

  while (!f_in.ignore(MAX_STREAM, '\n').eof());

    
}
