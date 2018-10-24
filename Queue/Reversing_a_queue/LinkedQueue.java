public class LinkedQueue <T> implements Queue <T>
{
    private LinkedList<T> list = new LinkedList<T>();

    public void enqueue(T t)
    {
        list.addLast(t);
    }
    public T dequeue()
    {
        return list.removeFirst();
    }
    public T front()
    {
        return list.first();
    }
    public T rear()
    {
        return list.last();
    }
    public int size()
    {
        return list.size();
    }
    public boolean isEmpty()
    {
        return list.isEmpty();
    }
}
