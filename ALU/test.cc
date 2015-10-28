#include "test.h"

void TEST::do_test()
{
    bool select = false;

    wait();
    wait();
    for (int i=0; ; i++) {
        if (i%4 == 0) {
            select = select ? false : true;
        }
        if (i%4 == 0) {
            alu_in_op = 0x04;
        }
		else if(i%3==0)
			alu_in_op = 0x2;
		else if(i%2==0)
			alu_in_op = 0xC;
		else
			alu_in_op = 0x0;

        alu_is_imm = select;
        alu_in_a = i*5;
        alu_in_b = i*3+1;
        alu_in_imm = i*1;

        wait();
    }
}
