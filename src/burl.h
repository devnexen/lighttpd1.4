#ifndef INCLUDED_BURL_H
#define INCLUDED_BURL_H
#include "first.h"

#include "buffer.h"

struct burl_parts_t {
  buffer *scheme;
  buffer *authority;
  buffer *path;
  buffer *query;
};

enum burl_opts_e {
  HTTP_PARSEOPT_HEADER_STRICT  = 0x1
 ,HTTP_PARSEOPT_HOST_STRICT    = 0x2
 ,HTTP_PARSEOPT_HOST_NORMALIZE = 0x4
 ,HTTP_PARSEOPT_URL_NORMALIZE  = 0x8/*normalize chars %-encoded, uppercase hex*/
 ,HTTP_PARSEOPT_URL_NORMALIZE_UNRESERVED          =0x10 /* decode unreserved */
 ,HTTP_PARSEOPT_URL_NORMALIZE_REQUIRED            =0x20 /* decode (un)reserved*/
 ,HTTP_PARSEOPT_URL_NORMALIZE_CTRLS_REJECT        =0x40
 ,HTTP_PARSEOPT_URL_NORMALIZE_PATH_BACKSLASH_TRANS=0x80 /* "\\" -> "/" Cygwin */
 ,HTTP_PARSEOPT_URL_NORMALIZE_PATH_2F_DECODE      =0x100/* "%2F"-> "/" */
 ,HTTP_PARSEOPT_URL_NORMALIZE_PATH_2F_REJECT      =0x200
 ,HTTP_PARSEOPT_URL_NORMALIZE_PATH_DOTSEG_REMOVE  =0x400/* "." ".." "//" */
 ,HTTP_PARSEOPT_URL_NORMALIZE_PATH_DOTSEG_REJECT  =0x800
 ,HTTP_PARSEOPT_URL_NORMALIZE_QUERY_20_PLUS       =0x1000
};

int burl_normalize (buffer *b, buffer *t, int flags);

#endif