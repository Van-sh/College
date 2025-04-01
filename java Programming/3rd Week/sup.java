public class sup {
   public static void main(String[] args) {
      ChildTest obj = new ChildTest();
      obj.display();
      obj.show();
   }
}

class ParentTest {
   int x = 10;

   ParentTest() {
      System.out.println("ParentTest Constructor");
   }

   void display() {
      System.out.println("ParentTest method");
   }
}

class ChildTest extends ParentTest {
   int x = 20;

   ChildTest() {
      super();
      System.out.println("ChildTest Constructor");
   }

   void display() {
      super.display();
      System.out.println("ChildTest method");
   }

   void show() {
      System.out.println("ChildTest x = " + x);
      System.out.println("Parent x = " + super.x);
   }
}
