#include <cmath>

#ifndef INPUT_PROT_H_INC
#define INPUT_PROT_H_INC

// helper method for comparing floating points
inline bool equals(double input, double comparison) {
  double epsilon = 0.000001;

  bool okay = !std::isnan(comparison) &&
              !std::isnan(input) &&  // checking if nan
              !std::isinf(comparison) && !std::isinf(input) &&  // checking inf
              std::abs(input - comparison) < epsilon;  // checking epsilon
  return okay;
}

char input_prot(const char prompt[], const char error_message[],
                const char exceptions[]);

char input_prot(const char prompt[], const char error_message[], char lower,
                char upper);

char input_prot(const char prompt[], const char error_message[], char single,
                bool is_lower);

long input_prot(const char prompt[], const char error_message[], long lower,
                long upper);

long input_prot(const char prompt[], const char error_message[], long single,
                bool is_lower);

long input_prot(const char prompt[], const char error_message[],
                const long menu[], const size_t SIZE_OF_MENU);

double input_prot(const char prompt[], const char error_message[],
                  double single, bool is_lower);

double input_prot(const char prompt[], const char error_message[], double lower,
                  double upper);

double input_prot(const char prompt[], const char error_message[],
                  const double menu[], const size_t SIZE_OF_MENU);

#endif
