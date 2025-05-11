  .global _exit
  .type   _exit, @function
_exit:
    # exit with the return code on the qemu virt machine
    lui t0, 0x100
    slli a0, a0, 12
    addi a0, a0, 0x333
    slli a0, a0, 4
    addi a0, a0, 0x3
    sw a0, 0(t0)