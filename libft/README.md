<i>Este proyecto ha sido creado como parte del currículo de 42 por rumartin.</i>

# Libft - @42Malaga <img align="right" src="https://img.shields.io/badge/Lenguaje-C-green?style=for-the-badge&logo=c" alt="Lenguaje C">

## Descripción
Proyecto consistente en programar una librería propia en lenguaje `C`. Esta librería contiene una serie de funciones generales que podrán ser utilizadas en futuros proyectos de mi paso por la escuela 42. El objetivo es comprender las funciones estándar de `libc` recreándolas desde cero y añadiendo algunas utilidades adicionales para el manejo de strings, memoria y listas enlazadas, así como escritura en descriptores de archivos.

## Instrucciones
Este proyecto utiliza un archivo Makefile para automatizar el proceso de compilación de la librería `libft.a`. Es necesario tener instalado un compilador de lenguaje `C` y la herramienta `make` para poder usarlo.

### Compilación

#### - Comandos:
```c
make all
```
Compila la librería y genera el archivo `libft.a` y una carpeta `obj/` con los archivos objeto para mantener la carpeta raiz lo más limpia posible.

```c
make clean
```
Elimina la carpeta `obj/` que contiene los archivos `.o` generados durante la compilación.

```c
make fclean
```
Elimina tanto la carpeta `obj/` como el archivo de la librería compilada `libft.a`.

```c
make re
```
Realiza un `make fclean` para eliminar todos los archivos creados con `make all` y, posteriormente, un `make all` para reconstruir todos los archivos desde cero.

#### - Cómo usar la librería:

Para usar la librería en proyectos de `C` hay que incluir el encabezado correspondiente en el código:

```c
#include "libft.h"
```

y enlazar la librería al compilar el programa en cuestión.

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o nombre_del_programa
```

## Recursos

###  Fuentes de información
Para el desarrollo y comprensión de las funciones de esta librería, se han utilizado las siguientes fuentes:

* **Subject del proyecto:** Ha sido la guía para realizar el proyecto en su totalidad.
* **Manuales del sistema (`man` pages):** Han sido la fuente principal y definitiva para comprender el comportamiento exacto, los valores de retorno y los casos extremos de cada función estándar de C (ej. `man 3 isalpha`).
* **Peer-learning:** Discusiones y resolución de dudas conjuntas con los demás compañeros de @42Malaga, que constituyen el pilar fundamental del aprendizaje en la escuela.
* **Testers de la comunidad:** Para garantizar la robustez del código y evitar crasheos inesperados, se han empleado herramientas para el testeo de esta librería por programadores de la comunidad, en concreto [Francinette](https://github.com/xicodomingues/francinette) y [libftTester](https://github.com/Tripouille/libftTester).


###  Uso de Inteligencia Artificial
De acuerdo con la pedagogía de 42, el uso de modelos de inteligencia artificial se ha limitado estrictamente a funciones de **tutoría y asistencia al estudio**, nunca como generadores de código. Específicamente, la IA se ha utilizado para:

* Aclarar la terminología técnica o descripciones ambiguas presentes en los manuales oficiales de `UNIX`.
* Realizar comprobaciones técnicas una vez elaborado el código, solicitando explícitamente la detección de errores sin sugerencias de corrección alguna.
* Asistir en la estructura, corrección orto-tipográfica y formato Markdown de este archivo `README.md`.

**Nota:** Ningún fragmento del código fuente de la `libft` ha sido generado y copiado desde una IA.

## Funciones incluidas

### Sumario

|        Funciones  de `<ctype.h>`       |                              Breve descripción                                     |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_isalpha.c`](#ft_isalpha)          | Comprueba si el carácter es alfabético                                             |
| [`ft_isdigit.c`](#ft_isdigit)          | Comprueba si el carácter es un dígito                                              |
| [`ft_isalnum.c`](#ft_isalnum)          | Comprueba si el carácter es alfanumérico                                           |
| [`ft_isascii.c`](#ft_isascii)          | Comprueba si el carácter pertenece al set `ASCII`                                  |
| [`ft_isprint.c`](#ft_isprint)          | Comprueba si el carácter es imprimible                                             |
| ______________________________________ | __________________________________________________________________________________ |

|       Funciones  de `<string.h>`       |                          Breve descripción                                         |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_strlen.c`](#ft_strlen)            | Calcula la longitud de una cadena de caracteres                                    |
| [`ft_memset.c`](#ft_memset)            | Llena la memoria con un byte constante                                             |
| [`ft_bzero.c`](#ft_bzero)              | Pone a cero una cadena de bytes                                                    |
| [`ft_memcpy.c`](#ft_memcpy)            | Copia un área de memoria                                                           |
| [`ft_memmove.c`](#ft_memmove)          | Copia un área de memoria evitando solapamientos                                    |
| [`ft_strlcpy.c`](#ft_strlcpy)          | Copia una cadena a un tamaño específico                                            |
| [`ft_strlcat.c`](#ft_strlcat)          | Concatena una cadena a un tamaño específico                                        |
| [`ft_toupper.c`](#ft_toupper)          | Convierte un carácter a mayúscula                                                  |
| [`ft_tolower.c`](#ft_tolower)          | Convierte un carácter a minúscula                                                  |
| [`ft_strchr.c`](#ft_strchr)            | Localiza la primera coincidencia de un carácter en una cadena                      |
| [`ft_strrchr.c`](#ft_strrchr)          | Localiza la última coincidencia de un carácter en una cadena                       |
| [`ft_strncmp.c`](#ft_strncmp)          | Compara dos cadenas hasta N caracteres                                             |
| [`ft_memchr.c`](#ft_memchr)            | Localiza un byte en un bloque de memoria                                           |
| [`ft_memcmp.c`](#ft_memcmp)            | Compara dos bloques de memoria                                                     |
| [`ft_strnstr.c`](#ft_strnstr)          | Localiza una subcadena en una cadena                                               |
| [`ft_atoi.c`](#ft_atoi)                | Convierte una cadena de caracteres en entero                                       |
| ______________________________________ | __________________________________________________________________________________ |

|       Funciones de `<stdlib.h>`        |                          Breve descripción                                         |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_calloc.c`](#ft_calloc)            | Reserva memoria y la inicializa a cero                                             |
| [`ft_strdup.c`](#ft_strdup)            | Duplica una cadena asignando memoria dinámica                                      |
| ______________________________________ | __________________________________________________________________________________ |

|     Funciones de manejo de cadenas     |                          Breve descripción                                         |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_substr.c`](#ft_substr)            | Crea una subcadena a partir de una cadena principal                                |
| [`ft_strjoin.c`](#ft_strjoin)          | Concatena dos cadenas en una nueva cadena                                          |
| [`ft_strtrim.c`](#ft_strtrim)          | Elimina caracteres específicos al principio y al final de una cadena               |
| [`ft_split.c`](#ft_split)              | Divide una cadena en un array de cadenas usando un delimitador                     |
| [`ft_itoa.c`](#ft_itoa)                | Convierte un entero en una cadena de caracteres                                    |
| [`ft_strmapi.c`](#ft_strmapi)          | Aplica una función a cada carácter de una cadena creando una nueva                 |
| [`ft_striteri.c`](#ft_striteri)        | Aplica una función a cada carácter de una cadena                                   |
| ______________________________________ | __________________________________________________________________________________ |

|  Funciones de descriptores de archivos |                                 Breve descripción                                  |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_putchar_fd.c`](#ft_putchar_fd)    | Escribe un carácter en un descriptor de archivo                                    |
| [`ft_putstr_fd.c`](#ft_putstr_fd)      | Escribe una cadena en un descriptor de archivo                                     |
| [`ft_putendl_fd.c`](#ft_putendl_fd)    | Escribe una cadena seguida de un salto de línea en un descriptor de archivo        |
| [`ft_putnbr_fd.c`](#ft_putnbr_fd)      | Escribe un número en un descriptor de archivo                                      |
| ______________________________________ | _______________________________________________________________________________ |

|     Funciones de listas enlazadas      |                          Breve descripción                                         |
|:---------------------------------------|:-----------------------------------------------------------------------------------|
| [`ft_lstnew.c`](#ft_lstnew)            | Crea un nuevo nodo en una lista                                                    |
| [`ft_lstadd_front.c`](#ft_lstadd_front)| Añade un nodo al principio de una lista                                            |
| [`ft_lstsize.c`](#ft_lstsize)          | Cuenta el número de nodos de una lista                                             |
| [`ft_lstlast.c`](#ft_lstlast)          | Devuelve el último nodo de una lista                                               |
| [`ft_lstadd_back.c`](#ft_lstadd_back)  | Añade un nodo al final de una lista                                                |
| [`ft_lstdelone.c`](#ft_lstdelone)      | Elimina un nodo liberando la memoria del contenido                                 |
| [`ft_lstclear.c`](#ft_lstclear)        | Elimina y libera todos los nodos de una lista                                      |
| [`ft_lstiter.c`](#ft_lstiter)          | Recorre una lista y aplica una función al contenido de cada nodo                   |
| [`ft_lstmap.c`](#ft_lstmap)            | Recorre una lista y crea una nueva lista aplicando una función a cada nodo         |
| ______________________________________ | __________________________________________________________________________________ |

### Funciones de `<ctype.h>`

#### ft_isalpha

```c
int ft_isalpha(int c)
```
Recibe una variable de tipo `int` y devuelve `1` en caso de que corresponda a un caracter alfabético. En caso contrario, devuelve `0`.

---
#### ft_isdigit

```c
int ft_isdigit(int c)
```
Recibe una variable de tipo `int` y devuelve `1` en caso de que corresponda a un dígito. En caso contrario, devuelve `0`.

---
#### ft_isalnum

```c
int ft_isalnum(int c)
```
Recibe una variable de tipo `int` y devuelve `1` en caso de que corresponda a un caracter alfanumérico. En caso contrario, devuelve `0`.

---
#### ft_isascii

```c
int	ft_isascii(int c)
```
Recibe una variable de tipo `int` y devuelve `1` en caso de que corresponda a un caracter perteneciente al set `ASCII`. En caso contrario, devuelve `0`.

---
#### ft_isprint

```c
int	ft_isprint(int c)
```
Recibe una variable de tipo `int` y devuelve `1` en caso de que corresponda a un caracter imprimible. En caso contrario, devuelve `0`.

---
### Funciones de `<string.h>`

#### ft_strlen

```c
size_t ft_strlen(const char *str)
```
Recibe una variable de tipo `const char *` y devuelve la longitud de la cadena de caracteres que recibió sin contar el `nulo`.

---
#### ft_memset

```c
void *ft_memset(void *str, int c, size_t n)
```
Recibe un `puntero` a una zona de memoria, una variable `c` y un número de bytes. Llena los primeros `n` bytes del área de memoria con el valor de `c`. Devuelve el `puntero` original.

---
#### ft_bzero

```c
void ft_bzero(void *s, size_t n)
```
Recibe un `puntero` a una zona de memoria y un numero de bytes. Llena los primeros `n` bytes del área de memoria con el valor `0`.

---
#### ft_memcpy

```c
void *ft_memcpy(void *dest, const void *src, size_t n)
```
Recibe un `puntero` destino, un `puntero` origen y un número `n` de bytes. Copia `n` bytes de origen a destino. Devuelve el `puntero` destino. No evita solapamientos.

---
#### ft_memmove

```c
void *ft_memmove(void *dest, const void *src, size_t n)
```
Recibe un `puntero` destino, un `puntero` origen y un número `n` de bytes. Copia `n` bytes de origen a destino evitando solapamientos. Devuelve el `puntero` destino.

---
#### ft_strlcpy

```c
size_t ft_strlcpy(char *dest, const char *src, size_t dest_size)
```
Recibe un `puntero` destino, un `puntero` origen y el tamaño total del buffer de destino. Copia la cadena de origen a destino asegurando que termine en `nulo`. Devuelve la longitud de la cadena que intentó crear.

---
#### ft_strlcat

```c
size_t ft_strlcat(char *dest, const char *src, size_t size)
```
Recibe un `puntero` destino, un `puntero` origen y el tamaño total del buffer de destino. Concatena la cadena origen al final de la de destino asegurando que termine en `nulo`. Devuelve la longitud total de la cadena que intentó crear.

---
#### ft_toupper

```c
int ft_toupper(int c)
```
Recibe una variable tipo `int` y, si corresponde a una letra minúscula, la devuelve convertida a `mayúscula`.

---
#### ft_tolower

```c
int ft_tolower(int c)
```
Recibe una variable tipo `int` y, si corresponde a una letra mayúscula, la devuelve convertida a `minúscula`.

---
#### ft_strchr

```c
char *ft_strchr(const char *str, int c)
```
Recibe un `puntero` a una cadena y una variable `c`. Busca la primera aparición de `c` en la cadena y devuelve un `puntero` a esa posición. Si no lo encuentra, devuelve `NULL`.

---
#### ft_strrchr

```c
char *ft_strrchr(const char *str, int c)
```
Recibe un `puntero` a una cadena y una variable `c`. Busca la última aparición de `c` en la cadena y devuelve un `puntero` a esa posición. Si no lo encuentra, devuelve `NULL`.

---
#### ft_strncmp

```c
int ft_strncmp(const char *s1, const char *s2, size_t n)
```
Recibe dos `punteros` a dos cadenas y un número `n` de bytes. Compara los primeros `n` caracteres de ambas cadenas y devuelve la `diferencia` entre los dos primeros caracteres que no coincidan. Si no encuentra ninguna diferencia, devuelve `0`.

---
#### ft_memchr

```c
void *ft_memchr(const void *src, int c, size_t n)
```
Recibe un `puntero` a una zona de memoria, una variable `c` y un número `n` de bytes. Busca la primera aparición del carácter `c` dentro de los primeros `n` bytes en dicha zona de memoria y, si se encuentra, devuelve un puntero a esa posición. En caso contrario, devuelve `NULL`.

---
#### ft_memcmp

```c
int ft_memcmp(const void *s1, const void *s2, size_t n)
```
Recibe dos `punteros` a dos zonas de memoria y un número `n` de bytes. Compara los primeros `n` bytes de ambas zonas de memoria y devuelve la `diferencia` entre los dos primeros bytes que no coincidan. Si no encuentra ninguna diferencia, devuelve `0`.

---
#### ft_strnstr

```c
char *ft_strnstr(const char *str, const char *to_find, size_t n)
```
Recibe un `puntero` a una cadena principal, un `puntero` a una subcadena y un número `n` de caracteres. Busca la primera aparición de la subcadena dentro de los primeros `n` caracteres de la cadena principal y devuelve un puntero al inicio de la subcadena encontrada o `NULL` si no hay coincidencia. Si la subcadena está vacía, devuelve un `puntero` a la cadena principal. 

---
#### ft_atoi

```c
int ft_atoi(const char *str)
```
Recibe un `puntero` a una cadena de caracteres y devuelve su valor entero. Ignora los espacios en blanco iniciales, gestiona un posible signo positivo o negativo y detiene la conversión al encontrar el primer carácter no numérico.

---
### Funciones de `<stdlib.h>`

---
#### ft_calloc

```c
void *ft_calloc(size_t count, size_t size)
```
Recibe el número de elementos a reservar y el tamaño en bytes de cada uno de ellos y reserva memoria dinámica utilizando `malloc`. Inicializa todos los bytes de dicho espacio de memoria a `\0` y devuelve un `puntero` al inicio del espacio de memoria reservado. Si la reserva falla, devuelve `NULL`.

---
#### ft_strdup

```c
char *ft_strdup(const char *str)
```
Recibe un `puntero` a una cadena y reserva memoria dinamica suficiente para una copia de la misma mediante `malloc`. Devuelve un `puntero` a esa nueva cadena. Si el proceso de reserva de memoria dinámica falla, devuelve `NULL`.

---

### Funciones de manejo de cadenas
---

#### ft_substr

```c
char *ft_substr(char const *s, unsigned int start, size_t len)
```
Recibe un `puntero` a una cadena, un índice de inicio `start` y una longitud `len`. Reserva memoria dinámica con `malloc` y devuelve una nueva cadena que es una subcadena de la inicial, empezando en `start` y con un tamaño máximo de `len`. Si la reserva falla, devuelve `NULL`.

---
#### ft_strjoin

```c
char *ft_strjoin(char const *s1, char const *s2)
```
Recibe dos `punteros` a dos cadenas y reserva memoria dinámica con `malloc` para crear una nueva cadena resultante de la concatenación de ambas. Devuelve un `puntero` a la nueva cadena o `NULL` si falla la reserva de memoria.

---
#### ft_strtrim

```c
char *ft_strtrim(char const *s1, char const *set)
```
Recibe un `puntero` a una cadena y un conjunto de caracteres de referencia y reserva memoria dinámica con `malloc` para almacenar una copia de la cadena con los caracteres especificados en `set` eliminados al principio y al final. Devuelve dicha cadena resultante o `NULL` si falla la reserva de memoria.

---
#### ft_split

```c
char **ft_split(char const *s, char c)
```
Recibe un `puntero` a una cadena y un carácter delimitador `c`. Reserva un array de cadenas de caracteres con `malloc` tras fragmentar la cadena original usando el carácter `c` como separador. El array termina con un puntero `NULL`. Devuelve el array resultante o `NULL` si alguna de las reservas de memoria falla.

---
#### ft_itoa

```c
char *ft_itoa(int n)
```
Recibe una variable `int n` y reserva memoria de manera dinámica con `malloc` para almacenar una cadena de caracteres que representa dicho valor. Devuelve un `puntero` a la cadena creada o `NULL` si falla la reserva de memoria.

---
#### ft_strmapi

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
```
Recibe un `puntero` a una cadena y una función `f`. Aplica la función `f` a cada carácter de la cadena y almacena el resultado en una nueva cadena creada reservando memoria dinamica con `malloc`. Devuelve un `puntero` a la cadena creada o `NULL` si falla la reserva de memoria.

---
#### ft_striteri

```c
void ft_striteri(char *s, void (*f)(unsigned int, char*))
```
Recibe un `puntero` a una cadena y una función `f`. Aplica la función `f` a cada carácter de la cadena, almacenando el resultado en la cadena original gracias a que `f` recibe como argumento el puntero de cada carácter de la cadena.

---

### Funciones de descriptores de archivos
---

#### ft_putchar_fd

```c
void ft_putchar_fd(char c, int fd)
```
Recibe un carácter `c` y un descriptor de archivo `fd`. Escribe el carácter `c` en el descriptor de archivo especificado.

---
#### ft_putstr_fd

```c
void ft_putstr_fd(char *s, int fd)
```
Recibe un `puntero` a una cadena y un descriptor de archivo `fd`. Escribe la cadena en el descriptor de archivo especificado.

---
#### ft_putendl_fd

```c
void ft_putendl_fd(char *s, int fd)
```
Recibe un `puntero` a una cadena y un descriptor de archivo `fd`. Escribe la cadena en el descriptor de archivo especificado seguida de un salto de línea `\n`.

---
#### ft_putnbr_fd

```c
void ft_putnbr_fd(int n, int fd)
```
Recibe un `int n` y un descriptor de archivo `fd`. Escribe el número `n` en el descriptor de archivo especificado.

---

### Funciones de listas enlazadas
---

#### Prototipo de la lista enlazada

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

---
#### ft_lstnew

```c
t_list *ft_lstnew(void *content)
```
Recibe el contenido para un nuevo `nodo` y reserva memoria de manera dinámica con `malloc` para él. Inicializa la variable `content` con el valor pasado por parámetro y el `puntero` `next` con `NULL`. Devuelve un `puntero` al nuevo `nodo` creado.

---
#### ft_lstadd_front

```c
void ft_lstadd_front(t_list **lst, t_list *new)
```
Recibe un `puntero` a una `lista` y un `puntero` al `nodo` que se desea añadir. Añade el `nodo` `new` al `principio` de la `lista`.

---
#### ft_lstsize

```c
int ft_lstsize(t_list *lst)
```
Recibe un `puntero` al primer `nodo` de una `lista` y cuenta el número de `nodos` que la componen. Devuelve el tamaño total de la `lista`.

---
#### ft_lstlast

```c
t_list *ft_lstlast(t_list *lst)
```
Recibe un `puntero` al primer `nodo` de una `lista` y la recorre hasta llegar al final. Devuelve un `puntero` al último `nodo` de la `lista`.

---
#### ft_lstadd_back

```c
void ft_lstadd_back(t_list **lst, t_list *new)
```
Recibe un `puntero` a una lista y un `puntero` al `nodo` que se desea añadir. Añade el `nodo` `new` al `final` de la `lista`.

---
#### ft_lstdelone

```c
void ft_lstdelone(t_list *lst, void (*del)(void*))
```
Recibe un `puntero` a un `nodo` y un `puntero` a una función de borrado `del`. Elimina el contenido y libera el `nodo` dado utilizando la función `del`.

---
#### ft_lstclear

```c
void ft_lstclear(t_list **lst, void (*del)(void*))
```
Recibe un `puntero` a una `lista` y un `puntero` a una función de borrado `del`. Elimina el contenido y libera el primer `nodo` de la `lista` y todos los siguientes utilizando la función `del` y `free`. Al finalizar, el `puntero` a la `lista` es `NULL`.

---
#### ft_lstiter

```c
void ft_lstiter(t_list *lst, void (*f)(void *))
```
Recibe un `puntero` al primer `nodo` de una `lista` y una función `f`. Recorre cada `nodo` de la `lista` y aplica la función `f` al contenido de cada `nodo`.

---
#### ft_lstmap

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```
Recibe un `puntero` a un `nodo` de una `lista`, una función `f` y una función `del`. Recorre cada `nodo` de la `lista` y aplica la función `f` al contenido de cada `nodo` para crear una nueva `lista` resultante. Si algo falla durante el proceso, utiliza `del` para liberar la memoria de los `nodos` creados y devuelve `NULL`.

---