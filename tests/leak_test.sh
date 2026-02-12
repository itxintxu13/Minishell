#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "======================================"
echo "    MINISHELL LEAK TESTS"
echo "======================================"

if ! command -v valgrind &> /dev/null; then
    echo -e "${RED}Valgrind no está instalado${NC}"
    exit 1
fi

MINISHELL="./minishell"

if [ ! -f "$MINISHELL" ]; then
    echo -e "${RED}Error: minishell no encontrado${NC}"
    exit 1
fi

run_leak_test() {
    local cmd="$1"
    local desc="$2"
    
    echo -e "${YELLOW}Testing:${NC} $desc"
    echo -e "$cmd\nexit" | valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --error-exitcode=1 $MINISHELL &> /tmp/valgrind_output.txt
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ No leaks${NC}\n"
    else
        echo -e "${RED}✗ LEAKS DETECTED${NC}"
        cat /tmp/valgrind_output.txt
        echo ""
    fi
}

echo "=== Testing basic commands ==="
run_leak_test "echo hola" "echo"
run_leak_test "pwd" "pwd"
run_leak_test "env" "env"

echo "=== Testing pipes ==="
run_leak_test "echo hola | cat" "simple pipe"
run_leak_test "ls | grep test | wc -l" "multiple pipes"

echo "=== Testing redirections ==="
run_leak_test "echo test > /tmp/test_leak.txt" "output redirect"
run_leak_test "cat < /tmp/test_leak.txt" "input redirect"

rm -f /tmp/test_leak.txt /tmp/valgrind_output.txt

echo "======================================"
echo "    LEAK TESTS COMPLETED"
echo "======================================"
