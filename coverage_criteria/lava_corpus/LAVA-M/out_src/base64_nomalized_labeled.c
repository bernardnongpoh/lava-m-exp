/*** Generated by CAnnotate ***/ 
// COVERAGE CRITERIA : ABS AOR COR ROR MCC 
#include "coverage.h"

#include <stdio.h>
extern unsigned int lava_get(unsigned int) ;
static unsigned int lava_val[1000000];
void lava_set(unsigned int bug_num, unsigned int val);
void lava_set(unsigned int bug_num, unsigned int val) { lava_val[bug_num] = val; }
unsigned int lava_get(unsigned int bug_num);


#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
#include <stdio.h>
unsigned int lava_get(unsigned int bug_num) {
    
// ABS Label 7
if(bug_num < 0)  {
	report_label_coverage("ABS", 7);
}
// ABS Label 8
if(lava_val[bug_num] < 0)  {
	report_label_coverage("ABS", 8);
}

// AOR Label 9
if(1818326625 / bug_num != 1818326625 - bug_num)  {
	report_label_coverage("AOR", 9);
}
// AOR Label 10
if(1818326625 + bug_num != 1818326625 - bug_num)  {
	report_label_coverage("AOR", 10);
}
// AOR Label 11
if(1818326625 * bug_num != 1818326625 - bug_num)  {
	report_label_coverage("AOR", 11);
}

// COR Label 12
if((1818326625 - bug_num == lava_val[bug_num] && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) != (1818326625 - bug_num == lava_val[bug_num] || (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]))  {
	report_label_coverage("COR", 12);
}

// ROR Label 13
if((1818326625 - bug_num != lava_val[bug_num]) != (1818326625 - bug_num == lava_val[bug_num]))  {
	report_label_coverage("ROR", 13);
}
// ROR Label 14
if(((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) != lava_val[bug_num]) != ((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]))  {
	report_label_coverage("ROR", 14);
}

// MCC Label 15
if(1818326625 - bug_num == lava_val[bug_num] && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num] ) {
	report_label_coverage("MCC", 15);
}
// MCC Label 16
if(1818326625 - bug_num == lava_val[bug_num] && !((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) ) {
	report_label_coverage("MCC", 16);
}
// MCC Label 17
if(!(1818326625 - bug_num == lava_val[bug_num]) && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num] ) {
	report_label_coverage("MCC", 17);
}
// MCC Label 18
if(!(1818326625 - bug_num == lava_val[bug_num]) && !((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) ) {
	report_label_coverage("MCC", 18);
}
if (0x6c617661 - bug_num == lava_val[bug_num] ||
        SWAP_UINT32(0x6c617661 - bug_num) == lava_val[bug_num]) {
        
// ABS Label 19
if(bug_num < 0)  {
	report_label_coverage("ABS", 19);
}
dprintf(1, "Successfully triggered bug %d, crashing now!\n", bug_num);
    }
    else {
        //printf("Not successful for bug %d; val = %08x not %08x or %08x\n", bug_num, lava_val[bug_num], 0x6c617661 + bug_num, 0x6176616c + bug_num);                                                                                                                                                                         
    }
    
// ABS Label 20
if(bug_num < 0)  {
	report_label_coverage("ABS", 20);
}
// ABS Label 21
if(lava_val[bug_num] < 0)  {
	report_label_coverage("ABS", 21);
}
return lava_val[bug_num];
}


/* Base64 encode/decode strings or files.
   Copyright (C) 2004-2015 Free Software Foundation, Inc.

   This file is part of Base64.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

/* Written by Simon Josefsson <simon@josefsson.org>.  */

#include <config.h>

#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>

#include "system.h"
#include "error.h"
#include "fadvise.h"
#include "xstrtol.h"
#include "quote.h"
#include "quotearg.h"
#include "xfreopen.h"

#include "base64.h"

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "base64"

#define AUTHORS proper_name ("Simon Josefsson")

static struct option const long_options[] =
{
  {"decode", no_argument, 0, 'd'},
  {"wrap", required_argument, 0, 'w'},
  {"ignore-garbage", no_argument, 0, 'i'},

  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};

