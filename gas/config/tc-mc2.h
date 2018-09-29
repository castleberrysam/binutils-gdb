#ifndef TC_MC2
#define TC_MC2

#define LISTING_HEADER "MC2 GAS "
#define LISTING_WORD_SIZE 2

#define TARGET_ARCH bfd_arch_mc2
#define TARGET_FORMAT "a.out-mc2"
#define TARGET_BYTES_BIG_ENDIAN 0

#define WORKING_DOT_WORD

#define md_register_arithmetic 0
#define md_number_to_chars number_to_chars_littleendian

extern long mc2_relax_frag(segT segment, fragS *fragP, long stretch);
#define md_relax_frag(segment, fragP, stretch) mc2_relax_frag(segment, fragP, stretch)

#define md_apply_fix gas_cgen_md_apply_fix
#define tc_gen_reloc gas_cgen_tc_gen_reloc

#endif
