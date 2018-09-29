#include "as.h"
#include "opcodes/mc2-desc.h"
#include "opcodes/mc2-opc.h"
#include "cgen.h"

const char *md_shortopts = "";
struct option md_longopts[] = {
  {NULL, no_argument, NULL, 0},
};
size_t md_longopts_size = sizeof(md_longopts);

int md_parse_option(int c ATTRIBUTE_UNUSED, const char *arg ATTRIBUTE_UNUSED) {return 0;}
void md_show_usage(FILE *stream ATTRIBUTE_UNUSED) {}

const pseudo_typeS md_pseudo_table[] = {
  {NULL, NULL, 0},
};

const char comment_chars[]        = ";";
const char line_comment_chars[]   = "#";
const char line_separator_chars[] = "!";
const char EXP_CHARS[]            = "eE";
const char FLT_CHARS[]            = "dD";

void md_begin(void)
{
  /* Set the machine number and endianness.  */
  gas_cgen_cpu_desc =
    mc2_cgen_cpu_open(CGEN_CPU_OPEN_MACHS, 0 /* mach number */,
                      CGEN_CPU_OPEN_ENDIAN, CGEN_ENDIAN_LITTLE,
                      CGEN_CPU_OPEN_END);
  mc2_cgen_init_asm(gas_cgen_cpu_desc);

  /* This is a callback from cgen to gas to parse operands.  */
  cgen_set_parse_operand_fn(gas_cgen_cpu_desc, gas_cgen_parse_operand);
}

void md_assemble(char *str)
{
  const CGEN_INSN *insn;
  char *errmsg;
  CGEN_FIELDS fields;
  
#if CGEN_INT_INSN_P
  CGEN_INSN_INT buffer[CGEN_MAX_INSN_SIZE / sizeof(CGEN_INSN_INT)];
#else
  unsigned char buffer[CGEN_MAX_INSN_SIZE];
#endif

  gas_cgen_init_parse();

  insn = mc2_cgen_assemble_insn(gas_cgen_cpu_desc, str, &fields, buffer, &errmsg);
  if(!insn) {
    as_bad("%s", errmsg);
    return;
  }

  gas_cgen_finish_insn(insn, buffer, CGEN_FIELDS_BITSIZE(&fields), 0, NULL);
}

symbolS * md_undefined_symbol(char *name ATTRIBUTE_UNUSED)
{
  return NULL;
}

void md_operand(expressionS *expressionP ATTRIBUTE_UNUSED)
{
  ;
}

const char * md_atof(int type ATTRIBUTE_UNUSED, char *litP ATTRIBUTE_UNUSED, int *sizeP ATTRIBUTE_UNUSED)
{
  return _("Floating point is unsupported on the mc2");
}

int md_estimate_size_before_relax(fragS *fragP ATTRIBUTE_UNUSED, segT segment ATTRIBUTE_UNUSED)
{
  return 0;
}

long mc2_relax_frag(segT segment ATTRIBUTE_UNUSED, fragS *fragP ATTRIBUTE_UNUSED, long stretch ATTRIBUTE_UNUSED)
{
  return 0;
}

void md_convert_frag(bfd *abfd ATTRIBUTE_UNUSED, segT segment ATTRIBUTE_UNUSED, fragS *fragP ATTRIBUTE_UNUSED) {}

long md_pcrel_from(fixS *fixP ATTRIBUTE_UNUSED)
{
  /* The mc2 does not have any pc-relative operations. */
  return 0;
}

valueT md_section_align(segT segment, valueT size)
{
  int align = bfd_get_section_alignment(stdoutput, segment);
  return ((size + (1 << align) - 1) & -(1 << align));
}

bfd_reloc_code_real_type
md_cgen_lookup_reloc(const CGEN_INSN *insn ATTRIBUTE_UNUSED,
                     const CGEN_OPERAND *operand ATTRIBUTE_UNUSED,
                     fixS *fixP ATTRIBUTE_UNUSED)
{
  return BFD_RELOC_NONE;
}
