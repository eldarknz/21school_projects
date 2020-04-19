#!/bin/sh

#HH API
HH_API_URL="https://api.hh.ru/vacancies"

#Values
VALUE_TEXT="datascientist"
VALUE_PAGE="0"
VALUE_PER_PAGE="20"
VALUE_SEARCH_FIELD="name"

#params
PARAM_TEXT="text"
PARAM_PER_PAGE="per_page"
PARAM_PAGE="page"
PARAM_SEARCH_FIELD="search_field"

#Key CURL values
A_KEY="api-test-agent"

#Python JSON processing
PYTHON_SCRIPT='import sys ;import json ; print(json.dumps(json.loads(sys.stdin.read()), sort_keys=False, ensure_ascii=False, indent=4, separators=(",", " : ")))'

#Output filename
FILENAME=`basename $0 | cut -f 1 -d '.'`
EXT="json"

if [ $# -eq 1 ]
then
	VALUE_TEXT="$1"
elif [ $# -gt 1 ]
then
	echo "usage: ./hh.sh vacancy"
	exit 0
fi

#Query
curl -A $A_KEY "$HH_API_URL?$PARAM_PER_PAGE=$VALUE_PER_PAGE&$PARAM_PAGE=$VALUE_PAGE&$PARAM_TEXT=$VALUE_TEXT&$PARAM_SEARCH_FIELD=$VALUE_SEARCH_FIELD" \
     | python3 -c "$PYTHON_SCRIPT" > "$FILENAME.$EXT"

