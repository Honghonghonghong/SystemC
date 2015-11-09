#include "mem.h"

void MEM::do_mem()
{
	if(is_rd && is_wr){
		cout << "err : R and W true!" <<endl;
	}else if(addr>=size){
		cout << "addr : error bound" <<endl;
	}
	else{
		if(is_rd)
		{
			dout = mem_data[addr];
		}
		else if(is_wr)
		{
		
			mem_data[addr] = din;
			//쓰기에서 출력은 입력한 결과를 출력
			dout = mem_data[addr];
		}
	}
}
