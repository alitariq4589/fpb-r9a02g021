  .extern initialize_vect

  .text
  .global _PowerON_Reset
  .type   _PowerON_Reset, @function
_PowerON_Reset:
  # Initialize global pointer
.option push
.option norelax
1:auipc gp, %pcrel_hi(__global_pointer$)
  addi  gp, gp, %pcrel_lo(1b)
.option pop

  # initialize the stack and frame pointers
  la      sp, __stack
  add s0, sp, zero

  # Clear the bss segment
  la      a0, __bss
  la      a2, __ebss
  sub     a2, a2, a0
  li      a1, 0
  call    memset

  # Init the data segment
  la      a0, __datastart
  la      a1, __romdatastart
  la      a2, __romdatacopysize
  call    memcpy

  # Init the data segment for ECC
  la      a0, __dataeccramstart
  la      a1, __romdataeccramstart
  la      a2, __romdataeccramcopysize
  call    memcpy

  # Make reference to atexit weak to avoid unconditionally pulling in
  # support code.  Refer to comments in __atexit.c for more details.
  .weak   atexit
  la      a0, atexit
  beqz    a0, .Lweak_atexit
  .weak   __libc_fini_array


  la      a0, __libc_fini_array   # Register global termination functions
  call    atexit                  #  to be called upon exit

.Lweak_atexit:

  call    __libc_init_array       # Run global initialization functions

  call    initialize_vect        # Initialize vect

  li      a0, 0                  # a0 = argc
  li      a1, 0                  # a1 = argv
  li      a2, 0                  # a2 = envp = NULL
  call    main
  tail    exit
  .size  _PowerON_Reset, .-_PowerON_Reset
