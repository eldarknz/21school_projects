#!/bin/sh

#HH API
HH_API_URL='https://api.hh.ru/vacancies'

#Values
VALUE_TEXT='datascientist'
VALUE_PAGE='0'
VALUE_PER_PAGE='20'

#params
PARAM_TEX="text"
PARAM_PER_PAGE="per_page"
PARAM_PAGE="page"

#Key CURL values
A_KEY='api-test-agent'

#Python JSON processing
PYTHON_SCRIPT='import sys ;import json ; print(json.dumps(json.loads(sys.stdin.read()), sort_keys=False, ensure_ascii=False, indent=4, separators=(",", " : ")))'

#Output filename
FILENAME=`basename $0 | cut -f 1 -d '.'`
EXT="json"

if [ $# -eq 0 ]
then
	RQST_VALUE=$DFLT_VAC
elif [ $# -eq 1 ]
then
	RQST_VALUE=$1
else
	echo "usage: ./hh.sh vacancy"
	exit 0
fi

#Query
#curl -A $A_KEY "$HH_API_URL$Q$DFLT_PER_PAGE$D$DFLT_PAGE$D$RQST_PARAM$RQST_VALUE&search_field=name" | python3 -c "$PYTHON_SCRIPT" > "$FILENAME.$EXT"
curl -A $A_KEY \
     "$HH_API_URL\
     ?$PARAM_PER_PAGE=$VALUE_PER_PAGE\
     &$PARAM_PAGE=$VALUE_PAGE\
     &$PARAM_TEXT=$VALUE_TEXT\
     &search_field=name" \
     | python3 -c "$PYTHON_SCRIPT" > "$FILENAME.$EXT"
