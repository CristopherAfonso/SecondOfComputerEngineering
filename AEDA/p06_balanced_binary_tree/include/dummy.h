#ifndef _DUMMY_
#define _DUMMY_

#include <iostream>
#include <string>

class dummy {
 public:
  dummy(const int& key = 0, const std::string& name = "");
  int clave;
  std::string name;
  bool operator==(const dummy& other) const;
  friend std::ostream& operator<<(std::ostream& out, const dummy& other);

 private:
  
};

#endif