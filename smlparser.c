/*
 ============================================================================
 Name        : smlparser.c
 Author      : MF
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

// http://www.stefan-weigert.de/php_loader/sml.php
// https://www.bsi.bund.de/SharedDocs/Downloads/DE/BSI/Publikationen/TechnischeRichtlinien/TR03109/TR-03109-1_Anlage_Feinspezifikation_Drahtgebundene_LMN-Schnittstelle_Teilb.pdf?__blob=publicationFile
// https://www.mit-n.de/fileadmin/user_upload/Dateien/Messwesen/Messwesen_Strom/EFR-SGM-C4-Produkthandbuch.pdf

// http://www.kabza.de/MyHome/SmartMeter/ESP8266_SML_public.ino
// https://stackoverflow.com/questions/58768018/what-is-the-difference-between-crc-16-ccitt-false-and-crc-16-x-25

"\x00\x00\x60\x01\xFF\xFF" => "Seriennummer",
"\x01\x00\x00\x00\x09\xFF" => "Server-Id / Geraeteeinzelidentifikation",
"\x01\x00\x01\x08\x00\xFF" => "Zaehlwerk pos. Wirkenergie (Bezug), tariflos",
"\x01\x00\x01\x08\x01\xFF" => "Zaehlwerk pos. Wirkenergie (Bezug), Tarif 1",
"\x01\x00\x01\x08\x02\xFF" => "Zaehlwerk pos. Wirkenergie (Bezug), Tarif 2",
"\x01\x00\x02\x08\x00\xFF" => "Zaehlwerk neg. Wirkenergie (Einspeisung), tariflos",
"\x01\x00\x02\x08\x01\xFF" => "Zaehlwerk neg. Wirkenergie (Einspeisung), Tarif 1",
"\x01\x00\x02\x08\x02\xFF" => "Zaehlwerk neg. Wirkenergie (Einspeisung), Tarif 2",
"\x01\x00\x0F\x07\x00\xFF" => "Betrag der aktuellen Wirkleistung",
"\x01\x00\x10\x07\x00\xFF" => "Aktuelle Wirkleistung gesamt",
"\x01\x00\x24\x07\x00\xFF" => "Aktuelle Wirkleistung L1",
"\x01\x00\x38\x07\x00\xFF" => "Aktuelle Wirkleistung L2",
"\x01\x00\x4c\x07\x00\xFF" => "Aktuelle Wirkleistung L3",
"\x81\x81\xC7\x82\x03\xFF" => "Hersteller-Identifikation",
"\x81\x81\xC7\x82\x05\xFF" => "Public Key",


 */



#include <stdint.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "defs.h"
#include "tools.h"

#include "testdata.h"

#define SML_TELEGRAM_MAX    	768
#define SML_START      			"\x1B\x1B\x1B\x1B\x01\x01\x01\x01"
#define SML_START_LEN			LLEN(SML_START)
#define SML_END        			"\x1B\x1B\x1B\x1B\x1A"
#define SML_END_LEN				LLEN(SML_END)

#define SML_DEPTH_MAX			32

#define _SML_PRINTF(format, ...) printf(format, ## __VA_ARGS__)

char* path2str(const char* path, int depth)
{
	static char str[4 * SML_DEPTH_MAX + 1];

    int n = 0;
    for (int i=0; i<=depth; i++)
    {
    	n += snprintf(str + n, sizeof(str) - n, "%u.", 0xff & path[i]);
    }
    str[n] = '\0';
    return str;
}

bool path_matches(const char* pattern, const char* path)
{
	const char* p = pattern;
	const char* s = path;

    while (*p && *s)
    {
    	if (*p == '*')
        {
        	p += LLEN("*.");
        	while (*s != '.')
            {
            	s++;
            }
            s++;
        }
        else
        {
        	if (*p++ != *s++)
            	return false;

        }
    }

    return true;
}

#define SML_OPCODE_GETLISTRESP				0x0701

#define PATH_OPCODE							"1.4.1."
#define PATTERN_OBIS_NAME					"1.4.2.5.*.1."
#define PATTERN_OBIS_SCALER					"1.4.2.5.*.5." // its the exponent x of the scaler: " * 10^x"
#define PATTERN_OBIS_VALUE					"1.4.2.5.*.6."

