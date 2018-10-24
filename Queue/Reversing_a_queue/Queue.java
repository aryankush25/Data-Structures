public interface Queue <T>
{
    void enqueue(T t);
    T dequeue();
    T front();
    T rear();
    boolean isEmpty();
    int size();
}
