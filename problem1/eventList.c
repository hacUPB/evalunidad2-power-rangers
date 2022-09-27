#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    //We check that the list has been initialize
    if(this -> isEmpty == 1)
    {
        // ptr that has the reference of the the head node
        Event *root = this -> head;
        //search procees
        while (root != NULL)
        {
            //We check until we find the match
            if(strcmp(name, root ->eventName) == 0)
            //Return the event
            return root;
            //root travel acroos the nodes until the NULL
            root = root ->next;
        }
    }
    else
    {
        printf("List Empty");
    }
}

void AddEvent(EventList *this, Event *event)
{
    // ptr that has the reference of the the head node
    Event *root = this ->head;
    if(this->head == NULL)
    {
        this->head = event;
        this->last =event;
        this->isEmpty = 1;
    }
    else
    {
        this ->last->next = event;
        this ->last = event;  
        while (root != NULL)
        {
            //Name comparasion, we check that the won't exist two events with the same name
            if(strcmp(event->eventName, root->eventName) == 0)
            return;
            //root travel acroos the nodes until the NULL
            root = root->next;
        }
    }
}

void RemoveEvent(EventList *this, char *name)
{
    // ptr that has the reference of the the node after the head
    Event *current = this ->head ->next;
    // ptr that has the reference of the the head node
    Event *root = this ->head;
    //We check that the list has been initialize
    if(this -> isEmpty == 1)
    {
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
    else
    {
         printf("List Empty");
    }
}

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
        printf("List Empty");
    }
}