#define OBIS_WIRKENERGIE_TOTAL_BEZUG 		"1.0.1.8.0.255."  // Unit=Wh
#define OBIS_WIRKENERGIE_TOTAL_LIEFERUNG	"1.0.2.8.0.255."  // Unit=Wh
#define OBIS_WIRKLEISTUNG_MOMENTAN			"1.0.16.7.0.255." // Unit=W, mit Vorzeichen!
#define OBIS_WIRKLEISTUNG_L1_MOMENTAN		"1.0.36.7.0.255." // Unit=W, mit Vorzeichen!
#define OBIS_WIRKLEISTUNG_L2_MOMENTAN		"1.0.56.7.0.255." // Unit=W, mit Vorzeichen!
#define OBIS_WIRKLEISTUNG_L3_MOMENTAN		"1.0.76.7.0.255." // Unit=W, mit Vorzeichen!
#define OBIS_SPANNUNG_L1					"1.0.32.7.0.255." // Unit=V
#define OBIS_SPANNUNG_L2					"1.0.52.7.0.255." // Unit=V
#define OBIS_SPANNUNG_L3					"1.0.72.7.0.255." // Unit=V
#define OBIS_STROM_L1						"1.0.31.7.0.255." // Unit=A
#define OBIS_STROM_L2						"1.0.51.7.0.255." // Unit=A
#define OBIS_STROM_L3						"1.0.71.7.0.255." // Unit=A
#define OBIS_PHASENWINKEL_U2_U1				"1.0.81.7.1.255." // Unit=deg
#define OBIS_PHASENWINKEL_U3_U1				"1.0.81.7.2.255." // Unit=deg
#define OBIS_PHASENWINKEL_I1_U1				"1.0.81.7.4.255." // Unit=deg
#define OBIS_PHASENWINKEL_I2_U2				"1.0.81.7.15.255." // Unit=deg
#define OBIS_PHASENWINKEL_I3_U3				"1.0.81.7.26.255." // Unit=deg
#define OBIS_NETZFREQUENZ					"1.0.14.7.0.255." // Unit=Hz

#define OBIS_HARDWARE_VERSION				"1.0.96.50.1.1."
#define OBIS_GERAETE_IDENTIFIKATION			"1.0.96.1.0.255."
#define OBIS_FIRMWARE_VERION				"1.0.0.2.0.0."
#define OBIS_FIRMWARE_CHECKSUM				"1.0.96.90.2.1."
#define OBIS_FEHLERREGISTER					"1.0.97.97.0.0."
#define OBIS_HARDWARE_VERSION_XXX			"1.0.96.50.1.4"

const char* obis2str(const char* obis)
{
	static const char* obis_names[][2] =
	{
		{ OBIS_WIRKENERGIE_TOTAL_BEZUG 		, "Wh_tot_in"   },
		{ OBIS_WIRKENERGIE_TOTAL_LIEFERUNG	, "Wh_tot_out"  },
		{ OBIS_WIRKLEISTUNG_MOMENTAN		, "W_now"       },
		{ OBIS_WIRKLEISTUNG_L1_MOMENTAN		, "W_L1_now"    },
		{ OBIS_WIRKLEISTUNG_L2_MOMENTAN		, "W_L2_now"    },
		{ OBIS_WIRKLEISTUNG_L3_MOMENTAN		, "W_L3_now"    },
		{ OBIS_SPANNUNG_L1					, "U_L1"        },
		{ OBIS_SPANNUNG_L2					, "U_L2"        },
		{ OBIS_SPANNUNG_L3					, "U_L3"        },
		{ OBIS_STROM_L1						, "I_L1"        },
		{ OBIS_STROM_L2						, "I_L2"        },
		{ OBIS_STROM_L3						, "I_L3"        },
		{ OBIS_PHASENWINKEL_U2_U1			, "Pha_U2_U1"   },
		{ OBIS_PHASENWINKEL_U3_U1			, "Pha_U3_U1"   },
		{ OBIS_PHASENWINKEL_I1_U1			, "Pha_I1_U1"   },
		{ OBIS_PHASENWINKEL_I2_U2			, "Pha_I2_U2"   },
		{ OBIS_PHASENWINKEL_I3_U3			, "Pha_I3_U3"   },
		{ OBIS_NETZFREQUENZ					, "Freq"        },
	};

	for (int i=0; i<ELEMCNT(obis_names); i++)
	{
		if (STREQU(obis, obis_names[i][0]))
		{
			return obis_names[i][1];
		}
	}
	return NULL;
}


