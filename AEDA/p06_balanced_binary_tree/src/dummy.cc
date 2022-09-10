#include "../include/dummy.h"

dummy::dummy(const int& key, const std::string& nombre) : clave(key), name(nombre) {}

bool dummy::operator==(const dummy& other) const {
  return ((clave == other.clave) && (name == other.name));
}

std::ostream& operator<<(std::ostream& out, const dummy& other) {
  return out << other.name << ": " << other.clave << " ";
}
