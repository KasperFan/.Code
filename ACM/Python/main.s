	.arch armv8-a
	.text
	.cstring
	.align	3
lC1:
	.ascii "%p\12\0"
	.align	3
lC2:
	.ascii "%d\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.align	2
	.p2align 4,,11
	.globl _main
_main:
LFB20:
	sub	sp, sp, #96
LCFI0:
	adrp	x1, lC0@PAGE
	add	x1, x1, lC0@PAGEOFF;momd
	add	x2, sp, 56
	add	x0, sp, 72
	stp	x29, x30, [sp, 16]
LCFI1:
	add	x29, sp, 16
	ldp	q0, q1, [x1]
	str	x0, [sp]
	ldr	x1, [x1, 32]
	str	x19, [sp, 32]
LCFI2:
	adrp	x0, lC1@PAGE
	add	x0, x0, lC1@PAGEOFF;momd
	stp	q0, q1, [x2]
	adrp	x19, lC2@PAGE
	add	x19, x19, lC2@PAGEOFF;momd
	str	x1, [sp, 88]
	bl	_printf
	ldr	w0, [sp, 80]
	str	w0, [sp]
	mov	x0, x19
	bl	_printf
	ldr	w1, [sp, 80]
	mov	x0, x19
	str	w1, [sp]
	bl	_printf
	ldr	w1, [sp, 88]
	mov	x0, x19
	str	w1, [sp]
	add	w1, w1, 1
	str	w1, [sp, 88]
	bl	_printf
	ldp	x29, x30, [sp, 16]
	mov	w0, 0
	ldr	x19, [sp, 32]
	add	sp, sp, 96
LCFI3:
	ret
LFE20:
	.const
	.align	2
lC0:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.word	9
	.word	10
	.section __TEXT,__text_startup,regular,pure_instructions
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB20-.
	.set L$set$2,LFE20-LFB20
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB20
	.long L$set$3
	.byte	0xe
	.uleb128 0x60
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0xa
	.byte	0x9e
	.uleb128 0x9
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0x93
	.uleb128 0x8
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0xdd
	.byte	0xde
	.byte	0xd3
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 12.3.0) 12.3.0"
	.subsections_via_symbols
