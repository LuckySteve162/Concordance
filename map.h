using namespace std;
#include <iostream>
#include <string>

#ifndef MAP_H_INC
#define MAP_H_INC

template <typename KeyType, typename BlockType>
class Map {
  KeyType *key;
  BlockType *block;
  size_t size, count = 0;

  void resize(size_t newsize) {
    KeyType *newkey = new (nothrow) KeyType[newsize];
    BlockType *newblock = new (nothrow) BlockType[newsize];
    for (size_t pos = 0; pos < count; pos++) {
      newkey[pos] = key[pos];
      newblock[pos] = block[pos];
    }
    delete[] key;
    delete[] block;

    key = newkey;
    block = newblock;
  }

 public:
  Map(size_t input_size = 5) {
    size = input_size;
    key = new (nothrow) KeyType[size];
    block = new (nothrow) BlockType[size];
  }

  BlockType &operator[](KeyType find) {
    size_t pos = 0;
    while (pos < count && find != key[pos]) {
      pos++;
    }
    if (pos == count) {
      if (count == size - 1) {
        resize(size * 2);
      }
      key[pos] = find;
      count++;
    }

    return block[pos];
  }
  void print(ostream &out) {
    size_t pos = 0;
    while (pos < count) {
      out << key[pos] << ":  " << block[pos] << '\n';
      pos++;
    }
  }
};
#endif
