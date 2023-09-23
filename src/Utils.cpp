#include <Utils.hpp>

long hexStringToLong(std::string hexString) {
  return std::stol(hexString.erase(0, 1), nullptr, 16);
}
