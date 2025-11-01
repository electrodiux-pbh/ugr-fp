Elegiría la segunda opción, ya que imprimir cuadrado e imprimir pirámide son acciones
independientes y que no han de mezclarse. Al tener el código más modularizado es más
fácil de trabajar ya que son funciones más especializadas y con menos código, y permite añadir
más figuras de forma sencilla, y que cada una tenga propiedades únicas si fuera necesaio en un futuro.

Mencionar también que pasar un bool para indicar si es pirámide o no, no es buena opción ya que es confuso,
no se especifica que hace al pasarle un false "no pirámide" y un enum class tampoco ayudaría.

Una posibilidad es cada figura en su respectiva función y otra que reciba el tipo con un enum type y esa función
llame a las otras de forma correspondiente. Pero en lineas generales es mejor usar una función para cada cosa.

```cpp
void ImprimeCuadrado(int inicio, int num_filas);
void ImprimePiramide(int inicio, int num_filas);
```
