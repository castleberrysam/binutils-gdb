	.text
	.globl _start
	.type _start,@function
_start:
	bl foo
	bl bar
.ifndef __guard_property_bti__
	.section ".note.gnu.property", "a"
	.p2align 3
	.long 1f - 0f		/* name length */
	.long 5f - 2f		/* data length */
	.long 5			/* note type */
0:	.asciz "GNU"		/* vendor name */
1:
	.p2align 3
2:	.long 0xc0000000	/* pr_type.  */
	.long 4f - 3f		/* pr_datasz.  */
3:
	.long 0x1		/* BTI.  */
4:
	.p2align 3
5:
.endif
