#include "isp_error_codes.h"
namespace Isp {
inline uint32_t unlock(void) { return Isp::CMD_SUCCESS; }
inline uint32_t SetBaudRate(const uint32_t baudrate, const uint32_t stop_bits) { return Isp::CMD_SUCCESS; }
inline uint32_t WriteToRam(const uint32_t start, const uint32_t length) { return Isp::CMD_SUCCESS; }

template<typename T>
inline uint32_t ReadMemory(const uint32_t start, const uint32_t length, T& buffer) { return Isp::CMD_SUCCESS; }
inline uint32_t PrepSectorsForWrite(const uint32_t start, const uint32_t end) { return Isp::CMD_SUCCESS; }
inline uint32_t CopyRAMToFlash(const uint32_t flash_address, const uint32_t ram_address, const uint32_t length) { return Isp::CMD_SUCCESS; }
inline uint32_t Go(const uint32_t address, const char mode) { return Isp::CMD_SUCCESS; }
inline uint32_t EraseSector(const uint32_t start, const uint32_t end) { return Isp::CMD_SUCCESS; }
inline uint32_t ErasePages(const uint32_t start, const uint32_t end) { return Isp::CMD_SUCCESS; }
inline uint32_t ReadPartID(uint32_t* part_id) {
  *part_id = 0x00008454;
  return Isp::CMD_SUCCESS;
}

inline uint32_t ReadBootCodeVersion(uint32_t* major, uint32_t* minor) {
  *major = 0xDEAD;
  *minor = 0xBEEF;
  return Isp::CMD_SUCCESS;
}
inline uint32_t MemoryLocationsEqual(const uint32_t address1, const uint32_t address2, const uint32_t length) { return Isp::CMD_SUCCESS; }
inline uint32_t ReadUID(std::array<uint32_t, 4>* uuid) {
  uuid->at(0) = 0xDEAD;
  uuid->at(1) = 0xDEAD;
  uuid->at(2) = 0xDEAD;
  uuid->at(3) = 0xDEAD;
  return Isp::CMD_SUCCESS;
}

inline uint32_t ReadCRC(const uint32_t start, const uint32_t length, uint32_t* crc) {
  *crc = 0xDEADBEEF; 
  return Isp::CMD_SUCCESS;
}

inline uint32_t ReadFlashSig(const uint32_t start, const uint32_t end, const uint32_t wait_states, const uint32_t mode, uint32_t* signature) {
  *signature = 0xDEADBEEF; 
  return Isp::CMD_SUCCESS;
}
}
