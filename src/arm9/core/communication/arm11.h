#ifndef ARM_CORE_COMMUNICATION_H
#define ARM_CORE_COMMUNICATION_H

typedef enum {
  NONE = 0,
  TEST = 1,
} Arm9Message;

// Shared memory region for ARM9 core to talk to ARM11 core
#define ARM11_COMMUNICATION_REGION 0x1FF80000

void send_message(Arm9Message msg);

#endif // ARM_CORE_COMMUNICATION_H