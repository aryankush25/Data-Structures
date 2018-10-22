import java.util.*;

class EvaluatePostfix
{
    static Integer evaluatePostfix(String s)
    {
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = 0; i < s.length(); i++)
        {
            Character c = s.charAt(i);

            if(c >= 48 && c <= 75)
            {
                Integer x = Character.getNumericValue(c);
                stack.push(x);
            }
            else
            {
                Integer x = stack.pop();
                Integer y = stack.pop();

                switch(c)
                {
                    case '+':
                    stack.push(y + x);
                    break;

                    case '-':
                    stack.push(y - x);
                    break;

                    case '*':
                    stack.push(y * x);
                    break;

                    case '/':
                    stack.push(y / x);
                    break;
                }
            }
        }
        return stack.pop();
    }
    public static void main(String[] args)
    {
        String s = "231*+9-";

        Integer x = evaluatePostfix(s);

        System.out.println("The total is :-> " + x);
    }
}
