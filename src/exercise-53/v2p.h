#ifndef _V2P_H__
#define _V2P_H__

#include <stdint.h>

#define PAGE_SIZE 4096
#define PAGE_TABLE_BASE 0x100000
#define PAGE_TABLE_ENTRY_SIZE 4

uint32_t translate_address (uint32_t virtual_address);
#endif
