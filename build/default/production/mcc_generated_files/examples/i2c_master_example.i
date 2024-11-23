
# 1 "mcc_generated_files/examples/i2c_master_example.c"

# 13 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\stdint.h"
typedef signed char int8_t;

# 20
typedef signed int int16_t;

# 28
typedef __int24 int24_t;

# 36
typedef signed long int int32_t;

# 52
typedef unsigned char uint8_t;

# 58
typedef unsigned int uint16_t;

# 65
typedef __uint24 uint24_t;

# 72
typedef unsigned long int uint32_t;

# 88
typedef signed char int_least8_t;

# 96
typedef signed int int_least16_t;

# 109
typedef __int24 int_least24_t;

# 118
typedef signed long int int_least32_t;

# 136
typedef unsigned char uint_least8_t;

# 143
typedef unsigned int uint_least16_t;

# 154
typedef __uint24 uint_least24_t;

# 162
typedef unsigned long int uint_least32_t;

# 181
typedef signed char int_fast8_t;

# 188
typedef signed int int_fast16_t;

# 200
typedef __int24 int_fast24_t;

# 208
typedef signed long int int_fast32_t;

# 224
typedef unsigned char uint_fast8_t;

# 230
typedef unsigned int uint_fast16_t;

# 240
typedef __uint24 uint_fast24_t;

# 247
typedef unsigned long int uint_fast32_t;

# 268
typedef int32_t intmax_t;

# 282
typedef uint32_t uintmax_t;

# 289
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;

# 4 "C:/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/PIC12-16F1xxx_DFP/1.3.90/xc8\pic\include\__size_t.h"
typedef unsigned size_t;

# 7 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\stdarg.h"
typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);

# 43 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\stdio.h"
struct __prbuf
{
char * ptr;
void (* func)(char);
};

# 29 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\errno.h"
extern int errno;

# 12 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\conio.h"
extern void init_uart(void);

extern char getch(void);
extern char getche(void) __attribute__((__deprecated__));
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);

# 23
extern char * cgets(char *) __attribute__((__deprecated__));
extern void cputs(const char *) __attribute__((__deprecated__));

# 88 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\stdio.h"
extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);


# 180
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);

# 15 "C:\Program Files\Microchip\xc8\v2.46\pic\include\c90\stdbool.h"
typedef unsigned char bool;

# 58 "mcc_generated_files/examples/../i2c_master.h"
typedef enum {
I2C_NOERR,
I2C_BUSY,
I2C_FAIL


} i2c_error_t;

typedef enum
{
I2C_STOP=1,
I2C_RESTART_READ,
I2C_RESTART_WRITE,
I2C_CONTINUE,
I2C_RESET_LINK
} i2c_operations_t;

typedef uint8_t i2c_address_t;
typedef i2c_operations_t (*i2c_callback_t)(void *funPtr);


i2c_operations_t I2C_CallbackReturnStop(void *funPtr);
i2c_operations_t I2C_CallbackReturnReset(void *funPtr);
i2c_operations_t I2C_CallbackRestartWrite(void *funPtr);
i2c_operations_t I2C_CallbackRestartRead(void *funPtr);

# 89
void I2C_Initialize(void);

# 101
i2c_error_t I2C_Open(i2c_address_t address);

# 111
i2c_error_t I2C_Close(void);

# 123
i2c_error_t I2C_MasterOperation(bool read);

# 128
i2c_error_t I2C_MasterWrite(void);

# 133
i2c_error_t I2C_MasterRead(void);

# 142
void I2C_SetTimeout(uint8_t timeOut);

# 152
void I2C_SetBuffer(void *buffer, size_t bufferSize);

# 164
void I2C_SetDataCompleteCallback(i2c_callback_t cb, void *ptr);

# 174
void I2C_SetWriteCollisionCallback(i2c_callback_t cb, void *ptr);

# 184
void I2C_SetAddressNackCallback(i2c_callback_t cb, void *ptr);

# 194
void I2C_SetDataNackCallback(i2c_callback_t cb, void *ptr);

# 204
void I2C_SetTimeoutCallback(i2c_callback_t cb, void *ptr);

# 213
void (*MSSP_InterruptHandler)(void);