bool has_obis = false;
const char* obis_name = NULL;
int obis_scaler = 0;

void sml_msg_begin(int msgcnt) // called at begin of message
{
	_SML_PRINTF("== BEGIN MSG %d == \n", msgcnt);

	has_obis = false;
	obis_name = NULL;
}

void sml_msg_end(int msgcnt) // called at end of message
{
	_SML_PRINTF("== END MSG %d == \n", msgcnt);
}

void sml_msg_data(const char* path, int type, const char* buf, int len) // called for every data entry in msg
{
    _SML_PRINTF(" # ");

    uint64_t  intval = 0;

    bool is_signed = false;

    if (type == 0x0)
    {
        _SML_PRINTF("str:'");
        for (int i=0; i<len; i++)
        {
            char data = buf[i];
            _SML_PRINTF("%c", isprint(data) ? data : '.');
        }
        _SML_PRINTF("'");
    }
    else
    if (type == 0x5) // signed int
    {
        for (int i=0; i<len; i++)
        {
        	intval <<= 8;
            char data = buf[i];
            intval |= (0xff & data);
        }
        switch (len)
        {
        	case 1: { intval = (int8_t)(intval);  break; }
        	case 2: { intval = (int16_t)(intval); break; }
        	case 4: { intval = (int32_t)(intval); break; }
        	case 8: { intval = (int64_t)(intval); break; }
        }

        is_signed = true;

        _SML_PRINTF("int:%lld (0x%llx)", intval, intval);
    }
    else
    if (type == 0x6) // unsigned int
    {
        for (int i=0; i<len; i++)
        {
        	intval <<= 8;
            char data = buf[i];
            intval |= (0xff & data);
        }
        switch (len)
        {
        	case 1: { intval = (uint8_t)(intval);  break; }
        	case 2: { intval = (uint16_t)(intval); break; }
        	case 4: { intval = (uint32_t)(intval); break; }
        	case 8: { intval = (uint64_t)(intval); break; }
        }
        is_signed = false;

        _SML_PRINTF("uint:%llu (0x%llx)", intval, intval);
    }
    else
    {
        _SML_PRINTF("unknown_type!");
    }

    if (path_matches(PATH_OPCODE, path))
    {
    	// _SML_PRINTF(" # msg body opcode");
    	has_obis = (intval == SML_OPCODE_GETLISTRESP);
    }
    else
    if (has_obis && path_matches(PATTERN_OBIS_NAME, path))
    {
    	const char* obis = path2str(buf, len - 1);
    	obis_name = obis2str(obis);
    	_SML_PRINTF(" # obis: %s (%s)", obis, obis_name);
    }
    else
    if (has_obis && path_matches(PATTERN_OBIS_SCALER, path))
    {
    	obis_scaler = (int8_t)intval;
    	_SML_PRINTF(" # scaler: %d",  obis_scaler);

    }
    else
    if (has_obis && path_matches(PATTERN_OBIS_VALUE, path))
    {
    	double val = is_signed ?
    			(signed)(intval) * pow(10.0, obis_scaler) :
				(unsigned)(intval) * pow(10.0, obis_scaler);
    	_SML_PRINTF(" # value: %s=%g", obis_name, val);

		#if (__ESP__ == 1)
		sensors_update(obis_name, val, NULL);
		#endif
    }
}

