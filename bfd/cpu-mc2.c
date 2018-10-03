#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

const bfd_arch_info_type
bfd_mc2_arch =
 {
   16,				/* 16 bits in a word.  */
   16,				/* 16 bits in an address.  */
   8,				/* 8 bits in a byte.  */
   bfd_arch_mc2,		/* Architecture.  */
   0,				/* Machine number - 0 for now.  */
   "mc2",			/* Architecture name.  */
   "mc5-base",			/* Printable name.  */
   1,				/* Section align power.  */
   TRUE,			/* This is the default architecture.  */
   bfd_default_compatible,	/* Architecture comparison function.  */
   bfd_default_scan,		/* String to architecture conversion.  */
   bfd_arch_default_fill,	/* Default fill.  */
   NULL				/* Next in list.  */
};