void
usage (int status)
{
  
// ABS Label 174
if(status < 0)  {
	report_label_coverage("ABS", 174);
}

// ROR Label 175
if((status == 0) != (status != 0))  {
	report_label_coverage("ROR", 175);
}
if (status != EXIT_SUCCESS)
    emit_try_help ();
  else
    {
      
// ABS Label 176
if(program_name < 0)  {
	report_label_coverage("ABS", 176);
}
printf (_("\
Usage: %s [OPTION]... [FILE]\n\
Base64 encode or decode FILE, or standard input, to standard output.\n\
"), program_name);

      emit_stdin_note ();
      emit_mandatory_arg_note ();

      fputs (_("\
  -d, --decode          decode data\n\
  -i, --ignore-garbage  when decoding, ignore non-alphabet characters\n\
  -w, --wrap=COLS       wrap encoded lines after COLS character (default 76).\n\
                          Use 0 to disable line wrapping\n\
\n\
"), stdout);
      fputs (HELP_OPTION_DESCRIPTION, stdout);
      fputs (VERSION_OPTION_DESCRIPTION, stdout);
      fputs (_("\
\n\
The data are encoded as described for the base64 alphabet in RFC 3548.\n\
When decoding, the input may contain newlines in addition to the bytes of\n\
the formal base64 alphabet.  Use --ignore-garbage to attempt to recover\n\
from any other non-alphabet bytes in the encoded stream.\n"),
             stdout);
      emit_ancillary_info (PROGRAM_NAME);
    }

  
// ABS Label 173
if(status < 0)  {
	report_label_coverage("ABS", 173);
}
exit (status);
}

#define ENC_BLOCKSIZE (1024*3*10)
#define ENC_B64BLOCKSIZE BASE64_LENGTH (ENC_BLOCKSIZE)
/* Note that increasing this may decrease performance if --ignore-garbage
   is used, because of the memmove operation below.  */
#define DEC_BLOCKSIZE (1024*3)
#define DEC_B64BLOCKSIZE BASE64_LENGTH (DEC_BLOCKSIZE)

/* Ensure that BLOCKSIZE is a multiple of 3 and 4.  */
verify (ENC_BLOCKSIZE % 12 == 0);
verify (DEC_BLOCKSIZE % 12 == 0);

