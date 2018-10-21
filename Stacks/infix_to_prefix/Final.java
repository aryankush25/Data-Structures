class Final
{
    public static class Reverse
    {
        public String reverse(String temp)
        {
            String rev = "";

            for(int i = temp.length() - 1; i >= 0; i--)
            {
                if(temp.charAt(i) == '(')
                {
                    rev += ')';
                }
                else if(temp.charAt(i) == ')')
                {
                    rev += '(';
                }
                else
                {
                    rev += temp.charAt(i);
                }
            }
            return rev;
        }
    }

    public static class Postfix
    {
        public boolean isChar(char c)
        {
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
            {
                return true;
            }
            return false;
        }
        public int precedence(char c)
        {
            if (c == '^')
            {
                return 3;
            }
            else if (c == '*' || c == '/')
            {
                return 2;
            }
            else if (c == '+' || c == '-')
            {
                return 1;
            }
            else if(c == '(' || c == ')')
            {
                return 0;
            }
            return -1;
        }

        public String postfix(String infix)
        {
            Stack<Character> s = new ArrayStack<>();
            String postFix = "";

            for(int i = 0; i < infix.length(); i++)
            {
                char c = infix.charAt(i);

                if(isChar(c))
                {
                    postFix += c;
                }
                else
                {
                    if(s.isEmpty())
                    {
                        s.push(c);
                    }
                    else
                    {
                        int prec  = precedence(c);
                        int prec1 = precedence(s.peek());

                        if(prec == 0)
                        {
                            if(c == '(')
                            {
                                s.push(c);
                            }
                            else
                            {
                                while(s.peek() != '(')
                                {
                                    postFix += s.pop();
                                }
                                s.pop();
                            }
                        }
                        else
                        {
                            if(prec > prec1)
                            {
                                s.push(c);
                            }
                            else
                            {
                                while(prec <= prec1)
                                {
                                    postFix += s.pop();
                                    if(s.isEmpty())
                                    {
                                        break;
                                    }
                                    prec1 = precedence(s.peek());
                                }
                                s.push(c);
                            }
                        }
                    }
                }
            }

            while(!s.isEmpty())
            {
                postFix += s.pop();
            }

            return postFix;
        }
    }

    public static void main(String[] args)
    {
        Reverse rev = new Reverse();
        Postfix post = new Postfix();
        String infix = "(a-b/c)*(a/k-l)", prefix = "", postfix = "", rinfix = "";
        rinfix = rev.reverse(infix);

        postfix = post.postfix(rinfix);

        System.out.println(rev.reverse(postfix));
    }
}