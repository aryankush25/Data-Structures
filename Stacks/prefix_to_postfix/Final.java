class Final
{
    public static boolean isChar(char c)
    {
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            return true;
        }
        return false;
    }

    public static void main(String[] args)
    {
        Stack<String> s = new ArrayStack<>();

        String prefix = "*-A/BC-/AKL", postfix = "";

        for(int i = prefix.length() - 1; i >= 0; i--)
        {
            Character c = prefix.charAt(i);
            if(isChar(c))
            {
                s.push(c.toString());
            }
            else
            {
                String temp = "";

                temp += s.pop();
                temp += s.pop();
                temp += c.toString();

                s.push(temp);
            }
        }

        while(!s.isEmpty())
        {
            postfix += s.pop();
        }

        System.out.println(postfix);
    }
}