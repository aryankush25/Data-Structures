public class LinkedList<T>
{
    private static class Node<T>
    {
        // Private Elements of class Node
        private T element;
        private Node<T> next;

        // Constructors of class Node
        public Node(T element)
        {
            this(element, null);
        }
        public Node(T element, Node<T> next)
        {
            this.element = element;
            this.next = next;
        }

        // Access methode of class Node (getter & setters)
        public T getElement()
        {
    		return this.element;
    	}
    	public void setElement(T element)
        {
    		this.element = element;
    	}
    	public Node<T> getNext()
        {
    		return this.next;
    	}
    	public void setNext(Node<T> next)
        {
    		this.next = next;
    	}
    }

    // Private Elements of class LinkedList
    private Node<T> head = null;
    private Node<T> tail = null;
    private Integer size = 0;

    // Access methods of class LinkedList
    public Integer Size()
    {
        return size;
    }
    public boolean isEmpty()
    {
        return (size == 0);
    }
    public T first()
    {
        return head.getElement();
    }
    public T last()
    {
        return tail.getElement();
    }
    public void addAtFirst(T t)
    {
        size++;
        Node<T> first = new Node<T>(t);

        if (head == null) {
            head = first;
            tail = head;
            return;
        }

        first.setNext(head);
        head = first;
    }
    public void addAtlast(T t)
    {
        size++;
        Node<T> last = new Node<T>(t);

        if (tail == null) {
            tail = last;
            head = tail;
            return;
        }

        tail.setNext(last);
        tail = last;
    }
    public void removeFirst()
    {
        if (head == null) {
            return;
        }
        size--;
        head = head.getNext();
        if (head == null) {
            tail = null;
        }
    }
    public void removeLast()
    {
        if (tail == null) {
            return;
        }
        size--;

        if(head.getNext() == null)
        {
            removeFirst();
            return;
        }

        Node<T> temp = head;

        while(temp.getNext().getNext() != null)
        {
            temp = temp.getNext();
        }

        tail = temp;
        tail.setNext(null);
    }
    public void display()
    {
        Node<T> temp = head;

        while(temp != null)
        {
            System.out.println(temp.getElement());
            temp = temp.getNext();
        }
    }
}
