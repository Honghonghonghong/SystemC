#include "test.h"

void TEST::do_test()
{
	/*
	sc_in<uint32_t> addr;
	sc_in<uint32_t> din;
	sc_in<bool> is_rd, is_wr;
	
		sc_in<bool> clock;
	sc_out<uint32_t> mem_addr, mem_din;
	sc_out<bool> mem_is_rd, mem_is_wr;
	
	sc_in<uint32_t> mem_dout;//del
	
	*/
	
	wait();
	
	for(int i=0; i<10; i++){
	
		mem_is_wr = true;
		mem_addr = i;
		mem_din = i;
		wait();
	}
	for(int i=1; i<11; i++){
	
		mem_is_wr = true;
		mem_addr = i*5;
		mem_din = i*100+i*10+i;
		wait();
	}
	
	mem_is_wr = false;
	for(int i=0; ; i++){
		mem_is_rd = true;
		mem_addr = i;
		wait();
	}

}


