//******************** font6 (6x8dot????) ***********************
const char font6[91][6] =
{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // " " 0x20
    { 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00 }, // ! 0x21
    { 0x00, 0x07, 0x00, 0x07, 0x00, 0x00 }, // " 0x22
    { 0x14, 0x7f, 0x14, 0x7f, 0x14, 0x00 }, // # 0x23
    { 0x24, 0x2a, 0x7f, 0x2a, 0x12, 0x00 }, // $ 0x24
    { 0x23, 0x13, 0x08, 0x64, 0x62, 0x00 }, // % 0x25
    { 0x36, 0x49, 0x55, 0x22, 0x50, 0x00 }, // & 0x26
    { 0x00, 0x05, 0x03, 0x00, 0x00, 0x00 }, // ' 0x27
    { 0x00, 0x1c, 0x22, 0x41, 0x00, 0x00 }, // ( 0x28
    { 0x00, 0x41, 0x22, 0x1c, 0x00, 0x00 }, // ) 0x29
    { 0x14, 0x08, 0x3e, 0x08, 0x14, 0x00 }, // * 0x2A
    { 0x08, 0x08, 0x3e, 0x08, 0x08, 0x00 }, // + 0x2B
    { 0x00, 0x50, 0x30, 0x00, 0x00, 0x00 }, // , 0x2C
    { 0x08, 0x08, 0x08, 0x08, 0x08, 0x00 }, // - 0x2D
    { 0x00, 0x60, 0x60, 0x00, 0x00, 0x00 }, // . 0x2E
    { 0x20, 0x10, 0x08, 0x04, 0x02, 0x00 }, // / 0x2F
    { 0x3e, 0x51, 0x49, 0x45, 0x3e, 0x00 }, // 0 0x30
    { 0x00, 0x42, 0x7f, 0x40, 0x00, 0x00 }, // 1 0x31
    { 0x42, 0x61, 0x51, 0x49, 0x46, 0x00 }, // 2 0x32
    { 0x21, 0x41, 0x45, 0x4b, 0x31, 0x00 }, // 3 0x33
    { 0x18, 0x14, 0x12, 0x7f, 0x10, 0x00 }, // 4 0x34
    { 0x27, 0x45, 0x45, 0x45, 0x39, 0x00 }, // 5 0x35
    { 0x3c, 0x4a, 0x49, 0x49, 0x30, 0x00 }, // 6 0x36
    { 0x01, 0x71, 0x09, 0x05, 0x03, 0x00 }, // 7 0x37
    { 0x36, 0x49, 0x49, 0x49, 0x36, 0x00 }, // 8 0x38
    { 0x06, 0x49, 0x49, 0x29, 0x1e, 0x00 }, // 9 0x39
    { 0x00, 0x36, 0x36, 0x00, 0x00, 0x00 }, // : 0x3A
    { 0x00, 0x56, 0x36, 0x00, 0x00, 0x00 }, // ; 0x3B
    { 0x08, 0x14, 0x22, 0x41, 0x00, 0x00 }, // < 0x3C
    { 0x14, 0x14, 0x14, 0x14, 0x14, 0x00 }, // = 0x3D
    { 0x00, 0x41, 0x22, 0x14, 0x08, 0x00 }, // > 0x3E
    { 0x02, 0x01, 0x51, 0x09, 0x06, 0x00 }, // ? 0x3F
    { 0x32, 0x49, 0x79, 0x41, 0x3e, 0x00 }, // @ 0x40
    { 0x7e, 0x11, 0x11, 0x11, 0x7e, 0x00 }, // A 0x41
    { 0x7f, 0x49, 0x49, 0x49, 0x36, 0x00 }, // B 0x42
    { 0x3e, 0x41, 0x41, 0x41, 0x22, 0x00 }, // C 0x43
    { 0x7f, 0x41, 0x41, 0x22, 0x1c, 0x00 }, // D 0x44
    { 0x7f, 0x49, 0x49, 0x49, 0x41, 0x00 }, // E 0x45
    { 0x7f, 0x09, 0x09, 0x09, 0x01, 0x00 }, // F 0x46
    { 0x3e, 0x41, 0x49, 0x49, 0x7a, 0x00 }, // G 0x47
    { 0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00 }, // H 0x48
    { 0x00, 0x41, 0x7f, 0x41, 0x00, 0x00 }, // I 0x49
    { 0x20, 0x40, 0x41, 0x3f, 0x01, 0x00 }, // J 0x4A
    { 0x7f, 0x08, 0x14, 0x22, 0x41, 0x00 }, // K 0x4B
    { 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00 }, // L 0x4C
    { 0x7f, 0x02, 0x0c, 0x02, 0x7f, 0x00 }, // M 0x4D
    { 0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00 }, // N 0x4E
    { 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00 }, // O 0x4F
    { 0x7f, 0x09, 0x09, 0x09, 0x06, 0x00 }, // P 0x50
    { 0x3e, 0x41, 0x51, 0x21, 0x5e, 0x00 }, // Q 0x51
    { 0x7f, 0x09, 0x19, 0x29, 0x46, 0x00 }, // R 0x52
    { 0x46, 0x49, 0x49, 0x49, 0x31, 0x00 }, // S 0x53
    { 0x01, 0x01, 0x7f, 0x01, 0x01, 0x00 }, // T 0x54
    { 0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00 }, // U 0x55
    { 0x1f, 0x20, 0x40, 0x20, 0x1f, 0x00 }, // V 0x56
    { 0x3f, 0x40, 0x38, 0x40, 0x3f, 0x00 }, // W 0x57
    { 0x63, 0x14, 0x08, 0x14, 0x63, 0x00 }, // X 0x58
    { 0x07, 0x08, 0x70, 0x08, 0x07, 0x00 }, // Y 0x59
    { 0x61, 0x51, 0x49, 0x45, 0x43, 0x00 }, // Z 0x5A
    { 0x00, 0x7f, 0x41, 0x41, 0x00, 0x00 }, // [ 0x5B
    { 0x02, 0x04, 0x08, 0x10, 0x20, 0x00 }, // "\" 0x5C
    { 0x00, 0x41, 0x41, 0x7f, 0x00, 0x00 }, // ] 0x5D
    { 0x04, 0x02, 0x01, 0x02, 0x04, 0x00 }, // ^ 0x5E
    { 0x40, 0x40, 0x40, 0x40, 0x40, 0x00 }, // _ 0x5F
    { 0x00, 0x01, 0x02, 0x04, 0x00, 0x00 }, // ` 0x60
    { 0x20, 0x54, 0x54, 0x54, 0x78, 0x00 }, // a 0x61
    { 0x7f, 0x48, 0x44, 0x44, 0x38, 0x00 }, // b 0x62
    { 0x38, 0x44, 0x44, 0x44, 0x20, 0x00 }, // c 0x63
    { 0x38, 0x44, 0x44, 0x48, 0x7f, 0x00 }, // d 0x64
    { 0x38, 0x54, 0x54, 0x54, 0x18, 0x00 }, // e 0x65
    { 0x08, 0x7e, 0x09, 0x01, 0x02, 0x00 }, // f 0x66
    { 0x0c, 0x52, 0x52, 0x52, 0x3e, 0x00 }, // g 0x67
    { 0x7f, 0x08, 0x04, 0x04, 0x78, 0x00 }, // h 0x68
    { 0x00, 0x44, 0x7d, 0x40, 0x00, 0x00 }, // i 0x69
    { 0x20, 0x40, 0x44, 0x3d, 0x00, 0x00 }, // j 0x6A
    { 0x7f, 0x10, 0x28, 0x44, 0x00, 0x00 }, // k 0x6B
    { 0x00, 0x41, 0x7f, 0x40, 0x00, 0x00 }, // l 0x6C
    { 0x7c, 0x04, 0x18, 0x04, 0x78, 0x00 }, // m 0x6D
    { 0x7c, 0x08, 0x04, 0x04, 0x78, 0x00 }, // n 0x6E
    { 0x38, 0x44, 0x44, 0x44, 0x38, 0x00 }, // o 0x6F
    { 0x7c, 0x14, 0x14, 0x14, 0x08, 0x00 }, // p 0x70
    { 0x08, 0x14, 0x14, 0x18, 0x7c, 0x00 }, // q 0x71
    { 0x7c, 0x08, 0x04, 0x04, 0x08, 0x00 }, // r 0x72
    { 0x48, 0x54, 0x54, 0x54, 0x20, 0x00 }, // s 0x73
    { 0x04, 0x3f, 0x44, 0x40, 0x20, 0x00 }, // t 0x74
    { 0x3c, 0x40, 0x40, 0x20, 0x7c, 0x00 }, // u 0x75
    { 0x1c, 0x20, 0x40, 0x20, 0x1c, 0x00 }, // v 0X76
    { 0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00 }, // w 0x77
    { 0x44, 0x28, 0x10, 0x28, 0x44, 0x00 }, // x 0x78
    { 0x0c, 0x50, 0x50, 0x50, 0x3c, 0x00 }, // y 0x79
    { 0x44, 0x64, 0x54, 0x4c, 0x44, 0x00 } // z 0x7A
}; // 6x8dot