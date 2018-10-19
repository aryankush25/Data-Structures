public interface Stack<T> {
    int size();
    boolean isEmpty();
    void push(T t);
    T peek();
    T pop();
}