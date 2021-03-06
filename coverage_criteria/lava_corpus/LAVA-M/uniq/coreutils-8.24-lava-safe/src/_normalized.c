#include <stdio.h>
extern unsigned int lava_get(unsigned int) ;
void lava_set(unsigned int bn, unsigned int val);
static unsigned int lava_val[1000000];
void lava_set(unsigned int bug_num, unsigned int val);
void lava_set(unsigned int bug_num, unsigned int val) { lava_val[bug_num] = val; }
unsigned int lava_get(unsigned int bug_num);
unsigned int lava_get(unsigned int bug_num) {
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
    if (0x6c617661 - bug_num == lava_val[bug_num] ||
        SWAP_UINT32(0x6c617661 - bug_num) == lava_val[bug_num]) {
        dprintf(1, "Successfully triggered bug %d, crashing now!\n", bug_num);
    }
    else {
        //printf("Not successful for bug %d; val = %08x not %08x or %08x\n", bug_num, lava_val[bug_num], 0x6c617661 + bug_num, 0x6176616c + bug_num);
    }

    return lava_val[bug_num];
}
/* uniq -- remove duplicate lines from a sorted file
   Copyright (C) 1986-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Richard M. Stallman and David MacKenzie. */

#include <config.h>

#include <getopt.h>
#include <sys/types.h>

#include "system.h"
#include "argmatch.h"
#include "linebuffer.h"
#include "error.h"
#include "fadvise.h"
#include "hard-locale.h"
#include "posixver.h"
#include "quote.h"
#include "stdio--.h"
#include "xmemcoll.h"
#include "xstrtol.h"
#include "memcasecmp.h"

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "uniq"

#define AUTHORS \
  proper_name ("Richard M. Stallman"), \
  proper_name ("David MacKenzie")

#define SWAP_LINES(A, B)			\
  do						\
    {						\
      struct linebuffer *_tmp;			\
      _tmp = (A);				\
      (A) = (B);				\
      (B) = _tmp;				\
    }						\
  while (0)

/* True if the LC_COLLATE locale is hard.  */
static bool hard_LC_COLLATE;

/* Number of fields to skip on each line when doing comparisons. */
static size_t skip_fields;

/* Number of chars to skip after skipping any fields. */
static size_t skip_chars;

/* Number of chars to compare. */
static size_t check_chars;

enum countmode
{
  count_occurrences,		/* -c Print count before output lines. */
  count_none			/* Default.  Do not print counts. */
};

/* Whether and how to precede the output lines with a count of the number of
   times they occurred in the input. */
static enum countmode countmode;

/* Which lines to output: unique lines, the first of a group of
   repeated lines, and the second and subsequented of a group of
   repeated lines.  */
static bool output_unique;
static bool output_first_repeated;
static bool output_later_repeated;

/* If true, ignore case when comparing.  */
static bool ignore_case;

enum delimit_method
{
  /* No delimiters output.  --all-repeated[=none] */
  DM_NONE,

  /* Delimiter precedes all groups.  --all-repeated=prepend */
  DM_PREPEND,

  /* Delimit all groups.  --all-repeated=separate */
  DM_SEPARATE
};

static char const *const delimit_method_string[] =
{
  "none", "prepend", "separate", NULL
};

static enum delimit_method const delimit_method_map[] =
{
  DM_NONE, DM_PREPEND, DM_SEPARATE
};

/* Select whether/how to delimit groups of duplicate lines.  */
static enum delimit_method delimit_groups;

enum grouping_method
{
  /* No grouping, when "--group" isn't used */
  GM_NONE,

  /* Delimiter preceges all groups.  --group=prepend */
  GM_PREPEND,

  /* Delimiter follows all groups.   --group=append */
  GM_APPEND,

  /* Delimiter between groups.    --group[=separate] */
  GM_SEPARATE,

  /* Delimiter before and after each group. --group=both */
  GM_BOTH
};

static char const *const grouping_method_string[] =
{
  "prepend", "append", "separate", "both", NULL
};

static enum grouping_method const grouping_method_map[] =
{
  GM_PREPEND, GM_APPEND, GM_SEPARATE, GM_BOTH
};

static enum grouping_method grouping = GM_NONE;

