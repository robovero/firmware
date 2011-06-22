/* This file is part of the CodeSourcery Common Startup Code Sequence (CS3).

   Copyright (c) 2007 - 2011 CodeSourcery, Inc.
 * Version:Sourcery G++ 2011.02-2
 * BugURL:https://support.codesourcery.com/GNUToolchain/

   THIS FILE CONTAINS PROPRIETARY, CONFIDENTIAL, AND TRADE SECRET
   INFORMATION OF CODESOURCERY AND/OR ITS LICENSORS.

   You may not use, modify or distribute this file without the express
   written permission of CodeSourcery or its authorized
   distributor. Please consult your license agreement for the
   applicable terms and conditions.  */

#ifndef CSL_CS3_H
#define CSL_CS3_H

#include <stddef.h>

#if __cplusplus
extern "C" {
#endif

/* The __cs3_regions array is used by CS3's startup code to initialize
   the contents of memory regions during the C initialization phase.

   For each region descriptor __cs3_regions[i], __cs3_regions[i].init_size
   bytes beginning at __cs3_regions[i].data are initialized by copying from
   __cs3_regions[i].init.  (E.g., the data field is the VMA and the init
   field is the LMA.)  Then the following __cs3_regions[i].zero_size bytes
   are zero-initialized.

   __cs3_regions is normally defined in the linker script.  */

typedef unsigned char __cs3_byte_align8 __attribute ((aligned (8)));

struct __cs3_region
{
  unsigned flags;       /* Flags for this region.  None defined yet.  */
  __cs3_byte_align8 *init;  /* Initial contents of this region.  */
  __cs3_byte_align8 *data;  /* Start address of region.  */
  size_t init_size;     /* Size of initial data.  */
  size_t zero_size;     /* Additional size to be zeroed.  */
};

extern const struct __cs3_region __cs3_regions[];

/* The number of elements in __cs3_regions.  This is weak, so the
   compiler does not presume it is non-zero.  */

extern const char __cs3_region_num __attribute__((weak));
#define __cs3_region_num ((size_t)&__cs3_region_num)

/* __cs3_start_c is the entry point to the C initialization phase.
   CS3's library provides a default implementation, but it is possible
   for user code to override it by defining this function.  */

extern void __cs3_start_c (void) __attribute ((noreturn));

/* Space for the heap is designated by the array __cs3_heap_start.
   __cs3_heap_limit points at the end of the heap.  

   CS3 provides default definitions for __cs3_heap_start and
   __cs3_heap_end in the linker scripts (typically placed after the
   .data and .bss sections in RAM), and a default definition for
   __cs3_heap_limit pointing to __cs3_heap_end in the CS3 library.
   As a special case, in some profiles &__cs3_heap_end may be zero to
   indicate that the end of the heap must be determined some other way,
   such as by a supervisory operation on a simulator, or simply by
   treating the stack pointer as the limit.

   User programs may override these default definitions either by using
   a custom linker script, or by defining __cs3_heap_start and
   __cs3_heap_limit appropriately from C.  */

extern unsigned char __cs3_heap_start[] __attribute ((aligned (8)));
extern unsigned char __cs3_heap_end[] __attribute ((aligned (8)));
extern void *__cs3_heap_limit;

/* The default initial stack pointer.  This is normally defined by the
   linker script except in profiles where the stack pointer is
   initialized externally, e.g. by a simulator or boot monitor.
   Refer to the documentation for the Assembly Initialization phase.  */
extern unsigned char __cs3_stack[] __attribute ((aligned (8)));

/* Regions.  Some may not be present on particular boards or profiles. */

/* We use weak on objects that might be at address zero.
   The compiler is at liberty to presume that no non-weak
   object resides at address zero (because that's
   indistinguishable from the NULL pointer on the systems
   we care about).  */

/* ahbsram0 region */
extern unsigned char __cs3_region_start_ahbsram0[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_ahbsram0[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_ahbsram0[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_ahbsram0 __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_ahbsram0 ((size_t)&__cs3_region_init_size_ahbsram0)
extern const char __cs3_region_zero_size_ahbsram0 __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_ahbsram0 ((size_t)&__cs3_region_zero_size_ahbsram0)

/* ahbsram1 region */
extern unsigned char __cs3_region_start_ahbsram1[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_ahbsram1[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_ahbsram1[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_ahbsram1 __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_ahbsram1 ((size_t)&__cs3_region_init_size_ahbsram1)
extern const char __cs3_region_zero_size_ahbsram1 __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_ahbsram1 ((size_t)&__cs3_region_zero_size_ahbsram1)

/* boot region */
extern unsigned char __cs3_region_start_boot[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_boot[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_boot[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_boot __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_boot ((size_t)&__cs3_region_init_size_boot)
extern const char __cs3_region_zero_size_boot __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_boot ((size_t)&__cs3_region_zero_size_boot)

/* datarom region */
extern unsigned char __cs3_region_start_datarom[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_datarom[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_datarom[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_datarom __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_datarom ((size_t)&__cs3_region_init_size_datarom)
extern const char __cs3_region_zero_size_datarom __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_datarom ((size_t)&__cs3_region_zero_size_datarom)

/* extnand region */
extern unsigned char __cs3_region_start_extnand[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extnand[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extnand[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extnand __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extnand ((size_t)&__cs3_region_init_size_extnand)
extern const char __cs3_region_zero_size_extnand __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extnand ((size_t)&__cs3_region_zero_size_extnand)

/* extnor region */
extern unsigned char __cs3_region_start_extnor[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extnor[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extnor[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extnor __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extnor ((size_t)&__cs3_region_init_size_extnor)
extern const char __cs3_region_zero_size_extnor __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extnor ((size_t)&__cs3_region_zero_size_extnor)

/* extram region */
extern unsigned char __cs3_region_start_extram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extram ((size_t)&__cs3_region_init_size_extram)
extern const char __cs3_region_zero_size_extram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extram ((size_t)&__cs3_region_zero_size_extram)

/* extrom region */
extern unsigned char __cs3_region_start_extrom[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extrom[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extrom[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extrom __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extrom ((size_t)&__cs3_region_init_size_extrom)
extern const char __cs3_region_zero_size_extrom __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extrom ((size_t)&__cs3_region_zero_size_extrom)

/* extsdram region */
extern unsigned char __cs3_region_start_extsdram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extsdram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extsdram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extsdram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extsdram ((size_t)&__cs3_region_init_size_extsdram)
extern const char __cs3_region_zero_size_extsdram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extsdram ((size_t)&__cs3_region_zero_size_extsdram)

/* extsram region */
extern unsigned char __cs3_region_start_extsram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_extsram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_extsram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_extsram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_extsram ((size_t)&__cs3_region_init_size_extsram)
extern const char __cs3_region_zero_size_extsram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_extsram ((size_t)&__cs3_region_zero_size_extsram)

/* flexnvm region */
extern unsigned char __cs3_region_start_flexnvm[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_flexnvm[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_flexnvm[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_flexnvm __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_flexnvm ((size_t)&__cs3_region_init_size_flexnvm)
extern const char __cs3_region_zero_size_flexnvm __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_flexnvm ((size_t)&__cs3_region_zero_size_flexnvm)

/* flexram region */
extern unsigned char __cs3_region_start_flexram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_flexram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_flexram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_flexram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_flexram ((size_t)&__cs3_region_init_size_flexram)
extern const char __cs3_region_zero_size_flexram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_flexram ((size_t)&__cs3_region_zero_size_flexram)

/* internalram region */
extern unsigned char __cs3_region_start_internalram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_internalram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_internalram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_internalram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_internalram ((size_t)&__cs3_region_init_size_internalram)
extern const char __cs3_region_zero_size_internalram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_internalram ((size_t)&__cs3_region_zero_size_internalram)

/* itcm region */
extern unsigned char __cs3_region_start_itcm[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_itcm[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_itcm[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_itcm __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_itcm ((size_t)&__cs3_region_init_size_itcm)
extern const char __cs3_region_zero_size_itcm __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_itcm ((size_t)&__cs3_region_zero_size_itcm)

/* nbrom region */
extern unsigned char __cs3_region_start_nbrom[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_nbrom[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_nbrom[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_nbrom __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_nbrom ((size_t)&__cs3_region_init_size_nbrom)
extern const char __cs3_region_zero_size_nbrom __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_nbrom ((size_t)&__cs3_region_zero_size_nbrom)

/* ocram region */
extern unsigned char __cs3_region_start_ocram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_ocram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_ocram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_ocram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_ocram ((size_t)&__cs3_region_init_size_ocram)
extern const char __cs3_region_zero_size_ocram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_ocram ((size_t)&__cs3_region_zero_size_ocram)

/* option_bytes_rom region */
extern unsigned char __cs3_region_start_option_bytes_rom[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_option_bytes_rom[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_option_bytes_rom[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_option_bytes_rom __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_option_bytes_rom ((size_t)&__cs3_region_init_size_option_bytes_rom)
extern const char __cs3_region_zero_size_option_bytes_rom __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_option_bytes_rom ((size_t)&__cs3_region_zero_size_option_bytes_rom)

/* ram region */
extern unsigned char __cs3_region_start_ram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_ram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_ram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_ram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_ram ((size_t)&__cs3_region_init_size_ram)
extern const char __cs3_region_zero_size_ram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_ram ((size_t)&__cs3_region_zero_size_ram)

/* remappedram region */
extern unsigned char __cs3_region_start_remappedram[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_remappedram[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_remappedram[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_remappedram __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_remappedram ((size_t)&__cs3_region_init_size_remappedram)
extern const char __cs3_region_zero_size_remappedram __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_remappedram ((size_t)&__cs3_region_zero_size_remappedram)

/* rom region */
extern unsigned char __cs3_region_start_rom[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_rom[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_rom[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_rom __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_rom ((size_t)&__cs3_region_init_size_rom)
extern const char __cs3_region_zero_size_rom __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_rom ((size_t)&__cs3_region_zero_size_rom)

/* sram_l region */
extern unsigned char __cs3_region_start_sram_l[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_sram_l[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_sram_l[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_sram_l __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_sram_l ((size_t)&__cs3_region_init_size_sram_l)
extern const char __cs3_region_zero_size_sram_l __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_sram_l ((size_t)&__cs3_region_zero_size_sram_l)

/* ssram1 region */
extern unsigned char __cs3_region_start_ssram1[] __attribute__((weak,aligned(8)));
extern unsigned char __cs3_region_size_ssram1[] __attribute__((aligned(8)));
extern const unsigned char __cs3_region_init_ssram1[] __attribute__((weak,aligned(8)));
extern const char __cs3_region_init_size_ssram1 __attribute__((weak,aligned(8)));
#define __cs3_region_init_size_ssram1 ((size_t)&__cs3_region_init_size_ssram1)
extern const char __cs3_region_zero_size_ssram1 __attribute__((weak,aligned(8)));
#define __cs3_region_zero_size_ssram1 ((size_t)&__cs3_region_zero_size_ssram1)

#if __cplusplus
}
#endif
#endif /* CSL_CS3_H */
