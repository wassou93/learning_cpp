#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T> class Node
{
  public:
    T data;
    Node *next;
    Node *prev;

    Node( T value );
};

template <typename T> class DoublyLinkedList
{
  private:
    Node<T> *head;
    Node<T> *tail;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void append( T value );
    void prepend( T value );
    void remove( T value );
    void clear();
    void printForward() const;
    void printBackward() const;
};

#endif // LINKED_LIST_H