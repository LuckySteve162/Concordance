#include "input_prot.h"

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

// between 2 bounds
long input_prot(const char prompt[], const char error_message[], long lower,
                long upper) {
  cout << prompt;
  long input;

  cin >> input;

  while (input < lower || input > upper) {
    cout << error_message;
    cin.clear();
    cin >> input;
  }
  cin.clear();
  return input;
}

// between 2 bounds
double input_prot(const char prompt[], const char error_message[], double lower,
                  double upper) {
  cout << prompt;
  double input;

  cin >> input;

  while (input < lower || input > upper) {
    cout << error_message;
    cin.clear();
    cin >> input;
  }
  cin.clear();
  return input;
}

// between 2 bounds
char input_prot(const char prompt[], const char error_message[], char lower,
                char upper) {
  cout << prompt;
  char input;

  cin >> input;

  while (input < lower || input > upper) {
    cout << error_message;
    cin.clear();
    cin >> input;
  }
  cin.clear();
  return input;
}

// single
long input_prot(const char prompt[], const char error_message[], long single,
                bool is_lower = true) {
  cout << prompt;
  long input;

  cin >> input;

  if (is_lower) {
    while (input < single) {
      cout << error_message;
      cin.clear();
      cin >> input;
    }
  } else {
    while (input > single) {
      cout << error_message;
      cin.clear();
      cin >> input;
    }
  }

  cin.clear();
  return input;
}

// single
double input_prot(const char prompt[], const char error_message[],
                  double single, bool is_lower = true) {
  cout << prompt;
  double input;

  cin >> input;

  if (is_lower) {
    while (input > single) {
      cout << error_message;
      cin.clear();
      cin >> input;
    }
    return input;
  }
  while (input < single) {
    cout << error_message;
    cin.clear();
    cin >> input;
  }
  cin.clear();
  return input;
}

// single
char input_prot(const char prompt[], const char error_message[], char single,
                bool is_lower = true) {
  cout << prompt;
  char input;

  cin >> input;

  if (is_lower) {
    while (input < single) {
      cout << error_message;
      cin.clear();
      cin >> input;
    }
    return input;
  } else {
    while (input > single) {
      cout << error_message;
      cin.clear();
      cin >> input;
    }
  }
  cin.clear();
  return input;
}

// checking if it fits menu choices
char input_prot(const char prompt[], const char error_message[],
                const char menu[]) {
  char input;

  cout << prompt;

  bool done = false;
  size_t menu_pos = 0;

  while (!done) {
    cin >> input;
    while (menu[menu_pos] != '\0') {
      if (input == menu[menu_pos]) {
        input = menu[menu_pos];
        done = true;
      }
      menu_pos++;
    }
    if (!done) {
      menu_pos = 0;  // resets menu_pos
      cout << error_message;
      cin.clear();
    }
  }
  cin.clear();
  return input;
}

// checking if it fits menu choices
long input_prot(const char prompt[], const char error_message[],
                const long menu[], const size_t SIZE_OF_MENU) {
  long input;

  cout << prompt;

  bool done;
  size_t menu_pos = 0;

  while (!done) {
    cin >> input;
    while (menu_pos < SIZE_OF_MENU) {
      if (input == menu[menu_pos]) {
        input = menu[menu_pos];
        done = true;
      }
      menu_pos++;
    }
    if (!done) {
      menu_pos = 0;  // resets menu_pos
      cout << error_message;
      cin.clear();
    }
  }
  cin.clear();
  return input;
}

// checking menu choices
double input_prot(const char prompt[], const char error_message[],
                  const double menu[], const size_t SIZE_OF_MENU) {
  double input;

  cout << prompt;

  bool done = false;
  size_t menu_pos = 0;

  while (!done) {
    cin >> input;
    while (menu_pos < SIZE_OF_MENU) {
      if (equals(menu[menu_pos], input)) {
        input = menu[menu_pos];
        done = true;
      }
      menu_pos++;
    }
    if (!done) {
      menu_pos = 0;  // resets menu_pos
      cout << error_message;
      cin.clear();
    }
  }
  cin.clear();
  return input;
}
