# Estructuras de Datos

> [!Note]
> Las estructuras implementadas en este repositorio han sido en lenguaje C. Por lo que debes tener cierto conocimiento en el lenguaje para poder entender como se están realizando las diferentes implementaciones. 

Las **estructuras de datos** son formas de organizar y almacenar la información en un programa de manera que sea más fácil y eficiente accederla, modificarla o recorrerla.

Son fundamentales en el desarrollo de software porque permiten resolver problemas de forma eficiente en términos de tiempo y memoria.

---

## 🔧 Clasificación de estructuras de datos

### 📌 Estructuras Estáticas
Son aquellas cuyo tamaño se define al momento de su creación y no puede modificarse en tiempo de ejecución. Son simples y eficientes, pero menos flexibles.

Ejemplos:
- **Arreglos (Arrays)**: colección fija de elementos del mismo tipo.
- **Listas, Pilas y Colas implementadas con arreglos no reajustables**: el tamaño máximo está definido desde el inicio.

Ventajas:
- Acceso rápido por índice.
- Bajo uso de memoria si el tamaño es conocido.

Desventajas:
- No permiten crecer o reducir su tamaño dinámicamente.
- Riesgo de desperdiciar memoria o desbordar si el tamaño no es suficiente.

---

### 🔁 Estructuras Dinámicas
Estas estructuras se pueden ajustar en tiempo de ejecución. Utilizan punteros o referencias para gestionar la memoria de forma flexible.

#### 🔹 Lineales
Se recorren en una secuencia desde el inicio hasta el final.

- **Listas enlazadas** (simples, dobles, circulares): cada nodo apunta al siguiente (y opcionalmente al anterior).
- **Pilas dinámicas**: última en entrar, primera en salir (LIFO).
- **Colas dinámicas**: primera en entrar, primera en salir (FIFO).
- **Colas dobles (Deque)**: permiten inserciones y eliminaciones en ambos extremos.

#### 🔹 No lineales
Los datos no siguen una secuencia estricta; tienen relaciones jerárquicas o arbitrarias.

- **Árboles**: estructuras jerárquicas, como árboles binarios, AVL, B-Trees, etc.
- **Grafos**: estructuras que representan conexiones entre nodos (dirigidos o no dirigidos).

### 🔹 Estructuras abstractas (ADT)
- **Conjuntos (Sets)**
- **Mapas o Diccionarios (HashMaps)**
- **Colas de prioridad (Heaps)**

Ventajas:
- Flexibilidad para crecer o reducir tamaño según necesidad.
- Uso eficiente de memoria para estructuras dinámicas de datos complejos.

Desventajas:
- Más complejas de implementar.
- Requieren gestión de punteros/referencias.

---

## 🧠 ¿Por qué son importantes?

Usar la estructura de datos adecuada permite:
- Reducir el tiempo de ejecución.
- Optimizar el uso de memoria.
- Facilitar la implementación de algoritmos eficientes.

---

> 📚 Aprender estructuras de datos es clave para convertirte en un mejor programador, ya que te da las herramientas para pensar y resolver problemas de manera más efectiva.

## Redes
Para ver una explicación más detallada y el proceso de implementación de cada una de estas estructuras o te interesa ver más de los proyectos que desarrollo y a que me dedico, puedes revisar mis redes sociales:

[Canal de Youtube](https://www.youtube.com/@bpp_mx)

[Página web](https://www.brayantellez.com)