	.arch armv8-a
	.text
	.cstring
	.align	3
lC0:
	.ascii "%d\0"
	.text
	.align	2
	.globl _main
_main:
LFB1:
	sub	sp, sp, #48
LCFI0:
	stp	x29, x30, [sp, 16]
LCFI1:
	add	x29, sp, 16
	add	x0, sp, 44
	str	x0, [sp]
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	bl	_scanf
	ldr	w0, [sp, 44]
	bl	_PrintN
	mov	w0, 0
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 48
LCFI2:
	ret
LFE1:
	.cstring
	.align	3
lC1:
	.ascii "%d\12\0"
	.text
	.align	2
	.globl _PrintN
_PrintN:
LFB2:
	sub	sp, sp, #48
LCFI3:
	stp	x29, x30, [sp, 16]
LCFI4:
	add	x29, sp, 16
	str	w0, [sp, 44]
	ldr	w0, [sp, 44]
	cmp	w0, 0
	ble	L5
	ldr	w0, [sp, 44]
	sub	w0, w0, #1
	bl	_PrintN
	ldr	w0, [sp, 44]
	str	w0, [sp]
	adrp	x0, lC1@PAGE
	add	x0, x0, lC1@PAGEOFF;momd
	bl	_printf
L5:
	nop
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 48
LCFI5:
	ret
LFE2:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
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
	.quad	LFB1-.
	.set L$set$2,LFE1-LFB1
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1
	.long L$set$3
	.byte	0xe
	.uleb128 0x30
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
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
	.quad	LFB2-.
	.set L$set$7,LFE2-LFB2
	.quad L$set$7
	.uleb128 0
	.byte	0x4
	.set L$set$8,LCFI3-LFB2
	.long L$set$8
	.byte	0xe
	.uleb128 0x30
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xdd
	.byte	0xde
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 13.1.0) 13.1.0"
	.subsections_via_symbols
