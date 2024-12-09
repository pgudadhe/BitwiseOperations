#include <iostream>

#define LW_SIZE 32
#define DW_SIZE 64

#define BIT_MASK( data, bit )                          ( (data) & (1<<(bit)) )
#define BIT_EXT( data, bit )                           ( (BIT_MASK( data, bit ) >> (bit)) & 1 )
#define FIELD_MASK( msb, lsb )                         ( (~0 << (lsb)) & ((unsigned int)~0 >> (LW_SIZE-(msb)-1)) )
#define FIELD_EXT( data, msb, lsb )                    ( ((data) >> (lsb)) & ~(~((uint64_t) 0) << ((msb)-(lsb)+1)) )
#define BIT_INSERT( word, data_bit, bit )              { if ( data_bit ) word |= (1<<(bit)); else word &= ~(1<<(bit)); }
#define FIELD_INSERT( word, data, msb, lsb )           { word &= ~FIELD_MASK( msb, lsb ); word |= (data) << (lsb); }


#define BIT_MASK_64( data, bit )                          ( (data) & ((uint64_t)1<<(bit)) )
#define BIT_EXT_64( data, bit )                           ( (BIT_MASK_64( data, bit ) >> (bit)) & (uint64_t)1 )
#define FIELD_MASK_64_1( msb, lsb )                       (~((uint64_t)0) << (lsb))
#define FIELD_MASK_64_2( msb, lsb )                       (~((uint64_t)0) >> (DW_SIZE-(msb)-1))
#define FIELD_MASK_64( msb, lsb )                         ( (~((uint64_t)0) << (lsb)) & (~((uint64_t)0) >> (DW_SIZE-(msb)-1)) )
#define FIELD_EXT_64( data, msb, lsb )                    ( ((data) >> (lsb)) & ~(~((uint64_t) 0) << ((msb)-(lsb)+1)) )


#define BIT_INSERT_64( word, data_bit, bit )   { if ( data_bit ) word |= ((uint64_t)1<<(bit)); else word &= ~((uint64_t)1<<(bit)); }
#define FIELD_INSERT_64( word, data, msb, lsb )  { word &= ~FIELD_MASK_64( msb, lsb ); word |= (data) << (lsb); }



int main()
{
    uint64_t rd_addr = 0x801544;

    bool is_VF = BIT_EXT_64(rd_addr, 22);
    unsigned int func_num = FIELD_EXT_64(rd_addr, 29, 23);

    unsigned int absolute_fnum = is_VF * 4 + func_num;

    // Clearing bits 22 - 29
    FIELD_INSERT_64(rd_addr, 0, 29, 22);

    //BIT_INSERT_64(mynum, 0, 16);
    //BIT_INSERT_64(mynum, 0, 61);

    //bool a = BIT_EXT_64(mynum, 61);
    //a = BIT_EXT_64(mynum, 62);

    //uint64_t mynum1 = BIT_MASK_64(mynum, 0);
    //mynum1 = BIT_MASK_64(mynum, 63);

    //mynum1 = FIELD_MASK(7, 0);
    //mynum1 = FIELD_MASK_64(63, 32);

    //mynum1 = FIELD_EXT_64(mynum, 63, 60);
    //FIELD_INSERT_64(mynum, 0, 63, 60);

    //FIELD_INSERT_64(mynum, 0, 32, 24);
    //FIELD_INSERT_64(mynum, 0, 60, 55);


    return 0;
}