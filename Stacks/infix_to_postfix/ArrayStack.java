package infix_to_postfix;

public class ArrayStack <T> implements Stack <T>
{
    static int capacity = 1000;
    T[] data;
    int top = 0;

    public ArrayStack()
    {
        this(capacity);
    }

    public ArrayStack(int capacity)
    {
        data = (T[]) new Object[capacity];
    }

    public int size()
    {
        return top;
    }

    public boolean isEmpty()
    {
        return (top == 0);
    }

    public void push(T t)
    {
        if (size() == data.length) {
            System.out.println("Array Is Full");
            return;
        }

        data[top++] = t;
    }

    public T peek()
    {
        if (isEmpty()) {
            return null;
        }
        return data[top - 1];
    }

    public T pop()
    {
        if (isEmpty()) {
            return null;
        }
        top--;
        T ans = data[top];
        data[top] = null;
        return ans;
    }
}