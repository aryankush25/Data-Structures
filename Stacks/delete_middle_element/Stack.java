public interface Stack<T>
{
    Integer Size();
    boolean isEmpty();
    T peek();
    T pop();
    void push(T t);
}
