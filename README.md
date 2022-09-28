# evalunidad2-power-rangers

## CreateEventList: 
- Crea un puntero de tipo eventlist(elptr) y reserva memoria usando malloc.
- Declara el head y el last de la lista como NULL.
- Declara isEmpty en la lista como 0.

```
EventList *CreateEventList(void)
{
    EventList *elptr;
    elptr = (EventList *)malloc(sizeof(EventList));
    elptr ->head = NULL;
    elptr ->last = NULL;
    elptr ->isEmpty = 0;
    if(!elptr)
        perror("None memory space reserve");
    return elptr;
}
```

## CreateEvent:
- Crea un puntero tipo event(eptr) y reserva memoria usando malloc.
- Copia el nombre del buffer en el evento.
- Declara el next del evento a NULL.
- Devuelve el evento.

```
Event *CreateEvent(char *name)
{  
Event *eptr = malloc(sizeof(Event));
name[15] = 0;
strncpy(eptr->eventName,name,strlen(name) + 1);
eptr ->next = NULL;
return eptr;  
}
```

## DestroyEvent:
Libera la memoria antes reservada con malloc.

```
void DestroyEvent(Event *this)
{
    free(this);
}
```

## DestroyEventList:
Libera la memoria antes reservada con malloc.

```
void DestroyEventList(EventList *this)
{
    free(this);
}
```

## SearchEvent:
- Se verifica que la lista no está vacía.
- Se declara un puntero(root) tipo event que apunta al head de la lista.
- Mientras que root no sea NULL se comparan los nombres de la lista con el del root y se devulve el nombre del root que tenga match.
- El root se mueve por la lista hasta que es igual a NULL, es decir, hasta que llega al final.

```
Event *SearchEvent(EventList *this, char *name)
{
    if(this -> isEmpty == 1)
    {
        Event *root = this -> head;
        while (root != NULL)
        {
            //We check until we find the match
            if(strcmp(name, root ->eventName) == 0)
            return root;
            root = root ->next;
        }
    }
}
```

## AddEvent:
- Se declara un puntero (root) tipo event que apunta al head de la lista.
- Si head de la lista es NULL(la lista está vacía) se declaran los datos head y last con el evento nuevo y isEmpty cambia a 1, estamos anexando el primer dato.
- Cuando head de la lista es ! = NULL(la lista con 1 item por lo menos).
- Se verifica que no existan dos eventos con el mismo nombre y recorre los nodos comprobando.
- Una vez verifcado se le asigna al nodo que esta de ultimo la direccion del nuevo nodo event en el next y declaramos que event es last.

```
void AddEvent(EventList *this, Event *event)
{
    Event *root = this ->head;
    if(this->head == NULL)
    {
        this->head = event;
        this->last =event;
        this->isEmpty = 1;
    }
    else
    {  
        while (root != NULL)
        {
            if(strcmp(event->eventName, root->eventName) == 0)
            return;
            root = root->next;
        }
        this ->last->next = event;
        this ->last = event;
    }
}
```

## RemoveEvent:
- Se declara un puntero(current) que apunta a un nodo después del head.
- Se declara un puntero(root) que apunta al head.
- Se verifica que la lista no está vacía.


* Si en la lista el elemento que se desea eliminar es el primero:
1. Se compara el nombre del head(root ->eventName) con el del buffer(name).
2. Si la lista solo tiene un event, el root, los valores de head y last se establecen en NULL, isEmpty vuelve a 0 (lista vacía) y llamamos al destroy.
3. Por el caso contrario de que haya al menos otro nodo, cambiamos el head al nodo de la segunda posición y llamamos el destroy para el root.


* Si en la lista el elemento que se desea eliminar es diferente del primero en alguna posición n:
1. Miramos que current no sea NULL (haya un segundo evento en la lista).
2. Se compara el nombre del buffer con el de current, y recorremos la lista asignado el valor del current al root y el current next al current.
3. Si hay match el next del root event(1) pasa a ser el del current next(3) (se comprueba si el evento a eliminar es el ultimo para reasignarlo al evento anterior) y se llama el destroy para el current.

```
void RemoveEvent(EventList *this, char *name)
{
    Event *current = this ->head -> next;
    Event *root = this ->head;
    if(this -> isEmpty == 1)
    {
        
        if(strcmp(name, root ->eventName) == 0)
            {
                if(root ->next == NULL)
                {
                    this ->head = NULL;
                    this ->last = NULL;
                    this ->isEmpty = 0;
                    DestroyEvent(root);
                }
                else
                {
                    this ->head = current;
                    DestroyEvent(root);
                }
            }
        while (current != NULL)
        {
            if(strcmp(name, current ->eventName) == 0)
            {
                root->next = current->next;
                if(this ->last->next == NULL)
                {
                    this->last = root;
                    DestroyEvent(current);
                }
            }
            root = current;
            current = current ->next;
        }      
    }
}
```

## ListEvents:
- Se verifica que la lista no está vacía.
- Se declara un puntero(root) que apunta al head.
- Mientras que el puntero no sea NULL(hasta que llegue al final de la lista) imprime el nombre del evento.
- El puntero avanza entre los eventos de la lista.

```
void ListEvents(EventList *this)
{
    //We check that the list has been initialize
    if(this -> isEmpty == 1)
    {
        // ptr that has the reference of the the head node
        Event *root = this -> head;
        //print procees
        while (root != NULL)
        {
            printf("%s\n", root ->eventName);
            //root travel acroos the nodes until the NULL
            root = root ->next;
        }
    }
    else
    {
        printf("empty\n");
    }
}
```

