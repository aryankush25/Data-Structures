import java.util.*;

class SwapNodes {
    Node head;

    class Node {
        int value;
        Node next;
        Node(int value)
        {
            this.value = value;
            this.next = null;
        }
    }

    void push(int value)
    {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }

    void append(int value)
    {
        Node newNode = new Node(value);

        if(head == null)
        {
            head = newNode;
            return;
        }

        Node last = head;

        while(last.next != null)
        {
            last = last.next;
        }
        last.next = newNode;
    }

    void remove(int pos)
    {
        if(head == null)
        {
            return;
        }

        if(pos == 0)
        {
            head = head.next;
            return;
        }

        Node temp = head;
        int i = 0;

        while(i < pos - 1 && temp != null)
        {
            temp = temp.next;
            i++;
        }

        if(temp == null || temp.next == null)
        {
            return;
        }
        temp.next = temp.next.next;

    }

    void swapNodes(int key1, int key2)
    {
        if(head == null || key1 == key2)
        {
            return;
        }

        Node temp = head, prev1 = null, curr1 = null, prev2 = null, curr2 = null, t = null;

        while(temp != null)
        {
            if(temp.value == key1)
            {
                prev1 = t;
                curr1 = temp;
            }
            else if(temp.value == key2)
            {
                prev2 = t;
                curr2 = temp;
            }
            t = temp;
            temp = temp.next;
        }

        if(curr1 == null || curr2 == null)
        {
            return;
        }

        if(prev1 == null) {
            head = curr2;
        } else {
            prev1.next = curr2;
        }

        if(prev2 == null) {
            head = curr1;
        } else {
            prev2.next = curr1;
        }

        temp = curr1.next;
        curr1.next = curr2.next;
        curr2.next = temp;

    }

    void display()
    {
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.value + " ");
            temp = temp.next;
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        SwapNodes s = new SwapNodes();

        s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);
        s.push(1);
        s.push(0);

        s.display();

        s.swapNodes(0, 1);

        s.display();
    }
}