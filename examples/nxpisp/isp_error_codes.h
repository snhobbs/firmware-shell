#include <array>
namespace Isp {
const constexpr std::array<const char*, 32> return_codes{
    "CMD_SUCCESS"                              ,
    "INVALID_COMMAND"                          ,
    "SRC_ADDR_ERROR"                           ,
    "DST_ADDR_ERROR"                           ,
    "SRC_ADDR_NOT_MAPPED"                      ,
    "DST_ADDR_NOT_MAPPED"                      ,
    "COUNT_ERROR"                              ,
    "INVALID_SECTOR/INVALID_PAGE"              ,
    "SECTOR_NOT_BLANK"                         ,
    "SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION"  ,
    "COMPARE_ERROR"                            ,
    "BUSY"                                     ,
    "PARAM_ERROR"                              ,
    "ADDR_ERROR"                               ,
    "ADDR_NOT_MAPPED"                          ,
    "CMD_LOCKED"                               ,
    "INVALID_CODE"                             ,
    "INVALID_BAUD_RATE"                        ,
    "INVALID_STOP_BIT"                         ,
    "CODE_READ_PROTECTION_ENABLED"             ,
    "Unused 1"                                 ,
    "USER_CODE_CHECKSUM"                       ,
    "Unused 2"                                 ,
    "EFRO_NO_POWER"                            ,
    "FLASH_NO_POWER"                           ,
    "Unused 3"                                 ,
    "Unused 4"                                 ,
    "FLASH_NO_CLOCK"                           ,
    "REINVOKE_ISP_CONFIG"                      ,
    "NO_VALID_IMAGE"                           ,
    "FAIM_NO_POWER"                            ,
    "FAIM_NO_CLOCK"                            ,
};

const uint32_t CMD_SUCCESS = 0x0;
const uint32_t INVALID_COMMAND = 0x1;
const uint32_t SRC_ADDR_ERROR = 0x2;
const uint32_t DST_ADDR_ERROR = 0x3;
const uint32_t SRC_ADDR_NOT_MAPPED = 0x4;
const uint32_t DST_ADDR_NOT_MAPPED = 0x5;
const uint32_t COUNT_ERROR = 0x6;
const uint32_t INVALID_SECTOR_OR_INVALID_PAGE = 0x7;
const uint32_t SECTOR_NOT_BLANK = 0x8;
const uint32_t SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION = 0x9;
const uint32_t COMPARE_ERROR = 0xa;
const uint32_t BUSY = 0xb;
const uint32_t PARAM_ERROR = 0xc;
const uint32_t ADDR_ERROR = 0xd;
const uint32_t ADDR_NOT_MAPPED = 0xe;
const uint32_t CMD_LOCKED = 0xf;
const uint32_t INVALID_CODE = 0x10;
const uint32_t INVALID_BAUD_RATE = 0x11;
const uint32_t INVALID_STOP_BIT = 0x12;
const uint32_t CODE_READ_PROTECTION_ENABLED = 0x13;
const uint32_t Unused_1 = 0x14;
const uint32_t USER_CODE_CHECKSUM = 0x15;
const uint32_t Unused_2 = 0x16;
const uint32_t EFRO_NO_POWER = 0x17;
const uint32_t FLASH_NO_POWER = 0x18;
const uint32_t Unused_3 = 0x19;
const uint32_t Unused_4 = 0x1a;
const uint32_t FLASH_NO_CLOCK = 0x1b;
const uint32_t REINVOKE_ISP_CONFIG = 0x1c;
const uint32_t NO_VALID_IMAGE = 0x1d;
const uint32_t FAIM_NO_POWER = 0x1e;
const uint32_t FAIM_NO_CLOCK = 0x1f;
}  //  namespace Isp
