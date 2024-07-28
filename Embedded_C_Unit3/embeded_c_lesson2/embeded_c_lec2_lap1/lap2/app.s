
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <uart_send_string>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	743a6874 	ldrtvc	r6, [sl], #-2164	; 0x874
  10:	616d6f68 	cmnvs	sp, r8, ror #30
  14:	00000073 	andeq	r0, r0, r3, ror r0
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000b8 	strheq	r0, [r0], -r8
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000019 	andeq	r0, r0, r9, lsl r0
  10:	00000e01 	andeq	r0, r0, r1, lsl #28
  14:	00006a00 	andeq	r6, r0, r0, lsl #20
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001800 	andeq	r1, r0, r0, lsl #16
  20:	00000000 	andeq	r0, r0, r0
  24:	002a0200 	eoreq	r0, sl, r0, lsl #4
  28:	01030000 	mrseq	r0, (UNDEF: 3)
  2c:	00004e08 	andeq	r4, r0, r8, lsl #28
  30:	07040300 	streq	r0, [r4, -r0, lsl #6]
  34:	000000c2 	andeq	r0, r0, r2, asr #1
  38:	ac060103 	stfges	f0, [r6], {3}
  3c:	03000000 	movweq	r0, #0
  40:	00b80502 	adcseq	r0, r8, r2, lsl #10
  44:	02030000 	andeq	r0, r3, #0
  48:	00009907 	andeq	r9, r0, r7, lsl #18
  4c:	05040400 	streq	r0, [r4, #-1024]	; 0x400
  50:	00746e69 	rsbseq	r6, r4, r9, ror #28
  54:	00050803 	andeq	r0, r5, r3, lsl #16
  58:	03000000 	movweq	r0, #0
  5c:	00370708 	eorseq	r0, r7, r8, lsl #14
  60:	04030000 	streq	r0, [r3], #-0
  64:	00006105 	andeq	r6, r0, r5, lsl #2
  68:	07040300 	streq	r0, [r4, -r0, lsl #6]
  6c:	000000d6 	ldrdeq	r0, [r0], -r6
  70:	25070403 	strcs	r0, [r7, #-1027]	; 0x403
  74:	03000000 	movweq	r0, #0
  78:	005c0801 	subseq	r0, ip, r1, lsl #16
  7c:	01050000 	mrseq	r0, (UNDEF: 5)
  80:	00000014 	andeq	r0, r0, r4, lsl r0
  84:	00010401 	andeq	r0, r1, r1, lsl #8
  88:	18000000 	stmdane	r0, {}	; <UNPREDICTABLE>
  8c:	00000000 	andeq	r0, r0, r0
  90:	01000000 	mrseq	r0, (UNDEF: 0)
  94:	00002506 	andeq	r2, r0, r6, lsl #10
  98:	0000a400 	andeq	sl, r0, r0, lsl #8
  9c:	00690700 	rsbeq	r0, r9, r0, lsl #14
  a0:	00630000 	rsbeq	r0, r3, r0
  a4:	0000cf08 	andeq	ip, r0, r8, lsl #30
  a8:	b6030100 	strlt	r0, [r3], -r0, lsl #2
  ac:	01000000 	mrseq	r0, (UNDEF: 0)
  b0:	00000305 	andeq	r0, r0, r5, lsl #6
  b4:	94020000 	strls	r0, [r2], #-0
  b8:	00000000 	andeq	r0, r0, r0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	13490035 	movtne	r0, #36917	; 0x9035
  18:	24030000 	strcs	r0, [r3], #-0
  1c:	3e0b0b00 	vmlacc.f64	d0, d11, d0
  20:	000e030b 	andeq	r0, lr, fp, lsl #6
  24:	00240400 	eoreq	r0, r4, r0, lsl #8
  28:	0b3e0b0b 	bleq	f82c5c <main+0xf82c5c>
  2c:	00000803 	andeq	r0, r0, r3, lsl #16
  30:	3f002e05 	svccc	0x00002e05
  34:	3a0e030c 	bcc	380c6c <main+0x380c6c>
  38:	270b3b0b 	strcs	r3, [fp, -fp, lsl #22]
  3c:	1201110c 	andne	r1, r1, #12, 2
  40:	96064001 	strls	r4, [r6], -r1
  44:	00000c42 	andeq	r0, r0, r2, asr #24
  48:	49010106 	stmdbmi	r1, {r1, r2, r8}
  4c:	00130113 	andseq	r0, r3, r3, lsl r1
  50:	00210700 	eoreq	r0, r1, r0, lsl #14
  54:	0b2f1349 	bleq	bc4d80 <main+0xbc4d80>
  58:	34080000 	strcc	r0, [r8], #-0
  5c:	3a0e0300 	bcc	380c64 <main+0x380c64>
  60:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  64:	020c3f13 	andeq	r3, ip, #19, 30	; 0x4c
  68:	0000000a 	andeq	r0, r0, sl

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000018 	andeq	r0, r0, r8, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4b1600 	blmi	12c5834 <main+0x12c5834>
  30:	01000402 	tsteq	r0, r2, lsl #8
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
   4:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
   8:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
   c:	70610074 	rsbvc	r0, r1, r4, ror r0
  10:	00632e70 	rsbeq	r2, r3, r0, ror lr
  14:	6e69616d 	powvsez	f6, f1, #5.0
  18:	554e4700 	strbpl	r4, [lr, #-1792]	; 0x700
  1c:	34204320 	strtcc	r4, [r0], #-800	; 0x320
  20:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
  24:	6e6f6c00 	cdpvs	12, 6, cr6, cr15, cr0, {0}
  28:	6e752067 	cdpvs	0, 7, cr2, cr5, cr7, {3}
  2c:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  30:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
  34:	6c00746e 	cfstrsvs	mvf7, [r0], {110}	; 0x6e
  38:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  3c:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
  40:	736e7520 	cmnvc	lr, #32, 10	; 0x8000000
  44:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  48:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
  4c:	6e750074 	mrcvs	0, 3, r0, cr5, cr4, {3}
  50:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  54:	63206465 	teqvs	r0, #1694498816	; 0x65000000
  58:	00726168 	rsbseq	r6, r2, r8, ror #2
  5c:	72616863 	rsbvc	r6, r1, #6488064	; 0x630000
  60:	6e6f6c00 	cdpvs	12, 6, cr6, cr15, cr0, {0}
  64:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
  68:	3a450074 	bcc	1140240 <main+0x1140240>
  6c:	7469675c 	strbtvc	r6, [r9], #-1884	; 0x75c
  70:	5c627568 	cfstr64pl	mvdx7, [r2], #-416	; 0xfffffe60
  74:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
  78:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  7c:	555f435f 	ldrbpl	r4, [pc, #-863]	; fffffd25 <main+0xfffffd25>
  80:	3374696e 	cmncc	r4, #1802240	; 0x1b8000
  84:	626d655c 	rsbvs	r6, sp, #92, 10	; 0x17000000
  88:	64656465 	strbtvs	r6, [r5], #-1125	; 0x465
  8c:	6c5f635f 	mrrcvs	3, 5, r6, pc, cr15	; <UNPREDICTABLE>
  90:	5f326365 	svcpl	0x00326365
  94:	3170616c 	cmncc	r0, ip, ror #2
  98:	6f687300 	svcvs	0x00687300
  9c:	75207472 	strvc	r7, [r0, #-1138]!	; 0x472
  a0:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  a4:	2064656e 	rsbcs	r6, r4, lr, ror #10
  a8:	00746e69 	rsbseq	r6, r4, r9, ror #28
  ac:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  b0:	63206465 	teqvs	r0, #1694498816	; 0x65000000
  b4:	00726168 	rsbseq	r6, r2, r8, ror #2
  b8:	726f6873 	rsbvc	r6, pc, #7536640	; 0x730000
  bc:	6e692074 	mcrvs	0, 3, r2, cr9, cr4, {3}
  c0:	6e750074 	mrcvs	0, 3, r0, cr5, cr4, {3}
  c4:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  c8:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
  cc:	6200746e 	andvs	r7, r0, #1845493760	; 0x6e000000
  d0:	65666675 	strbvs	r6, [r6, #-1653]!	; 0x675
  d4:	69730072 	ldmdbvs	r3!, {r1, r4, r5, r6}^
  d8:	7974657a 	ldmdbvc	r4!, {r1, r3, r4, r5, r6, r8, sl, sp, lr}^
  dc:	Address 0x000000dc is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
