#!/bin/bash

OUTPUT="generated.h"

echo "#ifndef GENERATED_H" > "$OUTPUT"
echo "#define GENERATED_H" >> "$OUTPUT"
echo >> "$OUTPUT"

# Find function definitions and convert to prototypes
grep -Ehr '^[a-zA-Z_][a-zA-Z0-9_*\t ]+\([a-zA-Z0-9_*,\t ]*\)[ \t]*\{' \
    --include="*.c" . \
| sed 's/{/;/' \
| sed 's/^[ \t]*//' \
| while read -r line; do
    # Ignore static functions
    if [[ "$line" != static* ]]; then
        echo "$line" >> "$OUTPUT"
    fi
done

echo >> "$OUTPUT"
echo "#endif" >> "$OUTPUT"

echo "Header generated at $OUTPUT"
