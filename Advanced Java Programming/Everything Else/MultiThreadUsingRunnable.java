public class MultiThreadUsingRunnable {
   public static void main(String[] args) {
      EvenRunnable obj1 = new EvenRunnable();
      OddRunnable obj2 = new OddRunnable();
      Thread t1 = new Thread(obj1);
      Thread t2 = new Thread(obj2);
      t1.start();
      t2.start();
   }
}

class EvenRunnable implements Runnable {
   public void run() {
      for (int i = 2; i <= 10; i += 2) {
         System.out.println("Even Thread: " + i);
         try {
            Thread.sleep(500);
         } catch (InterruptedException e) {
            System.out.println(e);
         }
      }
   }
}

class OddRunnable implements Runnable {
   public void run() {
      for (int i = 1; i <= 9; i += 2) {
         System.out.println("Odd Thread: " + i);
         try {
            Thread.sleep(500);
         } catch (InterruptedException e) {
            System.out.println(e);
         }
      }
   }
}