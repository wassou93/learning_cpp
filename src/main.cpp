#include <iostream>

// Assume wl_list is defined like this
struct wl_list
{
    struct wl_list* prev; // Pointer to the previous element in the list
    struct wl_list* next; // Pointer to the next element in the list
};

// Definition of wl_listener
struct wl_listener
{
    struct wl_list link; // This links the listener in a wl_list
    void ( *notify )( struct wl_listener* listener, void* data ); // Callback function
};

// Definition of the event source
struct event_source
{
    struct wl_list listeners; // List of listeners
};

// Function to initialize the wl_list
void wl_list_init( struct wl_list* list )
{
    list->prev = list; // Point to itself (circular)
    list->next = list; // Point to itself (circular)
}

// Function to insert a new element into the list
void wl_list_insert( struct wl_list* list, struct wl_list* new_elem )
{
    new_elem->next   = list->next; // Link new element to the next element in the list
    new_elem->prev   = list; // Link new element back to the list
    list->next->prev = new_elem; // Adjust the next element's previous pointer
    list->next       = new_elem; // Update the list's next pointer to new element
}

// Function to initialize the event source
void event_source_init( struct event_source* source )
{
    wl_list_init( &source->listeners ); // Initialize the listeners list
}

// Listener callback function
void my_event_handler( struct wl_listener* listener, void* data )
{
    printf( "Event triggered! Data: %s\n", (char*)data );
}

// Function to add a listener
void add_listener( struct event_source* source, struct wl_listener* listener )
{
    listener->notify = my_event_handler; // Set the callback
    wl_list_insert( &source->listeners, &listener->link ); // Insert the listener's link into the list
}

// Function to trigger the event
void trigger_event( struct event_source* source, void* data )
{
    struct wl_listener* listener;

    // Traverse the list and call each listener's notify function
    for ( listener = (struct wl_listener*)source->listeners.next;
          listener != (struct wl_listener*)&source->listeners;
          listener = (struct wl_listener*)listener->link.next )
    {
        listener->notify( listener, data ); // Call the listener's callback
        std::cout << listener << std::endl;
    }
}

// Main function demonstrating the usage
int main()
{
    struct event_source source;
    struct wl_listener listener1, listener2;

    event_source_init( &source ); // Initialize the event source

    // Add first listener
    add_listener( &source, &listener1 );
    std::cout << &listener1 << std::endl;

    // Add second listener
    add_listener( &source, &listener2 );
    std::cout << &listener2 << std::endl;

    // Trigger the event with some data
    char event_data[] = "Hello, listeners!";
    trigger_event( &source, event_data );

    return 0;
}