enum
{
  GROUP_OPTION = CHAR_MAX + 1
};

static struct option const longopts[] =
{
  {"count", no_argument, NULL, 'c'},
  {"repeated", no_argument, NULL, 'd'},
  {"all-repeated", optional_argument, NULL, 'D'},
  {"group", optional_argument, NULL, GROUP_OPTION},
  {"ignore-case", no_argument, NULL, 'i'},
  {"unique", no_argument, NULL, 'u'},
  {"skip-fields", required_argument, NULL, 'f'},
  {"skip-chars", required_argument, NULL, 's'},
  {"check-chars", required_argument, NULL, 'w'},
  {"zero-terminated", no_argument, NULL, 'z'},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};

void
usage (int status)
{
  if (status != EXIT_SUCCESS)
    emit_try_help ();
  else
    {
      printf (_("\
Usage: %s [OPTION]... [INPUT [OUTPUT]]\n\
"),
              program_name);
      fputs (_("\
Filter adjacent matching lines from INPUT (or standard input),\n\
writing to OUTPUT (or standard output).\n\
\n\
With no options, matching lines are merged to the first occurrence.\n\
"), stdout);

      emit_mandatory_arg_note ();

     fputs (_("\
  -c, --count           prefix lines by the number of occurrences\n\
  -d, --repeated        only print duplicate lines, one for each group\n\
"), stdout);
     fputs (_("\
  -D, --all-repeated[=METHOD]  print all duplicate lines;\n\
                          groups can be delimited with an empty line;\n\
                          METHOD={none(default),prepend,separate}\n\
"), stdout);
     fputs (_("\
  -f, --skip-fields=N   avoid comparing the first N fields\n\
"), stdout);
     fputs (_("\
      --group[=METHOD]  show all items, separating groups with an empty line;\n\
                          METHOD={separate(default),prepend,append,both}\n\
"), stdout);
     fputs (_("\
  -i, --ignore-case     ignore differences in case when comparing\n\
  -s, --skip-chars=N    avoid comparing the first N characters\n\
  -u, --unique          only print unique lines\n\
"), stdout);
      fputs (_("\
  -z, --zero-terminated     line delimiter is NUL, not newline\n\
"), stdout);
     fputs (_("\
  -w, --check-chars=N   compare no more than N characters in lines\n\
"), stdout);
     fputs (HELP_OPTION_DESCRIPTION, stdout);
     fputs (VERSION_OPTION_DESCRIPTION, stdout);
     fputs (_("\
\n\
A field is a run of blanks (usually spaces and/or TABs), then non-blank\n\
characters.  Fields are skipped before chars.\n\
"), stdout);
     fputs (_("\
\n\
Note: 'uniq' does not detect repeated lines unless they are adjacent.\n\
You may want to sort the input first, or use 'sort -u' without 'uniq'.\n\
Also, comparisons honor the rules specified by 'LC_COLLATE'.\n\
"), stdout);
      emit_ancillary_info (PROGRAM_NAME);
    }
  exit (status);
}

/* Convert OPT to size_t, reporting an error using MSGID if OPT is
   invalid.  Silently convert too-large values to SIZE_MAX.  */

static size_t
size_opt (char const *opt, char const *msgid)
{
  unsigned long int size;
  verify (SIZE_MAX <= ULONG_MAX);

  switch (xstrtoul (opt, NULL, 10, &size, ""))
    {
    case LONGINT_OK:
    case LONGINT_OVERFLOW:
      break;

    default:
      error (EXIT_FAILURE, 0, "%s: %s", opt, _(msgid));
    }

  return MIN (size, SIZE_MAX);
}

/* Given a linebuffer LINE,
   return a pointer to the beginning of the line's field to be compared. */

static char * _GL_ATTRIBUTE_PURE
find_field (struct linebuffer const *line)
{
  size_t count;
  char const *lp = line->buffer;
  size_t size = line->length - 1;
  size_t i = 0;

  for (count = 0; count < skip_fields && i < size; count++)
    {
      while (1)
    {
        {
            int temp_1 = !(i < size && ((*__ctype_b_loc())[(int)((to_uchar(lp[i])))] & (unsigned short)_ISblank));
            if (temp_1)
                break;
        }
        i++;
    }
;
      while (1)
    {
        {
            int temp_1 = !(i < size && !((*__ctype_b_loc())[(int)((to_uchar(lp[i])))] & (unsigned short)_ISblank));
            if (temp_1)
                break;
        }
        i++;
    }
;
    }

  i += MIN (skip_chars, size - i);

  return line->buffer + i;
}

