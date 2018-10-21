public interface Stack<T>
{
    boolean isEmpty();
    T peek();
    T pop();
    void push(T t);
    int Size();
}