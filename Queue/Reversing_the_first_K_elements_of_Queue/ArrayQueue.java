public class ArrayQueue <T> implements Queue <T>
{
    private Integer front, rear, size, capacity;
    private T[] arr;

    ArrayQueue()
    {
        this(1000);
    }
    ArrayQueue(Integer capacity)
    {
        this.front = this.rear = -1;
        this.size = 0;
        this.capacity = capacity;
        arr = (T[]) new Object[capacity];
    }
    public int size()
    {
        return size;
    }
    public boolean isEmpty()
    {
        return (size() == 0);
    }
    public boolean isFull()
    {
        if(front == 0 && rear == capacity - 1)
        {
            return true;
        }
        if(front == rear + 1)
        {
            return true;
        }
        return false;
    }
    public void enqueue(T t)
    {
        if (isFull()) {
            System.out.println("Queue is full");
        }
        else {
            size++;
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = t;
        }
    }
    public T dequeue()
    {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return null;
        }
        else {
            size--;
            T y = arr[front];
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % capacity;
            }
            return(y);
        }
    }
    public T front()
    {
        return arr[front];
    }
    public T rear()
    {
        return arr[rear];
    }
}
