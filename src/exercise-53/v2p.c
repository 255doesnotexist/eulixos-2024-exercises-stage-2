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
  // 页号：从虚拟地址的高 20 位提取
  uint32_t page_number = virtual_address >> 12;
  // 页内偏移：从虚拟地址的低 12 位提取
  uint32_t offset = virtual_address & 0xFFF;
  // 从页表中查找对应页号的物理页帧基地址
  uint32_t physical_page_base = page_table[page_number];
  // 最终的物理地址 = 物理页帧基地址 + 页内偏移
  uint32_t physical_address = physical_page_base + offset;

  return physical_address;
}
