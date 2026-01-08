#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

TOTAL=0
PASSED=0
FAILED=0

BINARY="./RPN"

# check if binary exists
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Error: Binary '$BINARY' not found!${NC}"
    echo "Please compile the project first with 'make'"
    exit 1
fi

# check if test file is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <test_file>"
    echo ""
    echo "Test file format:"
    echo "input|expected_output"
    echo ""
    echo "Example:"
    echo "8 9 * 9 - 9 - 9 - 4 - 1 +|42"
    echo "5 0 /|Error"
    exit 1
fi

TEST_FILE=$1

# check if test file exists
if [ ! -f "$TEST_FILE" ]; then
    echo -e "${RED}Error: Test file '$TEST_FILE' not found!${NC}"
    exit 1
fi

echo "========================================="
echo "       RPN Calculator Test Suite"
echo "========================================="
echo ""

# read test file line by line
while IFS='|' read -r input expected || [ -n "$input" ]; do
    # skip empty lines and comments
    [[ -z "$input" || "$input" =~ ^#.*$ ]] && continue
    
    TOTAL=$((TOTAL + 1))
    
    # run the program and capture output
    if [ -z "$input" ]; then
        # handle empty input case
        output=$($BINARY 2>&1)
    else
        output=$($BINARY "$input" 2>&1)
    fi
    
    # trim whitespace from output
    output=$(echo "$output" | tr -d '\n' | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    expected=$(echo "$expected" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    
    # compare output with expected
    if [ "$output" = "$expected" ]; then
        echo -e "${GREEN}✓ Test $TOTAL PASSED${NC}"
        echo "  Input:    \"$input\""
        echo "  Expected: $expected"
        echo "  Got:      $output"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ Test $TOTAL FAILED${NC}"
        echo "  Input:    \"$input\""
        echo "  Expected: $expected"
        echo -e "  Got:      ${RED}$output${NC}"
        FAILED=$((FAILED + 1))
    fi
    echo ""
    
done < "$TEST_FILE"

echo "========================================="
echo "              Summary"
echo "========================================="
echo -e "Total tests:  $TOTAL"
echo -e "Passed:       ${GREEN}$PASSED${NC}"
echo -e "Failed:       ${RED}$FAILED${NC}"
echo "========================================="

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed!${NC}"
    exit 1
fi