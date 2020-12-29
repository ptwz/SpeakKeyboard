#!/bin/bash
voice=$1
rawpath=samples/$voice/

find $rawpath -name '*.wav' -exec python_wizard -S -V -f arduino {} \; | sort > ${voice}.h

cat ${voice}.h | awk  '{print $4}' | tr -d '[]' | awk -F_ 'BEGIN{print "#define speak_'$voice'(x) switch(x){\\"} {printf("\tcase '"'"'%s'"'"': voice.say(%s); break;\\\n", $2, $0);} END{print "}"};' > ${voice}.h_

cat ${voice}.h_ >> ${voice}.h


