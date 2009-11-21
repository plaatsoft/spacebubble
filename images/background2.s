.rodata
.balign 32
.globl pic48length
.globl pic48data

pic48length:	.long	picdataend - pic48data
pic48data:
.incbin "../images/background2.png"
picdataend:


