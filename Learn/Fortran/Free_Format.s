	.arch armv8-a
	.text
	.cstring
	.align	3
lC0:
	.ascii "Format/Free_Format.f90\0"
	.const
	.align	3
lC1:
	.ascii "Hello"
	.text
	.align	2
_MAIN__:
LFB0:
	sub	sp, sp, #544
LCFI0:
	stp	x29, x30, [sp]
LCFI1:
	mov	x29, sp
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	str	x0, [sp, 24]
	mov	w0, 11
	str	w0, [sp, 32]
	mov	w0, 128
	str	w0, [sp, 16]
	mov	w0, 6
	str	w0, [sp, 20]
	add	x0, sp, 16
	bl	__gfortran_st_write
	add	x3, sp, 16
	mov	x2, 5
	adrp	x0, lC1@PAGE
	add	x1, x0, lC1@PAGEOFF;momd
	mov	x0, x3
	bl	__gfortran_transfer_character_write
	add	x0, sp, 16
	bl	__gfortran_st_write_done
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	str	x0, [sp, 24]
	mov	w0, 13
	str	w0, [sp, 32]
	mov	w0, 128
	str	w0, [sp, 16]
	mov	w0, 6
	str	w0, [sp, 20]
	add	x0, sp, 16
	bl	__gfortran_st_write
	add	x3, sp, 16
	mov	x2, 5
	adrp	x0, lC1@PAGE
	add	x1, x0, lC1@PAGEOFF;momd
	mov	x0, x3
	bl	__gfortran_transfer_character_write
	add	x0, sp, 16
	bl	__gfortran_st_write_done
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	str	x0, [sp, 24]
	mov	w0, 19
	str	w0, [sp, 32]
	mov	w0, 128
	str	w0, [sp, 16]
	mov	w0, 6
	str	w0, [sp, 20]
	add	x0, sp, 16
	bl	__gfortran_st_write
	add	x3, sp, 16
	mov	x2, 5
	adrp	x0, lC1@PAGE
	add	x1, x0, lC1@PAGEOFF;momd
	mov	x0, x3
	bl	__gfortran_transfer_character_write
	add	x0, sp, 16
	bl	__gfortran_st_write_done
	nop
	ldp	x29, x30, [sp]
	add	sp, sp, 544
LCFI2:
	ret
LFE0:
	.align	2
	.globl _main
_main:
LFB1:
	stp	x29, x30, [sp, -32]!
LCFI3:
	mov	x29, sp
	str	w0, [sp, 28]
	str	x1, [sp, 16]
	ldr	x1, [sp, 16]
	ldr	w0, [sp, 28]
	bl	__gfortran_set_args
	adrp	x0, _options.3.0@PAGE
	add	x1, x0, _options.3.0@PAGEOFF;momd
	mov	w0, 7
	bl	__gfortran_set_options
	bl	_MAIN__
	mov	w0, 0
	ldp	x29, x30, [sp], 32
LCFI4:
	ret
LFE1:
	.const
	.align	2
_options.3.0:
	.word	2116
	.word	4095
	.word	0
	.word	1
	.word	1
	.word	0
	.word	31
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
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB0
	.long L$set$3
	.byte	0xe
	.uleb128 0x220
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0x44
	.byte	0x9e
	.uleb128 0x43
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xdd
	.byte	0xde
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1-.
	.set L$set$7,LFE1-LFB1
	.quad L$set$7
	.uleb128 0
	.byte	0x4
	.set L$set$8,LCFI3-LFB1
	.long L$set$8
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 12.3.0) 12.3.0"
	.subsections_via_symbols
