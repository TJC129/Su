	.syntax unified
	.arch armv7-a
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfpv3-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"gcd1.c"
	.text
	.align	2
	.global	findGCD
	.thumb
	.thumb_func
	.type	findGCD, %function
findGCD:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
.L6:
	ldr	r2, [r7, #4]
	ldr	r3, [r7]
	cmp	r2, r3
	ble	.L2
	ldr	r2, [r7, #4]
	ldr	r3, [r7]
	subs	r3, r2, r3
	str	r3, [r7, #4]
	b	.L3
.L2:
	ldr	r2, [r7, #4]
	ldr	r3, [r7]
	cmp	r2, r3
	bge	.L4
	ldr	r2, [r7]
	ldr	r3, [r7, #4]
	subs	r3, r2, r3
	str	r3, [r7]
	b	.L3
.L4:
	ldr	r3, [r7, #4]
	b	.L7
.L3:
	b	.L6
.L7:
	mov	r0, r3
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
	.size	findGCD, .-findGCD
	.ident	"GCC: (Ubuntu/Linaro 4.9.2-10ubuntu10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