/* Return false if two strings OLD and NEW match, true if not.
   OLD and NEW point not to the beginnings of the lines
   but rather to the beginnings of the fields to compare.
   OLDLEN and NEWLEN are their lengths. */

static bool
different (char *old, char *new, size_t oldlen, size_t newlen)
{
  if (check_chars < oldlen)
    oldlen = check_chars;
  if (check_chars < newlen)
    newlen = check_chars;

  if (ignore_case)
    {
      /* FIXME: This should invoke strcoll somehow.  */
      return oldlen != newlen || memcasecmp (old, new, oldlen);
    }
  else if (hard_LC_COLLATE)
    return xmemcoll (old, oldlen, new, newlen) != 0;
  else
    return oldlen != newlen || memcmp (old, new, oldlen);
}

/* Output the line in linebuffer LINE to standard output
   provided that the switches say it should be output.
   MATCH is true if the line matches the previous line.
   If requested, print the number of times it occurred, as well;
   LINECOUNT + 1 is the number of times that the line occurred. */

static void
writeline (struct linebuffer const *line,
           bool match, uintmax_t linecount)
{
  if (! (linecount == 0 ? output_unique
         : !match ? output_first_repeated
         : output_later_repeated))
    return;

  if (countmode == count_occurrences)
    printf ("%7" PRIuMAX " ", linecount + 1);

  fwrite (line->buffer, sizeof (char), line->length, stdout);
}

/* Process input file INFILE with output to OUTFILE.
   If either is "-", use the standard I/O stream for it instead. */

