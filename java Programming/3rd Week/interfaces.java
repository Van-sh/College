public class interfaces {
   public static void main(String[] args) {
      MyInterface obj = new MyClass();
      obj.show();
   }
}

interface MyInterface {
   void show();
}

class MyClass implements MyInterface {
   public void show() {
      System.out.println("Interface method implemented");
   }
}
