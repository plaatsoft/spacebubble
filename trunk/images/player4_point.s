.rodata
.balign 32
.globl pic41length
.globl pic41data

pic41length:	.long	picdataend - pic41data
pic41data:
.incbin "../images/player4_point.png"
picdataend:


