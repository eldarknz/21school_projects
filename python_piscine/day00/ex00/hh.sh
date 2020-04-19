curl -A 'api-test-agent' \
     'https://api.hh.ru/vacancies?per_page=20&page=0&text=datascientist' \
     | python3 -c 'import sys ;import json ; print(json.dumps(json.loads(sys.stdin.read()), sort_keys=False, ensure_ascii=False, indent=4, separators=(",", " : ")))' \
     > hh.json
