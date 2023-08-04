# smlparser
Parses binary files of serial smart meter output data for SML telegrams


Get a serial optical reader, connect it to a serial terminal programm (9600, 8N1) and look at the output.
If there are periodically arriving data blocks starting abbout like ...
```
1b 1b 1b 1b 01 01 01 01 76 05 03 ...
```
... then its likely that your meter spits out SML telegrams.
Record this output to a binary file. YOu dont have to align the files begin and end to the datagrams.

Then feed this output to the smlparser binary (will compile using gcc in Linux or MinGW under Windows and is also used in my ESP-implementation).

If the output looks similar to this then you will get the values you are probably most interested (watt consumption right now, total watthours in/out) in:
```
smlparser.exe ..\test\testdata1.bin
smlparser - built Aug  4 2023/14:34:59

sml_decode_binfile: ..\test\testdata1.bin (size: 5544) ...

=== BEGIN TELEGRAM 0 (size=396) ===============
0x1b, 0x1b, 0x1b, 0x1b, 0x01, 0x01, 0x01, 0x01, 0x76, 0x07, 0x00, 0x10, 0x13, 0x1d, 0xc9, 0xfc,
…
0x10, 0x13, 0x1d, 0xca, 0x00, 0x62, 0x00, 0x62, 0x00, 0x72, 0x63, 0x02, 0x01, 0x71, 0x01, 0x63,
0x2d, 0x7c, 0x00, 0x00, 0x1b, 0x1b, 0x1b, 0x1b, 0x1a, 0x01, 0xcc, 0x53,
== BEGIN MSG 0 ==
1.                   76
1.1.                    07 00 10 13 1d c9 fc  # str:'......'
1.2.                    62 00  # uint:0 (0x0)

…

1.6.                    00
== END MSG 0 ==
== BEGIN MSG 1 ==
1.                   76
1.1.                    07 00 10 13 1d c9 fd  # str:'......'
1.2.                    62 00  # uint:0 (0x0)
1.3.                    62 00  # uint:0 (0x0)
1.4.                    72
1.4.1.                     63 07 01  # uint:1793 (0x701)
1.4.2.                     77
1.4.2.1.                      01  # str:''
1.4.2.2.                      0b 09 01 45 4d 48 00 00 4f 07 09  # str:'..EMH..O..'
1.4.2.3.                      07 01 00 62 0a ff ff  # str:'..b...'

…

1.4.2.5.3.3.                        01  # str:''
1.4.2.5.3.4.                        62 1e  # uint:30 (0x1e)
1.4.2.5.3.5.                        52 ff  # int:-1 (0xffffffffffffffff) # scaler: -1
1.4.2.5.3.6.                        56 00 07 7b ab fd  # int:125545469 (0x77babfd) # value: Wh_tot_in=1.25545e+007
1.4.2.5.3.7.                        01  # str:''
1.4.2.5.4.                       77
1.4.2.5.4.1.                        07 01 00 02 08 00 ff  # str:'......' # obis: 1.0.2.8.0.255. (Wh_tot_out)
1.4.2.5.4.2.                        64 01 01 a2  # uint:65954 (0x101a2)
1.4.2.5.4.3.                        01  # str:''
1.4.2.5.4.4.                        62 1e  # uint:30 (0x1e)
1.4.2.5.4.5.                        52 ff  # int:-1 (0xffffffffffffffff) # scaler: -1
1.4.2.5.4.6.                        56 00 12 3e e2 f6  # int:306111222 (0x123ee2f6) # value: Wh_tot_out=3.06111e+007
1.4.2.5.4.7.                        01  # str:''
1.4.2.5.5.                       77

…

1.4.2.5.8.4.                        62 1e  # uint:30 (0x1e)
1.4.2.5.8.5.                        52 ff  # int:-1 (0xffffffffffffffff) # scaler: -1
1.4.2.5.8.6.                        56 00 00 00 00 00  # int:0 (0x0) # value: (null)=0
1.4.2.5.8.7.                        01  # str:''
1.4.2.5.9.                       77
1.4.2.5.9.1.                        07 01 00 10 07 00 ff  # str:'......' # obis: 1.0.16.7.0.255. (W_now)
1.4.2.5.9.2.                        01  # str:''
1.4.2.5.9.3.                        01  # str:''
1.4.2.5.9.4.                        62 1b  # uint:27 (0x1b)
1.4.2.5.9.5.                        52 ff  # int:-1 (0xffffffffffffffff) # scaler: -1
1.4.2.5.9.6.                        55 ff ff f7 ff  # int:-2049 (0xfffffffffffff7ff) # value: W_now=-204.9
1.4.2.5.9.7.                        01  # str:''
1.4.2.5.10.                      77
```










Hterm Serial Terminal Programm for Windows
(https://www.heise.de/download/product/hterm-53283)

Very good description of the optical hardware and the SML protocol
(http://www.stefan-weigert.de/php_loader/sml.php)