static void
wrap_write (const char *buffer, size_t len,
            uintmax_t wrap_column, size_t *current_column, FILE *out)
{
  size_t written;

  
// ABS Label 181
if(wrap_column < 0)  {
	report_label_coverage("ABS", 181);
}

// ROR Label 182
if((wrap_column != 0) != (wrap_column == 0))  {
	report_label_coverage("ROR", 182);
}
if (wrap_column == 0)
    {
      /* Simple write. */
      {
    size_t temp_1 = fwrite_unlocked(buffer, 1, len, stdout);
    
// ABS Label 183
if(len < 0)  {
	report_label_coverage("ABS", 183);
}
// ABS Label 184
if(temp_1 < 0)  {
	report_label_coverage("ABS", 184);
}

// ROR Label 185
if((temp_1 <= len) != (temp_1 < len))  {
	report_label_coverage("ROR", 185);
}
// ROR Label 186
if((temp_1 > len) != (temp_1 < len))  {
	report_label_coverage("ROR", 186);
}
// ROR Label 187
if((temp_1 >= len) != (temp_1 < len))  {
	report_label_coverage("ROR", 187);
}
if (temp_1 < len)
        error(1, (*__errno_location()), gettext("write error"));
}
;
    }
  else
    written = 0;

// ABS Label 188
if(len < 0)  {
	report_label_coverage("ABS", 188);
}
// ABS Label 189
if(written < 0)  {
	report_label_coverage("ABS", 189);
}

// ROR Label 190
if((written <= len) != (written < len))  {
	report_label_coverage("ROR", 190);
}
// ROR Label 191
if((written > len) != (written < len))  {
	report_label_coverage("ROR", 191);
}
// ROR Label 192
if((written >= len) != (written < len))  {
	report_label_coverage("ROR", 192);
}
for (; written < len;)
      {
        
// ABS Label 198
if(*current_column < 0)  {
	report_label_coverage("ABS", 198);
}
// ABS Label 199
if(wrap_column < 0)  {
	report_label_coverage("ABS", 199);
}

// AOR Label 200
if(wrap_column / *current_column != wrap_column - *current_column)  {
	report_label_coverage("AOR", 200);
}
// AOR Label 201
if(wrap_column + *current_column != wrap_column - *current_column)  {
	report_label_coverage("AOR", 201);
}
// AOR Label 202
if(wrap_column * *current_column != wrap_column - *current_column)  {
	report_label_coverage("AOR", 202);
}
uintmax_t cols_remaining = wrap_column - *current_column;
        size_t to_write = MIN (cols_remaining, SIZE_MAX);
        to_write = MIN (to_write, len - written);

        
// ABS Label 203
if(to_write < 0)  {
	report_label_coverage("ABS", 203);
}

// ROR Label 204
if((to_write != 0) != (to_write == 0))  {
	report_label_coverage("ROR", 204);
}
if (to_write == 0)
          {
            {
    int temp_1 = fputc_unlocked('\n', out);
    int temp_2 = -1;
    
// ABS Label 205
if(temp_1 < 0)  {
	report_label_coverage("ABS", 205);
}
// ABS Label 206
if(temp_2 < 0)  {
	report_label_coverage("ABS", 206);
}

// ROR Label 207
if((temp_1 != temp_2) != (temp_1 == temp_2))  {
	report_label_coverage("ROR", 207);
}
if (temp_1 == temp_2)
        error(1, (*__errno_location()), gettext("write error"));
}
;
            *current_column = 0;
          }
        else
          {
            {
    size_t temp_1 = fwrite_unlocked(buffer + written, 1, to_write, stdout);
    
// ABS Label 208
if(temp_1 < 0)  {
	report_label_coverage("ABS", 208);
}
// ABS Label 209
if(to_write < 0)  {
	report_label_coverage("ABS", 209);
}

// ROR Label 210
if((temp_1 <= to_write) != (temp_1 < to_write))  {
	report_label_coverage("ROR", 210);
}
// ROR Label 211
if((temp_1 > to_write) != (temp_1 < to_write))  {
	report_label_coverage("ROR", 211);
}
// ROR Label 212
if((temp_1 >= to_write) != (temp_1 < to_write))  {
	report_label_coverage("ROR", 212);
}
if (temp_1 < to_write)
        error(1, (*__errno_location()), gettext("write error"));
}
;
            *current_column += to_write;
            written += to_write;
          }
      };
// ABS Label 193
if(len < 0)  {
	report_label_coverage("ABS", 193);
}
// ABS Label 194
if(written < 0)  {
	report_label_coverage("ABS", 194);
}

// ROR Label 195
if((written <= len) != (written < len))  {
	report_label_coverage("ROR", 195);
}
// ROR Label 196
if((written > len) != (written < len))  {
	report_label_coverage("ROR", 196);
}
// ROR Label 197
if((written >= len) != (written < len))  {
	report_label_coverage("ROR", 197);
}

}

