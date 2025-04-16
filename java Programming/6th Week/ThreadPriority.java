public class ThreadPriority {
   public static void main(String[] args) {
      PriorityThread t1 = new PriorityThread(Thread.MIN_PRIORITY);
      PriorityThread t2 = new PriorityThread(Thread.NORM_PRIORITY);
      PriorityThread t3 = new PriorityThread(Thread.MAX_PRIORITY);

      t1.start();
      t2.start();
      t3.start();
   }
}

class PriorityThread extends Thread {
   PriorityThread(int priority) {
      super();
      super.setPriority(priority);
   }

   public void run() {
      try {
         Thread.sleep(2000);
         System.out.println(Thread.currentThread().getName() + " Priority: " + getPriority());
      } catch (Exception e) {
         System.out.println(e);
      }
   }
}
