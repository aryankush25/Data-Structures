import java.util.Stack;

class ReverseStack
{
    static void atBottom(Stack<Integer> stack, Integer x)
    {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }

        Integer y = stack.pop();

        atBottom(stack, x);

        stack.push(y);

    }

    static void reverse(Stack<Integer> stack)
    {
        if ((stack.isEmpty())) {
            return;
        }
        Integer x = stack.pop();

        reverse(stack);

        atBottom(stack, x);
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        reverse(stack);

        System.out.println(stack);

    }
}
