#define TARGETNAME "a.out-mc2"
#define DEFAULT_ARCH bfd_arch_mc2

#undef TARGET_IS_BIG_ENDIAN_P
#define ARCH_SIZE 16
#define TARGET_PAGE_SIZE 256
#define TEXT_START_ADDR 0

#define MY(OP) CONCAT2 (mc2_aout_,OP)

#define N_HEADER_IN_TEXT(x) 0
#define N_FLAGS(execp) 0
#define N_SET_FLAGS(execp, flags) do {} while(0)

#include "aoutx.h"
#include "aout-target.h"
