#include "v2p.h"
#include <stdint.h>
#include <stdio.h>
// 模拟页表（在真实情况下，这会在内存中）
uint32_t page_table[] = {
  0x20000000, // 第一个虚拟页映射到物理页帧基地址 0x20000000
  0x20001000, // 第二个虚拟页映射到物理页帧基地址 0x20001000
  0x20002000, // 第三个虚拟页映射到物理页帧基地址 0x20002000
  0x20003000  // 第四个虚拟页映射到物理页帧基地址 0x20003000
};

uint32_t
translate_address (uint32_t virtual_address)
{
  // TODO
}
