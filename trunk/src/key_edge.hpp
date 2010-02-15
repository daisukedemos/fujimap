#ifndef KEYEDGE_HPP__
#define KEYEDGE_HPP__

#include "fujimap_common.hpp"

#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>

#include <iostream>

namespace fujimap_tool{

/*
 * Intermediated representation of key/value
 * used in HashMap. 
 */
struct KeyEdge{
  KeyEdge(); 
  KeyEdge(const std::string& str, const uint64_t code,
	  const uint64_t seed); 

  uint64_t get(uint64_t i, uint64_t bn) const{
    return (v[i] % bn) + bn * i;
  }

  uint64_t getRaw(uint64_t i, uint64_t bn) const{
    return v[i] % bn;
  }

  bool operator < (const KeyEdge& k) const {
    for (uint64_t i = 0; i < R; ++i){
      if (v[i] != k.v[i]) return v[i] < k.v[i];
    }
    return false;
  }

  void save(std::ofstream& ofs);
  void load(std::ifstream& ifs);

  uint64_t v[3];
  uint64_t code;
};

}

#endif // KEYEDGE_HPP__
