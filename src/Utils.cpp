#include <Utils.hpp>

long long hexStringToLong(std::string hexString) {
  return std::stoll(hexString.erase(0, 1), nullptr, 16);
}
