import java.lang.*;
class Final
{
    public static boolean isChar(char s)
    {
        if((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
            return true;
        return false;
    }
    public static void main(String[] args) {
        Stack<Character> s = new ArrayStack<Character>();

        String infix = "a+b*c+(d/e)+f", postfix = "";
        for(int i = 0; i < infix.length(); i++)
        {
            if(isChar(infix.charAt(i)))
            {
                postfix = postfix + infix.charAt(i);
            }
            else
            {
                s.push(infix.charAt(i));
            }
        }

        while(!s.isEmpty())
        {
            postfix = postfix + s.pop();
        }
        
        System.out.println(postfix);
    }
}