int sml_decode_tree(const char* buf, int depth)
{
	int pos = 0;

	static char sml_pathbuf[SML_DEPTH_MAX];
    if (depth == 0)
	    memset(sml_pathbuf, 0, sizeof(sml_pathbuf));

    sml_pathbuf[depth]++;
    const char* pathstr = path2str(sml_pathbuf, depth);

	_SML_PRINTF("%-21s", pathstr);

    for (int i=0; i<depth; i++)
        _SML_PRINTF("   ");

    char tl   = buf[pos++];
    char type = (tl >> 4) & 0x07;
    int  len  = tl & 0x0f;
    bool xlen = tl & 0x80;

    _SML_PRINTF("%02x ", 0xff & tl);

    if (xlen) // extended-length bit is set
    {
    	int lolen = buf[pos++]; // low nibble of extended length
        _SML_PRINTF("%02x ", lolen);
        len = (len << 4) | (lolen & 0x0f);
    }

	if (type == 0x7) // list or extended-length list
    {
        _SML_PRINTF("\n");
        for (int i=0; i<len; i++)
        {
        	pos += sml_decode_tree(buf + pos, depth + 1);
        }
        sml_pathbuf[depth + 1] = 0;
    }
    else
    {
	    if (len > 0)
        {
	        len--;
            for (int i=0; i<len; i++)
            {
                char data = buf[pos + i];
                _SML_PRINTF("%02x ", 0xff & data);
            }
            sml_msg_data(pathstr, type, buf + pos, len);
            pos += len;
        }

        _SML_PRINTF("\n");
    }

    return pos;
}

bool sml_decode_telegram(const char* buf, int size)
{
	static int tgcnt = 0;
    _SML_PRINTF("\n=== BEGIN TELEGRAM %d (size=%d) ===============\n", tgcnt, size);

	for (int i = 0; i<size; i++)
    {
    	unsigned int n = 0xff & buf[i];

        _SML_PRINTF("0x%02x, ", n);

        if (i % 16 == 15)
	        _SML_PRINTF("\n");
    }
    _SML_PRINTF("\n");

    int pos = SML_START_LEN;
    buf += SML_START_LEN;
    int msgcnt = 0;
    while (pos < size)
    {
    	if (*buf == 0x00)
        {
            _SML_PRINTF("== END_MSGS == \n");
        	break;
        }

        sml_msg_begin(msgcnt);
        int n = sml_decode_tree(buf, 0);
        sml_msg_end(msgcnt);
        buf += n;
        pos += n;
        msgcnt++;
    }

    _SML_PRINTF("\n=== END TELEGRAM %d  ===============\n", tgcnt);

    tgcnt++;
    return true;
}

#define CRC_X25_SEED 0xffff

uint16_t crc16_x25(uint8_t data, uint16_t crc)
{
	crc ^= data << 0;
	for (int i=0; i < 8; i++)
	{
		crc = crc & 0x0001 ? (crc >> 1) ^ 0x8408 : crc >> 1;
	}
    return crc;
}

uint16_t crc16_x25_mem(const char* buf, int length)
{
    uint16_t crc = CRC_X25_SEED;
    while (length--)
    {
    	crc = crc16_x25(*buf++, crc);
    }
    return crc ^ 0xffff;
}

static enum
{
	SML_SEARCH_START,
	SML_SEARCH_END,
	SML_CHECKSUM,
}   sml_state = SML_SEARCH_START;


void sml_reset_stream()
{
	sml_state = SML_SEARCH_START;
}

static int tgpos = SML_START_LEN - 1;
int streampos = 0;

bool sml_decode_stream(char c)
{
	static char tgbuf[SML_TELEGRAM_MAX]; // telegram buffer

	static int cslen  = 0;
	static int cscnt  = 0;
	static uint16_t tgcrc = 0;

	bool res = false;

	if (tgpos < sizeof(tgbuf))
	{
		tgbuf[tgpos++] = c;
	}
	else
	{
		tgpos = 0;
	}

	switch (sml_state)
	{
		case SML_SEARCH_START:
		{
			if (memcmp(tgbuf, SML_START, SML_START_LEN) == 0)
			{
				sml_state = SML_SEARCH_END;
			}
			else
			{
				tgpos = SML_START_LEN - 1;
				memmove(tgbuf, tgbuf + 1, SML_START_LEN - 1);
			}
			break;
		}
		case SML_SEARCH_END:
		{
			int eoffs = tgpos - SML_END_LEN;
			char* end = tgbuf + eoffs;

			if (memcmp(end, SML_END, SML_END_LEN) == 0)
			{
				sml_state = SML_CHECKSUM;
				cscnt = 0;
				tgcrc = 0x0000;
			}
			break;
		}
        case SML_CHECKSUM:
        {
			if (cscnt == 0)
			{
				// cslen = c; // the first byte after the outro tells us how many bytes will follow until crc is complete
				cslen = 3; // tsometimes it is 0 ... dont understand - hardcode it to 3 works best...
				tgcrc = 0x0000;
			}
			else
			{
				tgcrc >>= 8;
				tgcrc |= ((0xff & c) << 8);
			}
            cscnt++;

            if (cscnt == cslen)
            {
                uint16_t mycrc = crc16_x25_mem(tgbuf, tgpos - 2);

// #if (SML_TCP_PORT > 0)
				// if (wifiClient)
				// {
					// wifiClient.printf("\r\n#CRC: L=%04x R=%04\r\n", mycrc, tgcrc);
				// }
// #endif

				#if (SMLREADER_IGNORE_CRC == 1)
				res = true;
				#else
				res = (mycrc == tgcrc);
				#endif

                if (res)
                {
					static unsigned long frames_count = 0;
					//sensors_update("frames_count", ++frames_count);
                	sml_decode_telegram(tgbuf, tgpos);
                }


                sml_reset_stream(false);
            }
        	break;
        }
	}

	return res;
}

void sml_decode_mem(const char* buf, int size)
{
	for (int i = 0; i<size; i++)
    {
    	unsigned int n = 0xff & buf[i];
    	streampos = i;
    	sml_decode_stream(n);
    }
}

bool sml_decode_binfile(const char* filename)
{
	int size = 0;
    char* buf = file_to_mem(filename, &size);
	printf("sml_decode_binfile: %s (size: %d) ...\n", filename, size);

	if (buf == NULL)
		return false;

    sml_decode_mem(buf, size);
	free(buf);
	return true;
}

bool sml_decode_txtfile(const char* filename)
{
	printf("sml_decode_txtfile: %s ...\n", filename);

	FILE* file = fopen(filename, "rt");
	if (file)
	{
		int linenum = 0;
		while (!feof(file))
		{
			char line[1024];
			fgets(line, sizeof(line), file);
			linenum++;

			char* s = strtriml(line);

			if (*s == '#')
			{
				printf(s);
				continue;
			}

			int c, n;

			if (sscanf(s, "%x %n", &c, &n) > 0)
			{
				streampos = linenum;
				sml_decode_stream(c);
				s += n;
			}
		}
		fclose(file);
		file = NULL;
		return true;
	}
	return false;
}

// #include "time_simple.h"

void usage(const char* prog)
{
	printf("usage: ...\n");
	printf("  %s -bin BINARYFILE \n", prog);
	printf("  %s -hex HEXDUMP_TEXTFILE \n", prog);
	printf("  %s -demo \n", prog);
}

int scanargs(int argc, char **argv)
{
	int i;
	for (i=1; i<argc; i++)
	{
		const char* arg = argv[i];

		while (*arg == '-') // strip leading dashes
			arg++;

		if (STREQU(arg, "hex"))
		{
			const char* filename = argv[++i];
			bool res = sml_decode_txtfile(filename);
			exit(res ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		else
		if (STREQU(arg, "bin"))
		{
			const char* filename = argv[++i];
			bool res = sml_decode_binfile(filename);
			exit(res ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		else
		if (STREQU(arg, "demo"))
		{
			sml_decode_mem(sml_telegram0, sizeof(sml_telegram0));
			exit(EXIT_SUCCESS);
		}
		else
		if (sml_decode_binfile(argv[i]))
		{
			exit(EXIT_SUCCESS);
		}
		else
		if (sml_decode_txtfile(argv[i]))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			usage(argv[0]);
			exit(EXIT_SUCCESS);
		}
	}

	return i;
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	puts("smlparser - built " COMPILE_TIMESTAMP "\n");
	scanargs(argc, argv);

	usage(argv[0]);

	//	time_simple_test();
	//	return EXIT_SUCCESS;

	//	sml_decode_binfile("cutecom.log");
	//
	//	sml_decode_txtfile(".\\test\\sml1.txt");

		// sml_decode_mem(sml_telegram1, sizeof(sml_telegram1));
		//sml_decode_mem(sml_telegram0, sizeof(sml_telegram0));



//	puts("smlparser - ready.\n");
	//	return EXIT_SUCCESS;

}
