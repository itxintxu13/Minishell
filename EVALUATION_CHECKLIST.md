# Checklist de Evaluación Minishell

## ✅ Pre-evaluación

### Compilación
- [ ] `make` compila sin warnings
- [ ] `make re` funciona correctamente
- [ ] `make clean` elimina .o
- [ ] `make fclean` elimina ejecutable
- [ ] No hay errores de norminette

### Leaks
- [ ] Probado con valgrind: `valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./minishell`
- [ ] No hay leaks en comandos básicos
- [ ] No hay leaks en pipes
- [ ] No hay leaks en redirecciones
- [ ] File descriptors cerrados correctamente

## 📋 Funcionalidades Obligatorias

### Built-ins
- [ ] `echo` con y sin opción `-n`
- [ ] `cd` solo con path relativo o absoluto
- [ ] `pwd` sin opciones
- [ ] `export` sin opciones
- [ ] `unset` sin opciones
- [ ] `env` sin opciones
- [ ] `exit` sin opciones

### Expansiones
- [ ] Variables de entorno: `$USER`, `$HOME`, etc.
- [ ] Exit status: `$?`
- [ ] Variables inexistentes se expanden a vacío

### Comillas
- [ ] Comillas simples `'`: No expande nada
- [ ] Comillas dobles `"`: Expande variables
- [ ] Comillas sin cerrar: Error

### Redirecciones
- [ ] `<` input redirection
- [ ] `>` output redirection (truncate)
- [ ] `>>` append
- [ ] `<<` heredoc (con delimitador)

### Pipes
- [ ] Pipe simple: `cmd1 | cmd2`
- [ ] Múltiples pipes: `cmd1 | cmd2 | cmd3`

### Señales
- [ ] `Ctrl+C` en prompt: Nueva línea
- [ ] `Ctrl+C` en comando: Mata el comando
- [ ] `Ctrl+D` en prompt vacío: Sale
- [ ] `Ctrl+\` en prompt: No hace nada

## 🎯 Casos de Prueba Importantes

### Echo
```bash
echo hola mundo
echo -n hola
echo -n -n -n hola
echo ""
echo ''
echo "$USER"
echo '$USER'
```

### CD
```bash
cd /tmp
pwd
cd ..
pwd
cd
pwd
cd -  # Si está implementado
```

### Export/Unset
```bash
export TEST=hello
echo $TEST
unset TEST
echo $TEST
```

### Pipes
```bash
ls | grep minishell
cat file | grep pattern | wc -l
echo hola | cat | cat | cat
```

### Redirecciones
```bash
echo test > file
cat < file
echo line1 > file
echo line2 >> file
cat << EOF
hola
mundo
EOF
```

### Exit Status
```bash
ls
echo $?
ls /nonexistent 2>/dev/null
echo $?
```

### Casos Edge
```bash
# Espacios extras
echo     hola     mundo
# Pipe al inicio (debe dar error)
| cat
# Pipe al final (debe dar error)
cat |
# Redirección sin archivo (debe dar error)
cat <
# Múltiples redirecciones
< file1 cat > file2
```

## 🐛 Problemas Comunes

- [ ] Built-ins en pipes deben ejecutarse en hijo
- [ ] Built-ins sin pipes deben ejecutarse en padre (cd, export, etc.)
- [ ] Verificar que PATH funciona correctamente
- [ ] Comprobar comportamiento con `env -i ./minishell`
- [ ] Exit codes correctos
- [ ] Manejo de SIGINT y SIGQUIT
- [ ] Prompt muestra después de Ctrl+C

## 📊 Bonus (si aplica)

- [ ] Operadores lógicos `&&` y `||`
- [ ] Wildcards `*`
- [ ] Paréntesis para prioridad
- [ ] Variables locales

## 🎓 Consejos

1. Compara siempre con bash: `bash -c "comando"`
2. Prueba con comandos que no existen
3. Prueba con permisos denegados
4. Prueba con archivos que no existen
5. Prueba combinaciones de pipes y redirecciones
