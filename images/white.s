.rodata
.balign 32
.globl pic37length
.globl pic37data

pic37length:	.long	picdataend - pic37data
pic37data:
.incbin "../images/white.png"
picdataend:

