#include <iostream>

using namespace std;

#define LW_SIZE 32
#define DW_SIZE 64

#define BIT_MASK( data, bit )                          ( (data) & (1<<(bit)) )
#define BIT_EXT( data, bit )                           ( (BIT_MASK( data, bit ) >> (bit)) & 1 )
#define FIELD_MASK( msb, lsb )                         ( (~0 << (lsb)) & ((unsigned int)~0 >> (LW_SIZE-(msb)-1)) )
#define FIELD_EXT( data, msb, lsb )                    ( ((data) >> (lsb)) & ~(~((uint64_t) 0) << ((msb)-(lsb)+1)) )
#define BIT_INSERT( word, data_bit, bit )              { if ( data_bit ) word |= (1<<(bit)); else word &= ~(1<<(bit)); }
#define FIELD_INSERT( word, data, msb, lsb )           { word &= ~FIELD_MASK( msb, lsb ); word |= (data) << (lsb); }


#define BIT_MASK_64( data, bit )                       ( (data) & ((uint64_t)1<<(bit)) )
#define BIT_EXT_64( data, bit )                        ( (BIT_MASK_64( data, bit ) >> (bit)) & (uint64_t)1 )
#define FIELD_MASK_64_1( msb, lsb )                    (~((uint64_t)0) << (lsb))
#define FIELD_MASK_64_2( msb, lsb )                    (~((uint64_t)0) >> (DW_SIZE-(msb)-1))
#define FIELD_MASK_64( msb, lsb )                      ( (~((uint64_t)0) << (lsb)) & (~((uint64_t)0) >> (DW_SIZE-(msb)-1)) )
#define FIELD_EXT_64( data, msb, lsb )                 ( ((data) >> (lsb)) & ~(~((uint64_t) 0) << ((msb)-(lsb)+1)) )


#define BIT_INSERT_64( word, data_bit, bit )           { if ( data_bit ) word |= ((uint64_t)1<<(bit)); else word &= ~((uint64_t)1<<(bit)); }
#define FIELD_INSERT_64( word, data, msb, lsb )        { word &= ~FIELD_MASK_64( msb, lsb ); word |= (data) << (lsb); }



int main()
{
    uint32_t val_32 = 0xFFFFFFFF;

    bool bit22 = BIT_EXT(val_32, 22);

    uint32_t fld15_8 = FIELD_EXT(val_32, 15, 8);

    cout << "Data: 0x" << hex << val_32 << ", BIT#22: " << bit22 << ", FIELD[15,8]: 0x" << fld15_8 << endl;

    FIELD_INSERT(val_32, 0, 15, 8);

    cout << hex << "Insert data 0 at [15,8]: 0x" << val_32 << endl;


    uint64_t val_64 = 0xFFFFFFFFFFFFFFFF;

    bool bit42 = BIT_EXT_64(val_64, 42);

    uint64_t fld45_13 = FIELD_EXT_64(val_64, 45, 13);

    cout << "Data: 0x" << hex << val_64 << ", BIT#42: " << bit42 << ", FIELD[45,13]: 0x" << fld45_13 << endl;

    FIELD_INSERT_64(val_64, 0, 45, 13);

    cout << hex << "Insert data 0 at [45,13]: 0x" << val_64 << endl;

    return 0;
}