static void
check_file (const char *infile, const char *outfile, char delimiter)
{
  struct linebuffer lb1, lb2;
  struct linebuffer *thisline, *prevline;

  {
    int temp_1 = !((strcmp(infile, "-") == 0) || freopen_safer(infile, "r", stdin));
    if (temp_1)
        error(1, (*__errno_location()), "%s", infile);
}
;
  {
    int temp_1 = !((strcmp(outfile, "-") == 0) || freopen_safer(outfile, "w", stdout));
    if (temp_1)
        error(1, (*__errno_location()), "%s", outfile);
}
;

  fadvise (stdin, FADVISE_SEQUENTIAL);

  thisline = &lb1;
  prevline = &lb2;

  initbuffer (thisline);
  initbuffer (prevline);

  /* The duplication in the following 'if' and 'else' blocks is an
     optimization to distinguish between when we can print input
     lines immediately (1. & 2.) or not.

     1. --group => all input lines are printed.
        checking for unique/duplicated lines is used only for printing
        group separators.

     2. The default case in which none of these options has been specified:
          --count, --repeated,  --all-repeated, --unique
        In the default case, this optimization lets uniq output each different
        line right away, without waiting to see if the next one is different.

     3. All other cases.
  */
  if (output_unique && output_first_repeated && countmode == count_none)
    {
      char *prevfield IF_LINT ( = NULL);
      size_t prevlen IF_LINT ( = 0);
      bool first_group_printed = false;

      while (1)
    {
        {
            int temp_1 = !(!feof_unlocked(stdin));
            if (temp_1)
                break;
        }
        {
            char *thisfield;
            size_t thislen;
            _Bool new_group;
            {
                struct linebuffer *temp_2 = readlinebuffer_delim(thisline + (lava_get(215)) * (1818326410 == (lava_get(215)) || 2322948460U == (lava_get(215))), stdin, delimiter);
                if (temp_2 == 0)
                    break;
            }
            thisfield = ({
                char *kbcieiubweuhc1967513926 = find_field(thisline + (lava_get(169)) * (1818326456 == (lava_get(169)) || 3094700396U == (lava_get(169))) + (lava_get(171)) * (1818326454 == (lava_get(171)) || 3061145964U == (lava_get(171))) + (lava_get(170)) * (1818326455 == (lava_get(170)) || 3077923180U == (lava_get(170))));
                if ((kbcieiubweuhc1967513926) && (kbcieiubweuhc1967513926)) {
                    int lava_443 = 0;
                    lava_443 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_443 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_443 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_443 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(443, lava_443);
                    int lava_293 = 0;
                    lava_293 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_293 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_293 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_293 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(293, lava_293);
                    int lava_318 = 0;
                    lava_318 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_318 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_318 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_318 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(318, lava_318);
                    int lava_468 = 0;
                    lava_468 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_468 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_468 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_468 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(468, lava_468);
                    int lava_368 = 0;
                    lava_368 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_368 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_368 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_368 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(368, lava_368);
                    int lava_393 = 0;
                    lava_393 |= ((unsigned char *)kbcieiubweuhc1967513926)[0] << (0 * 8);
                    lava_393 |= ((unsigned char *)kbcieiubweuhc1967513926)[1] << (1 * 8);
                    lava_393 |= ((unsigned char *)kbcieiubweuhc1967513926)[2] << (2 * 8);
                    lava_393 |= ((unsigned char *)kbcieiubweuhc1967513926)[3] << (3 * 8);
                    lava_set(393, lava_393);
                }
                kbcieiubweuhc1967513926;
            });
            thislen = thisline->length - 1 - (thisfield - thisline->buffer);
            new_group = (prevline->length == 0 || ({
                if (((thisfield)) && ((thisfield))) {
                    int lava_446 = 0;
                    lava_446 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_446 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_446 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_446 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(446, lava_446);
                    int lava_296 = 0;
                    lava_296 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_296 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_296 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_296 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(296, lava_296);
                    int lava_346 = 0;
                    lava_346 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_346 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_346 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_346 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(346, lava_346);
                    int lava_321 = 0;
                    lava_321 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_321 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_321 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_321 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(321, lava_321);
                    int lava_471 = 0;
                    lava_471 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_471 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_471 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_471 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(471, lava_471);
                    int lava_371 = 0;
                    lava_371 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_371 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_371 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_371 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(371, lava_371);
                    int lava_396 = 0;
                    lava_396 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_396 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_396 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_396 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(396, lava_396);
                }
                _Bool kbcieiubweuhc1365180540 = different(thisfield, prevfield, thislen, prevlen);
                if (((thisfield)) && ((thisfield))) {
                    int lava_447 = 0;
                    lava_447 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_447 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_447 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_447 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(447, lava_447);
                    int lava_297 = 0;
                    lava_297 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_297 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_297 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_297 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(297, lava_297);
                    int lava_347 = 0;
                    lava_347 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_347 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_347 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_347 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(347, lava_347);
                    int lava_322 = 0;
                    lava_322 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_322 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_322 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_322 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(322, lava_322);
                    int lava_472 = 0;
                    lava_472 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_472 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_472 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_472 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(472, lava_472);
                    int lava_372 = 0;
                    lava_372 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_372 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_372 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_372 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(372, lava_372);
                    int lava_397 = 0;
                    lava_397 |= ((unsigned char *)(thisfield))[0] << (0 * 8);
                    lava_397 |= ((unsigned char *)(thisfield))[1] << (1 * 8);
                    lava_397 |= ((unsigned char *)(thisfield))[2] << (2 * 8);
                    lava_397 |= ((unsigned char *)(thisfield))[3] << (3 * 8);
                    lava_set(397, lava_397);
                }
                kbcieiubweuhc1365180540;
            }));
            if (new_group && grouping != GM_NONE && (grouping == GM_PREPEND || grouping == GM_BOTH || (first_group_printed && (grouping == GM_APPEND || grouping == GM_SEPARATE))))
                putchar_unlocked(delimiter);
            if (new_group || grouping != GM_NONE) {
                fwrite_unlocked(thisline->buffer, sizeof(char), thisline->length, stdout);
                do {
                    struct linebuffer *_tmp;
                    _tmp = (prevline);
                    (prevline) = (thisline);
                    (thisline) = _tmp;
                } while (0);
                prevfield = thisfield;
                prevlen = thislen;
                first_group_printed = 1;
            }
        }
    }

      if ((grouping == GM_BOTH || grouping == GM_APPEND) && first_group_printed)
        putchar (delimiter);
    }
  else
    {
      char *prevfield;
      size_t prevlen;
      uintmax_t match_count = 0;
      bool first_delimiter = true;

      {
    struct linebuffer *temp_1 = readlinebuffer_delim(prevline, stdin, delimiter);
    if (temp_1 == 0)
        goto closefiles;
}
;
      prevfield = find_field (prevline);
      prevlen = prevline->length - 1 - (prevfield - prevline->buffer);

      while (1)
    {
        {
            int temp_1 = !(!feof_unlocked(stdin));
            if (temp_1)
                break;
        }
        {
            _Bool match;
            char *thisfield;
            size_t thislen;
            {
                struct linebuffer *temp_3 = readlinebuffer_delim(thisline, stdin, delimiter);
                if (temp_3 == 0) {
                    {
                        int temp_2 = ferror_unlocked(stdin);
                        if (temp_2)
                            goto closefiles;
                    }
                    break;
                }
            }
            thisfield = find_field(thisline);
            thislen = thisline->length - 1 - (thisfield - thisline->buffer);
            match = !different(thisfield, prevfield, thislen, prevlen);
            match_count += match;
            if (match_count == (18446744073709551615UL)) {
                if (count_occurrences)
                    error(1, 0, gettext("too many repeated lines"));
                match_count--;
            }
            if (delimit_groups != DM_NONE) {
                if (!match) {
                    if (match_count)
                        first_delimiter = 0;
                } else if (match_count == 1) {
                    if ((delimit_groups == DM_PREPEND) || (delimit_groups == DM_SEPARATE && !first_delimiter))
                        putchar_unlocked(delimiter);
                }
            }
            if (!match || output_later_repeated) {
                writeline(prevline, match, match_count);
                do {
                    struct linebuffer *_tmp;
                    _tmp = (prevline);
                    (prevline) = (thisline);
                    (thisline) = _tmp;
                } while (0);
                prevfield = thisfield;
                prevlen = thislen;
                if (!match)
                    match_count = 0;
            }
        }
    }


      writeline (prevline, false, match_count);
    }

 closefiles:
  {
    int temp_2 = ferror_unlocked(stdin);
    if (temp_2)
        goto label_2;
    else {
        int temp_1 = rpl_fclose(stdin);
        if (temp_1 != 0)
          label_2:
            error(1, 0, gettext("error reading %s"), infile);
    }
}
;

  /* stdout is handled via the atexit-invoked close_stdout function.  */

  free (lb1.buffer);
  free (lb2.buffer);
}

