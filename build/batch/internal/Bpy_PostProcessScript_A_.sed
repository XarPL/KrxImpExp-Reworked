# This file does global replace LINEBREAK with LF, ___ with tabulation

s/LINEBREAK[ \t]*/\n/g
s/#line.*//
s/^[ \t]+//
s/___[ \t]*/\t/g