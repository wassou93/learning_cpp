#include "linked_list.h"

template <typename T>
Node<T>::Node( T value ) : data( value ), next( nullptr ), prev( nullptr )
{
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head( nullptr ), tail( nullptr )
{
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
void DoublyLinkedList<T>::append( T value )
{
    Node<T>* current = new Node<T>( value );
    if ( !this->head )
        this->head = this->tail = current;
    else
    {
        tail->next    = current;
        current->prev = tail;
        tail          = current;
    }
}
template <typename T>
void DoublyLinkedList<T>::prepend( T value )
{
    Node<T>* current = new Node<T>( value );
    if ( !this->head )
        this->head = this->tail = current;
    else
    {
        head->prev    = current;
        current->next = head;
        head          = current;
    }
}
template <typename T>
void DoublyLinkedList<T>::remove( T value )
{
    Node<T>* current = this->head;
    while ( current )
    {
        if ( current->data == value )
        {
            if ( this->head == this->tail )
            {
                this->head = this->tail = nullptr;
            }
            else if ( current == this->head )
            {
                head = head->next;
                if ( head ) head->prev = nullptr;
            }
            else if ( current == this->tail )
            {
                tail = tail->prev;
                if ( tail ) tail->next = nullptr;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error( "Value doesn't exist in the list." );
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    Node<T>* current = this->head;
    while ( current )
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    this->head = this->tail = nullptr;
}
template <typename T>
void DoublyLinkedList<T>::printForward() const
{
    Node<T>* current = head;
    while ( current )
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
template <typename T>
void DoublyLinkedList<T>::printBackward() const
{
    Node<T>* current = tail;
    while ( current )
    {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}