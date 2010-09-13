.rodata
.balign 32
.globl pic23length
.globl pic23data

pic23length:	.long	picdataend - pic23data
pic23data:
.incbin "../images/green.png"
picdataend:


