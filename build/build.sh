#!/bin/sh

BASEDIR="$(dirname "$0")"
CFLAGS="-g -std=c99 -Wall -Werror"
LDFLAGS="-lm"
SRC="$BASEDIR/../src/*.c"
BIN="$BASEDIR/../bin/paisley"

gcc $CFLAGS $SRC -o $BIN $LDFLAGS
