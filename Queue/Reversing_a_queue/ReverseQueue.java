class ReverseQueue
{
    static void display(LinkedQueue<Integer> queue)
    {
        LinkedStack<Integer> stack = new LinkedStack<>();

        while(!queue.isEmpty())
        {
            Integer x = queue.dequeue();
            System.out.println(x);
            stack.push(x);
        }

        while(!stack.isEmpty())
        {
            queue.enqueue(stack.pop());
        }
    }

    static void reverse(LinkedQueue<Integer> queue)
    {
        if (queue.isEmpty()) {
            return;
        }

        Integer x = queue.dequeue();

        reverse(queue);

        queue.enqueue(x);

    }

    public static void main(String[] args) {
        LinkedQueue<Integer> queue = new LinkedQueue<>();

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        display(queue);
        reverse(queue);
        display(queue);

    }
}