static void
do_encode (FILE *in, FILE *out, uintmax_t wrap_column)
{
  size_t current_column = 0;
  char inbuf[ENC_BLOCKSIZE];
  char outbuf[ENC_B64BLOCKSIZE];
  size_t sum;

  do {
    {
        size_t n;
        sum = 0;
        do {
            {
                n = fread_unlocked(inbuf + sum, 1, (1024 * 3 * 10) - sum, in);
                sum += n;
            }
            {
                int temp_2 = !(!feof_unlocked(in) && !ferror_unlocked(in) && sum < (1024 * 3 * 10));
                
// ABS Label 213
if(temp_2 < 0)  {
	report_label_coverage("ABS", 213);
}
if (temp_2)
                    break;
            }
        } while (1);;
        
// ABS Label 214
if(sum < 0)  {
	report_label_coverage("ABS", 214);
}

// ROR Label 215
if((sum <= 0) != (sum > 0))  {
	report_label_coverage("ROR", 215);
}
// ROR Label 216
if((sum < 0) != (sum > 0))  {
	report_label_coverage("ROR", 216);
}
// ROR Label 217
if((sum >= 0) != (sum > 0))  {
	report_label_coverage("ROR", 217);
}
if (sum > 0) {
            
// ABS Label 218
if(sum < 0)  {
	report_label_coverage("ABS", 218);
}
base64_encode(inbuf, sum, outbuf, ((((sum) + 2) / 3) * 4));
            
// ABS Label 219
if(wrap_column < 0)  {
	report_label_coverage("ABS", 219);
}

// ABS Label 220
if(out < 0)  {
	report_label_coverage("ABS", 220);
}
wrap_write(outbuf, ((((sum) + 2) / 3) * 4), wrap_column, &current_column, out);
        }
    }
    {
        int temp_1 = !(!feof_unlocked(in) && !ferror_unlocked(in) && sum == (1024 * 3 * 10));
        
// ABS Label 221
if(temp_1 < 0)  {
	report_label_coverage("ABS", 221);
}
if (temp_1)
            break;
    }
} while (1);;
;

  /* When wrapping, terminate last line. */
  
// ABS Label 222
if(current_column < 0)  {
	report_label_coverage("ABS", 222);
}
// ABS Label 223
if(wrap_column < 0)  {
	report_label_coverage("ABS", 223);
}

// COR Label 224
if((wrap_column || current_column > 0) != (wrap_column && current_column > 0))  {
	report_label_coverage("COR", 224);
}

// ROR Label 225
if((current_column <= 0) != (current_column > 0))  {
	report_label_coverage("ROR", 225);
}
// ROR Label 226
if((current_column < 0) != (current_column > 0))  {
	report_label_coverage("ROR", 226);
}
// ROR Label 227
if((current_column >= 0) != (current_column > 0))  {
	report_label_coverage("ROR", 227);
}

// MCC Label 228
if(wrap_column && current_column > 0 ) {
	report_label_coverage("MCC", 228);
}
// MCC Label 229
if(wrap_column && !(current_column > 0) ) {
	report_label_coverage("MCC", 229);
}
// MCC Label 230
if(!(wrap_column) && current_column > 0 ) {
	report_label_coverage("MCC", 230);
}
// MCC Label 231
if(!(wrap_column) && !(current_column > 0) ) {
	report_label_coverage("MCC", 231);
}
if (wrap_column && current_column > 0) {
    int temp_1 = fputc_unlocked('\n', out);
    int temp_2 = -1;
    
// ABS Label 232
if(temp_1 < 0)  {
	report_label_coverage("ABS", 232);
}
// ABS Label 233
if(temp_2 < 0)  {
	report_label_coverage("ABS", 233);
}

// ROR Label 234
if((temp_1 != temp_2) != (temp_1 == temp_2))  {
	report_label_coverage("ROR", 234);
}
if (temp_1 == temp_2)
        error(1, (*__errno_location()), gettext("write error"));
}
;

  {
    int temp_1 = ferror_unlocked(in);
    
// ABS Label 235
if(temp_1 < 0)  {
	report_label_coverage("ABS", 235);
}
if (temp_1)
        error(1, (*__errno_location()), gettext("read error"));
}
;
}

