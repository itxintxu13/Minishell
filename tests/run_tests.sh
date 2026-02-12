#!/bin/bash

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

MINISHELL="./minishell"
PASSED=0
FAILED=0

# Función para comparar output
test_command() {
    local cmd="$1"
    local desc="$2"
    
    echo -e "${YELLOW}Testing:${NC} $desc"
    
    # Ejecutar en bash
    bash_output=$(echo "$cmd" | bash 2>&1)
    bash_exit=$?
    
    # Ejecutar en minishell (con timeout)
    mini_output=$(echo -e "$cmd\nexit" | timeout 2 $MINISHELL 2>&1 | grep -v "minishell" | tail -n +2)
    mini_exit=$?
    
    if [ "$bash_output" = "$mini_output" ]; then
        echo -e "${GREEN}✓ PASS${NC}\n"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC}"
        echo "Expected: $bash_output"
        echo "Got: $mini_output"
        echo ""
        ((FAILED++))
    fi
}

echo "======================================"
echo "    MINISHELL COMPREHENSIVE TESTS"
echo "======================================"
echo ""

# Verificar que existe el ejecutable
if [ ! -f "$MINISHELL" ]; then
    echo -e "${RED}Error: minishell no encontrado${NC}"
    echo "Ejecuta 'make' primero"
    exit 1
fi

echo "=== 1. BUILT-INS BÁSICOS ==="
test_command "echo hola mundo" "echo básico"
test_command "echo -n hola" "echo con -n"
test_command "echo -n -n -n hola" "echo múltiples -n"
test_command "echo" "echo vacío"
test_command "pwd" "pwd básico"
test_command "env | grep USER" "env con pipe"

echo "=== 2. VARIABLES DE ENTORNO ==="
test_command "echo \$USER" "expansión \$USER"
test_command "echo \$HOME" "expansión \$HOME"
test_command "echo \$PATH | head -c 10" "expansión \$PATH"
test_command "echo \$NONEXISTENT" "variable inexistente"

echo "=== 3. EXIT STATUS ==="
test_command "ls /tmp > /dev/null; echo \$?" "exit code success"
test_command "ls /nonexistent 2>/dev/null; echo \$?" "exit code failure"
test_command "echo \$?" "exit code sin comando previo"

echo "=== 4. COMILLAS ==="
test_command "echo 'hola mundo'" "comillas simples"
test_command "echo \"hola mundo\"" "comillas dobles"
test_command "echo '\$USER'" "comillas simples con \$"
test_command "echo \"\$USER\"" "comillas dobles con \$"
test_command "echo \"'hola'\"" "comillas mixtas"

echo "=== 5. PIPES ==="
test_command "echo hola | cat" "pipe simple"
test_command "echo hola | cat | cat" "pipe doble"
test_command "ls /tmp | grep test | wc -l" "pipe triple"

echo "=== 6. REDIRECCIONES ==="
# Crear archivo temporal para tests
echo "test content" > /tmp/minishell_test_input.txt

test_command "cat < /tmp/minishell_test_input.txt" "input redirection"
test_command "echo test > /tmp/minishell_test_out.txt && cat /tmp/minishell_test_out.txt" "output redirection"
test_command "echo line1 > /tmp/minishell_append.txt && echo line2 >> /tmp/minishell_append.txt && cat /tmp/minishell_append.txt" "append redirection"

# Limpiar archivos temporales
rm -f /tmp/minishell_test_*.txt /tmp/minishell_append.txt

echo "=== 7. CASOS EDGE ==="
test_command "echo ''" "string vacío con comillas"
test_command "echo \"\"" "string vacío con comillas dobles"
test_command "echo \"   \"" "espacios en comillas"
test_command "echo \$" "solo símbolo dólar"

echo ""
echo "======================================"
echo "        RESULTADOS"
echo "======================================"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"
echo "======================================"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}¡Todos los tests pasaron!${NC}"
    exit 0
else
    echo -e "${RED}Algunos tests fallaron${NC}"
    exit 1
fi
