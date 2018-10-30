import java.util.Stack;

class DeleteKElements
{
    static void reverseK(ArrayQueue<Integer> queue, Integer k)
    {

    }

    static void display(ArrayQueue<Integer> queue)
    {
        ArrayQueue<Integer> queue1 = new ArrayQueue<>(4);

        while(!queue.isEmpty())
        {
            Integer x = queue.dequeue();
            if (x == null) {
                break;
            }
            System.out.println(x);
            queue1.enqueue(x);
        }

        while(!queue1.isEmpty())
        {
            queue.enqueue(queue1.dequeue());
        }
    }

    public static void main(String[] args) {
        ArrayQueue<Integer> queue = new ArrayQueue<>();

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        queue.dequeue();
        queue.enqueue(0);
        display(queue);
        reverseK(queue, 3);
        display(queue);
        System.out.println("Front " + queue.front());
        System.out.println("Rear " + queue.rear());
    }
}