static void
do_decode (FILE *in, FILE *out, bool ignore_garbage)
{
  char inbuf[DEC_B64BLOCKSIZE];
  char outbuf[DEC_BLOCKSIZE];
  size_t sum;
  struct base64_decode_context ctx;

  base64_decode_ctx_init (&ctx);

  do {
    {
        _Bool ok;
        size_t n;
        unsigned int k;
        sum = 0;
        do {
            {
                n = fread_unlocked(inbuf + sum, 1, (((((1024 * 3)) + 2) / 3) * 4) - sum, in);
                
// ABS Label 236
if(ignore_garbage < 0)  {
	report_label_coverage("ABS", 236);
}
if (ignore_garbage) {
                    size_t i;
                    i = 0;

// ABS Label 237
if(i < 0)  {
	report_label_coverage("ABS", 237);
}
// ABS Label 238
if(n < 0)  {
	report_label_coverage("ABS", 238);
}

// COR Label 239
if((n > 0 || i < n) != (n > 0 && i < n))  {
	report_label_coverage("COR", 239);
}

// ROR Label 240
if((n <= 0) != (n > 0))  {
	report_label_coverage("ROR", 240);
}
// ROR Label 241
if((n < 0) != (n > 0))  {
	report_label_coverage("ROR", 241);
}
// ROR Label 242
if((n >= 0) != (n > 0))  {
	report_label_coverage("ROR", 242);
}
// ROR Label 243
if((i <= n) != (i < n))  {
	report_label_coverage("ROR", 243);
}
// ROR Label 244
if((i > n) != (i < n))  {
	report_label_coverage("ROR", 244);
}
// ROR Label 245
if((i >= n) != (i < n))  {
	report_label_coverage("ROR", 245);
}

// MCC Label 246
if(n > 0 && i < n ) {
	report_label_coverage("MCC", 246);
}
// MCC Label 247
if(n > 0 && !(i < n) ) {
	report_label_coverage("MCC", 247);
}
// MCC Label 248
if(!(n > 0) && i < n ) {
	report_label_coverage("MCC", 248);
}
// MCC Label 249
if(!(n > 0) && !(i < n) ) {
	report_label_coverage("MCC", 249);
}
for (; n > 0 && i < n;)
                        
// COR Label 263
if((isbase64(inbuf[sum + i]) && inbuf[sum + i] == '=') != (isbase64(inbuf[sum + i]) || inbuf[sum + i] == '='))  {
	report_label_coverage("COR", 263);
}

// ROR Label 264
if((inbuf[sum + i] != '=') != (inbuf[sum + i] == '='))  {
	report_label_coverage("ROR", 264);
}

// MCC Label 265
if(isbase64(inbuf[sum + i]) && inbuf[sum + i] == '=' ) {
	report_label_coverage("MCC", 265);
}
// MCC Label 266
if(isbase64(inbuf[sum + i]) && !(inbuf[sum + i] == '=') ) {
	report_label_coverage("MCC", 266);
}
// MCC Label 267
if(!(isbase64(inbuf[sum + i])) && inbuf[sum + i] == '=' ) {
	report_label_coverage("MCC", 267);
}
// MCC Label 268
if(!(isbase64(inbuf[sum + i])) && !(inbuf[sum + i] == '=') ) {
	report_label_coverage("MCC", 268);
}
if (isbase64(inbuf[sum + i]) || inbuf[sum + i] == '=')
                            i++;
                        else
                            memmove(inbuf + sum + i, inbuf + sum + i + 1, --n - i);
// ABS Label 250
if(i < 0)  {
	report_label_coverage("ABS", 250);
}
// ABS Label 251
if(n < 0)  {
	report_label_coverage("ABS", 251);
}

// COR Label 252
if((n > 0 || i < n) != (n > 0 && i < n))  {
	report_label_coverage("COR", 252);
}

// ROR Label 253
if((n <= 0) != (n > 0))  {
	report_label_coverage("ROR", 253);
}
// ROR Label 254
if((n < 0) != (n > 0))  {
	report_label_coverage("ROR", 254);
}
// ROR Label 255
if((n >= 0) != (n > 0))  {
	report_label_coverage("ROR", 255);
}
// ROR Label 256
if((i <= n) != (i < n))  {
	report_label_coverage("ROR", 256);
}
// ROR Label 257
if((i > n) != (i < n))  {
	report_label_coverage("ROR", 257);
}
// ROR Label 258
if((i >= n) != (i < n))  {
	report_label_coverage("ROR", 258);
}

// MCC Label 259
if(n > 0 && i < n ) {
	report_label_coverage("MCC", 259);
}
// MCC Label 260
if(n > 0 && !(i < n) ) {
	report_label_coverage("MCC", 260);
}
// MCC Label 261
if(!(n > 0) && i < n ) {
	report_label_coverage("MCC", 261);
}
// MCC Label 262
if(!(n > 0) && !(i < n) ) {
	report_label_coverage("MCC", 262);
}
;
                }
                sum += n;
                {
                    int temp_3 = ferror_unlocked(in);
                    
// ABS Label 269
if(temp_3 < 0)  {
	report_label_coverage("ABS", 269);
}
if (temp_3)
                        error(1, (*__errno_location()), gettext("read error"));
                }
            }
            {
                int temp_2 = !(sum < (((((1024 * 3)) + 2) / 3) * 4) && !feof_unlocked(in));
                
// ABS Label 270
if(temp_2 < 0)  {
	report_label_coverage("ABS", 270);
}
if (temp_2)
                    break;
            }
        } while (1);;
        {
            k = 0;
            while (1)
                {
                    {
                        int temp_4 = !(k < 1 + !!feof_unlocked(in));
                        
// ABS Label 271
if(temp_4 < 0)  {
	report_label_coverage("ABS", 271);
}
if (temp_4)
                            break;
                    }
                    {
                        
// ABS Label 272
if(ctx.i < 0)  {
	report_label_coverage("ABS", 272);
}
// ABS Label 273
if(k < 0)  {
	report_label_coverage("ABS", 273);
}

// COR Label 274
if((k == 1 || ctx.i == 0) != (k == 1 && ctx.i == 0))  {
	report_label_coverage("COR", 274);
}

// ROR Label 275
if((k != 1) != (k == 1))  {
	report_label_coverage("ROR", 275);
}
// ROR Label 276
if((ctx.i != 0) != (ctx.i == 0))  {
	report_label_coverage("ROR", 276);
}

// MCC Label 277
if(k == 1 && ctx.i == 0 ) {
	report_label_coverage("MCC", 277);
}
// MCC Label 278
if(k == 1 && !(ctx.i == 0) ) {
	report_label_coverage("MCC", 278);
}
// MCC Label 279
if(!(k == 1) && ctx.i == 0 ) {
	report_label_coverage("MCC", 279);
}
// MCC Label 280
if(!(k == 1) && !(ctx.i == 0) ) {
	report_label_coverage("MCC", 280);
}
if (k == 1 && ctx.i == 0)
                            break;
                        n = (1024 * 3);
                        ok = base64_decode_ctx(&ctx + (lava_get(253)) * (1818326372 == (lava_get(253)) || 1685414252 == (lava_get(253))), inbuf + (lava_get(255)) * (1818326370 == (lava_get(255)) || 1651859820 == (lava_get(255))), (k == 0 ? sum : 0), outbuf, &n);
                        {
                            size_t temp_5 = fwrite_unlocked(outbuf, 1, n, out);
                            
// ABS Label 281
if(n < 0)  {
	report_label_coverage("ABS", 281);
}
// ABS Label 282
if(temp_5 < 0)  {
	report_label_coverage("ABS", 282);
}

// ROR Label 283
if((temp_5 <= n) != (temp_5 < n))  {
	report_label_coverage("ROR", 283);
}
// ROR Label 284
if((temp_5 > n) != (temp_5 < n))  {
	report_label_coverage("ROR", 284);
}
// ROR Label 285
if((temp_5 >= n) != (temp_5 < n))  {
	report_label_coverage("ROR", 285);
}
if (temp_5 < n)
                                error(1, (*__errno_location()), gettext("write error"));
                        }
                        if (!ok)
                            error(1, 0, gettext("invalid input"));
                    }
                    k++;
                };
        }
    }
    {
        int temp_1 = !(!feof_unlocked(in));
        
// ABS Label 286
if(temp_1 < 0)  {
	report_label_coverage("ABS", 286);
}
if (temp_1)
            break;
    }
} while (1);;
;
}

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
static FILE *covfp = NULL;
static int cov_write_enable = 0;
static clock_t start = 0;

