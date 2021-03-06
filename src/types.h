#ifndef TYPES_H
#define TYPES_H

// Some external libs include stddef.h
#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef bool
typedef _Bool bool;
#endif

#define true 1
#define false 0

#define auto __auto_type

typedef char i8;
typedef unsigned char u8;
typedef volatile unsigned char vu8;

typedef short i16;
typedef unsigned short u16;
typedef volatile unsigned short vu16;

typedef int i32;
typedef unsigned int u32;
typedef volatile unsigned int vu32;

#endif // TYPES_H