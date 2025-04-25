'''1. Write  a  Python  program  to  create  a  class  representing  a  linked  list  data  structure.  Include 
methods for displaying linked list data, inserting and deleting nodes. '''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def display(self):
        current = self.head
        while current:
            print(current.data, end=' -> ')
            current = current.next
        print('None')

    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def delete(self, key):
        current = self.head
        prev = None
        
        if current and current.data == key:
            self.head = current.next
            current = None
            return
        
        while current and current.data != key:
            prev = current
            current = current.next
        
        if current is None:
            print("Key not found in the list.")
            return
        
        prev.next = current.next
        current = None

# Example Usage
ll = LinkedList()
ll.insert(10)
ll.insert(20)
ll.insert(30)
ll.display()
ll.delete(20)
ll.display()
