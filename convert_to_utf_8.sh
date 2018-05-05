#!/bin/bash
#enter input encoding here
FROM_ENCODING="UTF-16"
#output encoding(UTF-8)
TO_ENCODING="UTF-8"
#convert
CONVERT=" iconv  -f   $FROM_ENCODING  -t   $TO_ENCODING"
#loop to convert multiple files 
for  file  in  *; do
$CONVERT   "$file"   -o  "${file%.txt}.utf8.converted"
done
exit 0

