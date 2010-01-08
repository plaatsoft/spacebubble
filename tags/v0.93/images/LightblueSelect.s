.rodata
.balign 32
.globl pic30length
.globl pic30data

pic30length:	.long	picdataend - pic30data
pic30data:
.incbin "../images/lightBlueSelect.png"
picdataend:


