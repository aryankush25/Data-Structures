package infix_to_postfix;

class Final
{
    public static boolean isChar(char s)
    {
        if((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
            return true;
        return false;
    }
    
    public static int precedence(char s)
    {
    	if(s == '^')
    		return 3;
    	else if(s == '/' || s == '*')
    		return 2;
    	else if(s == '+' || s == '-')
    		return 1;
    	else if(s == '(' || s == ')')
    		return 0;
    	
    	return -1;
    }
    
    public static void main(String[] args) {
        Stack<Character> s = new ArrayStack<Character>();

        String infix = "a+b*(c^d-e)^(f+g*h)-i", postfix = "";
        for(int i = 0; i < infix.length(); i++)
        {
            if(isChar(infix.charAt(i)))
            {
                postfix = postfix + infix.charAt(i);
            }
            else
            {   
                if(s.isEmpty())
                {
                	s.push(infix.charAt(i));
                }
                else
                {
                	int x = precedence(infix.charAt(i));
                	int y = precedence(s.peek());
                	
                	if(x == 0)
                	{
                		if(infix.charAt(i) == '(')
                		{
                			s.push(infix.charAt(i));
                		}
                		else
                		{
                			char c = s.peek();
                			while(c != '(')
                	        {
                	            postfix = postfix + s.pop();
                	            c = s.peek();
                	        }
                			s.pop();
                		}
                	}
                	else if(x > y)
                	{
                		s.push(infix.charAt(i));
                	}
                	else if(x == y || x < y)
                	{
            			while(x == y || x < y)
            	        {
            	            postfix = postfix + s.pop();
            	            if(s.isEmpty())
            	            	break;
            	            y = precedence(s.peek());
            	        }
            			
                		s.push(infix.charAt(i));
                	}
                }
                
            }
        }

        while(!s.isEmpty())
        {
            postfix = postfix + s.pop();
        }
        
        System.out.println(postfix);
    }
}