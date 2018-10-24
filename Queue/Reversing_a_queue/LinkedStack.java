public class LinkedStack<T>
{
    private LinkedList<T> stack = new LinkedList<T>();

    public Integer Size()
    {
        return stack.size();
    }

    public boolean isEmpty()
    {
        return stack.isEmpty();
    }

    public T peek()
    {
        return stack.first();
    }

    public T pop()
    {
        T temp = stack.first();
        stack.removeFirst();
        return temp;
    }

    public void push(T t)
    {
        stack.addFirst(t);
    }

}
