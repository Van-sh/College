public class supref {
   public static void main(String[] args) {
      Parent obj = new Child();
      obj.show();
   }
}

class Parent {
   void show() {
      System.out.println("This is the parent class");
   }
}

class Child extends Parent {
   void show() {
      System.out.println("This is the child class");
   }
}
