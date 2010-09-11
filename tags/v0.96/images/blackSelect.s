.rodata
.balign 32
.globl pic32length
.globl pic32data

pic32length:	.long	picdataend - pic32data
pic32data:
.incbin "../images/blackSelect.png"
picdataend:


