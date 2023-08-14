#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "input_prot.h"
#include "map.h"
#include "stream.h"
using namespace std;

class concordance {
 public:
  long occurences;
  vector<string> contexts;
  concordance() {
    occurences = 0;
    contexts = {};
  }
  void add_context(string context) { contexts.push_back(context); }
  void add_occurence() { occurences++; }
  bool operator!() { return !occurences ? false : true; }
};
ostream& operator<<(ostream& out, const concordance& p) {
  out << "this word occured " << p.occurences << " times\n";
  for (const auto& context : p.contexts) {
    out << "    " << context << '\n';
  }
  return out;
}

void generate_concordance(ostream& concordance_generation, istream& text,
                          Map<string, concordance>& map, long& words) {
  vector<string> exception = {};
  char choice;
  string input, context;
  streampos initial, after;
  choice = input_prot("\nDo you need to type exception(s)\n", "\ntry again\n",
                      "ynYN");
  while (choice != 'n' && choice != 'N') {
    cin >> input;
    exception.push_back(input);
    choice = input_prot("\nWould you like to type more exception(s)?\n",
                        "try again", "ynYN");
  }

  while (!text.eof()) {
    initial = text.tellg();
    text >> input;
    words++;
    after = text.tellg();
    if (find(exception.begin(), exception.end(), input) ==
        exception.end())  // input is not an exception
    {
      map[input].add_occurence();  // add occurance
      text.seekg(initial);
      getline(text, context);           // get context;
      map[input].add_context(context);  // add occurance

      text.seekg(after);
      text >> ws;
    }

    text.peek();
    input = "";
  }
  text.clear();
  map.print(concordance_generation);
}

bool contains(string input, vector<string>& exceptions) {
  size_t pos = 0;
  bool result = false;
  while (pos < size(exceptions) && !result) {
    result = exceptions[pos] == input;
    pos++;
  }
  return result;
}

int main() {
  vector<string> exception = {};
  ifstream text;
  ofstream concordance_generation;
  Map map = Map<string, concordance>(1000);
  char choice;
  string input;
  char context[20];
  long total_words = 0;

  cout << "Welcome to concordance program!\n";
  choice = input_prot("\nWould you like to rebuild a concordance?\n",
                      "\ntry again\n", "ynYN");
  if (choice == 'y' || choice == 'Y') {
    cout << "\nEnter name of Concordance file:\n";
    cin >> input;
    find_ofstream(input, concordance_generation);
    cout << "\nEnter input text file:\n";
    cin >> input;
    find_ifstream(input, text);
    cout << "Generating Concordance";
    generate_concordance(concordance_generation, text, map, total_words);
  } else {
    cout << "\nEnter name of new Concordance file:";
    cin >> input;
    concordance_generation.open(input);
    cout << "\nEnter input text file:\n";
    cin >> input;
    find_ifstream(input, text);
    cout << "Generating Concordance";
    generate_concordance(concordance_generation, text, map, total_words);
  }
  concordance_generation.close();
  text.close();

  while (choice != '2') {
    choice = input_prot("\n1)Search for word\n2)Quit\n", "try again", "12");
    if (choice == '1') {
      cout << "Type in word: ";
      cin >> input;
      cout << "\n" << map[input];
    }
  }
}
