#ifndef __CRC16_H__
#define __CRC16_H__

#define DCC_CRC_CHECK

#define CRC16_NUM_CHECK 16

extern const uint16_t crc16tab[];

static inline uint16_t CRC16(const void *buff) 
{
	const char *buf = (char *) buff;
	int i;
	uint16_t crc = 0;
	int stride = 4096 / CRC16_NUM_CHECK;
	//for (i = 0; i < len; i++)
	for (i = 0; i < 4096; i += stride) {
		crc = (crc << 8) ^ crc16tab[((crc >> 8) ^ *buf) & 0x00FF];
		buf += stride;
	}
	return crc;
}

#ifdef DCC_CRC_CHECK
static inline uint16_t CRC16_CHECK(uint16_t crc16, void *buff)
{
	return crc16 != CRC16(buff) ? 1 : 0;
}
#else 
static inline uint16_t CRC16_CHECK(uint16_t crc16, void *buff) { return 0; }
#endif

#endif // __CRC16_H__
