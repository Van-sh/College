public class Deadlock {
   public static void main(String[] args) {
      final String resource1 = "Resource1";
      final String resource2 = "Resource2";

      Thread t1 = new Thread(() -> {
         synchronized (resource1) {
            System.out.println("Thread 1: locked resource 1");

            try {
               Thread.sleep(100);
            } catch (Exception e) {
               System.out.println(e);
            }

            synchronized (resource2) {
               System.out.println("Thread 1: locked resource 2");
            }
         }
      });

      Thread t2 = new Thread(() -> {
         synchronized (resource2) {
            System.out.println("Thread 2: locked resource 2");

            try {
               Thread.sleep(100);
            } catch (Exception e) {
               System.out.println(e);
            }

            synchronized (resource1) {
               System.out.println("Thread 2: locked resource 1");
            }
         }
      });

      t1.start();
      t2.start();
   }
}
