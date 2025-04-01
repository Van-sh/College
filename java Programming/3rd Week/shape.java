public class shape {
   public static void main(String[] args) {
      Shape rect = new Rectangle();
      Shape tri = new Triangle();

      rect.draw();
      tri.draw();
   }
}

abstract class Shape {
   abstract void draw();
}

class Rectangle extends Shape {
   void draw() {
      System.out.println("Drawing Rectangle");
   }
}

class Triangle extends Shape {
   void draw() {
      System.out.println("Drawing Triangle");
   }
}
