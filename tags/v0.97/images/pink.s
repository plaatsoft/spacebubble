.rodata
.balign 32
.globl pic27length
.globl pic27data

pic27length:	.long	picdataend - pic27data
pic27data:
.incbin "../images/pink.png"
picdataend:


