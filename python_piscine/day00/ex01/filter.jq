# ["id", "created_at", "name", "has_test", "alternate_url"], (.items[] | [.id, .created_at, .name, .has_test, .alternate_url]) | @csv
.items | map({id: .id, created_at: .created_at, name: .name, has_test: .has_test, alternate_url: .alternate_url}) | (.[0] | to_entries | map(.key)), (.[] | [.[]]) | @csv
