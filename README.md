# Minishell - Guía de Estudio para la Evaluación

Este proyecto es una implementación de una shell básica (similar a Bash). A continuación se detallan todas las funciones organizadas por módulos para facilitar el repaso y estudio.

---

## 1. Núcleo del Proyecto (Core)

### `src/main.c`
- **`main`**: Punto de entrada. Inicializa la shell, entra en el bucle principal, lee la entrada con `readline`, añade al historial y llama a la ejecución.
- **`initialize_shell`**: Configura señales (`signal_main`), carga el entorno (`load_env`) y valida variables esenciales (`valid_env`).
- **`in_loop`**: Controla si la shell debe seguir ejecutándose.
- **`execute_console`**: El motor que coordina todo el proceso: busca pipes, hace fork, y en el hijo ejecuta la cadena de tokenización -> parseo -> expansión -> ejecución.

### `src/prompt/prompt.c`
- **`ft_prompt`**: Imprime el prompt personalizado con colores.

### `src/signal/signal.c`
- **`signal_main`**: Configura el comportamiento de `Ctrl+C` (SIGINT) y `Ctrl+\` (SIGQUIT) en el proceso principal.
- **`signal_father`**: Configura señales para el proceso padre durante la ejecución de comandos.
- **`signal_son`**: Configura señales para los procesos hijos.

---

## 2. Tokenización y Lexer

Convierte la línea de comandos (string) en una lista de palabras y operadores (tokens).

### `src/tokenizer/tokenizer.c`
- **`tokenize`**: Función principal del lexer. Limpia la entrada, maneja comillas y separa el string en un array de tokens.
- **`parse_quotes`**: Verifica que las comillas estén cerradas correctamente.
- **`compute_saves`**: Decide si guardar una palabra o un operador (meta-carácter).

### `src/tokenizer/process_input.c`
- **`read_token`**: Avanza por el string identificando el final de cada token.
- **`clear_input`**: Limpia espacios innecesarios al inicio y final.

---

## 3. Parsing y Análisis Sintáctico

Verifica que el orden de los tokens sea válido (ej: que no haya un pipe al final o dos pipes seguidos).

### `src/parse/parse.c`
- **`parse`**: Valida la sintaxis de los tokens.
- **`shear_error`**: Comprueba errores comunes como `| |` o redirecciones sin archivo.
- **`case_split`**: Identifica separadores lógicos.

---

## 4. Expansiones y Manejo de Comillas

Maneja variables de entorno (`$VAR`), el estado de salida (`$?`) y la eliminación de comillas.

### `src/expansions/expansions.c`
- **`expand`**: Recorre los tokens y expande variables de entorno y comodines.
- **`expand_token`**: Procesa un token individual para buscar el símbolo `$`.

### `src/expansions/quotes_utils.c`
- **`remove_quotes`**: Elimina las comillas de un token después de haber sido procesado.

### `src/expansions/hdoc_utils.c`
- Funciones para manejar la expansión de variables dentro de un *here-doc*.

---

## 5. Ejecución y Pipelines

### `src/execute/simple_command.c`
- **`execute_simple_command`**: Ejecuta un comando único. Maneja redirecciones, busca si es un *builtin* o un binario externo.
- **`execute_builtin`**: Redirige la ejecución a la función correspondiente si el comando es interno (echo, cd, etc.).
- **`execute_binary`**: Usa `execve` para ejecutar programas externos (ls, grep, etc.).

### `src/pipe/pipe.c`
- **`compute_pipeline`**: Gestiona la creación de múltiples procesos cuando hay pipes (`|`). Crea los pipes, hace forks y conecta las entradas/salidas de los hijos.
- **`redirect_out`**: Conecta los descriptores de archivo entre los procesos del pipeline.

---

## 6. Redirecciones

Maneja `>`, `>>`, `<` y `<<`.

### `src/redirections/redirections.c`
- **`redirection`**: Procesa todos los operadores de redirección en un comando.
- **`redir_input` / `redir_output`**: Abre los archivos correspondientes y usa `dup2` para cambiar `stdin` o `stdout`.
- **`redir_heredoc`**: Implementa el *here-doc* leyendo del terminal hasta encontrar el delimitador.

---

## 7. Comandos Internos (Built-ins)

- **`ft_echo`**: Imprime texto, maneja la opción `-n`.
- **`ft_cd`**: Cambia el directorio actual usando `chdir`.
- **`ft_pwd`**: Imprime la ruta del directorio actual.
- **`ft_export`**: Añade o actualiza variables de entorno.
- **`ft_unset`**: Elimina variables de entorno.
- **`ft_env`**: Muestra todas las variables de entorno.
- **`ft_exit`**: Sale de la shell con un estado específico.

---

## 8. Utilidades y Entorno

### `src/utils/env_utils.c`
- **`ft_getenv`**: Busca el valor de una variable en nuestro sistema de almacenamiento de entorno.
- **`load_env`**: Copia el entorno original de la shell a un archivo temporal/estructura interna para poder modificarlo.

### `src/utils/error.c`
- **`error_handle`**: Centraliza la impresión de mensajes de error y la gestión del estado de salida.

### `src/utils/ft_split_custom.c`
- Versión modificada de `split` que respeta las comillas al separar strings.

### `src/utils/` (Funciones de Apoyo)
- **Funciones de String**: Implementaciones propias de `strlen`, `strdup`, `strjoin`, `atoi`, `itoa`, etc. (repartidas en `ft_strings_X.c`, `ft_atoi.c`, `ft_itoa.c`).
- **`utils_matriz.c`**: Funciones para manejar arrays de strings (char **), como `free_all` (liberar una matriz completa) o `len_all` (contar elementos).
- **`ft_split_custom.c`**: Un `split` especial que no corta el string si el delimitador está dentro de comillas.
- **`valid_env.c`**: Asegura que variables críticas como `PATH` o `PWD` existan al arrancar, incluso si se inicia la shell sin entorno (`env -i ./minishell`).

---

## Consejos para la Evaluación:
1. **Pipes**: Recuerda que cada comando en un pipe se ejecuta en un proceso hijo diferente.
2. **Built-ins**: Algunos built-ins deben ejecutarse en el proceso padre si no hay pipes (como `cd` o `export`), porque si no, sus cambios se perderían al morir el hijo.
3. **Estado de salida**: El comando `echo $?` debe mostrar el código de error del último comando ejecutado.
4. **Señales**: `Ctrl+C` en una línea vacía debe mostrar un nuevo prompt, pero dentro de un comando debe matarlo.
