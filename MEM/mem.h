#include "systemc.h"
#include <stdint.h>

SC_MODULE(MEM)
{
	sc_in<uint32_t> addr;
	sc_in<uint32_t> din;
	sc_in<bool> is_rd, is_wr;

	sc_out<uint32_t> dout;

	uint32_t *mem_data;
	
	uint32_t size;

	void do_mem();
	void init_mem(const char *int_file_name);

	SC_HAS_PROCESS(MEM);

	MEM(sc_module_name _name, const char *init_file_name, uint32_t mem_size)
		: sc_module(_name)
	{
		size = mem_size;
		mem_data = (uint32_t*)malloc(sizeof(uint32_t)*mem_size);
		
		SC_METHOD(do_mem);//순서 주의
		sensitive << addr << din << is_rd << is_wr;
		
		
		
		dout.initialize(0);
	}
};
