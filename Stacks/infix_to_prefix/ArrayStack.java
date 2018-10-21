public class ArrayStack <T> implements Stack <T>
{
    private static int capacity = 1000;
    private T[] arr;
    private int top = 0;

    ArrayStack()
    {
        this(capacity);
    }

    ArrayStack(int capacity)
    {
        arr = (T[]) new Object[capacity];
    }

    public int Size()
    {
        return top;
    }

    public boolean isEmpty()
    {
        return (Size() == 0);
    }

    public T peek()
    {
        if(Size() == 0)
        {
            return null;
        }
        return arr[top - 1];
    }

    public T pop()
    {
        if(Size() == 0)
        {
            return null;
        }
        return arr[--top];
    }
    public void push(T t)
    {
        if(top == capacity)
        {
            System.out.println("The Stack is full");
            return;
        }
        arr[top++] = t;
    }
}