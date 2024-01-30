# Práctica 4: Algoritmos de ordenamiento
# Joshua Jacuinde Soria
# 2223028913
# Resultados:
Tabla de resultados:

![tiempos de ejecucion](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-joshua-jacuinde-soria/blob/main/tiempos%20de%20ejecucion.png)

(las casillas en blanco son valores que el programa ya no permitio).

Grafica:

![grafica](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-joshua-jacuinde-soria/blob/main/grafica.png)

# Análizis


Primero, examinaremos las tablas. En ellas, podemos observar que los tres primeros métodos (inserción, selección y burbuja) son bastante rápidos, incluso más que merge y quick, que se supone tienen tiempos más bajos. Se destaca que este patrón se repite en los primeros cuatro lugares (hasta 100). Sin embargo, a partir de 500, se produce un cambio significativo, siendo merge y quick los nuevos métodos más rápidos. Completan en microsegundos, mientras que el resto lo hace en milisegundos, momento en el cual los valores varían ligeramente.


Las diferencias más notables surgen en el caso de 5,000, donde las disparidades ya son de varios segundos. A partir de ese punto, los tiempos se incrementan a decenas de segundos, mientras que merge y quick aún se ejecutan en milisegundos. Para 10,000, la disparidad se magnifica de manera considerable y, más allá de este punto, ni siquiera es posible obtener un resultado debido a la extrema lentitud del proceso.


No obstante, aún podemos comparar estos dos métodos, donde notamos que la diferencia no es tan significativa. Merge se posiciona como el segundo más rápido, con quick siendo el más eficiente en tiempo de los cinco. En contraste, bubble se ubica como el menos eficiente, ya que fue el primero en evidenciar de manera notable su diferencia en tiempos.

# Conclusión:

Podemos observar, a través de las gráficas, las tablas y la experiencia, que los tres primeros métodos son eficientes para ordenar arreglos pequeños, de hasta 100 elementos. En este contexto, demuestran ser los más efectivos. Sin embargo, para arreglos de mayor tamaño, se hace evidente la necesidad de recurrir a métodos adicionales, siendo Quick la opción más destacada para ordenar arreglos de tamaño considerable. Asimismo, se observa que el método de burbuja exhibe los peores rendimientos en todos los casos.

Es importante destacar que los tres primeros métodos son más sencillos de recordar y ejecutar, mientras que los dos últimos poseen una lógica más compleja y difícil de entender. La elección del método óptimo dependerá del uso específico y de la preferencia de la persona. No obstante, en términos de eficiencia temporal, surge una clara opción: para arreglos pequeños, el método de inserción, y para arreglos grandes, el método Quick.
