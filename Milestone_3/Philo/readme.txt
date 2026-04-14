Philosophers (philo)

Descripción

Philosophers es un proyecto basado en el clásico problema de concurrencia conocido como Dining Philosophers. 

El objetivo es simular el comportamiento de varios filósofos sentados alrededor de una mesa, que tienen tres tareas entre las que alternan (pensar, comer y dormir), mientras comparten recursos limitados (tenedores).

Cada filósofo va necesitar dos tenedores para comer. Esto genera ciertos problemas típicos de programación concurrente como:

Deadlocks**
Race conditions
Sincronización entre hilos
Precisión en el control del tiempo

El programa está implementado en C utilizando threads y mutexes, garantizando que:

No haya condiciones de carrera
La simulación sea consistente
Los tiempos se respeten con precisión (≤ 10 ms de margen)


Funcionamiento

Cada filósofo sigue el siguiente ciclo:

1. Pensar 
2. Coger dos tenedores
3. Comer 
4. Dormir 

El programa termina cuando:

Un filósofo muere (no come a tiempo)
Todos los filósofos han comido un número mínimo de veces (si se especifica)


Uso

Compilación con ‘make’


Ejecución


./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]


Argumentos

number_of_philosophers`   => Número de filósofos (y tenedores) 
time_to_die`         => Tiempo máximo sin comer (ms) 
time_to_eat`         => Tiempo que tarda en comer (ms)
time_to_sleep      =>  Tiempo que duerme (ms
number_of_times_each_philosopher_must_eat (Opcional) => Número mínimo de comidas

