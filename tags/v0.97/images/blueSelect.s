.rodata
.balign 32
.globl pic20length
.globl pic20data

pic20length:	.long	picdataend - pic20data
pic20data:
.incbin "../images/blueSelect.png"
picdataend:


