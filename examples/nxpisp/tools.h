#pragma once
#include <cstdint>
#include <limits>
//  2s compliment of checksum
constexpr uint32_t CalculateCheckSum(const uint8_t* const frame, const uint32_t length) {
  uint64_t csum = 0;
  for (uint32_t i = 0; i < length; i++) {
    //  avoid rollover for constexpr use
    csum = (csum + frame[i]) & std::numeric_limits<uint32_t>::max();
  }
  return (uint64_t{1} << 32) - (csum % (uint64_t{1} << 32));
}
