import java.util.Stack;

class SortingStack
{
    static void toPlaceSort(Stack stack, Integer x)
    {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }

        Integer y = stack.peek();

        if (x > y) {
            stack.push(x);
            return;
        }
        else
        {
            stack.pop();
            toPlaceSort(stack, x);
            stack.push(y);
        }
    }

    static void sort(Stack stack)
    {
        if (stack.isEmpty()) {
            return;
        }

        Integer x = stack.pop();

        sort(stack);

        toPlaceSort(stack, x);

    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(1);
        stack.push(57);
        stack.push(4);
        stack.push(54);
        stack.push(43);
        stack.push(18);

        sort(stack);

        System.out.println(stack);
    }
}
