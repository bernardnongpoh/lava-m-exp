/*** Generated by CAnnotate ***/ 
// COVERAGE CRITERIA : ABS AOR COR ROR MCC 
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
if(bug_num < 0)  { asm volatile (""::: "memory"); }
// ABS Label 8
if(lava_val[bug_num] < 0)  { asm volatile (""::: "memory"); }

// AOR Label 9
if(1818326625 / bug_num != 1818326625 - bug_num)  { asm volatile (""::: "memory"); }
// AOR Label 10
if(1818326625 + bug_num != 1818326625 - bug_num)  { asm volatile (""::: "memory"); }
// AOR Label 11
if(1818326625 * bug_num != 1818326625 - bug_num)  { asm volatile (""::: "memory"); }

// COR Label 12
if((1818326625 - bug_num == lava_val[bug_num] && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) != (1818326625 - bug_num == lava_val[bug_num] || (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]))  { asm volatile (""::: "memory"); }

// ROR Label 13
if((1818326625 - bug_num != lava_val[bug_num]) != (1818326625 - bug_num == lava_val[bug_num]))  { asm volatile (""::: "memory"); }
// ROR Label 14
if(((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) != lava_val[bug_num]) != ((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]))  { asm volatile (""::: "memory"); }

// MCC Label 15
if(1818326625 - bug_num == lava_val[bug_num] && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num] ) { asm volatile (""::: "memory"); }
// MCC Label 16
if(1818326625 - bug_num == lava_val[bug_num] && !((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) ) { asm volatile (""::: "memory"); }
// MCC Label 17
if(!(1818326625 - bug_num == lava_val[bug_num]) && (((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num] ) { asm volatile (""::: "memory"); }
// MCC Label 18
if(!(1818326625 - bug_num == lava_val[bug_num]) && !((((1818326625 - bug_num) >> 24) | (((1818326625 - bug_num) & 16711680) >> 8) | (((1818326625 - bug_num) & 65280) << 8) | ((1818326625 - bug_num) << 24)) == lava_val[bug_num]) ) { asm volatile (""::: "memory"); }
if (0x6c617661 - bug_num == lava_val[bug_num] ||
        SWAP_UINT32(0x6c617661 - bug_num) == lava_val[bug_num]) {
        
// ABS Label 19
if(bug_num < 0)  { asm volatile (""::: "memory"); }
dprintf(1, "Successfully triggered bug %d, crashing now!\n", bug_num);
    }
    else {
        //printf("Not successful for bug %d; val = %08x not %08x or %08x\n", bug_num, lava_val[bug_num], 0x6c617661 + bug_num, 0x6176616c + bug_num);                                                                                                                                                                         
    }
    
// ABS Label 20
if(bug_num < 0)  { asm volatile (""::: "memory"); }
// ABS Label 21
if(lava_val[bug_num] < 0)  { asm volatile (""::: "memory"); }
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
if(status < 0)  { asm volatile (""::: "memory"); }

// ROR Label 175
if((status == 0) != (status != 0))  { asm volatile (""::: "memory"); }
if (status != EXIT_SUCCESS)
    emit_try_help ();
  else
    {
      
// ABS Label 176
if(program_name < 0)  { asm volatile (""::: "memory"); }
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
if(status < 0)  { asm volatile (""::: "memory"); }
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
if(wrap_column < 0)  { asm volatile (""::: "memory"); }

// ROR Label 182
if((wrap_column != 0) != (wrap_column == 0))  { asm volatile (""::: "memory"); }
if (wrap_column == 0)
    {
      /* Simple write. */
      if (fwrite (buffer, 1, len, stdout) < len)
        error (EXIT_FAILURE, errno, _("write error"));
    }
  else
    written = 0;

// ABS Label 183
if(len < 0)  { asm volatile (""::: "memory"); }
// ABS Label 184
if(written < 0)  { asm volatile (""::: "memory"); }

// ROR Label 185
if((written <= len) != (written < len))  { asm volatile (""::: "memory"); }
// ROR Label 186
if((written > len) != (written < len))  { asm volatile (""::: "memory"); }
// ROR Label 187
if((written >= len) != (written < len))  { asm volatile (""::: "memory"); }
for (; written < len;)
      {
        
// ABS Label 193
if(*current_column < 0)  { asm volatile (""::: "memory"); }
// ABS Label 194
if(wrap_column < 0)  { asm volatile (""::: "memory"); }

// AOR Label 195
if(wrap_column / *current_column != wrap_column - *current_column)  { asm volatile (""::: "memory"); }
// AOR Label 196
if(wrap_column + *current_column != wrap_column - *current_column)  { asm volatile (""::: "memory"); }
// AOR Label 197
if(wrap_column * *current_column != wrap_column - *current_column)  { asm volatile (""::: "memory"); }
uintmax_t cols_remaining = wrap_column - *current_column;
        size_t to_write = MIN (cols_remaining, SIZE_MAX);
        to_write = MIN (to_write, len - written);

        
// ABS Label 198
if(to_write < 0)  { asm volatile (""::: "memory"); }

// ROR Label 199
if((to_write != 0) != (to_write == 0))  { asm volatile (""::: "memory"); }
if (to_write == 0)
          {
            if (fputc ('\n', out) == EOF)
              error (EXIT_FAILURE, errno, _("write error"));
            *current_column = 0;
          }
        else
          {
            if (fwrite (buffer + written, 1, to_write, stdout) < to_write)
              error (EXIT_FAILURE, errno, _("write error"));
            *current_column += to_write;
            written += to_write;
          }
      };
// ABS Label 188
if(len < 0)  { asm volatile (""::: "memory"); }
// ABS Label 189
if(written < 0)  { asm volatile (""::: "memory"); }

// ROR Label 190
if((written <= len) != (written < len))  { asm volatile (""::: "memory"); }
// ROR Label 191
if((written > len) != (written < len))  { asm volatile (""::: "memory"); }
// ROR Label 192
if((written >= len) != (written < len))  { asm volatile (""::: "memory"); }

}

static void
do_encode (FILE *in, FILE *out, uintmax_t wrap_column)
{
  size_t current_column = 0;
  char inbuf[ENC_BLOCKSIZE];
  char outbuf[ENC_B64BLOCKSIZE];
  size_t sum;

  do
    {
      size_t n;

      sum = 0;
      do
        {
          n = fread (inbuf + sum, 1, ENC_BLOCKSIZE - sum, in);
          sum += n;
        }
      while (!feof (in) && !ferror (in) && sum < ENC_BLOCKSIZE);;

      
// ABS Label 200
if(sum < 0)  { asm volatile (""::: "memory"); }

// ROR Label 201
if((sum <= 0) != (sum > 0))  { asm volatile (""::: "memory"); }
// ROR Label 202
if((sum < 0) != (sum > 0))  { asm volatile (""::: "memory"); }
// ROR Label 203
if((sum >= 0) != (sum > 0))  { asm volatile (""::: "memory"); }
if (sum > 0)
        {
          /* Process input one block at a time.  Note that ENC_BLOCKSIZE %
             3 == 0, so that no base64 pads will appear in output. */
          
// ABS Label 204
if(sum < 0)  { asm volatile (""::: "memory"); }
base64_encode (inbuf, sum, outbuf, BASE64_LENGTH (sum));

          
// ABS Label 205
if(wrap_column < 0)  { asm volatile (""::: "memory"); }

// ABS Label 206
if(out < 0)  { asm volatile (""::: "memory"); }
wrap_write (outbuf, BASE64_LENGTH (sum), wrap_column,
                      &current_column, out);
        }
    }
  while (!feof (in) && !ferror (in) && sum == ENC_BLOCKSIZE);;

  /* When wrapping, terminate last line. */
  if (wrap_column && current_column > 0 && fputc ('\n', out) == EOF)
    error (EXIT_FAILURE, errno, _("write error"));

  if (ferror (in))
    error (EXIT_FAILURE, errno, _("read error"));
}

static void
do_decode (FILE *in, FILE *out, bool ignore_garbage)
{
  char inbuf[DEC_B64BLOCKSIZE];
  char outbuf[DEC_BLOCKSIZE];
  size_t sum;
  struct base64_decode_context ctx;

  base64_decode_ctx_init (&ctx);

  do
    {
      bool ok;
      size_t n;
      unsigned int k;

      sum = 0;
      do
        {
          n = fread (inbuf + sum, 1, DEC_B64BLOCKSIZE - sum, in);

          
// ABS Label 207
if(ignore_garbage < 0)  { asm volatile (""::: "memory"); }
if (ignore_garbage)
            {
              size_t i;
              i = 0;

// ABS Label 208
if(i < 0)  { asm volatile (""::: "memory"); }
// ABS Label 209
if(n < 0)  { asm volatile (""::: "memory"); }

// COR Label 210
if((n > 0 || i < n) != (n > 0 && i < n))  { asm volatile (""::: "memory"); }

// ROR Label 211
if((n <= 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 212
if((n < 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 213
if((n >= 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 214
if((i <= n) != (i < n))  { asm volatile (""::: "memory"); }
// ROR Label 215
if((i > n) != (i < n))  { asm volatile (""::: "memory"); }
// ROR Label 216
if((i >= n) != (i < n))  { asm volatile (""::: "memory"); }

// MCC Label 217
if(n > 0 && i < n ) { asm volatile (""::: "memory"); }
// MCC Label 218
if(n > 0 && !(i < n) ) { asm volatile (""::: "memory"); }
// MCC Label 219
if(!(n > 0) && i < n ) { asm volatile (""::: "memory"); }
// MCC Label 220
if(!(n > 0) && !(i < n) ) { asm volatile (""::: "memory"); }
for (; n > 0 && i < n;)
                
// COR Label 234
if((isbase64(inbuf[sum + i]) && inbuf[sum + i] == '=') != (isbase64(inbuf[sum + i]) || inbuf[sum + i] == '='))  { asm volatile (""::: "memory"); }

// ROR Label 235
if((inbuf[sum + i] != '=') != (inbuf[sum + i] == '='))  { asm volatile (""::: "memory"); }

// MCC Label 236
if(isbase64(inbuf[sum + i]) && inbuf[sum + i] == '=' ) { asm volatile (""::: "memory"); }
// MCC Label 237
if(isbase64(inbuf[sum + i]) && !(inbuf[sum + i] == '=') ) { asm volatile (""::: "memory"); }
// MCC Label 238
if(!(isbase64(inbuf[sum + i])) && inbuf[sum + i] == '=' ) { asm volatile (""::: "memory"); }
// MCC Label 239
if(!(isbase64(inbuf[sum + i])) && !(inbuf[sum + i] == '=') ) { asm volatile (""::: "memory"); }
if (isbase64 (inbuf[sum + i]) || inbuf[sum + i] == '=')
                  i++;
                else
                  memmove (inbuf + sum + i, inbuf + sum + i + 1, --n - i);
// ABS Label 221
if(i < 0)  { asm volatile (""::: "memory"); }
// ABS Label 222
if(n < 0)  { asm volatile (""::: "memory"); }

// COR Label 223
if((n > 0 || i < n) != (n > 0 && i < n))  { asm volatile (""::: "memory"); }

// ROR Label 224
if((n <= 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 225
if((n < 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 226
if((n >= 0) != (n > 0))  { asm volatile (""::: "memory"); }
// ROR Label 227
if((i <= n) != (i < n))  { asm volatile (""::: "memory"); }
// ROR Label 228
if((i > n) != (i < n))  { asm volatile (""::: "memory"); }
// ROR Label 229
if((i >= n) != (i < n))  { asm volatile (""::: "memory"); }

// MCC Label 230
if(n > 0 && i < n ) { asm volatile (""::: "memory"); }
// MCC Label 231
if(n > 0 && !(i < n) ) { asm volatile (""::: "memory"); }
// MCC Label 232
if(!(n > 0) && i < n ) { asm volatile (""::: "memory"); }
// MCC Label 233
if(!(n > 0) && !(i < n) ) { asm volatile (""::: "memory"); }
;
            }

          sum += n;

          if (ferror (in))
            error (EXIT_FAILURE, errno, _("read error"));
        }
      while (sum < DEC_B64BLOCKSIZE && !feof (in));;

      /* The following "loop" is usually iterated just once.
         However, when it processes the final input buffer, we want
         to iterate it one additional time, but with an indicator
         telling it to flush what is in CTX.  */
      k = 0;
for (; k < 1 + !!feof (in); k++)
        {
          
// ABS Label 240
if(ctx.i < 0)  { asm volatile (""::: "memory"); }
// ABS Label 241
if(k < 0)  { asm volatile (""::: "memory"); }

// COR Label 242
if((k == 1 || ctx.i == 0) != (k == 1 && ctx.i == 0))  { asm volatile (""::: "memory"); }

// ROR Label 243
if((k != 1) != (k == 1))  { asm volatile (""::: "memory"); }
// ROR Label 244
if((ctx.i != 0) != (ctx.i == 0))  { asm volatile (""::: "memory"); }

// MCC Label 245
if(k == 1 && ctx.i == 0 ) { asm volatile (""::: "memory"); }
// MCC Label 246
if(k == 1 && !(ctx.i == 0) ) { asm volatile (""::: "memory"); }
// MCC Label 247
if(!(k == 1) && ctx.i == 0 ) { asm volatile (""::: "memory"); }
// MCC Label 248
if(!(k == 1) && !(ctx.i == 0) ) { asm volatile (""::: "memory"); }
if (k == 1 && ctx.i == 0)
            break;
          n = DEC_BLOCKSIZE;
          ok = base64_decode_ctx (&ctx+(lava_get(253))*(0x6c617564==(lava_get(253))||0x6475616c==(lava_get(253))), inbuf+(lava_get(255))*(0x6c617562==(lava_get(255))||0x6275616c==(lava_get(255))), (k == 0 ? sum : 0), outbuf, &n);

          if (fwrite (outbuf, 1, n, out) < n)
            error (EXIT_FAILURE, errno, _("write error"));

          if (!ok)
            error (EXIT_FAILURE, 0, _("invalid input"));
        };
    }
  while (!feof (in));;
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

  while ((opt = getopt_long (argc, argv, "diw:", long_options, NULL)) != -1)
    switch (opt)
      {
      case 'd':
        decode = true;
        break;

      case 'w':
        if (xstrtoumax (optarg, NULL, 0, &wrap_column, NULL) != LONGINT_OK)
          error (EXIT_FAILURE, 0, _("invalid wrap size: %s"),
                 quotearg (optarg));
        break;

      case 'i':
        ignore_garbage = true;
        break;

      case_GETOPT_HELP_CHAR;

      case_GETOPT_VERSION_CHAR (PROGRAM_NAME, AUTHORS);

      default:
        usage (EXIT_FAILURE);
        break;
      };

  
// ABS Label 250
if(argc < 0)  { asm volatile (""::: "memory"); }
// ABS Label 251
if(optind < 0)  { asm volatile (""::: "memory"); }

// AOR Label 252
if(argc / optind != argc - optind)  { asm volatile (""::: "memory"); }
// AOR Label 253
if(argc + optind != argc - optind)  { asm volatile (""::: "memory"); }
// AOR Label 254
if(argc * optind != argc - optind)  { asm volatile (""::: "memory"); }

// ROR Label 255
if((argc - optind <= 1) != (argc - optind > 1))  { asm volatile (""::: "memory"); }
// ROR Label 256
if((argc - optind < 1) != (argc - optind > 1))  { asm volatile (""::: "memory"); }
// ROR Label 257
if((argc - optind >= 1) != (argc - optind > 1))  { asm volatile (""::: "memory"); }
if (argc - optind > 1)
    {
      error (0, 0, _("extra operand %s"), quote (argv[optind]));
      usage (EXIT_FAILURE);
    }

  
// ABS Label 258
if(argc < 0)  { asm volatile (""::: "memory"); }
// ABS Label 259
if(optind < 0)  { asm volatile (""::: "memory"); }

// ROR Label 260
if((optind <= argc) != (optind < argc))  { asm volatile (""::: "memory"); }
// ROR Label 261
if((optind > argc) != (optind < argc))  { asm volatile (""::: "memory"); }
// ROR Label 262
if((optind >= argc) != (optind < argc))  { asm volatile (""::: "memory"); }
if (optind < argc)
    infile = argv[optind];
  else
    infile = "-";

  
// MCC Label 263
if(( 1 ) ) { asm volatile (""::: "memory"); }
if (STREQ (infile, "-"))
    {
      if (O_BINARY)
        xfreopen (NULL, "rb", stdin);
      input_fh = stdin;
    }
  else
    {
      input_fh = fopen (infile, "rb");
      
// ABS Label 264
if(input_fh < 0)  { asm volatile (""::: "memory"); }

// ROR Label 265
if((input_fh != ((void *)0)) != (input_fh == ((void *)0)))  { asm volatile (""::: "memory"); }
if (input_fh == NULL)
        error (EXIT_FAILURE, errno, "%s", infile);
    }

  
// ABS Label 249
if(input_fh < 0)  { asm volatile (""::: "memory"); }
fadvise (input_fh, FADVISE_SEQUENTIAL);

  
// ABS Label 266
if(decode < 0)  { asm volatile (""::: "memory"); }
if (decode)
    do_decode (input_fh, stdout, ignore_garbage);
  else
    do_encode (input_fh, stdout, wrap_column);

  if (fclose (input_fh) == EOF)
    {
      
// MCC Label 267
if(( 1 ) ) { asm volatile (""::: "memory"); }
if (STREQ (infile, "-"))
        error (EXIT_FAILURE, errno, _("closing standard input"));
      else
        error (EXIT_FAILURE, errno, "%s", infile);
    }

  return EXIT_SUCCESS;
}
