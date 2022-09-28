# evalunidad2-power-rangers

## CreateEventList: 
- Crea un puntero de tipo eventlist(elptr) y reserva memoria usando malloc.
- Declara el head y el last de la lista como NULL.
- Declara isEmpty en la lista como 0.

## CreateEvent:
- Crea un puntero tipo event(eptr) y reserva memoria usando malloc.
- Copia el nombre del buffer en el evento.
- Cambia el next del evento a NULL.
- Devuelve el evento.

## DestroyEvent:
Libera la memoria antes reservada con malloc.

## DestroyEventList:
Libera la memoria antes reservada con malloc.

## SearchEvent:
- Se declara un puntero(root) tipo event que apunta al head de la lista.
- Se verifica que la lista no está vacía.
- Mientras que root no sea NULL se comparan los nombres de la lista con el del root y se devulve el nombre del root.
- El root se mueve por la lista hasta que es igual a NULL, es decir, hasta que llega al final.

## AddEvent:
- Se declara un puntero (root) tipo event que apunta al head de la lista.
- Si el head de la lista es NULL(la lista está vacía) se declaran los datos head y last con el evento nuevo y isEmpty cambia a 1.
- Se verifica que no existan dos eventos con el mismo nombre.
- Se recorren los eventos de la lista.

## RemoveEvent:
- Se verifica que la lista no está vacía.
- Se declara un puntero(current) que apunta a un nodo después del head.
- Se declara un puntero(root) que apunta al head.
- Se compara el nombre del head(root ->eventName) con el del buffer(name).
- Si en la lista solo hay un evento el head y el last de la lista se cambian a NULL e isEmpty cambia a 0 y luego se elimina ese evento de la lista.

- Si hay dos eventos en la lista el head pasa a ser el evento que está señalando el current(segundo actualmente) y se elimina el evento al que está
apuntando el root(primero de la lista).

- Mientras que current no sea NULL (hayan mas de dos eventos en la lista) se compara el nombre del buffer con el de current.
El next del primer evento pasa a ser el del tercer evento.
Se verifica que el último evento sea, en efecto, el último y pasa a tomar los datos del root.
Se elimina el evento del current.
La funcion se desplaza entre eventos.

## ListEvents:
- Se verifica que la lista no está vacía.
- Se declara un puntero(root) que apunta al head.
- Mientras que el puntero no sea NULL(hasta que llegue al final de la lista) imprime el nombre del evento.
- El puntero avanza entre los eventos de la lista.
