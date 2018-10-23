import java.util.Stack;

class NGE
{
    static void nge(Integer[] arr)
    {
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < arr.length; i++)
        {
            if (stack.isEmpty())
            {
                stack.push(arr[i]);
            }
            else
            {
                while(!stack.isEmpty() && arr[i] > stack.peek())
                {
                    System.out.println(stack.pop() + " --> " + arr[i]);
                }
                stack.push(arr[i]);
            }
        }

        while(!stack.isEmpty())
        {
            System.out.println(stack.pop() + " --> -1");
        }
    }
    public static void main(String[] args) {
        Integer[] arr = {11, 13, 21, 3};

        nge(arr);

    }
}
