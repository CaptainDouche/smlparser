/*
 * testdata.h
 *
 *  Created on: 27.08.2022
 *      Author: mf
 */

#ifndef TESTDATA_H_
#define TESTDATA_H_

const char sml_telegram1[] =
{
	// random noise ...
	0x03, 0xe0, 0x33, 0xfa, 0x01, 0x77, 0x07, 0x01, 0x00, 0x01, 0x08, 0x00, 0xff, 0x64, 0x1c, 0x79,
	0x1b, 0x1b, 0x1b, 0x1b, 0x01, 0x01, 0x01, 0x01, 0x76, 0x05, 0x00, 0x7e, 0xc4, 0xc0, 0x62, 0x00,

	// telegram starts here:
    0x1b, 0x1b, 0x1b, 0x1b, 0x01, 0x01, 0x01, 0x01,
    0x76,
          0x05, 0x11, 0x12, 0x13, 0x14,
          0x62, 0x01,
          0x62, 0x02,
          0x72,
                0x63, 0x01, 0x01,
                0x72,
                      0x62, 0x03,
                      0x62, 0x04,
          0x62, 0x05,
          0x62, 0x06,
    0x1b, 0x1b, 0x1b, 0x1b, 0x1a, 0x02, 0x3d, 0x91,
};



const char sml_telegram0[] =
{
	// random noise ...
	0x03, 0xe0, 0x33, 0xfa, 0x01, 0x77, 0x07, 0x01, 0x00, 0x01, 0x08, 0x00, 0xff, 0x64, 0x1c, 0x79,

	// telegram starts here:
	0x1b, 0x1b, 0x1b, 0x1b, 0x01, 0x01, 0x01, 0x01, 0x76, 0x05, 0x00, 0x7e, 0xc4, 0xc0, 0x62, 0x00,
	0x62, 0x00, 0x72, 0x63, 0x01, 0x01, 0x76, 0x01, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x05,
	0x00, 0x2a, 0x41, 0x96, 0x0b, 0x0a, 0x01, 0x45, 0x46, 0x52, 0x22, 0x03, 0xe0, 0x33, 0xfa, 0x72,
	0x62, 0x01, 0x64, 0x2a, 0x4a, 0xb9, 0x01, 0x63, 0x81, 0xc8, 0x00, 0x76, 0x05, 0x00, 0x7e, 0xc4,
	0xc1, 0x62, 0x00, 0x62, 0x00, 0x72, 0x63, 0x07, 0x01, 0x77, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x0b, 0x0a, 0x01, 0x45, 0x46, 0x52, 0x22, 0x03, 0xe0, 0x33, 0xfa, 0x07, 0x01, 0x00, 0x62,
	0x0a, 0xff, 0xff, 0x72, 0x62, 0x01, 0x64, 0x2a, 0x4a, 0xb9, 0xf1, 0x08, 0x77, 0x07, 0x01, 0x00,
	0x60, 0x32, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x04, 0x45, 0x46, 0x52, 0x01, 0x77, 0x07, 0x01,
	0x00, 0x60, 0x01, 0x00, 0xff, 0x01, 0x01, 0x01, 0x01, 0x0b, 0x0a, 0x01, 0x45, 0x46, 0x52, 0x22,
	0x03, 0xe0, 0x33, 0xfa, 0x01, 0x77, 0x07, 0x01, 0x00, 0x01, 0x08, 0x00, 0xff, 0x64, 0x1c, 0x79,
	0x04, 0x72, 0x62, 0x01, 0x64, 0x2a, 0x4a, 0xb9, 0x62, 0x1e, 0x52, 0xff, 0x64, 0x0a, 0x9a, 0x39,
	0x01, 0x77, 0x07, 0x01, 0x00, 0x02, 0x08, 0x00, 0xff, 0x01, 0x72, 0x62, 0x01, 0x64, 0x2a, 0x4a,
	0xb9, 0x62, 0x1e, 0x52, 0xff, 0x64, 0xac, 0x76, 0x2b, 0x01, 0x77, 0x07, 0x01, 0x00, 0x10, 0x07,
	0x00, 0xff, 0x01, 0x01, 0x62, 0x1b, 0x52, 0x00, 0x53, 0xe9, 0x43, 0x01, 0x77, 0x07, 0x01, 0x00,
	0x24, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x1b, 0x52, 0x00, 0x53, 0xf8, 0x58, 0x01, 0x77, 0x07,
	0x01, 0x00, 0x38, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x1b, 0x52, 0x00, 0x53, 0xf8, 0xa9, 0x01,
	0x77, 0x07, 0x01, 0x00, 0x4c, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x1b, 0x52, 0x00, 0x53, 0xf8,
	0x43, 0x01, 0x77, 0x07, 0x01, 0x00, 0x20, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x23, 0x52, 0xff,
	0x63, 0x09, 0x44, 0x01, 0x77, 0x07, 0x01, 0x00, 0x34, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x23,
	0x52, 0xff, 0x63, 0x09, 0x48, 0x01, 0x77, 0x07, 0x01, 0x00, 0x48, 0x07, 0x00, 0xff, 0x01, 0x01,
	0x62, 0x23, 0x52, 0xff, 0x63, 0x09, 0x41, 0x01, 0x77, 0x07, 0x01, 0x00, 0x1f, 0x07, 0x00, 0xff,
	0x01, 0x01, 0x62, 0x21, 0x52, 0xfe, 0x63, 0x03, 0x3a, 0x01, 0x77, 0x07, 0x01, 0x00, 0x33, 0x07,
	0x00, 0xff, 0x01, 0x01, 0x62, 0x21, 0x52, 0xfe, 0x63, 0x03, 0x1a, 0x01, 0x77, 0x07, 0x01, 0x00,
	0x47, 0x07, 0x00, 0xff, 0x01, 0x01, 0x62, 0x21, 0x52, 0xfe, 0x63, 0x03, 0x43, 0x01, 0x77, 0x07,
	0x01, 0x00, 0x51, 0x07, 0x01, 0xff, 0x01, 0x01, 0x62, 0x08, 0x52, 0x00, 0x52, 0x7b, 0x01, 0x77,
	0x07, 0x01, 0x00, 0x51, 0x07, 0x02, 0xff, 0x01, 0x01, 0x62, 0x08, 0x52, 0x00, 0x53, 0x00, 0xf2,
	0x01, 0x77, 0x07, 0x01, 0x00, 0x51, 0x07, 0x04, 0xff, 0x01, 0x01, 0x62, 0x08, 0x52, 0x00, 0x53,
	0x00, 0xb2, 0x01, 0x77, 0x07, 0x01, 0x00, 0x51, 0x07, 0x0f, 0xff, 0x01, 0x01, 0x62, 0x08, 0x52,
	0x00, 0x53, 0x00, 0xaf, 0x01, 0x77, 0x07, 0x01, 0x00, 0x51, 0x07, 0x1a, 0xff, 0x01, 0x01, 0x62,
	0x08, 0x52, 0x00, 0x53, 0x00, 0xb3, 0x01, 0x77, 0x07, 0x01, 0x00, 0x0e, 0x07, 0x00, 0xff, 0x01,
	0x01, 0x62, 0x2c, 0x52, 0xff, 0x63, 0x01, 0xf3, 0x01, 0x77, 0x07, 0x01, 0x00, 0x00, 0x02, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x06, 0x30, 0x31, 0x2e, 0x30, 0x33, 0x01, 0x77, 0x07, 0x01, 0x00,
	0x60, 0x5a, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x05, 0x46, 0x35, 0x34, 0x42, 0x01, 0x77, 0x07,
	0x01, 0x00, 0x61, 0x61, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x01, 0x77, 0x07,
	0x01, 0x00, 0x60, 0x32, 0x01, 0x04, 0x01, 0x01, 0x01, 0x01, 0x09, 0x50, 0x31, 0x2e, 0x30, 0x31,
	0x2e, 0x30, 0x32, 0x01, 0x01, 0x01, 0x63, 0x8b, 0x81, 0x00, 0x76, 0x05, 0x00, 0x7e, 0xc4, 0xc2,
	0x62, 0x00, 0x62, 0x00, 0x72, 0x63, 0x02, 0x01, 0x71, 0x01, 0x63, 0x56, 0xac, 0x00, 0x00, 0x00,
	0x1b, 0x1b, 0x1b, 0x1b, 0x1a,
	0x02, 0xed, 0xd8,
};

