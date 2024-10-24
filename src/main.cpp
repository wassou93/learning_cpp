#include <iostream>

#include "linked_list.h"

int main()
{
    DoublyLinkedList<int> list;

    // Test case 1: Append to empty list
    std::cout << "Test 1: Append to empty list\n";
    list.append( 10 );
    list.printForward();  // Expected: 10
    list.printBackward(); // Expected: 10

    // Test case 2: Append multiple elements
    std::cout << "Test 2: Append multiple elements\n";
    list.append( 20 );
    list.append( 30 );
    list.printForward();  // Expected: 10 20 30
    list.printBackward(); // Expected: 30 20 10

    // Test case 3: Prepend to empty list
    std::cout << "Test 3: Prepend to empty list\n";
    DoublyLinkedList<int> emptyList;
    emptyList.prepend( 5 );
    emptyList.printForward();  // Expected: 5
    emptyList.printBackward(); // Expected: 5

    // Test case 4: Prepend multiple elements
    std::cout << "Test 4: Prepend multiple elements\n";
    emptyList.prepend( 15 );
    emptyList.prepend( 25 );
    emptyList.printForward();  // Expected: 25 15 5
    emptyList.printBackward(); // Expected: 5 15 25

    // Test case 5: Remove head
    std::cout << "Test 5: Remove head\n";
    list.remove( 10 );
    list.printForward();  // Expected: 20 30
    list.printBackward(); // Expected: 30 20

    // Test case 6: Remove tail
    std::cout << "Test 6: Remove tail\n";
    list.remove( 30 );
    list.printForward();  // Expected: 20
    list.printBackward(); // Expected: 20

    // Test case 7: Remove middle element
    list.append( 30 );
    list.append( 40 );
    std::cout << "Test 7: Remove middle element\n";
    list.remove( 30 );
    list.printForward();  // Expected: 20 40
    list.printBackward(); // Expected: 40 20

    // Test case 8: Remove last remaining element
    std::cout << "Test 8: Remove last remaining elements\n";
    list.remove( 20 );
    list.remove( 40 );
    std::cout << "Print forward: ";
    list.printForward(); // Expected: (empty)
    std::cout << "Print backwardd: ";
    list.printBackward(); // Expected: (empty)

    // Test case 9: Handle removing from an empty list
    std::cout << "Test 9: Handle removing from an empty list\n";
    try
    {
        list.remove( 10 ); // Should throw an exception
    }
    catch ( const std::runtime_error &e )
    {
        std::cout << e.what()
                  << std::endl; // Expected: "Value doesn't exist in the list."
    }

    // Test case 10: Clear method
    std::cout << "Test 10: Clear method\n";
    list.append( 50 );
    list.append( 60 );
    list.clear();
    list.printForward(); // Expected: (empty)

    // Test case 11: Check prepend and append after clear
    std::cout << "Test 11: Prepend and append after clear\n";
    list.prepend( 70 );
    list.append( 80 );
    list.printForward(); // Expected: 70 80

    return 0;
}
