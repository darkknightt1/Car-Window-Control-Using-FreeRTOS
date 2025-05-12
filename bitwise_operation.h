#ifndef BITWISE_OPERATION_H_
#define BITWISE_OPERATION_H_

#define Set_Bit(REGISTER, BIT) (REGISTER |= (1 << BIT))
#define Clear_Bit(REGISTER, BIT) (REGISTER &= ~(1 << BIT))
#define Get_Bit(REGISTER, BIT) ((REGISTER & (1 << BIT)) >> BIT)
#define Toggle_Bit(REGISTER, BIT) (REGISTER ^= (1 << BIT))

#endif


