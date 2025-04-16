public class Synchronization {
   public static void main(String[] args) {
      Shared s = new Shared();
      MyThread t1 = new MyThread(s, "Thread 1");
      MyThread t2 = new MyThread(s, "Thread 2");
      t1.start();
      t2.start();
   }
}

class MyThread extends Thread {
   Shared s;
   String name;

   MyThread(Shared s, String name) {
      this.s = s;
      this.name = name;
   }

   public void run() {
      s.printCount(name);
   }
}

class Shared {
   synchronized void printCount(String threadName) {
      for (int i = 0; i < 3; i++) {
         System.out.println(threadName + ": " + i);
      }
   }
}
