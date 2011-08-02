import java.util.ArrayList;
import java.util.Stack;

public class QueueUsingStacks<E> {

  private Stack<E> s1;
  private Stack<E> s2;

  QueueUsingStacks() {
    s1 = new Stack<E>();
    s2 = new Stack<E>();
  }

  int size () {
    return s1.size() + s2.size();
  }
  
  boolean empty () {
    return (0 == (s1.size() + s2.size()));
  }

  void enque (E item) {
    s1.push(item);
  }

  /**
   *  Being Lazy: Only move items when needed
   **/
  E peek () {
    if (!s2.empty())
      return s2.peek();
    
    while (!s1.empty())
      s2.push(s1.pop());

    return s2.peek();
  }

  E deque () {
    if (!s2.empty())
      return s2.pop();

    while (!s1.empty())
      s2.push(s1.pop());

    return s2.pop();
  }

  public static void main (String args[]) {

    QueueUsingStacks<Integer> q = new QueueUsingStacks<Integer>();

    System.out.println(q.size());

    for (int i = 0; i < 10; i++)
      q.enque(i);

    System.out.println("Size = " + q.size());

    while (!q.empty())
      System.out.print(q.deque() + " ");

    System.out.println();
           
  }

}