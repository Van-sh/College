// 14. Write a java program to implement stack and queue concept.

import java.util.Scanner;

public class stackqueue {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int[] stack = new int[100];
      int[] queue = new int[100];
      int stackTop = -1;
      int queueFront = 0;
      int queueRear = 0;
      while (true) {
         System.out.println(
               "Choose an operation: 1. Push to Stack 2. Pop from Stack 3. Enqueue to Queue 4. Dequeue from Queue 5. Exit");
         int choice = sc.nextInt();
         switch (choice) {
            case 1:
               if (stackTop < stack.length - 1) {
                  System.out.print("Enter a number to push to stack: ");
                  stack[++stackTop] = sc.nextInt();
                  System.out.print("Stack: ");
                  for (int i = 0; i <= stackTop; i++) {
                     System.out.print(stack[i] + " ");
                  }
                  System.out.println();
               } else {
                  System.out.println("Stack is full.");
               }
               break;
            case 2:
               if (stackTop >= 0) {
                  System.out.println("Popped from stack: " + stack[stackTop--]);
                  System.out.print("Stack: ");
                  for (int i = 0; i <= stackTop; i++) {
                     System.out.print(stack[i] + " ");
                  }
                  System.out.println();
               } else {
                  System.out.println("Stack is empty.");
               }
               break;
            case 3:
               if (queueRear < queue.length) {
                  System.out.print("Enter a number to enqueue to queue: ");
                  queue[queueRear++] = sc.nextInt();
                  System.out.print("Queue: ");
                  for (int i = queueFront; i < queueRear; i++) {
                     System.out.print(queue[i] + " ");
                  }
                  System.out.println();
               } else {
                  System.out.println("Queue is full.");
               }
               break;
            case 4:
               if (queueFront < queueRear) {
                  System.out.println("Dequeued from queue: " + queue[queueFront++]);
                  System.out.print("Queue: ");
                  for (int i = queueFront; i < queueRear; i++) {
                     System.out.print(queue[i] + " ");
                  }
                  System.out.println();
               } else {
                  System.out.println("Queue is empty.");
               }
               break;
            case 5:
               System.out.println("Exiting...");
               sc.close();
               return;
            default:
               System.out.println("Invalid choice. Try again.");
         }
      }
   }
}