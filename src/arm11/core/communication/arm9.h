#ifndef ARM_CORE_COMMUNICATION_H
#define ARM_CORE_COMMUNICATION_H

typedef enum {
  NONE = 0,
  TEST = 1,
} Arm9Message;

Arm9Message handle_message(void);

#endif // ARM_CORE_COMMUNICATION_H