void report_label_coverage(char * crit, int id) {
	if(cov_write_enable) { 
		clock_t end = clock();
		float duration = (float)(end - start) / CLOCKS_PER_SEC;
		fprintf(covfp, "%s, %d, %f\n", crit, id, duration);
	}
}

int
main (int argc, char **argv)
{
  	

int opt;
  FILE *input_fh;
  const char *infile;

  /* True if --decode has been given and we should decode data. */
  bool decode = false;
  /* True if we should ignore non-base64-alphabetic characters. */
  bool ignore_garbage = false;
  /* Wrap encoded base64 data around the 76:th column, by default. */
  uintmax_t wrap_column = 76;

  initialize_main (&argc, &argv);
  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  atexit (close_stdout);

  while (1)
    {
        {
            int temp_1 = !((opt = getopt_long(argc, argv, "diw:", long_options, ((void *)0))) != -1);
            
// ABS Label 288
if(temp_1 < 0)  {
	report_label_coverage("ABS", 288);
}
if (temp_1)
                break;
        }
        switch (opt) {
          case 'd':
            decode = 1;
            break;
          case 'w':
            if (xstrtoumax(optarg, ((void *)0), 0, &wrap_column, ((void *)0)) != LONGINT_OK)
                error(1, 0, gettext("invalid wrap size: %s"), quotearg(optarg));
            break;
          case 'i':
            ignore_garbage = 1;
            break;
          case GETOPT_HELP_CHAR:
            usage(0);
            break;
            ;
          case GETOPT_VERSION_CHAR:
            version_etc(stdout, "base64", "GNU coreutils", Version, ("Simon Josefsson"), (char *)((void *)0));
            exit(0);
            break;
            ;
          default:
            usage(1);
            break;
        }
    };


  
// ABS Label 289
if(argc < 0)  {
	report_label_coverage("ABS", 289);
}
// ABS Label 290
if(optind < 0)  {
	report_label_coverage("ABS", 290);
}

// AOR Label 291
if(argc / optind != argc - optind)  {
	report_label_coverage("AOR", 291);
}
// AOR Label 292
if(argc + optind != argc - optind)  {
	report_label_coverage("AOR", 292);
}
// AOR Label 293
if(argc * optind != argc - optind)  {
	report_label_coverage("AOR", 293);
}

// ROR Label 294
if((argc - optind <= 1) != (argc - optind > 1))  {
	report_label_coverage("ROR", 294);
}
// ROR Label 295
if((argc - optind < 1) != (argc - optind > 1))  {
	report_label_coverage("ROR", 295);
}
// ROR Label 296
if((argc - optind >= 1) != (argc - optind > 1))  {
	report_label_coverage("ROR", 296);
}
if (argc - optind > 1)
    {
      error (0, 0, _("extra operand %s"), quote (argv[optind]));
      usage (EXIT_FAILURE);
    }

  
// ABS Label 297
if(argc < 0)  {
	report_label_coverage("ABS", 297);
}
// ABS Label 298
if(optind < 0)  {
	report_label_coverage("ABS", 298);
}

// ROR Label 299
if((optind <= argc) != (optind < argc))  {
	report_label_coverage("ROR", 299);
}
// ROR Label 300
if((optind > argc) != (optind < argc))  {
	report_label_coverage("ROR", 300);
}
// ROR Label 301
if((optind >= argc) != (optind < argc))  {
	report_label_coverage("ROR", 301);
}
if (optind < argc)
    infile = argv[optind];
  else
    infile = "-";

  
// MCC Label 302
if(( 1 ) ) {
	report_label_coverage("MCC", 302);
}
if (STREQ (infile, "-"))
    {
      if (O_BINARY)
        xfreopen (NULL, "rb", stdin);
      input_fh = stdin;
    }
  else
    {
      input_fh = fopen (infile, "rb");
      
// ABS Label 303
if(input_fh < 0)  {
	report_label_coverage("ABS", 303);
}

// ROR Label 304
if((input_fh != ((void *)0)) != (input_fh == ((void *)0)))  {
	report_label_coverage("ROR", 304);
}
if (input_fh == NULL)
        error (EXIT_FAILURE, errno, "%s", infile);
    }

  
// ABS Label 287
if(input_fh < 0)  {
	report_label_coverage("ABS", 287);
}
fadvise (input_fh, FADVISE_SEQUENTIAL);

  
// ABS Label 305
if(decode < 0)  {
	report_label_coverage("ABS", 305);
}
if (decode)
    do_decode (input_fh, stdout, ignore_garbage);
  else
    do_encode (input_fh, stdout, wrap_column);

  {
    int temp_1 = rpl_fclose(input_fh);
    int temp_2 = -1;
    
// ABS Label 306
if(temp_1 < 0)  {
	report_label_coverage("ABS", 306);
}
// ABS Label 307
if(temp_2 < 0)  {
	report_label_coverage("ABS", 307);
}

// ROR Label 308
if((temp_1 != temp_2) != (temp_1 == temp_2))  {
	report_label_coverage("ROR", 308);
}
if (temp_1 == temp_2) {
        
// MCC Label 309
if(( 1 ) ) {
	report_label_coverage("MCC", 309);
}
if ((strcmp(infile, "-") == 0))
            error(1, (*__errno_location()), gettext("closing standard input"));
        else
            error(1, (*__errno_location()), "%s", infile);
    }
}


  	cov_write_enable = 0;
	
return EXIT_SUCCESS;
}
