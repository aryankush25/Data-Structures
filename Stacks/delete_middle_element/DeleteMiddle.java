class DeleteMiddle
{
    public static void display(Stack<Integer> stack)
    {
        if (stack.isEmpty()) {
            return;
        }
        Integer temp = stack.pop();

        System.out.println(temp);

        display(stack);

        stack.push(temp);
    }

    static void deleteMiddle(Stack<Integer> stack, Integer x, Integer size)
    {
        if (stack.isEmpty()) {
            return;
        }
        if (size / 2 == x - 1) {
            stack.pop();
            return;
        }
        Integer y = stack.pop();

        deleteMiddle(stack, x + 1, size);

        stack.push(y);

    }

    static void deleteMiddle(Stack<Integer> stack)
    {
        deleteMiddle(stack, 1, stack.Size());
    }

    public static void main(String[] args) {

        Stack<Integer> stack = new LinkedStack<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);

        display(stack);

        deleteMiddle(stack);

        System.out.println();
        display(stack);
    }
}
