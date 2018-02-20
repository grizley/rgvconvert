#include <stdint.h>
#include <math.h>
#include <io.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <share.h> 


char * buff;
int main(int argc, const char** argv)
{
	if (argc <2)
		exit(1);
	
	int pozycja = 0,fh;
	const int pozoff = 0x46;
	
	_sopen_s(&fh,argv[1],_O_BINARY,_SH_DENYNO,0);
	
	_lseek(fh,pozoff,SEEK_SET);
	long pos_start = _tell(fh);
	
	_lseek(fh,0,SEEK_END);
	long pos_end =  _tell(fh);
	long buffsz = pos_end - pos_start;
	printf("%d\n",buffsz);
	
	buff = (char*) calloc(buffsz , sizeof (uint8_t) );
	printf("malloc buff size: %d \n",sizeof(buff) * sizeof(uint8_t));
	free(buff);
	
	
	/* Wielkość pliku */
	
	_lseek(fh,0,SEEK_END);
	long sizew = _tell(fh);
	printf("wielkosc pliku:%d\n", sizew / 2);
	
	
	_close(fh);
	return 0;
}

 
/*
	#if LOOP == 1
	while(1) {
	#endif
		for (int i=0; i < argc; i++) {
			printf("[param:%d %s] \r",i,argv[i]);
			for(int k=0; k < 50000; k++) ;
		}
		
	#if LOOP == 1
	}
	#endif
*/