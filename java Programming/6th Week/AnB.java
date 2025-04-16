public class AnB {
   public static void main(String[] args) {
      new AnThread().start();
      new BThread().start();
   }
}

class AnThread extends Thread {
   public void run() {
      try {
         while (true) {
            System.out.println("An");
            Thread.sleep(1000);
         }
      } catch (InterruptedException e) {
         System.out.println(e);
      }
   }
}

class BThread extends Thread {
   public void run() {
      try {
         while (true) {
            System.out.println("B");
            Thread.sleep(3000);
         }
      } catch (InterruptedException e) {
         System.out.println(e);
      }
   }
}
