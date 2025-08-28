#include "LinkedList.h"
#include <iostream>

int passCount = 0;

void testConstructor() {
    std::cout << "Test Default Constructor:\n";
    LinkedList list;
    std::string result = list.printList();
    std::string expected = "nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    std::cout << "Test Parameterized Constructor:\n";
    LinkedList listWithNode(10);
    result = listWithNode.printList();
    expected = "10->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";
}

void testAddToEnd() {
    std::cout << "Test addToEnd:\n";
    LinkedList list;
    list.addToEnd(5);
    list.addToEnd(10);
    list.addToEnd(15);

    std::string result = list.printList();
    std::string expected = "5->10->15->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";
}

void testContains() {
    LinkedList list;
    list.addToEnd(5);
    list.addToEnd(10);

    std::cout << "Test contains (5 exists):\n";
    if (list.contains(5)) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: true\nActual: " << (list.contains(5) ? "true" : "false") << "\n\n";

    std::cout << "Test contains (15 does not exist):\n";
    if (!list.contains(15)) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: false\nActual: " << (list.contains(15) ? "true" : "false") << "\n\n";
}

void testRemoveValue() {
    LinkedList list;
    list.addToEnd(5);
    list.addToEnd(10);
    list.addToEnd(15);

    std::cout << "Test removeValue (10 removed):\n";
    list.removeValue(10);
    std::string result = list.printList();
    std::string expected = "5->15->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    std::cout << "Test removeValue (5 removed):\n";
    list.removeValue(5);
    result = list.printList();
    expected = "15->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    std::cout << "Test removeValue (15 removed, list empty):\n";
    list.removeValue(15);
    result = list.printList();
    expected = "nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";
}

void testInsertValue() {
    LinkedList list;
    list.addToEnd(1);
    list.addToEnd(3);
    list.addToEnd(5);

    std::cout << "Test insertValue (2 at index 1):\n";
    list.insertValue(2, 1);
    std::string result = list.printList();
    std::string expected = "1->2->3->5->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    std::cout << "Test insertValue (4 at index 3):\n";
    list.insertValue(4, 3);
    result = list.printList();
    expected = "1->2->3->4->5->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    std::cout << "Test insertValue (0 at index 0):\n";
    list.insertValue(0, 0);
    result = list.printList();
    expected = "0->1->2->3->4->5->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";
}

void testPrintList() {
    LinkedList list;

    std::cout << "Test printList (empty list):\n";
    std::string result = list.printList();
    std::string expected = "nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    list.addToEnd(1);
    std::cout << "Test printList (single element):\n";
    result = list.printList();
    expected = "1->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";

    list.addToEnd(2);
    list.addToEnd(3);
    std::cout << "Test printList (multiple elements):\n";
    result = list.printList();
    expected = "1->2->3->nullptr";
    if (result == expected) {
        std::cout << "PASS\n";
        passCount++;
    } else {
        std::cout << "FAIL\n";
    }
    std::cout << "Expected: " << expected << "\nActual: " << result << "\n\n";
}

int main() {
    testConstructor();
    testAddToEnd();
    testContains();
    testRemoveValue();
    testInsertValue();
    testPrintList();

    std::cout << std::endl << "***** SUMMARY *****" << std::endl;
    std::cout << "Tests PASSED / FAILED: " << 
        passCount << "/" << 14 << " (" << (int)((passCount/14.0) * 100.0) << "%)" 
        << std::endl << std::endl;
    return 0;
}
