.rodata
.balign 32
.globl pic17length
.globl pic17data

pic17length:	.long	picdataend - pic17data
pic17data:
.incbin "../images/player1_point.png"
picdataend:


