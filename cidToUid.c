#include <stdio.h>
#include <stdint.h>
void int8Toint32ConvertToshiba(uint32_t* int32ptr, uint8_t* int8ptr);
void int8Toint32ConvertSamsung(uint32_t* int32ptr, uint8_t* int8ptr);
void int8Toint32ConvertHynix(uint32_t* int32ptr, uint8_t * int8ptr);
void print_the_uint32(uint32_t * uint32_ptr);
void int8Toint32ConvertSamsungPtr(uint32_t* int32ptr, uint8_t* int8ptr);

int main(){
	char cid_char[] = "0011002200330044005500660077008800990011";
	uint8_t cid_int_toshiba[] ={0x00,0x11,0x00,0x22,0x00,0x33,0x00,0x44,0x00,0x55,0x00,0x66,
				0x00,0x77,0x00,0x88,0x00,0x99,0x00,0xAA};
	uint8_t cid_int_samsung[] ={0x11,0x22,0x33,0x44,0x55,0x66,
				0x77,0x88,0x99,0xAA,0xBB,0xCC};
	uint8_t cid_int_hynix[] ={0x10,0x20,0x30,0x40,0x50,0x60};
	uint32_t cid_samsung[4] = {0};
	uint32_t cid_toshiba[4] = {0};
	uint32_t cid_hynix[4] = {0};
	uint32_t cid_samsung_dup[4] = {0};
	int8Toint32ConvertSamsung(cid_samsung,cid_int_samsung);	
	int8Toint32ConvertToshiba(cid_toshiba,cid_int_toshiba);
	int8Toint32ConvertHynix(cid_hynix,cid_int_hynix);
	int8Toint32ConvertSamsungPtr(cid_samsung_dup,cid_int_samsung);
	printf("\n--------samsung--------\n");
	print_the_uint32(cid_samsung);
	printf("\n--------toshiba--------\n");
	print_the_uint32(cid_toshiba);
	printf("\n--------hynix----------\n");
	print_the_uint32(cid_hynix);
	printf("\n--------samsung_ptr--------\n");
	print_the_uint32(cid_samsung_dup);
}
void print_the_uint32(uint32_t * uint32_ptr){
	int i;
	for(i = 0 ; i < 4 ; i++){
		printf("0x%8x\n", uint32_ptr[i]);
	}

}
void int8Toint32ConvertSamsungPtr(uint32_t * int32Ptr, uint8_t* int8Ptr){
	int i = 0;
	for(i = 0 ; i < 3; i++){	
		int32Ptr[i] = *(uint32_t *) int8Ptr;
		int8Ptr += 4;
	}
}
void int8Toint32ConvertHynix(uint32_t* int32ptr, uint8_t * int8ptr){
	int32ptr[0] = (uint8_t)0 << 24 | int8ptr[0] << 16 | (uint8_t) 0 << 8 | int8ptr[1];
	int32ptr[1] = (uint8_t)0 << 24 | int8ptr[2] << 16 | (uint8_t) 0 << 8 | int8ptr [3];
	int32ptr[2] = (uint8_t)0 << 24 | int8ptr[4] << 16 | (uint8_t) 0 << 8 | int8ptr[5];
}
void int8Toint32ConvertSamsung(uint32_t* int32ptr, uint8_t* int8ptr){
	int i =0;
	for(i =0 ; i < 3; i++){
		int32ptr[i] = (int8ptr[4*i + 0] << 24 ) | (int8ptr[4*i + 1] << 16 ) |
			(int8ptr[4*i +2] << 8) | (int8ptr[4*i +3] ); 
	}	
} 
void int8Toint32ConvertToshiba(uint32_t* int32ptr, uint8_t* int8ptr){
	int32ptr[0] = int8ptr[1] << 24 | int8ptr[3] << 16 | int8ptr[5] << 8 | int8ptr[7];
	int32ptr[1] = int8ptr[9] << 24 | int8ptr[11] << 16 | int8ptr[13] << 8 | int8ptr[15];
	int32ptr[2] = int8ptr[17] << 24 | int8ptr[19] << 16 | (uint8_t)0 << 8 |(uint8_t) 0;
}

