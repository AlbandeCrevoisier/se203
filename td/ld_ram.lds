/* Load script */
MEMORY {
    rom  (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
    raml (!rx) : ORIGIN = 0x1fffe000, LENGTH = 8K
    ramh (!rx) : ORIGIN = 0x20000000, LENGTH = 24K
}

SECTIONS {
    .text : {
        *(.text)
    } > ramh

    .data : {
        *(.data)
    } > ramh

    .rodata : {
        *(.rodata)
    } > ramh

    .bss : {
        _bss_start = . ;
        *(.bss) *(COMMON)
        _bss_end = . ;
    } > ramh
}

ENTRY(_start)
stack_top = ORIGIN(ramh);
