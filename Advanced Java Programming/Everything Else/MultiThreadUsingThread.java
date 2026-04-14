public class MultiThreadUsingThread {
   public static void main(String[] args) {
      EvenThread t1 = new EvenThread();
      OddThread t2 = new OddThread();
      t1.start();
      t2.start();
   }
}

class EvenThread extends Thread {
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

class OddThread extends Thread {
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