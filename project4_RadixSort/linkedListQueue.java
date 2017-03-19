import java.io.BufferedWriter;
import java.io.IOException;

public class linkedListQueue 
{
	listNode head; // a listNode pointer
	listNode tail; // a listNode pointer
	
	// to create a new queue with a dummy node, initially, head and tail point to the same dummy node.
	public linkedListQueue()
	{
		listNode dummy = new listNode(0);
		head = dummy;
		tail = dummy;
	}
	// add a node at the tail of the queue	
	public void addTail(listNode n)
	{	
		listNode oldTail = tail;
		tail = n;
		tail.next = null;
		if (isEmpty())
			head = tail;
		else
			oldTail.next = tail;
	}
	// delete a node from the head of queue
	public listNode deleteHead()		
	{
		if(isEmpty()) System.out.println("Queue is Empty!!! Deletion is not possible!!!");
		listNode temp = head;
		
		head = head.next;
		
		return temp;
	}
	
	
	// return 1 if the stack is empty, return 0 otherwise.
	public boolean isEmpty()
	{
		if(head == null) return true;
		return false; 
	}
	
	public void printQueue(BufferedWriter bw) throws IOException
	{
		if(isEmpty()) System.out.println("Queue is Empty!!!" );
		listNode temp = head;
		while(temp != null)
		{
			if(temp.data!=0)
			{
				bw.write(temp.data+", ");				
			}
			
			temp = temp.next;
		}
	}
}