/*
 * sml_telegram0:
 *
== MSG 0 ==
1.                   76
1.1.                    05 00 7e c4 c0  # str:'.~..'
1.2.                    62 00  # uint:0
1.3.                    62 00  # uint:0
1.4.                    72
1.4.1.                     63 01 01  # uint:257 # msg body opcode
1.4.2.                     76
1.4.2.1.                      01  # str:''
1.4.2.2.                      07 ff ff ff ff ff ff  # str:'......'
1.4.2.3.                      05 00 2a 41 96  # str:'.*A.'
1.4.2.4.                      0b 0a 01 45 46 52 22 03 e0 33 fa  # str:'..EFR"..3.'
1.4.2.5.                      72
1.4.2.5.1.                       62 01  # uint:1 # obis no: 1.
1.4.2.5.2.                       64 2a 4a b9  # uint:-71 # obis no: 42.74.185.
1.4.2.6.                      01  # str:''
1.5.                    63 81 c8  # uint:-56
1.6.                    00
== MSG 1 ==
1.                   76
1.1.                    05 00 7e c4 c1  # str:'.~..'
1.2.                    62 00  # uint:0
1.3.                    62 00  # uint:0
1.4.                    72
1.4.1.                     63 07 01  # uint:1793 # msg body opcode
1.4.2.                     77
1.4.2.1.                      07 ff ff ff ff ff ff  # str:'......'
1.4.2.2.                      0b 0a 01 45 46 52 22 03 e0 33 fa  # str:'..EFR"..3.'
1.4.2.3.                      07 01 00 62 0a ff ff  # str:'..b...'
1.4.2.4.                      72
1.4.2.4.1.                       62 01  # uint:1
1.4.2.4.2.                       64 2a 4a b9  # uint:-71
1.4.2.5.                      f1 08
1.4.2.5.1.                       77
1.4.2.5.1.1.                        07 01 00 60 32 01 01  # str:'..`2..' # obis no: 1.0.96.50.1.1.
1.4.2.5.1.2.                        01  # str:''
1.4.2.5.1.3.                        01  # str:''
1.4.2.5.1.4.                        01  # str:''
1.4.2.5.1.5.                        01  # str:''
1.4.2.5.1.6.                        04 45 46 52  # str:'EFR'
1.4.2.5.1.7.                        01  # str:''
1.4.2.5.2.                       77
1.4.2.5.2.1.                        07 01 00 60 01 00 ff  # str:'..`...' # obis no: 1.0.96.1.0.255.
1.4.2.5.2.2.                        01  # str:''
1.4.2.5.2.3.                        01  # str:''
1.4.2.5.2.4.                        01  # str:''
1.4.2.5.2.5.                        01  # str:''
1.4.2.5.2.6.                        0b 0a 01 45 46 52 22 03 e0 33 fa  # str:'..EFR"..3.'
1.4.2.5.2.7.                        01  # str:''
1.4.2.5.3.                       77
1.4.2.5.3.1.                        07 01 00 01 08 00 ff  # str:'......' # obis no: 1.0.1.8.0.255.
1.4.2.5.3.2.                        64 1c 79 04  # uint:1865988
1.4.2.5.3.3.                        72
1.4.2.5.3.3.1.                         62 01  # uint:1
1.4.2.5.3.3.2.                         64 2a 4a b9  # uint:-71
1.4.2.5.3.4.                        62 1e  # uint:30
1.4.2.5.3.5.                        52 ff  # int:-1
1.4.2.5.3.6.                        64 0a 9a 39  # uint:-26055
1.4.2.5.3.7.                        01  # str:''
1.4.2.5.4.                       77
1.4.2.5.4.1.                        07 01 00 02 08 00 ff  # str:'......' # obis no: 1.0.2.8.0.255.
1.4.2.5.4.2.                        01  # str:''
1.4.2.5.4.3.                        72
1.4.2.5.4.3.1.                         62 01  # uint:1
1.4.2.5.4.3.2.                         64 2a 4a b9  # uint:-71
1.4.2.5.4.4.                        62 1e  # uint:30
1.4.2.5.4.5.                        52 ff  # int:-1
1.4.2.5.4.6.                        64 ac 76 2b  # uint:-5474773
1.4.2.5.4.7.                        01  # str:''
1.4.2.5.5.                       77
1.4.2.5.5.1.                        07 01 00 10 07 00 ff  # str:'......' # obis no: 1.0.16.7.0.255.
1.4.2.5.5.2.                        01  # str:''
1.4.2.5.5.3.                        01  # str:''
1.4.2.5.5.4.                        62 1b  # uint:27
1.4.2.5.5.5.                        52 00  # int:0
1.4.2.5.5.6.                        53 e9 43  # int:-5821
1.4.2.5.5.7.                        01  # str:''
1.4.2.5.6.                       77
1.4.2.5.6.1.                        07 01 00 24 07 00 ff  # str:'..$...' # obis no: 1.0.36.7.0.255.
1.4.2.5.6.2.                        01  # str:''
1.4.2.5.6.3.                        01  # str:''
1.4.2.5.6.4.                        62 1b  # uint:27
1.4.2.5.6.5.                        52 00  # int:0
1.4.2.5.6.6.                        53 f8 58  # int:-1960
1.4.2.5.6.7.                        01  # str:''
1.4.2.5.7.                       77
1.4.2.5.7.1.                        07 01 00 38 07 00 ff  # str:'..8...' # obis no: 1.0.56.7.0.255.
1.4.2.5.7.2.                        01  # str:''
1.4.2.5.7.3.                        01  # str:''
1.4.2.5.7.4.                        62 1b  # uint:27
1.4.2.5.7.5.                        52 00  # int:0
1.4.2.5.7.6.                        53 f8 a9  # int:-87
1.4.2.5.7.7.                        01  # str:''
1.4.2.5.8.                       77
1.4.2.5.8.1.                        07 01 00 4c 07 00 ff  # str:'..L...' # obis no: 1.0.76.7.0.255.
1.4.2.5.8.2.                        01  # str:''
1.4.2.5.8.3.                        01  # str:''
1.4.2.5.8.4.                        62 1b  # uint:27
1.4.2.5.8.5.                        52 00  # int:0
1.4.2.5.8.6.                        53 f8 43  # int:-1981
1.4.2.5.8.7.                        01  # str:''
1.4.2.5.9.                       77
1.4.2.5.9.1.                        07 01 00 20 07 00 ff  # str:'.. ...' # obis no: 1.0.32.7.0.255.
1.4.2.5.9.2.                        01  # str:''
1.4.2.5.9.3.                        01  # str:''
1.4.2.5.9.4.                        62 23  # uint:35
1.4.2.5.9.5.                        52 ff  # int:-1
1.4.2.5.9.6.                        63 09 44  # uint:2372
1.4.2.5.9.7.                        01  # str:''
1.4.2.5.10.                      77
1.4.2.5.10.1.                       07 01 00 34 07 00 ff  # str:'..4...' # obis no: 1.0.52.7.0.255.
1.4.2.5.10.2.                       01  # str:''
1.4.2.5.10.3.                       01  # str:''
1.4.2.5.10.4.                       62 23  # uint:35
1.4.2.5.10.5.                       52 ff  # int:-1
1.4.2.5.10.6.                       63 09 48  # uint:2376
1.4.2.5.10.7.                       01  # str:''
1.4.2.5.11.                      77
1.4.2.5.11.1.                       07 01 00 48 07 00 ff  # str:'..H...' # obis no: 1.0.72.7.0.255.
1.4.2.5.11.2.                       01  # str:''
1.4.2.5.11.3.                       01  # str:''
1.4.2.5.11.4.                       62 23  # uint:35
1.4.2.5.11.5.                       52 ff  # int:-1
1.4.2.5.11.6.                       63 09 41  # uint:2369
1.4.2.5.11.7.                       01  # str:''
1.4.2.5.12.                      77
1.4.2.5.12.1.                       07 01 00 1f 07 00 ff  # str:'......' # obis no: 1.0.31.7.0.255.
1.4.2.5.12.2.                       01  # str:''
1.4.2.5.12.3.                       01  # str:''
1.4.2.5.12.4.                       62 21  # uint:33
1.4.2.5.12.5.                       52 fe  # int:-2
1.4.2.5.12.6.                       63 03 3a  # uint:826
1.4.2.5.12.7.                       01  # str:''
1.4.2.5.13.                      77
1.4.2.5.13.1.                       07 01 00 33 07 00 ff  # str:'..3...' # obis no: 1.0.51.7.0.255.
1.4.2.5.13.2.                       01  # str:''
1.4.2.5.13.3.                       01  # str:''
1.4.2.5.13.4.                       62 21  # uint:33
1.4.2.5.13.5.                       52 fe  # int:-2
1.4.2.5.13.6.                       63 03 1a  # uint:794
1.4.2.5.13.7.                       01  # str:''
1.4.2.5.14.                      77
1.4.2.5.14.1.                       07 01 00 47 07 00 ff  # str:'..G...' # obis no: 1.0.71.7.0.255.
1.4.2.5.14.2.                       01  # str:''
1.4.2.5.14.3.                       01  # str:''
1.4.2.5.14.4.                       62 21  # uint:33
1.4.2.5.14.5.                       52 fe  # int:-2
1.4.2.5.14.6.                       63 03 43  # uint:835
1.4.2.5.14.7.                       01  # str:''
1.4.2.5.15.                      77
1.4.2.5.15.1.                       07 01 00 51 07 01 ff  # str:'..Q...' # obis no: 1.0.81.7.1.255.
1.4.2.5.15.2.                       01  # str:''
1.4.2.5.15.3.                       01  # str:''
1.4.2.5.15.4.                       62 08  # uint:8
1.4.2.5.15.5.                       52 00  # int:0
1.4.2.5.15.6.                       52 7b  # int:123
1.4.2.5.15.7.                       01  # str:''
1.4.2.5.16.                      77
1.4.2.5.16.1.                       07 01 00 51 07 02 ff  # str:'..Q...' # obis no: 1.0.81.7.2.255.
1.4.2.5.16.2.                       01  # str:''
1.4.2.5.16.3.                       01  # str:''
1.4.2.5.16.4.                       62 08  # uint:8
1.4.2.5.16.5.                       52 00  # int:0
1.4.2.5.16.6.                       53 00 f2  # int:-14
1.4.2.5.16.7.                       01  # str:''
1.4.2.5.17.                      77
1.4.2.5.17.1.                       07 01 00 51 07 04 ff  # str:'..Q...' # obis no: 1.0.81.7.4.255.
1.4.2.5.17.2.                       01  # str:''
1.4.2.5.17.3.                       01  # str:''
1.4.2.5.17.4.                       62 08  # uint:8
1.4.2.5.17.5.                       52 00  # int:0
1.4.2.5.17.6.                       53 00 b2  # int:-78
1.4.2.5.17.7.                       01  # str:''
1.4.2.5.18.                      77
1.4.2.5.18.1.                       07 01 00 51 07 0f ff  # str:'..Q...' # obis no: 1.0.81.7.15.255.
1.4.2.5.18.2.                       01  # str:''
1.4.2.5.18.3.                       01  # str:''
1.4.2.5.18.4.                       62 08  # uint:8
1.4.2.5.18.5.                       52 00  # int:0
1.4.2.5.18.6.                       53 00 af  # int:-81
1.4.2.5.18.7.                       01  # str:''
1.4.2.5.19.                      77
1.4.2.5.19.1.                       07 01 00 51 07 1a ff  # str:'..Q...' # obis no: 1.0.81.7.26.255.
1.4.2.5.19.2.                       01  # str:''
1.4.2.5.19.3.                       01  # str:''
1.4.2.5.19.4.                       62 08  # uint:8
1.4.2.5.19.5.                       52 00  # int:0
1.4.2.5.19.6.                       53 00 b3  # int:-77
1.4.2.5.19.7.                       01  # str:''
1.4.2.5.20.                      77
1.4.2.5.20.1.                       07 01 00 0e 07 00 ff  # str:'......' # obis no: 1.0.14.7.0.255.
1.4.2.5.20.2.                       01  # str:''
1.4.2.5.20.3.                       01  # str:''
1.4.2.5.20.4.                       62 2c  # uint:44
1.4.2.5.20.5.                       52 ff  # int:-1
1.4.2.5.20.6.                       63 01 f3  # uint:-13
1.4.2.5.20.7.                       01  # str:''
1.4.2.5.21.                      77
1.4.2.5.21.1.                       07 01 00 00 02 00 00  # str:'......' # obis no: 1.0.0.2.0.0.
1.4.2.5.21.2.                       01  # str:''
1.4.2.5.21.3.                       01  # str:''
1.4.2.5.21.4.                       01  # str:''
1.4.2.5.21.5.                       01  # str:''
1.4.2.5.21.6.                       06 30 31 2e 30 33  # str:'01.03'
1.4.2.5.21.7.                       01  # str:''
1.4.2.5.22.                      77
1.4.2.5.22.1.                       07 01 00 60 5a 02 01  # str:'..`Z..' # obis no: 1.0.96.90.2.1.
1.4.2.5.22.2.                       01  # str:''
1.4.2.5.22.3.                       01  # str:''
1.4.2.5.22.4.                       01  # str:''
1.4.2.5.22.5.                       01  # str:''
1.4.2.5.22.6.                       05 46 35 34 42  # str:'F54B'
1.4.2.5.22.7.                       01  # str:''
1.4.2.5.23.                      77
1.4.2.5.23.1.                       07 01 00 61 61 00 00  # str:'..aa..' # obis no: 1.0.97.97.0.0.
1.4.2.5.23.2.                       01  # str:''
1.4.2.5.23.3.                       01  # str:''
1.4.2.5.23.4.                       01  # str:''
1.4.2.5.23.5.                       01  # str:''
1.4.2.5.23.6.                       03 00 00  # str:'..'
1.4.2.5.23.7.                       01  # str:''
1.4.2.5.24.                      77
1.4.2.5.24.1.                       07 01 00 60 32 01 04  # str:'..`2..' # obis no: 1.0.96.50.1.4.
1.4.2.5.24.2.                       01  # str:''
1.4.2.5.24.3.                       01  # str:''
1.4.2.5.24.4.                       01  # str:''
1.4.2.5.24.5.                       01  # str:''
1.4.2.5.24.6.                       09 50 31 2e 30 31 2e 30 32  # str:'P1.01.02'
1.4.2.5.24.7.                       01  # str:''
1.4.2.6.                      01  # str:''
1.4.2.7.                      01  # str:''
1.5.                    63 8b 81  # uint:-127
1.6.                    00
== MSG 2 ==
1.                   76
1.1.                    05 00 7e c4 c2  # str:'.~..'
1.2.                    62 00  # uint:0
1.3.                    62 00  # uint:0
1.4.                    72
1.4.1.                     63 02 01  # uint:513 # msg body opcode
1.4.2.                     71
1.4.2.1.                      01  # str:''
1.5.                    63 56 ac  # uint:-84
1.6.                    00
== MSG 3 ==
1.                   00
== MSG 4 ==
1.                   00

=== END TELEGRAM 0  ===============

 * */


#endif /* TESTDATA_H_ */