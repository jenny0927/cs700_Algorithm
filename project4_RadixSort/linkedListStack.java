import java.io.BufferedWriter;
import java.io.IOException;

public class linkedListStack 
{
	listNode top; 
	public  linkedListStack()
	{
		top = null;
	}

	void push(listNode newNode) 
	{
		listNode oldValue = top;
		top = newNode;
		top.next = oldValue;
	}

	public listNode Pop()
	{
		
		if(!isEmpty()) 
		{			
			listNode current = top;
			top = top.next;
			return current;
		}
		
		System.out.println("Stack is Empty!!! Deletion is not possible!!!");
		return null;
	 }

	public boolean isEmpty()
	{
		 if(top == null) 
			 return true;
		 return false;
	 }
	
	public void printStack(BufferedWriter bw)  throws IOException
	{
		if(isEmpty()) System.out.println("Stack is Empty!!! Deletion is not possible!!!");
		else{
			listNode temp = top;
			
			while(temp!=null)
			{
				bw.write(temp.data+"\n");
				//System.out.println(temp.data);
				temp = temp.next;
			}
		}	
	}
}