# 222
void I2C_SetInterruptHandler(void (* InterruptHandler)(void));

# 54 "mcc_generated_files/examples/i2c_master_example.h"
uint8_t I2C_Read1ByteRegister(i2c_address_t address, uint8_t reg);
uint16_t I2C_Read2ByteRegister(i2c_address_t address, uint8_t reg);
void I2C_Write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data);
void I2C_Write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data);
void I2C_WriteNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadDataBlock(i2c_address_t address, uint8_t reg, uint8_t *data, size_t len);

# 50 "mcc_generated_files/examples/i2c_master_example.c"
typedef struct
{
size_t len;
uint8_t *data;
}i2c_buffer_t;

static i2c_operations_t rd1RegCompleteHandler(void *ptr);
static i2c_operations_t rd2RegCompleteHandler(void *ptr);
static i2c_operations_t wr1RegCompleteHandler(void *ptr);
static i2c_operations_t wr2RegCompleteHandler(void *ptr);
static i2c_operations_t rdBlkRegCompleteHandler(void *ptr);


uint8_t I2C_Read1ByteRegister(i2c_address_t address, uint8_t reg)
{
uint8_t returnValue = 0x00;

while(!I2C_Open(address));
I2C_SetDataCompleteCallback(rd1RegCompleteHandler,&returnValue);
I2C_SetBuffer(&reg,1);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());

return returnValue;
}

uint16_t I2C_Read2ByteRegister(i2c_address_t address, uint8_t reg)
{
uint16_t returnValue =0x00;

while(!I2C_Open(address));
I2C_SetDataCompleteCallback(rd2RegCompleteHandler,&returnValue);
I2C_SetBuffer(&reg,1);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());

return (returnValue << 8 | returnValue >> 8);
}

void I2C_Write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data)
{
while(!I2C_Open(address));
I2C_SetDataCompleteCallback(wr1RegCompleteHandler,&data);
I2C_SetBuffer(&reg,1);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());
}

void I2C_Write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data)
{
while(!I2C_Open(address));
I2C_SetDataCompleteCallback(wr2RegCompleteHandler,&data);
I2C_SetBuffer(&reg,1);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());
}

void I2C_WriteNBytes(i2c_address_t address, uint8_t* data, size_t len)
{
while(!I2C_Open(address));
I2C_SetBuffer(data,len);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());
}

void I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len)
{
while(!I2C_Open(address));
I2C_SetBuffer(data,len);
I2C_MasterRead();
while(I2C_BUSY == I2C_Close());
}

void I2C_ReadDataBlock(i2c_address_t address, uint8_t reg, uint8_t *data, size_t len)
{
i2c_buffer_t bufferBlock;
bufferBlock.data = data;
bufferBlock.len = len;

while(!I2C_Open(address));
I2C_SetDataCompleteCallback(rdBlkRegCompleteHandler,&bufferBlock);
I2C_SetBuffer(&reg,1);
I2C_SetAddressNackCallback((0),(0));
I2C_MasterWrite();
while(I2C_BUSY == I2C_Close());
}

static i2c_operations_t rd1RegCompleteHandler(void *ptr)
{
I2C_SetBuffer(ptr,1);
I2C_SetDataCompleteCallback((0),(0));
return I2C_RESTART_READ;
}

static i2c_operations_t rd2RegCompleteHandler(void *ptr)
{
I2C_SetBuffer(ptr,2);
I2C_SetDataCompleteCallback((0),(0));
return I2C_RESTART_READ;
}

static i2c_operations_t wr1RegCompleteHandler(void *ptr)
{
I2C_SetBuffer(ptr,1);
I2C_SetDataCompleteCallback((0),(0));
return I2C_CONTINUE;
}

static i2c_operations_t wr2RegCompleteHandler(void *ptr)
{
I2C_SetBuffer(ptr,2);
I2C_SetDataCompleteCallback((0),(0));
return I2C_CONTINUE;
}

static i2c_operations_t rdBlkRegCompleteHandler(void *ptr)
{
I2C_SetBuffer(((i2c_buffer_t *)ptr)->data,((i2c_buffer_t*)ptr)->len);
I2C_SetDataCompleteCallback((0),(0));
return I2C_RESTART_READ;
}
