```cpp
void Imprime(double valor){
   double valor;
   cout << valor;
}
```

Se está declarando una variable valor dentro de Imprime, con lo que a la hora de llamar a cout, no
se está utilizando el valor del argumento.

```cpp
void Cuadrado (int entero){
   return entero*entero;
}
```

El tipo de dato de la función es void, sin embargo se está devolviendo el valor de una expresión int\*int que es int.
Por lo tanto la función debería tener el return type como int y no void.

```cpp
int Cuadrado (int entero){
   entero = entero*entero;
}
```

No se está devolviendo ningún dato cuando la función ha de devolver int, y se está asignando a la variable del argumento
que se está pasando por valor y no por referencia, por lo que no tiene ningún efecto.