enum Skip_field_option_type
  {
    SFO_NONE,
    SFO_OBSOLETE,
    SFO_NEW
  };

int
main (int argc, char **argv)
{
  int optc = 0;
  bool posixly_correct = (getenv ("POSIXLY_CORRECT") != NULL);
  enum Skip_field_option_type skip_field_option_type = SFO_NONE;
  int nfiles = 0;
  char const *file[2];
  char delimiter = '\n';	/* change with --zero-terminated, -z */
  bool output_option_used = false;   /* if true, one of -u/-d/-D/-c was used */

  file[0] = file[1] = "-";
  initialize_main (&argc, &argv);
  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);
  hard_LC_COLLATE = hard_locale (LC_COLLATE);

  atexit (close_stdout);

  skip_chars = 0;
  skip_fields = 0;
  check_chars = SIZE_MAX;
  output_unique = output_first_repeated = true;
  output_later_repeated = false;
  countmode = count_none;
  delimit_groups = DM_NONE;

  while (true)
    {
      /* Parse an operand with leading "+" as a file after "--" was
         seen; or if pedantic and a file was seen; or if not
         obsolete.  */

      if (optc == -1 || (posixly_correct && nfiles != 0))
    goto label_3;
else {
    int temp_1 = getopt_long(argc, argv, "-0123456789Dcdf:is:uw:z", longopts, ((void *)0));
    int temp_2 = -1;
    if (((optc = temp_1) == temp_2))
      label_3:
        {
            if (argc <= optind)
                break;
            if (nfiles == 2) {
                error(0, 0, gettext("extra operand %s"), quote(argv[optind]));
                usage(1);
            }
            file[nfiles++] = argv[optind++];
        }
    else
        switch (optc) {
          case 1:
            {
                unsigned long size;
                if (optarg[0] == '+' && posix2_version() < 200112 && xstrtoul(optarg, ((void *)0), 10, &size, "") == LONGINT_OK && size <= (18446744073709551615UL))
                    skip_chars = size;
                else if (nfiles == 2) {
                    error(0, 0, gettext("extra operand %s"), quote(optarg));
                    usage(1);
                } else
                    file[nfiles++] = optarg;
            }
            break;
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
            {
                if (skip_field_option_type == SFO_NEW)
                    skip_fields = 0;
                if (!((void)(&(skip_fields) == (size_t *)((void *)0)) , (void)(!!sizeof(struct (unnamed struct at /home/lsl/workspace/projects/marwan/benchmarks/lava_corpus/LAVA-M/uniq/coreutils-8.24-lava-safe/src/uniq.c:622:18))) , (void)(!!sizeof(struct (unnamed struct at /home/lsl/workspace/projects/marwan/benchmarks/lava_corpus/LAVA-M/uniq/coreutils-8.24-lava-safe/src/uniq.c:622:18))) , (((size_t)-1 / 10 < (skip_fields) || (size_t)((skip_fields) * 10 + (optc - '0')) < (skip_fields)) ? 0 : (((skip_fields) = (skip_fields) * 10 + (optc - '0')) , 1))))
                    skip_fields = (18446744073709551615UL);
                skip_field_option_type = SFO_OBSOLETE;
            }
            break;
          case 'c':
            countmode = count_occurrences;
            output_option_used = 1;
            break;
          case 'd':
            output_unique = 0;
            output_option_used = 1;
            break;
          case 'D':
            output_unique = 0;
            output_later_repeated = 1;
            if (optarg == ((void *)0))
                delimit_groups = DM_NONE;
            else
                delimit_groups = ((delimit_method_map)[__xargmatch_internal("--all-repeated", optarg, delimit_method_string, (const char *)(delimit_method_map), sizeof *(delimit_method_map), argmatch_die)]);
            output_option_used = 1;
            break;
          case GROUP_OPTION:
            if (optarg == ((void *)0))
                grouping = GM_SEPARATE;
            else
                grouping = ((grouping_method_map)[__xargmatch_internal("--group", optarg, grouping_method_string, (const char *)(grouping_method_map), sizeof *(grouping_method_map), argmatch_die)]);
            break;
          case 'f':
            skip_field_option_type = SFO_NEW;
            skip_fields = size_opt(optarg, "invalid number of fields to skip");
            break;
          case 'i':
            ignore_case = 1;
            break;
          case 's':
            skip_chars = size_opt(optarg, "invalid number of bytes to skip");
            break;
          case 'u':
            output_first_repeated = 0;
            output_option_used = 1;
            break;
          case 'w':
            check_chars = size_opt(optarg, "invalid number of bytes to compare");
            break;
          case 'z':
            delimiter = '\x00';
            break;
          case GETOPT_HELP_CHAR:
            usage(0);
            break;
            ;
          case GETOPT_VERSION_CHAR:
            version_etc(stdout, "uniq", "GNU coreutils", Version, ("Richard M. Stallman"), ("David MacKenzie"), (char *)((void *)0));
            exit(0);
            break;
            ;
          default:
            usage(1);
        }
}

    }

  /* Note we could allow --group with -D at least, and that would
     avoid the need to specify a grouping method to --all-repeated.
     It was thought best to avoid deprecating those parameters though
     and keep --group separate to other options.  */
  if (grouping != GM_NONE && output_option_used)
    {
      error (0, 0, _("--group is mutually exclusive with -c/-d/-D/-u"));
      usage (EXIT_FAILURE);
    }

  if (grouping != GM_NONE && countmode != count_none)
    {
      error (0, 0,
           _("grouping and printing repeat counts is meaningless"));
      usage (EXIT_FAILURE);
    }

  if (countmode == count_occurrences && output_later_repeated)
    {
      error (0, 0,
           _("printing all duplicated lines and repeat counts is meaningless"));
      usage (EXIT_FAILURE);
    }

  check_file (file[0], file[1], delimiter);

  return EXIT_SUCCESS;
}
