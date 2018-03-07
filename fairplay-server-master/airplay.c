#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fairplay.h"

#ifdef DEBUG
#define dprintf printf
#else
#define dprintf(...) 
#endif


void print_buf(unsigned char *name, unsigned char *buf, int size)
{
  int i;
  printf("%s at addr %p, size=%d\n", name, buf, size);
  for (i=0; i<size; i++)
    printf("0x%02x ", buf[i]);
  printf("\n");
}

int main(int argc, char **argv)
{
#if 0
  unsigned char fply_1[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x04,0x02,0x00,0x01,0xbb};
  unsigned char fply_2[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x82,0x02,0x01,0xcf,0x32,0xa2,0x57,0x14,0xb2,0x52,0x4f,0x8a,0xa0,0xad,0x7a,0xf1,0x64,0xe3,0x7b,0xcf,0x44,0x24,0xe2,0x00,0x04,0x7e,0xfc,0x0a,0xd6,0x7a,0xfc,0xd9,0x5d,0xed,0x1c,0x27,0x30,0xbb,0x59,0x1b,0x96,0x2e,0xd6,0x3a,0x9c,0x4d,0xed,0x88,0xba,0x8f,0xc7,0x8d,0xe6,0x4d,0x91,0xcc,0xfd,0x5c,0x7b,0x56,0xda,0x88,0xe3,0x1f,0x5c,0xce,0xaf,0xc7,0x43,0x19,0x95,0xa0,0x16,0x65,0xa5,0x4e,0x19,0x39,0xd2,0x5b,0x94,0xdb,0x64,0xb9,0xe4,0x5d,0x8d,0x06,0x3e,0x1e,0x6a,0xf0,0x7e,0x96,0x56,0x16,0x2b,0x0e,0xfa,0x40,0x42,0x75,0xea,0x5a,0x44,0xd9,0x59,0x1c,0x72,0x56,0xb9,0xfb,0xe6,0x51,0x38,0x98,0xb8,0x02,0x27,0x72,0x19,0x88,0x57,0x16,0x50,0x94,0x2a,0xd9,0x46,0x68,0x8a};
  unsigned char fply_3[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x03,0x00,0x00,0x00,0x00,0x98,0x01,0x8f,0x1a,0x9c,0xbe,0x45,0x38,0x77,0x4c,0x68,0x85,0x7d,0x63,0x26,0x9a,0x9f,0xc2,0x72,0xe4,0x61,0x24,0x04,0x51,0xc0,0x8d,0x39,0xf0,0x3f,0x9c,0x99,0xe6,0x69,0x41,0x73,0x1d,0x4b,0xb4,0x91,0x59,0xdc,0x1f,0x8b,0xa5,0xb9,0x57,0xda,0xd4,0x88,0xab,0x49,0xb6,0x4c,0x6b,0x77,0xf6,0xb2,0x2f,0x4f,0x79,0xae,0xd0,0x3e,0x4a,0x18,0x20,0x98,0xd1,0xa8,0x20,0x93,0xaa,0xdf,0x6d,0x33,0x0d,0x58,0x6d,0xe0,0x90,0x90,0x93,0x87,0xc2,0x56,0xf9,0x47,0xd7,0x81,0x0c,0xe2,0x90,0x34,0x1f,0x59,0xaf,0xd7,0x32,0x43,0x6b,0x0b,0x77,0xfb,0xf6,0xc9,0xd9,0x2a,0x42,0xaa,0x3f,0x17,0xc3,0xc9,0x95,0x61,0xa2,0xc6,0xcb,0xff,0xf4,0x55,0x5c,0x3e,0xa3,0x7b,0x14,0x8f,0xd0,0xcf,0x22,0x86,0x75,0x09,0xf0,0x81,0x8d,0xb4,0x3f,0x30,0x7f,0x7c,0xac,0x3c,0x3c,0x91,0x50,0xa3,0x17,0xd1,0x46,0xdb,0x5d,0xd8};
  unsigned char fply_4[] = {
0x46,0x50,0x4c,0x59,0x03,0x01,0x04,0x00,0x00,0x00,0x00,0x14,0xf0,0x81,0x8d,0xb4,0x3f,0x30,0x7f,0x7c,0xac,0x3c,0x3c,0x91,0x50,0xa3,0x17,0xd1,0x46,0xdb,0x5d,0xd8};

  unsigned char fpaesstr[]= {0x46,0x50,0x4c,0x59,0x01,0x02,0x01,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0x03,0x12,0xba,0xd6,0xe2,0x97,0xc1,0x68,0xa3,0x89,0xac,0xbb,0xa1,0xda,0x92,0x2a,0x00,0x00,0x00,0x10,0x35,0x33,0xb1,0x16,0x1e,0x43,0xc6,0x19,0xeb,0xd9,0xd5,0xf2,0x83,0x32,0xcf,0xb7,0x03,0x30,0xbe,0x88,0xd7,0x26,0x7d,0xb0,0xaf,0xf5,0xe9,0x36,0x1b,0x1f,0x49,0xa8,0x06,0xac,0xa6,0x28};

 unsigned char aeskey[] = {0x2f,0xe8,0x17,0xe3,0xf6,0xbb,0x72,0x8b,0x5a,0xd2,0x05,0x3d,0x4d,0x77,0x18,0x6f};
#endif
#if 0
  unsigned char fply_1[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x04,0x02,0x00,0x03,0xbb};
  unsigned char fply_2[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x82,0x02,0x03,0x90,0x01,0xe1,0x72,0x7e,0x0f,0x57,0xf9,0xf5,0x88,0x0d,0xb1,0x04,0xa6,0x25,0x7a,0x23,0xf5,0xcf,0xff,0x1a,0xbb,0xe1,0xe9,0x30,0x45,0x25,0x1a,0xfb,0x97,0xeb,0x9f,0xc0,0x01,0x1e,0xbe,0x0f,0x3a,0x81,0xdf,0x5b,0x69,0x1d,0x76,0xac,0xb2,0xf7,0xa5,0xc7,0x08,0xe3,0xd3,0x28,0xf5,0x6b,0xb3,0x9d,0xbd,0xe5,0xf2,0x9c,0x8a,0x17,0xf4,0x81,0x48,0x7e,0x3a,0xe8,0x63,0xc6,0x78,0x32,0x54,0x22,0xe6,0xf7,0x8e,0x16,0x6d,0x18,0xaa,0x7f,0xd6,0x36,0x25,0x8b,0xce,0x28,0x72,0x6f,0x66,0x1f,0x73,0x88,0x93,0xce,0x44,0x31,0x1e,0x4b,0xe6,0xc0,0x53,0x51,0x93,0xe5,0xef,0x72,0xe8,0x68,0x62,0x33,0x72,0x9c,0x22,0x7d,0x82,0x0c,0x99,0x94,0x45,0xd8,0x92,0x46,0xc8,0xc3,0x59 };
  unsigned char fply_3[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x03,0x00,0x00,0x00,0x00,0x98,0x03,0x8f,0x1a,0x9c,0x44,0xd2,0x0d,0xa9,0xa4,0xf1,0x23,0xb9,0xae,0x4a,0xa8,0xb9,0x1a,0xac,0x41,0xce,0xa6,0x5a,0xd2,0x0a,0x7b,0xd2,0x19,0xfd,0x05,0x9a,0x7c,0x1d,0x12,0xa7,0x43,0xc5,0x44,0x77,0x03,0xff,0x86,0xbc,0xd5,0x50,0xed,0x36,0x63,0x1a,0xc9,0xf7,0x8a,0x99,0xa0,0xcf,0x31,0x60,0x43,0x73,0x87,0xbb,0x9b,0xa5,0x1c,0xc8,0x4c,0x90,0x11,0x96,0x00,0x4f,0x80,0x84,0x85,0xa6,0xfd,0xe1,0x1c,0x19,0x07,0xb5,0xb8,0xf8,0xb5,0xf7,0xf5,0x0c,0xbc,0x9b,0x78,0x02,0x22,0xd1,0x7f,0x56,0x22,0xbe,0x5d,0x1a,0xff,0x17,0x79,0xc1,0x7e,0x57,0x8d,0xf9,0xbe,0xae,0x92,0xaf,0x75,0xb8,0xdf,0xbc,0xaa,0xa1,0xeb,0xe3,0x5f,0x26,0x08,0x04,0x6d,0xdc,0xfc,0xaa,0x50,0xe0,0xcf,0xb8,0xf3,0x50,0x5b,0x96,0x70,0x6c,0xd2,0x00,0x22,0x0e,0x86,0x5d,0xf6,0x57,0x52,0x69,0x94,0x43,0x20,0xf6,0xb7,0xb4
};
  unsigned char fply_4[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x04,0x00,0x00,0x00,0x00,0x14,0x5b,0x96,0x70,0x6c,0xd2,0x00,0x22,0x0e,0x86,0x5d,0xf6,0x57,0x52,0x69,0x94,0x43,0x20,0xf6,0xb7,0xb4 };

  unsigned char fpaesstr[]= {0x46,0x50,0x4c,0x59,0x01,0x02,0x01,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0x7e,0xd7,0xff,0x53,0x41,0x4b,0x30,0x7d,0x33,0x65,0x01,0xa9,0x75,0xa7,0xc9,0xc4,0x00,0x00,0x00,0x10,0x24,0x9a,0x7d,0xa7,0xf0,0xcc,0xb9,0xb2,0x87,0x92,0x47,0xd7,0x24,0x5c,0xfc,0xf1,0xbe,0x8a,0x16,0x6f,0xf5,0x28,0x3f,0xd2,0xf0,0x79,0x5d,0xc3,0xe1,0x57,0xd0,0xbb,0x4f,0xd1,0x7c,0x58};

 unsigned char aeskey[] = {0x56,0x2a,0x3f,0x38,0xcb,0x9b,0xac,0x1e,0xd7,0x7a,0xda,0x27,0xf3,0xe0,0xb2,0xda};
#endif
  /* *v = 0*/
  unsigned char fply_1[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x04,0x02,0x00,0x01,0xbb};
  unsigned char fply_2[] = {0x46,0x50,0x4c,0x59,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x82,0x02,0x01,0x18,0x01,0x16,0x9e,0x47,0xaa,0x15,0x8b,0x97,0x85,0x57,0x14,0x69,0x35,0x18,0xf8,0xcc,0xc7,0xec,0x08,0x8b,0xd2,0x7f,0xe9,0xea,0x46,0xb9,0xfb,0xe6,0xa0,0x7d,0x88,0xe4,0xa3,0x2e,0x76,0x64,0x1b,0x4a,0x6b,0xe9,0x45,0xca,0x5f,0x36,0xba,0x6c,0x40,0xb6,0x46,0xd2,0x37,0xf5,0x2c,0xbe,0x6f,0x5e,0x86,0xcc,0x3f,0xff,0x96,0x7a,0x65,0x57,0x60,0x01,0xf6,0x12,0x68,0x1f,0xe1,0x41,0x3e,0x0a,0x53,0x4b,0x2d,0x3c,0x99,0xf1,0xd0,0xdf,0x67,0x00,0x65,0x94,0x2d,0x46,0xb1,0x59,0x45,0xff,0x7f,0x7c,0x79,0xed,0x0c,0x06,0xbd,0x47,0x46,0x29,0xc8,0xe2,0xdb,0x8c,0xb4,0x03,0xa9,0x7a,0xe3,0x1b,0xb3,0x1c,0x56,0xa9,0x40,0x06,0xc2,0x02,0x3d,0x0b,0x75,0xcd,0x98,0x1d,0x15};
  unsigned char fply_3[] = { 0x46,0x50,0x4c,0x59,0x03,0x01,0x03,0x00,0x00,0x00,0x00,0x98,0x01,0x8f,0x1a,0x9c,0xf1,0xc8,0xc1,0x06,0x5a,0xe2,0x7e,0x96,0xfd,0x54,0x8f,0xe9,0x38,0xbe,0x2b,0x9e,0xbc,0x0b,0x7a,0xed,0x2c,0x8a,0xc2,0x44,0xf8,0x33,0x38,0x2b,0xb5,0xc4,0xb9,0xce,0x88,0x46,0xaa,0x24,0xe3,0xde,0x6c,0x74,0xd2,0xae,0xb3,0x99,0x5a,0xc9,0xc5,0x1e,0xd1,0xd1,0x70,0x65,0xfe,0x52,0xb3,0x0d,0xe3,0xf3,0x67,0x6e,0xc2,0xdc,0xa5,0x7b,0x45,0xc7,0x1b,0x9d,0xbb,0xb6,0x7e,0xe6,0x58,0x06,0xcd,0x98,0xe4,0x9e,0x43,0xa6,0x0f,0xb5,0x8d,0xed,0xbd,0x5e,0x27,0xa1,0xdf,0x23,0xff,0xc1,0x28,0x85,0x8d,0x0a,0x24,0xa2,0x68,0xcf,0xc1,0x95,0x8a,0x18,0xe2,0x10,0x87,0x27,0x67,0xcc,0x9e,0x4a,0xd2,0x80,0x56,0x53,0x07,0xac,0xa0,0xe7,0xda,0x41,0x9b,0xc4,0x80,0xcc,0x13,0x06,0x0f,0x9b,0xba,0x15,0xa2,0xd6,0xe1,0x68,0xd5,0xf9,0xd4,0x46,0x53,0xbc,0xc7,0x4b,0x71,0x50,0x80,0x9b};
  unsigned char fply_4[] = { 0x46,0x50,0x4c,0x59,0x03,0x01,0x04,0x00,0x00,0x00,0x00,0x14,0x0f,0x9b,0xba,0x15,0xa2,0xd6,0xe1,0x68,0xd5,0xf9,0xd4,0x46,0x53,0xbc,0xc7,0x4b,0x71,0x50,0x80,0x9b };

  unsigned char fpaesstr[]= {0x46,0x50,0x4c,0x59,0x01,0x02,0x01,0x00,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0xc1,0x4b,0xb8,0x45,0xcd,0x1d,0x46,0x9d,0xf1,0xac,0x69,0x3e,0x61,0xc2,0xa6,0xbb,0x00,0x00,0x00,0x10,0x74,0x98,0xfc,0x86,0xd4,0xaa,0x4d,0x75,0xa6,0xf5,0xc7,0x38,0xfc,0x21,0x6d,0xc6,0x41,0x99,0x3d,0xe0,0x5c,0x5d,0x16,0x55,0x37,0xad,0xdb,0xd5,0x87,0xaa,0xcf,0x55,0x42,0xfb,0xe0,0x91};

 unsigned char aeskey[] = {0x40,0xdd,0xb0,0xa1,0x22,0x04,0x49,0xe2,0x94,0xd1,0xff,0x44,0xc2,0x4e,0x58,0xb7};

  unsigned char *outbuf;
  int outsize;
  unsigned char hwinfo[24];
  unsigned char *sapbuf;
  unsigned char c;
  extern int debug;

//  debug = 1;

  airplay_load_hwinfo(hwinfo);
  print_buf("hwinfo", hwinfo, 24);
  airplay_initialize_sap(hwinfo, &sapbuf);
  print_buf("sapbuf", sapbuf, 276);
  airplay_process_fpsetup_message(3, hwinfo, sapbuf, fply_1, &outbuf, &outsize, &c);
  print_buf("fp-setup reply phase1", outbuf, outsize);

  if (memcmp(outbuf, fply_2, outsize) != 0) {
  	printf("wrong result!\n");
	return -1;
  }

  airplay_process_fpsetup_message(3, hwinfo, sapbuf, fply_3, &outbuf, &outsize, &c);
  print_buf("fp-setup reply phase2", outbuf, outsize);
  if (memcmp(outbuf, fply_4, outsize) != 0) {
  	printf("wrong result!\n");
	return -2;
  }

  airplay_get_encryption_key(sapbuf, fpaesstr, sizeof(fpaesstr), &outbuf, &outsize);
  print_buf("aeskey", outbuf, outsize);
  if (memcmp(outbuf, aeskey, outsize) != 0) {
  	printf("wrong result!\n");
	return -3;
  }
}
