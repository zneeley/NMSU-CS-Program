//
// Global Data
//
    .data
    .comm segment, 1
    .global segment
    .comm number, 1
    .global number

//
// Program Data
//
    .text
    .global PinSetup
    .global selectseg

PinSetup:
    ldi r17, 0b00011111 //PortB
    ldi r18, 0b11111100 //PortD

    out 0x04, r17
    out 0x0A, r18
    ret

selectseg:
    ld r18, segment

    
    

ret


