#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifndef STREAM_H_INC
#define STREAM_H_INC

void find_ifstream(string filename, ifstream &data_file) {
  data_file.open(filename);

  while (!data_file) {
    data_file.close();
    data_file.clear();
    cout << "No file try again \n";
    getline(cin, filename);
    data_file.open(filename);
  }
  return;
}

void find_ofstream(string filename, ofstream &data_file) {
  ifstream input;
  find_ifstream(filename, input);
  input.close();
  data_file.open(filename);
  return;
}
#endif
